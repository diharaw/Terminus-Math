#pragma once

#include <stdio.h>
#include <math.h>
#include <stdint.h>

template<typename T>
struct vec3
{
	union
	{
		struct
		{
			T x, y, z;
		};
		T data[3];
	};

	vec3() : x(0.0), y(0.0), z(0.0) {}
	vec3(T v) : x(v), y(v), z(v) {}
	vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

	inline vec3 operator+(vec3& other)
	{
		return vec3(x + other.x, y + other.y, z + other.z);
	}

	inline vec3 operator-(vec3& other)
	{
		return vec3(x - other.x, y - other.y, z - other.z);
	}

	inline vec3 operator*(T& s)
	{
		return vec3(x * s, y * s, z * s);
	}

	inline vec3 operator/(T& s)
	{
		return vec3(x / s, y / s, z / s);
	}

	inline float length()
	{
		return sqrt(x*x + y * y + z * z);
	}

	inline float distance(vec3& v)
	{
		auto r = *this - v;
		return r.length();
	}

	inline float dot(vec3& b)
	{
		return x * b.x + y * b.y + z * b.z;
	}

	inline float dot(vec3& b) const
	{
		return x * b.x + y * b.y + z * b.z;
	}

	inline vec3 cross(const vec3& b)
	{
		return vec3(y * b.z - z * b.y,
					z * b.x - x * b.z,
					x * b.y - y * b.x);
	}

	inline vec3 normalize()
	{
		auto l = length();
		return vec3(x / l, y / l, z / l);
	}

	inline vec3 direction(vec3& to)
	{
		auto v = to - *this;
		return v.normalize();
	}

	inline void print()
	{
		printf("[%f, %f, %f]\n", x, y, z);
	}
};

using vec3f = vec3<float>;
using vec3i = vec3<int32_t>;
using vec3u = vec3<uint32_t>;