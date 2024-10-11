#pragma once
#ifndef _Mat4_
#define _Mat4_
#include "GLOBAL/GLINCLUDES.h"
#include "VECTOR/VECTOR4/VECTOR4.h"
#include "intrin.h"
#include <QUTERION/QUATERION.h>
import REF_WRAPPER;
import std;
class Mat4 {

public:
	__m128 row0, row1, row2, row3;
	__inline Mat4(float s) :row0(_mm_setr_ps(s, 0, 0, 0)), row1(_mm_setr_ps(0, s, 0, 0)), row2(_mm_setr_ps(0, 0, s, 0)), row3(_mm_setr_ps(0, 0, 0, s)) {}
	__forceinline Mat4(Quaternion quat) {
		__m128 One = _mm_load_ps(&quat.x());


		__m128 Two = _mm_mul_ps(_mm_shuffle_ps(One, One, _MM_SHUFFLE(0, 2, 1, 0)), _mm_shuffle_ps(One, One, _MM_SHUFFLE(2, 2, 1, 0))); //T qxx qyy qzz qxz
		__m128 Three = _mm_mul_ps(_mm_shuffle_ps(One, One, _MM_SHUFFLE(3, 3, 1, 0)), _mm_shuffle_ps(One, One, _MM_SHUFFLE(1, 0, 2, 1))); //T qxy qyz qwx qwy
		__m256 Four = _mm256_set_m128(Three, Two);
		Two.m128_f32[0] = quat.w() * quat.z();
		//Two = _mm_shuffle_ps(Two, Two, _MM_SHUFFLE(0, 3, 2, 1));
		__m128 Five = _mm_setr_ps(-1, 1, 1, 1);

		__m256 Six = _mm256_set_m128(Three, Two);
		Six = _mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 0));



		row0 = _mm_add_ps(
			_mm_setr_ps(1, 0, 0, 0),
			_mm_mul_ps(
				_mm_add_ps(
					_mm256_extractf128_ps(_mm256_shuffle_ps(Six, Six, _MM_SHUFFLE(0, 2, 3, 0)), 0),
					_mm_mul_ps(
						_mm256_extractf128_ps(_mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(1, 7, 6, 0, 0, 0, 0, 0)), 0),
						//_mm_shuffle_ps(Five, Five,_MM_SHUFFLE(3,2,0,1))
						_mm_setr_ps(1, -1, 1, 1)
					)
				),
				_mm_setr_ps(-2, 2, 2, 0)
			)
		);

		row1 = _mm_add_ps(
			_mm_setr_ps(0, 1, 0, 0),
			_mm_mul_ps(
				_mm_add_ps(
					_mm256_extractf128_ps(_mm256_permutevar8x32_ps(Four, _mm256_setr_epi32(4, 0, 5, 0, 0, 0, 0, 0)), 0),
					_mm_mul_ps(
						_mm256_extractf128_ps(_mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(7, 1, 5, 0, 0, 0, 0, 0)), 0),
						//_mm_shuffle_ps(Five, Five, _MM_SHUFFLE(3, 0, 2, 1))

						_mm_setr_ps(1, 1, -1, 1)
					)
				),
				_mm_setr_ps(2, -2, 2, 0)
			)
		);


		//
		row2 = _mm_add_ps(
			_mm_setr_ps(0, 0, 1, 0),
			_mm_mul_ps(
				_mm_add_ps(
					_mm256_extractf128_ps(_mm256_permutevar8x32_ps(Four, _mm256_setr_epi32(3, 5, 0, 0, 0, 0, 0, 0)), 0),
					_mm_mul_ps(
						_mm256_extractf128_ps(_mm256_permutevar8x32_ps(Six, _mm256_setr_epi32(6, 5, 0, 0, 0, 0, 0, 0)), 0),
						//_mm_shuffle_ps(Five, Five, _MM_SHUFFLE(0, 3, 2, 1))

						_mm_setr_ps(-1, 1, 1, 1)
					)
				),
				_mm_setr_ps(2, 2, -2, 0)
			)
		);


		row3 = _mm_setr_ps(0, 0, 0, 1);
	}

	//__inline operator glm::mat4() { return glm::mat4(TSPVector4(row0), TSPVector4(row1), TSPVector4(row2), TSPVector4(row3)); }
	__forceinline static  Mat4 Look_At(Vector3 eye, Vector3 center, Vector3 up) {
		//TrPr(ctx,__func__)
		center = (center - eye).Normalized();
		center.pad() = -(center.Point(eye));
		up = (up ^ center).Normalized();
		up.pad() = -(up.Point(eye));
		Vector3 u((center ^ up));
		u.pad() = -(u.Point(eye));
		Mat4 result(1);
		result[0] = _mm_load_ps(&up.x());
		result[1] = _mm_load_ps(&u.x());
		result[2] = _mm_load_ps(&center.x());

		//TrPrE(ctx)
		return result;
	}
	__forceinline static  glm::mat4 Look_At_GLM(Vector3 eye, Vector3 center, Vector3 up) {
		//TrPr(ctx,__func__)
		center = (center - eye).Normalized();
		center.pad() = -(center.Point(eye));
		up = (up ^ center).Normalized();
		up.pad() = -(up.Point(eye));
		Vector3 u((center ^ up));
		u.pad() = -(u.Point(eye));
		__m256i suffle = _mm256_setr_epi32(0, 1, 4, 5, 2, 3, 6, 7);
		__m256 mlti = _mm256_set_ps(1, -1, 1, -1, 1, -1, 1, -1);

		__m128 row3(_mm_setr_ps(0, 0, 0, 1));

		__m256 One = _mm256_set_m128(_mm_unpacklo_ps(center, row3), _mm_unpacklo_ps(up, u));

		__m256 Two = _mm256_set_m128(_mm_unpackhi_ps(center, row3), _mm_unpackhi_ps(up, u));
		One = _mm256_mul_ps(One, mlti);
		Two = _mm256_mul_ps(Two, mlti);
		One = _mm256_permutevar8x32_ps(One, suffle);
		Two = _mm256_permutevar8x32_ps(Two, suffle);
		glm::mat4 ret{};
		ret;
		_mm256_store_ps(&ret[0].x, One);
		_mm256_store_ps(&ret[2].x, Two);

		//alignas(32) glm::vec4 col0[2];
		//alignas(32) glm::vec4 col1[2];
		//_mm256_store_ps(&col0[0].x, One);
		//_mm256_store_ps(&col1[0].x, Two);

		return ret;//glm::mat4(col0[0], col0[1], col1[0], col1[1]);;
	}



	__inline static Mat4 Perspective(float fov, float aspect, float zNear, float zFar) {
		TrPr(ctx, __func__)
			Mat4 result(0);

		float zMz = zFar - zNear;

		float tanhalffov = tan(((fov * 0.01745329251994329576923690768489)) / 2);
		__m128 tst = _mm_setr_ps(tanhalffov, zMz, 1, zMz);


		__m128 bottom3 = _mm_mul_ps(_mm_setr_ps(1, -1, -1, -1), (_mm_div_ps(_mm_setr_ps(1, zFar + zNear, 1, 2 * zFar * zNear), tst)));
		result(0, 0) = 1 / (aspect * tanhalffov);
		result(1, 1) = bottom3.m128_f32[0];
		result(2, 2) = bottom3.m128_f32[1];
		result(3, 2) = bottom3.m128_f32[2];
		result(2, 3) = bottom3.m128_f32[3];
		TrPrE(ctx)
			return result;

	}
	__inline glm::mat4 ToMat4glm() {
		_MM_TRANSPOSE4_PS(row0, row1, row2, row3);
		

		return glm::mat4(Vector4(row0).operator glm::vec<4, float, glm::packed_highp>(),
			Vector4(row1).operator glm::vec<4, float, glm::packed_highp>(),
			Vector4(row1).operator glm::vec<4, float, glm::packed_highp>(),
			Vector4(row1).operator glm::vec<4, float, glm::packed_highp>());
	}
	__forceinline operator glm::mat4() {
		TrPr(ctx, __func__)

			__m128 tmp0 = _mm_unpacklo_ps(row0, row1); // [r0.x, r1.x, r0.y, r1.y]
		__m128 tmp1 = _mm_unpackhi_ps(row0, row1); // [r0.z, r1.z, r0.w, r1.w]
		__m128 tmp2 = _mm_unpacklo_ps(row2, row3); // [r2.x, r3.x, r2.y, r3.y]
		__m128 tmp3 = _mm_unpackhi_ps(row2, row3); // [r2.z, r3.z, r2.w, r3.w]

		// Step 2: Unpack and interleave to get the final column vectors
		glm::vec4 col0;
		glm::vec4 col1;
		glm::vec4 col2;
		glm::vec4 col3;
		_mm_store_ps(&col0.x, _mm_movelh_ps(tmp0, tmp2)); // [r0.x, r1.x	 r2.x, r3.x]
		_mm_store_ps(&col1.x, _mm_movehl_ps(tmp2, tmp0)); // [r0.y, r1.y, r2.y, r3.y]
		_mm_store_ps(&col2.x, _mm_movelh_ps(tmp1, tmp3)); // [r0.z, r1.z, r2.z, r3.z]
		_mm_store_ps(&col3.x, _mm_movehl_ps(tmp3, tmp1)); // [r0.w, r1.w, r2.w, r3.w]
		TrPrE(ctx)

			return glm::mat4(col0, col1, col2, col3);
	}
	__inline __m128& operator[](int i) {

		if (i > 3)
		{
			//Log << "OUT Of RANGE!\n" << "trying to accses memory at: " << &(((__m128*)this)[i]) << "wich is outside the bounds of the mat4" << "\n";
			int i = *(int*)(nullptr); //throw error

		}
		return (((__m128*)this)[i]);
	}
	__inline float& operator()(int r, int c) {
		return (this->operator[](r)).m128_f32[c];

	}
};
#endif // !_Mat4_
