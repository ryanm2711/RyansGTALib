#include "ScriptSettings.h"

void Utility::ScriptSettings::Load()
{
	m_IniFile.LoadFile(m_IniPath.c_str());

	for (auto& setting : m_RegisteredSettings) {
		const wchar_t* result = m_IniFile.GetValue(setting.section.c_str(), setting.key.c_str());

		if (result != nullptr) {
		}
	}
}

template<typename T>
void Utility::ScriptSettings::RegisterSetting(const char* section, const char* key, T defaultValue, T* target)
{
	*target = defaultValue;

	// Store info so can be used later
	Setting newSetting;
	newSetting.section = section;
	newSetting.key = key;
	newSetting.defaultValue = defaultValue;
	newSetting.targetVariable = &target;
	newSetting.type = typeid(T).name();

	m_RegisteredSettings.push_back(newSetting);
}
