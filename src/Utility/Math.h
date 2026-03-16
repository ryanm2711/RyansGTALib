#pragma once
#define _USE_MATH_DEFINES

#include <string>
#include <types.h>
#include <math.h>

namespace Utility::Math {
	std::string FormatVector(Vector3 vec3);
	float DegreesToRadians(float deg);
	float RadiansToDegrees(float rad);
}