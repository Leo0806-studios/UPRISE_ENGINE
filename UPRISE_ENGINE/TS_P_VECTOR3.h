#pragma once
#include "glm/vec3.hpp"
namespace DATATYPES {


	struct TS_P_Vector3 {
	public:float x;
	public:float y;
	public:float z;
	public:float pad;
	public :
		  TS_P_Vector3() : x(0), y(0), z(0) ,pad(0){}
		  TS_P_Vector3(float x, float y, float z) : x(x), y(y), z(z),pad(0) {}
		  TS_P_Vector3(const TS_P_Vector3& other) = default;
		  TS_P_Vector3& operator=(const TS_P_Vector3& other) = default;
		  operator __m128()const {
			  __m128 tmp = _mm_set_ps(x, y, z, 0);
			  return tmp;
		   }
		  operator glm::vec3()const {
			  auto a = glm::vec3(x, y, z);
				  return a;
		  }

		  float magnitude() {

			  __m128 val = _mm_set_ps(x, y, z, pad);
			  return  _mm_cvtss_f32(_mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(val, val), _mm_setzero_ps()), _mm_setzero_ps())));
		  }

		  float point(TS_P_Vector3 a) {
			  __m128 val = _mm_set_ps(x, y, z, pad);
			  __m128 val1 = _mm_set_ps(a.x, a.y, a.z, a.pad);

			  return _mm_cvtss_f32((_mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(val, val1), _mm_setzero_ps()), _mm_setzero_ps())));
		  }

		  TS_P_Vector3 operator /(const float b) {

			  TS_P_Vector3 _tmp;
			  __m128 val = _mm_set_ps(x, y, z, pad);

			  _mm_store_ps(&_tmp.x, _mm_div_ps(val, _mm_set_ps1(b)));
			  return _tmp;

		  }
		  TS_P_Vector3 operator/(const TS_P_Vector3 b) {
			  TS_P_Vector3 _tmp;
			  __m128 val = _mm_set_ps(x, y, z, pad);
			  __m128 val1 = _mm_set_ps(b.x, b.y, b.z, b.pad);

			  _mm_store_ps(&_tmp.x, _mm_div_ps(val, val1));
			  return _tmp;
		  }
		  TS_P_Vector3 operator *(const float b) {

			  TS_P_Vector3 _tmp;
			  __m128 val = _mm_set_ps(x, y, z, pad);

			  _mm_store_ps(&_tmp.x, _mm_mul_ps(val, _mm_set_ps1(b)));
			  return _tmp;

		  }
		  TS_P_Vector3 operator*(const TS_P_Vector3 b) {
			  TS_P_Vector3 _tmp;
			  __m128 val = _mm_set_ps(x, y, z, pad);
			  __m128 val1 = _mm_set_ps(b.x, b.y, b.z, b.pad);

			  _mm_store_ps(&_tmp.x, _mm_mul_ps(val, val1));
			  return _tmp;
		  }
		  TS_P_Vector3 operator -(const TS_P_Vector3 b) {
			  __m128 val = _mm_set_ps(x, y, z, pad);
			  __m128 val1 = _mm_set_ps(b.x, b.y, b.z, b.pad);
			  TS_P_Vector3 _tmp;
			  _mm_store_ps(&_tmp.x, _mm_sub_ps(val, val1));
			  return _tmp;

		  }




	};
}