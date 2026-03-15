#pragma once
#include <Windows.h>

namespace GTA {
	namespace Controls {
		// parameters are the same as with aru's ScriptHook for IV
		void OnKeyboardMessage(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);

		bool IsKeyDown(DWORD key);
		bool IsKeyJustUp(DWORD key, bool exclusive = true);
		void ResetKeyState(DWORD key);
	}
}
