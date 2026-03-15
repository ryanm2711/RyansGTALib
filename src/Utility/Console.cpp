#include "Console.h"
#include <windows.h>
#include <iostream>

void Utility::CreateDebugConsole() {
	AllocConsole();

	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	freopen_s(&f, "CONOUT$", "w", stderr);
	freopen_s(&f, "CONIN$", "r", stdin);

	std::cout << "RyansGTALib - Debug console initialized!" << std::endl;
}

void Utility::CloseDebugConsole() {
	// 1. Flush the buffers
	std::cout.flush();
	std::cerr.flush();

	// 2. Close the console window
	FreeConsole();

	// Prevent stray stdout/stderr from crashing due to console no longer existing
	FILE* f;
	freopen_s(&f, "NUL", "w", stdout);
	freopen_s(&f, "NUL", "w", stderr);
	freopen_s(&f, "NUL", "r", stdin);
}