#pragma once

#include "vec3.h"

template<typename T>
struct mat3
{
	union
	{
		struct
		{
			// m[row][column]
			T m11, m21, m31, m12, m22, m32, m13, m23, m33;
		};
		float elem[9];
	};

	mat3()
	{
		for (int i = 0; i < 9; i++)
			elem[i] = 0;

		m11 = 1;
		m22 = 1;
		m33 = 1;
	}

	mat3(float _m11, float _m12, float _m13,
		float _m21, float _m22, float _m23,
		float _m31, float _m32, float _m33)
	{
		m11 = _m11;
		m12 = _m12;
		m13 = _m13;

		m21 = _m21;
		m22 = _m22;
		m23 = _m23;

		m31 = _m31;
		m32 = _m32;
		m33 = _m33;
	}

	mat3(vec3<T> _c1, vec3<T> _c2, vec3<T> _c3)
	{
		m11 = _c1.x;
		m21 = _c1.y;
		m31 = _c1.z;

		m12 = _c2.x;
		m22 = _c2.y;
		m32 = _c2.z;

		m13 = _c3.x;
		m23 = _c3.y;
		m33 = _c3.z;
	}

	mat3 transpose()
	{
		mat3 r;

		r.m11 = m11;
		r.m21 = m12;
		r.m31 = m13;

		r.m12 = m21;
		r.m22 = m22;
		r.m32 = m23;

		r.m13 = m31;
		r.m23 = m32;
		r.m33 = m33;

		return r;
	}

	void print()
	{
		printf("[%f, %f, %f]\n", m11, m12, m13);
		printf("[%f, %f, %f]\n", m21, m22, m23);
		printf("[%f, %f, %f]\n", m31, m32, m33);
	}

	inline mat3 operator*(T s)
	{
		mat3 r;

		for (int i = 0; i < 9; i++)
			r.elem[i] = elem[i] * s;

		return r;
	}

	inline mat3 operator*(T& s)
	{
		mat3 r;

		for (int i = 0; i < 9; i++)
			r.elem[i] *= s;

		return r;
	}
};

using mat3f = mat3<float>;