#pragma once

#include "vec3.h"
#include "mat4.h"
#include "quat.h"

namespace math
{
	inline mat4f rotation(const float& _radians, const vec3f& _axis)
	{
		mat4f m;

		float cosTheta = cosf(_radians);
		float sinTheta = sinf(_radians);

		m.m11 = powf(_axis.x, 2.0f) * (1.0f - cosTheta) + cosTheta;
		m.m12 = _axis.x * _axis.y * (1.0f - cosTheta) - _axis.z * sinTheta;
		m.m13 = _axis.x * _axis.z * (1.0f - cosTheta) + _axis.y * sinTheta;

		m.m21 = _axis.x * _axis.y * (1.0f - cosTheta) + _axis.z * sinTheta;
		m.m22 = powf(_axis.y, 2.0f) * (1.0f - cosTheta) + cosTheta; 
		m.m23 = _axis.y * _axis.z * (1.0f - cosf(_radians)) - _axis.x * sinTheta;

		m.m31 = _axis.x * _axis.z * (1.0f - cosTheta) - _axis.y * sinTheta;
		m.m32 = _axis.y * _axis.z * (1.0f - cosTheta) + _axis.x * sinTheta;
		m.m33 = powf(_axis.z, 2.0f) * (1.0f - cosTheta) + cosTheta;

		return m;
	}

	inline mat4f rotation(const float& _x, const float& _y, const float& _z)
	{
		mat4f B, P, H;

		P.m22 = cosf(_x);
		P.m23 = -sinf(_x);

		P.m32 = sinf(_x);
		P.m33 = cosf(_x);

		H.m11 = cosf(_y);
		H.m13 = sinf(_y);

		H.m31 = -sinf(_y);
		H.m33 = cosf(_y);

		B.m11 = cosf(_z);
		B.m12 = -sinf(_z);

		B.m21 = sinf(_z);
		B.m22 = cosf(_z);

		return H * P * B;
	}

	inline mat4f translation(const vec3f& _position)
	{
		mat4f m;

		m.m14 = _position.x;
		m.m24 = _position.y;
		m.m34 = _position.z;

		return m;
	}

	inline mat4f scale(const vec3f& _scale)
	{
		mat4f m;

		m.m11 = _scale.x;
		m.m22 = _scale.y;
		m.m33 = _scale.z;

		return m;
	}

	inline mat4f scale(const float& _scale, const vec3f& _axis)
	{
		mat4f m;

		m.m11 = 1.0f + (_scale - 1.0f) * powf(_axis.x, 2.0f);
		m.m12 = (_scale - 1.0f) * _axis.x * _axis.y;
		m.m13 = (_scale - 1.0f) * _axis.x * _axis.z;

		m.m21 = (_scale - 1.0f) * _axis.x * _axis.y;
		m.m22 = 1.0f + (_scale - 1.0f) * powf(_axis.y, 2.0f);
		m.m23 = (_scale - 1.0f) * _axis.y * _axis.z;

		m.m31 = (_scale - 1.0f) * _axis.x * _axis.z;
		m.m32 = (_scale - 1.0f) * _axis.y * _axis.z;
		m.m33 = 1.0f + (_scale - 1.0f) * powf(_axis.z, 2.0f);

		return m;
	}

	inline mat4f euler_to_mat4(const float& _x, const float& _y, const float& _z)
	{
		mat4f m;

		float ch = cosf(_y);
		float cb = cosf(_z);
		float cp = cosf(_x);
		float sh = sinf(_y);
		float sb = sinf(_z);
		float sp = sinf(_x);

		m.m11 = ch * cb + sh * sp * sb;
		m.m12 = ch * sb + sh * sp * cb;
		m.m13 = sh * cp;

		m.m21 = sb * cp;
		m.m22 = cb * cp;
		m.m23 = -sp;

		m.m31 = -sh * cb + ch * sp * sb;
		m.m32 = sb * sh + ch * sp * cb;
		m.m33 = ch * cp;

		return m;
	}

	inline mat4f quat_to_mat4(const quat& _quat)
	{
		mat4f m;

		m.m11 = 1.0f - (2.0f * (_quat.v.y * _quat.v.y)) - (2.0f * (_quat.v.z * _quat.v.z));
		m.m12 = (2.0f * (_quat.v.x * _quat.v.y)) - (2.0f * (_quat.w * _quat.v.z));
		m.m13 = (2.0f * (_quat.v.x * _quat.v.z)) + (2.0f * (_quat.w * _quat.v.y));

		m.m21 = (2.0f * (_quat.v.x * _quat.v.y)) + (2.0f * (_quat.w * _quat.v.z));
		m.m22 = 1.0f - (2.0f * (_quat.v.x * _quat.v.z)) - (2.0f * (_quat.v.z * _quat.v.z));
		m.m23 = (2.0f * (_quat.v.y * _quat.v.z)) + (2.0f * (_quat.w * _quat.v.x));

		m.m31 = (2.0f * (_quat.v.x * _quat.v.y)) - (2.0f * (_quat.w * _quat.v.z));
		m.m32 = (2.0f * (_quat.v.y * _quat.v.z)) + (2.0f * (_quat.w * _quat.v.x));
		m.m33 = 1.0f - (2.0f * (_quat.v.x * _quat.v.x)) - (2.0f * (_quat.v.y * _quat.v.y));

		return m;
	}

	inline quat mat4_to_quat(const mat4f& _mat)
	{

	}

	inline quat euler_to_quat(const float& _x, const float& _y, const float& _z)
	{

	}

	inline vec3f mat4_to_euler(const mat4f& _mat)
	{
		vec3f euler;

		float sp = -_mat.m23;

		if (sp <= -1.0f)
		{
			euler.x = -1.570796f;
		}
		else if (sp >= 1.0f)
			euler.x = 1.570796f;
		else
			euler.x = asinf(sp);

		if (fabs(sp) > 0.9999f)
		{
			euler.z = 0.0f;
			euler.y = atan2(-_mat.m31, _mat.m11);
		}
		else
		{
			euler.y = atan2(_mat.m31, _mat.m11);
			euler.z = atan2(_mat.m21, _mat.m22);
		}

		return euler;
	}

	inline vec3f quat_to_euler(const quat& _quat)
	{

	}
}