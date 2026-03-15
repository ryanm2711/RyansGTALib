#pragma once
#include <string>

namespace GTA::UI {
	int ShowNotification(std::string text);
	void ShowSubtitle(std::string text, int duration = 5);
	void ShowMessage(std::string text, bool emitSound = true, int duration=-1);
}