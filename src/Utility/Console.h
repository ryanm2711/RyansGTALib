#pragma once
#include <iostream>

namespace Utility {
	void CreateDebugConsole();
	void CloseDebugConsole();

	template<typename... Args>
	inline void Log(Args... args) {
		#ifdef _DEBUG
			(std::cout << ... << args) << "\n";
		#endif
	}
}