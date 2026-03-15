#pragma once
#include "../vendor/SimpleIni.h"
#include <string>
#include <vector>

namespace Utility {
	struct Setting {
		std::wstring section;
		std::wstring key;
		std::wstring defaultValue;
		void* targetVariable;
		std::wstring type;
	};

	class ScriptSettings {
	public:
		ScriptSettings(std::string iniPath) : m_IniPath(iniPath) {};

		template <typename T>
		void RegisterSetting(const char* section, const char* key, T defaultValue, T* target);
		void Load();
	private:
		CSimpleIni m_IniFile;
		std::vector<Setting> m_RegisteredSettings;
		std::string m_IniPath;
	};
}