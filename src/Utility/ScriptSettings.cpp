#include "ScriptSettings.h"
#include <iostream>
#include <stdexcept>

void Utility::ScriptSettings::Load()
{
	SI_Error response = m_IniFile.LoadFile(m_IniPath.c_str());
	if (response < 0) {
		// Handle proper reporting
		switch (response) {
		case -1:
			std::cout << "Failed to load file!\n";
			break;
		case -2:
			std::cout << "Failed to load file: Out of memory!\n";
			break;
		case -3:
			std::cout << "Failed to load file!\n";
			break;
		}

		// If file hasn't loaded properly, let's make a copy.
		Save();
	}
	else {
		// Ini loaded successfully, now let's compare data between our registered settings and ini

		for (Setting& setting : m_RegisteredSettings) {
			const wchar_t* result = m_IniFile.GetValue(setting.section.c_str(), setting.key.c_str());
			std::wstring s_result{ result };

			if (result == nullptr) {
				std::cerr << "result is invalid for ini, wrong input?\n";
				continue;
			}

			// Send ini results to variable
			try {
				if (setting.type == L"float") {
					float parsedValue = std::stof(s_result);
					// Cast void* to a float* so it's writable
					float* target = static_cast<float*>(setting.targetVariable);
					// Assign value
					*target = parsedValue;
				} // Repeat the same for the other data types
				else if (setting.type == L"int" || setting.type == L"short" || setting.type == L"long") {
					long parsedValue = std::stoi(s_result);
					long* target = static_cast<long*>(setting.targetVariable);
					*target = parsedValue;
				}
				else if (setting.type == L"unsigned long" || setting.type == L"DWORD") {
					unsigned long parsedValue = std::stoul(s_result);
					DWORD* target = static_cast<DWORD*>(setting.targetVariable);
					*target = parsedValue;
				}
				else {
					throw std::invalid_argument("Unsupported type");
				}
			}
			catch (const std::invalid_argument& e) {
				std::wcerr << "INI Error: Invalid value for " << setting.key << " " << e.what() << "\n";
				// We don't crash; we just keep the default value already in *target
			}
			catch (const std::out_of_range& e) {
				std::wcerr << "INI Error: Value for " << setting.key << " is too large/small." << "\n";
			}
			catch (...) {
				std::cerr << "An unknown error occurred while loading settings." << std::endl;
			}
		}
	}
}

void Utility::ScriptSettings::Save()
{
	CSimpleIni newIniFile;
	newIniFile.SetUnicode(true);

	for (Setting& setting : m_RegisteredSettings) {
		std::wstring s_value;
		if (setting.type == L"float") {
			auto value = *static_cast<float*>(setting.targetVariable);
			s_value = std::to_wstring(value);
		}
		else if (setting.type == L"int" || setting.type == L"short" || setting.type == L"long") {
			auto value = *static_cast<long*>(setting.targetVariable);
			s_value = std::to_wstring(value);
		}
		else if (setting.type == L"unsigned long" || setting.type == L"DWORD") {
			auto value = *static_cast<DWORD*>(setting.targetVariable);
			s_value = std::to_wstring(value);
		}

		SI_Error error = newIniFile.SetValue(setting.section.c_str(), setting.key.c_str(), s_value.c_str(), setting.comment.c_str(), false);
		if (error < 0) {
			// TODO: Proper error handling here
			std::wcerr << "Failed to save setting {SECTION: " << setting.section << ", KEY: " << setting.key << "}";
		}
	}

	std::string data;
	newIniFile.Save(data, false);

	newIniFile.SaveFile(m_IniPath.c_str());
}