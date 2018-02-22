#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace math
{
	inline float radians(const float& _degrees)
	{
		return (_degrees * M_PI) / 180.0f;
	}

	inline float degrees(const float& _radians)
	{
		return (_radians * 180.0f) / float(M_PI);
	}
}
