#include "Controls.h"
#include <natives.h>


bool GTA::Controls::IsControlPressed(int index, ControlTypes control)
{
	return PAD::IS_DISABLED_CONTROL_PRESSED(index, static_cast<int>(control));
}

bool GTA::Controls::IsControlJustPressed(int index, ControlTypes control)
{
	return PAD::IS_DISABLED_CONTROL_JUST_PRESSED(index, static_cast<int>(control));
}

void GTA::Controls::EnableControlThisFrame(int index, ControlTypes control, bool enableRelatedActions)
{
	PAD::ENABLE_CONTROL_ACTION(index, static_cast<int>(control), enableRelatedActions);
}

void GTA::Controls::DisableControlThisFrame(int index, ControlTypes control, bool disableRelatedActions)
{
	PAD::DISABLE_CONTROL_ACTION(index, static_cast<int>(control), disableRelatedActions);
}
