#pragma once

#include "vec4.h"

template<typename T>
struct mat4
{
	union
	{
		struct
		{
			// m[row][column]
			T m11, m21, m31, m41, m12, m22, m32, m42, m13, m23, m33, m43, m14, m24, m34, m44;
		};
		float elem[16];
	};

	mat4()
	{
		for (int i = 0; i < 16; i++)
			elem[i] = 0;

		m11 = 1;
		m22 = 1;
		m33 = 1;
		m44 = 1;
	}

	mat4(float _m11, float _m12, float _m13, float _m14,
		float _m21, float _m22, float _m23, float _m24,
		float _m31, float _m32, float _m33, float _m34,
		float _m41, float _m42, float _m43, float _m44)
	{
		m11 = _m11;
		m12 = _m12;
		m13 = _m13;
		m14 = _m14;

		m21 = _m21;
		m22 = _m22;
		m23 = _m23;
		m24 = _m24;

		m31 = _m31;
		m32 = _m32;
		m33 = _m33;
		m34 = _m34;

		m41 = _m41;
		m42 = _m42;
		m43 = _m43;
		m44 = _m44;
	}

	mat4(vec4<T> _c1, vec4<T> _c2, vec4<T> _c3, vec4<T> _c4)
	{
		m11 = _c1.x;
		m21 = _c1.y;
		m31 = _c1.z;
		m41 = _c1.w;

		m12 = _c2.x;
		m22 = _c2.y;
		m32 = _c2.z;
		m42 = _c2.w;

		m13 = _c3.x;
		m23 = _c3.y;
		m33 = _c3.z;
		m43 = _c3.w;

		m14 = _c4.x;
		m24 = _c4.y;
		m34 = _c4.z;
		m44 = _c4.w;
	}

	mat4 transpose()
	{
		mat4 r;

		r.m11 = m11;
		r.m21 = m12;
		r.m31 = m13;
		r.m41 = m14;

		r.m12 = m21;
		r.m22 = m22;
		r.m32 = m23;
		r.m42 = m24;

		r.m13 = m31;
		r.m23 = m32;
		r.m33 = m33;
		r.m43 = m34;

		r.m14 = m41;
		r.m24 = m42;
		r.m34 = m43;
		r.m44 = m44;

		return r;
	}

	void print()
	{
		printf("[%f, %f, %f, %f]\n", m11, m12, m13, m14);
		printf("[%f, %f, %f, %f]\n", m21, m22, m23, m24);
		printf("[%f, %f, %f, %f]\n", m31, m32, m33, m34);
		printf("[%f, %f, %f, %f]\n", m41, m42, m43, m44);
	}

	inline mat4 operator*(T s)
	{
		mat4 r;

		for (int i = 0; i < 16; i++)
			r.elem[i] = elem[i] * s;

		return r;
	}

	inline mat4 operator*(T& s)
	{
		mat4 r;

		for (int i = 0; i < 16; i++)
			r.elem[i] *= s;

		return r;
	}
};

using mat4f = mat4<float>;