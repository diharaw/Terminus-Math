#pragma once

#include <stdio.h>
#include <math.h>
#include <stdint.h>

namespace math
{

	template<typename T>
	struct vec2
	{
		union
		{
			struct
			{
				T x, y;
			};
			T data[2];
		};

		vec2() : x(0.0), y(0.0) {}
		vec2(T v) : x(v), y(v) {}
		vec2(T _x, T _y) : x(_x), y(_y) {}

		inline vec2 operator+(vec2& other)
		{
			return vec2(x + other.x, y + other.y);
		}

		inline vec2 operator-(vec2& other)
		{
			return vec2(x - other.x, y - other.y);
		}

		inline vec2 operator*(T& s)
		{
			return vec2(x * s, y * s);
		}

		inline vec2 operator/(T& s)
		{
			return vec2(x / s, y / s);
		}

		inline float length()
		{
			return sqrt(x*x + y * y);
		}

		inline float distance(vec2& v)
		{
			auto r = *this - v;
			return r.length();
		}

		inline float dot(vec2& b)
		{
			return x * b.x + y * b.y;
		}

		inline float dot(vec2& b) const
		{
			return x * b.x + y * b.y;
		}

		inline vec2 normalize()
		{
			auto l = length();
			return vec2(x / l, y / l);
		}

		inline vec2 direction(vec2& to)
		{
			auto v = to - *this;
			return v.normalize();
		}

		inline void print()
		{
			printf("[%f, %f]\n", x, y);
		}
	};

	using vec2f = vec2<float>;
	using vec2i = vec2<int32_t>;
	using vec2u = vec2<uint32_t>;

}