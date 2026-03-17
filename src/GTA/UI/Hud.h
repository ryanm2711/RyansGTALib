#pragma once
#include <string>

namespace GTA::UI {
	struct Color {
		int r;
		int g;
		int b;
		int a;
	};

	int ShowNotification(std::string text);
	void ShowSubtitle(std::string text, int duration = 5);
	void ShowMessage(std::string text, bool emitSound = true, int duration=-1);
	void ShowText(std::string text, float x, float y, GTA::UI::Color color={255, 255, 255, 255}, int font=0, float scale=0.5f);
}