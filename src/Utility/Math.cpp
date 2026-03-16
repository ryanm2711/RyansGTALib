#include "Math.h"

std::string Utility::Math::FormatVector(Vector3 vec3)
{
	std::string str = "Vector(X:";
	str = str + std::to_string(vec3.x) + ", Y: ";
	str = str + std::to_string(vec3.y) + ", Z: ";
	str = str + std::to_string(vec3.z) + ")";

	return str;
}

float Utility::Math::DegreesToRadians(float deg)
{
	return deg * (M_PI / 180.0f);
}

float Utility::Math::RadiansToDegrees(float rad)
{
	return rad * (180.0f / M_PI);
}
