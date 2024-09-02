#ifndef _TS_P_VECTOR3_

#define _TS_P_VECTOR3_
#include "GLINCLUDES.h"
#include "pch.h"
#include "MODULE_IMPORTS.h"
namespace DATATYPES {



	struct TSPVector3 {
	public:  float x;
	public:  float y;
	public: float z;
	public: float pad;
	public:
		TSPVector3();
		__forceinline  TSPVector3(float x, float y, float z) : x(x), y(y), z(z), pad(0) {}
		__forceinline TSPVector3(const TSPVector3& other) = default;
		 TSPVector3(glm::vec3 vec);
		 __forceinline TSPVector3(__m128 vec) {
			_mm_store_ps(&this->x, vec);
		}

		TSPVector3(aiVector3D vec);
		TSPVector3& operator=(const TSPVector3& other) = default;
		TSPVector3& operator=(const aiVector3D& other);;
		operator __m128()const;
		//operator aiVector3D() const;
		operator glm::vec3()const;

		__forceinline float magnitude() {

			//TrPr(ctx, __func__)


				// TrPr(profiletest, "new way");
				__m128 val2 = _mm_load_ps(&this->x);
			val2 = _mm_mul_ps(val2, val2);
			__m128 shuf = _mm_movehdup_ps(val2);        // broadcast elements 3,1 to 2,0
			val2 = _mm_add_ps(val2, shuf);
			shuf = _mm_movehl_ps(shuf, val2); // high half -> low half
			val2 = _mm_add_ss(val2, shuf);
			val2 = _mm_sqrt_ps(val2);
			//TrPrE(ctx)
				// TrPrE(profiletest);
				return _mm_cvtss_f32(val2);
		}
		__inline __m128 magnitudeV() {
			//TrPr(ctx, __func__)

				// TrPr(profiletest, "new way");
				__m128 val2 = _mm_load_ps(&this->x);
			val2 = _mm_mul_ps(val2, val2);
			__m128 shuf = _mm_movehdup_ps(val2);        // broadcast elements 3,1 to 2,0
			val2 = _mm_add_ps(val2, shuf);
			shuf = _mm_movehl_ps(shuf, val2); // high half -> low half
			val2 = _mm_add_ss(val2, shuf);
			val2 = _mm_sqrt_ps(val2);
			//TrPrE(ctx)
				// TrPrE(profiletest);
				return val2;
		}
		__forceinline TSPVector3 Normalized() {
			//TrPr(ctx, __func__)

				float mag = this->magnitude();
			//__m128 val = _mm_set_ps(x, y, z, pad);
			TSPVector3 tmp;
			_mm_store_ps(&tmp.x,_mm_div_ps(_mm_load_ps(&this->x),_mm_load_ps1(&mag)));
			//TrPrE(ctx)

				return tmp;
		}
		__forceinline TSPVector3 operator^(TSPVector3 b){
			__m128 val = _mm_load_ps(&this->x);
			__m128 val2 = _mm_load_ps(&b.x);
			__m128 a_yzx = _mm_shuffle_ps(val, val, _MM_SHUFFLE(3, 0, 2, 1));
			__m128 b_yzx = _mm_shuffle_ps(val2, val2, _MM_SHUFFLE(3, 0, 2, 1));
			//resULT = _mm_fnmadd_ps(, , _mm_mul_ps(_mm_shuffle_ps(val2, val2, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(val, val, _MM_SHUFFLE(3, 1, 0, 2))));
			//resULT = 
			_mm_store_ps(&b.x, _mm_fnmadd_ps(_mm_shuffle_ps(val, val, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(val2, val2, _MM_SHUFFLE(3, 0, 2, 1)), _mm_mul_ps(_mm_shuffle_ps(val, val, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(val2, val2, _MM_SHUFFLE(3, 1, 0, 2)))));
			return b;
		}

		__inline float point(TSPVector3 a) {
			//TrPr(ctx, __func__)
				__m128 val = _mm_load_ps(&this->x);
			__m128 val1 = _mm_load_ps(&a.x);
			val = _mm_mul_ps(val, val1);
			val1 = _mm_movehdup_ps(val);        // broadcast elements 3,1 to 2,0
			val = _mm_add_ps(val, val1);
			val1 = _mm_movehl_ps(val1, val); // high half -> low half
			val = _mm_add_ss(val, val1);

			//TrPrE(ctx)
				return _mm_cvtss_f32(val);
		}
		TSPVector3 operator/(const __m128 b) {}
		TSPVector3 operator*(const __m128 b) {}
		TSPVector3 operator -(const __m128 b) {}
		__inline TSPVector3 operator+(__m128 b) {
		}
		TSPVector3 operator /(const float b);
		TSPVector3 operator/(const TSPVector3 b);
		TSPVector3 operator *(const float b);
		__inline TSPVector3 operator*(const TSPVector3 b) {
			//TrPr(ctx, __func__)

				TSPVector3 _tmp;
			__m128 val = _mm_setr_ps(x, y, z, pad);
			__m128 val1 = _mm_setr_ps(b.x, b.y, b.z, b.pad);

			_mm_store_ps(&_tmp.x, _mm_mul_ps(val, val1));

			//TrPrE(ctx)
				return _tmp;
		}
		__forceinline TSPVector3 operator -( TSPVector3 b) {
			//TrPr(ctx, __func__)

				_mm_store_ps(&b.x, _mm_sub_ps(_mm_load_ps(&this->x), _mm_load_ps(&b.x)));

			//TrPrE(ctx)

				return b;

		}
		__forceinline TSPVector3 operator+(TSPVector3 b) {
			//TrPr(ctx, __func__)

				//TSPVector3 tmp;
			//__m128 this3 = _mm_setr_ps(x, y, z, pad);
			//__m128 be = _mm_setr_ps(b.x, b.y, b.z, b.pad);
			//_mm_store_ps(&b.x, _mm_add_ps(this3, be));
				_mm_store_ps(&b.x, _mm_add_ps(_mm_load_ps(&this->x), _mm_load_ps(&b.x)));

			//TrPrE(ctx)
				return b;
		}





	};


		struct FASTVec3 {
	public:
		//FASTVec3(FASTVec3&& other) = default;
		FASTVec3() = default;
		FASTVec3(__m128 other) :vals(other) {}
		FASTVec3(__m128& other) :vals(other) {}
		FASTVec3(TSPVector3 other) :vals(_mm_load_ps(&other.x)) {}

		__m128 vals;
		float& x() {
			return(((float*)this)[0]);
		}
		float& y() {
			return(((float*)this)[1]);
		}
		float& z() {
			return(((float*)this)[2]);
		}
		float& pad() {
			return(((float*)this)[3]);
		}
		float& operator[](int i) {
			return(((float*)this)[i]);
		}
		

		__forceinline float magnitude() {

			//TrPr(ctx, __func__)


				// TrPr(profiletest, "new way");
			__m128 val2 = vals;
			val2 = _mm_mul_ps(val2, val2);
			__m128 shuf = _mm_movehdup_ps(val2);        // broadcast elements 3,1 to 2,0
			val2 = _mm_add_ps(val2, shuf);
			shuf = _mm_movehl_ps(shuf, val2); // high half -> low half
			val2 = _mm_add_ss(val2, shuf);
			val2 = _mm_sqrt_ps(val2);
			//TrPrE(ctx)
				// TrPrE(profiletest);
			return _mm_cvtss_f32(val2);
		}
		__forceinline FASTVec3 Normalized() {
			//TrPr(ctx, __func__)

			float mag = this->magnitude();
			//__m128 val = _mm_set_ps(x, y, z, pad);
			FASTVec3 tmp;
			_mm_store_ps(&tmp.x(), _mm_div_ps(vals, _mm_load_ps1(&mag)));
			//TrPrE(ctx)

			return tmp;
		}
		__forceinline FASTVec3 operator^(FASTVec3 b) {
		
			//__m128 a_yzx = _mm_shuffle_ps(vals, vals, _MM_SHUFFLE(3, 0, 2, 1));
			//__m128 b_yzx = _mm_shuffle_ps(b.vals, b.vals, _MM_SHUFFLE(3, 0, 2, 1));
			//resULT = _mm_fnmadd_ps(, , _mm_mul_ps(_mm_shuffle_ps(val2, val2, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(val, val, _MM_SHUFFLE(3, 1, 0, 2))));
			//resULT = 
			return _mm_fnmadd_ps(_mm_shuffle_ps(vals, vals, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(b.vals, b.vals, _MM_SHUFFLE(3, 0, 2, 1)), _mm_mul_ps(_mm_shuffle_ps(vals, vals, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(b.vals, b.vals, _MM_SHUFFLE(3, 1, 0, 2))));
			// b;
		}

		__inline float point(FASTVec3 a) {
			//TrPr(ctx, __func__)
			__m128 val = vals;
				
			val = _mm_mul_ps(val, a.vals);
			a.vals = _mm_movehdup_ps(val);        // broadcast elements 3,1 to 2,0
			val = _mm_add_ps(val, a.vals);
			a.vals = _mm_movehl_ps(a.vals, val); // high half -> low half
			val = _mm_add_ss(val, a.vals);

			//TrPrE(ctx)
			return _mm_cvtss_f32(val);
		}
		__inline FASTVec3 operator*(const FASTVec3 b) {
			//TrPr(ctx, __func__)



			//TrPrE(ctx)
			return _mm_mul_ps(this->vals, b.vals);
		}
		__forceinline FASTVec3 operator -(FASTVec3 b) const{
			//TrPr(ctx, __func__)

			

			//TrPrE(ctx)

			return _mm_sub_ps(vals, b.vals);

		}
		__forceinline FASTVec3 operator+(FASTVec3 b) {
			//TrPr(ctx, __func__)

				//TSPVector3 tmp;
			//__m128 this3 = _mm_setr_ps(x, y, z, pad);
			//__m128 be = _mm_setr_ps(b.x, b.y, b.z, b.pad);
			//_mm_store_ps(&b.x, _mm_add_ps(this3, be));

			//TrPrE(ctx)
			return _mm_add_ps(vals, b.vals);
		}
	};
}


#endif // !_TS_P_VECTOR3_
