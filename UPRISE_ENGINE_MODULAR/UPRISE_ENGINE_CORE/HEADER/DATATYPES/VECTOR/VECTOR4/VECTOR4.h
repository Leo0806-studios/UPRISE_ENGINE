#pragma once
#ifndef _T_S_P_VECTOR4
#define _T_S_P_VECTOR4
#include "GLOBAL/GLINCLUDES.h"
#include <intrin.h>
import std;


 class Vector4 {
	 __m128 Data;

	public:
#pragma region Constructor
		__inline UPRISE_CORE_API Vector4(__m128 in):Data(in) { }
		__inline  UPRISE_CORE_API Vector4() = default;
		__inline UPRISE_CORE_API Vector4(float x, float y, float z, float w) :Data(_mm_setr_ps(x, y, z, w)) {};
#pragma endregion

#pragma region getter
		__inline UPRISE_CORE_API float& x() const {
			return ((float*)&Data)[0];
		}
		__inline UPRISE_CORE_API float& y() const {
			return ((float*)&Data)[1];

		}
		__inline UPRISE_CORE_API float& z() const {
			return ((float*)&Data)[2];

		}
		__inline UPRISE_CORE_API float& w() const {
			return ((float*)&Data)[3];

		}
#pragma endregion
#pragma region setter
		//set vals
		__inline UPRISE_CORE_API float& x(const float& x) {
			return (((float*)&Data)[0] = x);

		}
		__inline UPRISE_CORE_API float& y(const float& y) {
			return (((float*)&Data)[1] = y);

		}
		__inline UPRISE_CORE_API float& z(const float& z) {
			return (((float*)&Data)[2] = z);


		}
		__inline UPRISE_CORE_API float& w(const float& pad) {
			return (((float*)this)[3] = pad);

		}
#pragma endregion

		__inline UPRISE_CORE_API operator glm::vec4() { return glm::vec4(x(), y(), z(), w()); }
	};

#endif // !_T_S_P_VECTOR4