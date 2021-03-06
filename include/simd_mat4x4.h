#pragma once

#include "simd_vec4x4.h"

namespace math
{
	namespace simd
	{
		struct mat4fx4
		{
			vec4fx4 col[4];

			inline mat4fx4(const vec4fx4& _col0 = vec4fx4(), const vec4fx4& _col1 = vec4fx4(), const vec4fx4& _col2 = vec4fx4(), const vec4fx4& _col3 = vec4fx4())
			{
				col[0] = _col0;
				col[1] = _col1;
				col[2] = _col2;
				col[3] = _col3;
			}
            
            inline mat4fx4(const mat4fx4& rhs)
            {
                col[0] = rhs.col[0];
                col[1] = rhs.col[1];
                col[2] = rhs.col[2];
                col[3] = rhs.col[3];
            }
            
            inline mat4fx4& operator=(const mat4fx4& rhs)
            {
                col[0] = rhs.col[0];
                col[1] = rhs.col[1];
                col[2] = rhs.col[2];
                col[3] = rhs.col[3];
                return *this;
            }

			inline friend vec4fx4 operator*(const mat4fx4& lhs, const vec4fx4& rhs)
			{
				vec4fx4 v;

				v.x = lhs.col[0].x * rhs.x + lhs.col[1].x * rhs.y + lhs.col[2].x * rhs.z + lhs.col[3].x * rhs.w;
				v.y = lhs.col[0].y * rhs.x + lhs.col[1].y * rhs.y + lhs.col[2].y * rhs.z + lhs.col[3].y * rhs.w;
				v.z = lhs.col[0].z * rhs.x + lhs.col[1].z * rhs.y + lhs.col[2].z * rhs.z + lhs.col[3].z * rhs.w;
				v.w = lhs.col[0].w * rhs.x + lhs.col[1].w * rhs.y + lhs.col[2].w * rhs.z + lhs.col[3].w * rhs.w;

				return v;
			}

			inline friend mat4fx4 operator*(const mat4fx4& lhs, const mat4fx4& rhs)
			{
				mat4fx4 m;

				m.col[0] = lhs * rhs.col[0];
				m.col[1] = lhs * rhs.col[1];
				m.col[2] = lhs * rhs.col[2];
				m.col[3] = lhs * rhs.col[3];

				return m;
			}
		};
	}
}
