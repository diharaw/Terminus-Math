#pragma once

#include <stdio.h>
#include <math.h>
#include <stdint.h>

template<typename T>
struct vec4
{
	union
	{
		struct
		{
			T x, y, z, w;
		};
		T data[4];
	};

	vec4() : x(0.0), y(0.0), z(0.0), w(0.0) {}
	vec4(T v) : x(v), y(v), z(v), w(v) {}
	vec4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}

	inline vec4 operator+(vec4& other)
	{
		return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	inline vec4 operator-(vec4& other)
	{
		return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	inline vec4 operator*(T& s)
	{
		return vec4(x * s, y * s, z * s, w * s);
	}

	inline vec4 operator/(T& s)
	{
		return vec4(x / s, y / s, z / s, w / s);
	}

	inline float length()
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	inline float dot(vec4& b)
	{
		return x * b.x + y * b.y + z * b.z + w * b.w;
	}

	inline float dot(vec4& b) const
	{
		return x * b.x + y * b.y + z * b.z + w * b.w;
	}

	inline vec4 normalize()
	{
		auto l = length();
		return vec4(x / l, y / l, z / l, w / l);
	}

	inline void print()
	{
		printf("[%f, %f, %f, %f]\n", x, y, z, w);
	}
};

using vec4f = vec4<float>;
using vec4i = vec4<int32_t>;
using vec4u = vec4<uint32_t>;