#include "Hud.h"
#include <natives.h>

int GTA::UI::ShowNotification(std::string text) {
	HUD::BEGIN_TEXT_COMMAND_THEFEED_POST((char*)"STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text.c_str());
	return HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(1, 1);
}

void GTA::UI::ShowSubtitle(std::string text, int duration) {
	HUD::BEGIN_TEXT_COMMAND_PRINT((char*)"STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text.c_str());
	HUD::END_TEXT_COMMAND_PRINT(duration, true);
}

void GTA::UI::ShowMessage(std::string text, bool emitSound, int duration) {
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_HELP((char*)"STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text.c_str());
	HUD::END_TEXT_COMMAND_DISPLAY_HELP(0, false, emitSound, duration);
}

void GTA::UI::ShowText(std::string text, float x, float y, GTA::UI::Color color, int font, float scale)
{
	HUD::SET_TEXT_FONT(font);
	HUD::SET_TEXT_SCALE(1.0f, scale); // p0 is unknown what it does
	HUD::SET_TEXT_COLOUR(color.r, color.g, color.b, color.a);
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text.c_str());
	HUD::END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0); // Unsure what p2 does
}
