#pragma once

#include "simd_float4.h"

namespace math
{
	namespace simd
	{
		struct vec4f
		{
			float4 x;
			float4 y;
			float4 z;
			float4 w;

			vec4f(const float4& _x = float4(), const float4& _y = float4(), const float4& _z = float4(), const float4& _w = float4()) : x(_x), y(_y), z(_z), w(_w) { }
			
			friend vec4f operator+(const vec4f& lhs, const vec4f& rhs)
			{
				return vec4f(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
			}

			friend vec4f operator-(const vec4f& lhs, const vec4f& rhs)
			{
				return vec4f(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
			}

			inline float4 dot(const vec4f& rhs)
			{
				return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
			}

			inline vec4f cross(const vec4f& rhs)
			{
				return vec4f(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
			}
		};
	}
}