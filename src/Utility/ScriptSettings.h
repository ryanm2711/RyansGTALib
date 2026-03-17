	#pragma once
#include "../vendor/SimpleIni.h"

#include <typeinfo>
#include <string>
#include <vector>

namespace Utility {
	struct Setting {
		std::wstring section;
		std::wstring key;
		std::wstring comment;
		std::wstring defaultValue;
		void* targetVariable;
		std::wstring type;
	};

	class ScriptSettings {
	public:
		ScriptSettings(std::string iniPath) : m_IniPath(iniPath) {};

		void Load();
		void Save();

		template <typename T>
		inline void RegisterSetting(const wchar_t* section, const wchar_t* key, T defaultValue, T* target, const wchar_t* comment=L"") {
			*target = defaultValue;

			// Store info so can be used later
			Setting newSetting;

			// Convert data types to wstring
			std::wstring s_section{ section };
			std::wstring s_key{ key };
			std::wstring s_comment{ comment };

			newSetting.section = s_section;
			newSetting.key = s_key;
			newSetting.comment = s_comment;


			// Convert the T value to wstring
			if constexpr (std::is_same_v<T, const wchar_t*> || std::is_same_v<T, std::string>) {
				// Handle strings
				newSetting.defaultValue = std::wstring{ defaultValue };
			} 
			else {
				newSetting.defaultValue = std::to_wstring(defaultValue);
			}

			// Store pointer itself
			newSetting.targetVariable = static_cast<void*>(target);

			std::string t_name = typeid(T).name();
			newSetting.type = std::wstring(t_name.begin(), t_name.end());

			m_RegisteredSettings.push_back(newSetting);
		}
	private:
		CSimpleIni m_IniFile;
		std::vector<Setting> m_RegisteredSettings;
		std::string m_IniPath;
	};
}