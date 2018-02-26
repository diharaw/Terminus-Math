#pragma once

#include "simd_vec4.h"

namespace math
{
	namespace simd
	{
		struct mat4f
		{
			vec4f col[4];

			mat4f(const vec4f& _col0 = vec4f(), const vec4f& _col1 = vec4f(), const vec4f& _col2 = vec4f(), const vec4f& _col3 = vec4f())
			{
				col[0] = _col0;
				col[1] = _col1;
				col[2] = _col2;
				col[3] = _col3;
			}

			friend vec4f operator*(const mat4f& lhs, const vec4f& rhs)
			{
				vec4f v;

				v.x = lhs.col[0].x * rhs.x + lhs.col[0].y * rhs.y + lhs.col[0].z * rhs.z + lhs.col[0].w * rhs.w;
				v.y = lhs.col[1].x * rhs.x + lhs.col[1].y * rhs.y + lhs.col[1].z * rhs.z + lhs.col[1].w * rhs.w;
				v.z = lhs.col[2].x * rhs.x + lhs.col[2].y * rhs.y + lhs.col[2].z * rhs.z + lhs.col[2].w * rhs.w;
				v.w = lhs.col[3].x * rhs.x + lhs.col[3].y * rhs.y + lhs.col[3].z * rhs.z + lhs.col[3].w * rhs.w;

				return v;
			}

			friend mat4f operator*(const mat4f& lhs, const mat4f& rhs)
			{
				mat4f m;

				m.col[0] = lhs * rhs.col[0];
				m.col[1] = lhs * rhs.col[1];
				m.col[2] = lhs * rhs.col[2];
				m.col[3] = lhs * rhs.col[3];

				return m;
			}
		};
	}
}