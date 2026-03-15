#pragma once
#include "ControlTypes.h"
#include "ControlActionSets.h"
#include "Keyboard.h"

namespace GTA {
	namespace Controls {
		bool IsControlPressed(int index, ControlTypes control);
		bool IsControlJustPressed(int index, ControlTypes control);
		void EnableControlThisFrame(int index, ControlTypes control, bool enableRelatedActions=true);
		void DisableControlThisFrame(int index, ControlTypes control, bool disableRelatedActions=true);
	}
}