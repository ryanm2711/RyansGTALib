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