#pragma once

#include "vec3.h"
#include "mat4.h"
#include "quat.h"

namespace math
{
	inline mat4f rotation(const float& _radians, const vec3f& _axis)
	{

	}

	inline mat4f rotation(const float& _x, const float& _y, const float& _z)
	{

	}

	inline mat4f translation(const vec3f& _position)
	{

	}

	inline mat4f scale(const vec3f& _scale)
	{

	}

	inline mat4f euler_to_mat4(const float& _x, const float& _y, const float& _z)
	{

	}

	inline mat4f quat_to_mat4(const quat& _quat)
	{

	}

	inline quat mat4_to_quat(const mat4f& _mat)
	{

	}

	inline quat euler_to_quat(const float& _x, const float& _y, const float& _z)
	{

	}

	inline vec3f mat4_to_euler(const mat4f& _mat)
	{

	}

	inline vec3f quat_to_euler(const quat& _quat)
	{

	}
}