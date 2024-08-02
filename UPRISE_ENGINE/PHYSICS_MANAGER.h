#pragma once
#ifndef _PHYSICS_MANAGER_
#define _PHYSICS_MANAGER_
#include "pch.h"
#include "PHYSICS_OBJECT.h"
class _PhysicsObject;
namespace PHYSICS {
	class Physics;
	class Physics_Object;
	class Physics {
	public :
		static std::vector < std::shared_ptr<PHYSICS::Physics>> physicsobjects;

		virtual void UpdatePhysics() = 0;
		static void UpdateAllPhysics();
		bool OverlapOnAxis(__m128* a, __m128* b, __m128 axis)
		{
			float mx = (std::numeric_limits<float>::max)();
			float mi = -(std::numeric_limits<float>::max)();
			__m128 MINMAX = _mm_set_ps(mi, mx, mi, mx);
			//float min = 0;
			//min.MaxValue;
			//float max = 0;
			//max.MinValue;
			//float minOther = 0;
			//minOther.MaxValue;
			//float maxOther = 0;
			//maxOther.MinValue;
			float proj[8];
			__m128 corner[8];
			__m128 PROJ[4];

			{
				//__m128 AXIS = axis;

				corner[0] = _mm_mul_ps(axis, a[0]);
				corner[1] = _mm_mul_ps(axis, a[1]);
				corner[2] = _mm_mul_ps(axis, a[2]);
				corner[3] = _mm_mul_ps(axis, a[3]);
				corner[4] = _mm_mul_ps(axis, a[4]);
				corner[5] = _mm_mul_ps(axis, a[5]);
				corner[6] = _mm_mul_ps(axis, a[6]);
				corner[7] = _mm_mul_ps(axis, a[7]);
				//__m128 PROJ[4];
				PROJ[0] = _mm_hadd_ps(_mm_hadd_ps(corner[0], corner[1]), _mm_setzero_ps());
				PROJ[1] = _mm_hadd_ps(_mm_hadd_ps(corner[2], corner[3]), _mm_setzero_ps());
				PROJ[2] = _mm_hadd_ps(_mm_hadd_ps(corner[4], corner[5]), _mm_setzero_ps());
				PROJ[3] = _mm_hadd_ps(_mm_hadd_ps(corner[6], corner[7]), _mm_setzero_ps());
				//float proj[8]{
				//proj[0] = PROJ[0].m128_f32[1],
				//	proj[1] = PROJ[0].m128_f32[2],
				//	proj[2] = PROJ[1].m128_f32[1],
				//	proj[3] = PROJ[1].m128_f32[2],
				//	proj[4] = PROJ[2].m128_f32[1],
				//	proj[5] = PROJ[2].m128_f32[2],
				//	proj[6] = PROJ[3].m128_f32[1],
				//	proj[7] = PROJ[3].m128_f32[2],
				//	};


				__m128 One = _mm_min_ps(PROJ[0], PROJ[1]);
				__m128 Two = _mm_min_ps(PROJ[2], PROJ[3]);
				__m128 Tree = _mm_min_ps(Two, One);
				__m128 Four = _mm_unpacklo_ps(Tree, _mm_setzero_ps());
				__m128 Five = _mm_unpackhi_ps(Tree, _mm_setzero_ps());
				__m128 Six = _mm_min_ps(Four, Five);
				MINMAX.m128_f32[0] = Six.m128_f32[1];
				if (Six.m128_f32[0] < Six.m128_f32[1]) {
					MINMAX.m128_f32[0] = Six.m128_f32[0];
				}


				__m128 Seven = _mm_max_ps(PROJ[0], PROJ[1]);
				__m128 Eight = _mm_max_ps(PROJ[2], PROJ[3]);
				__m128 Nine = _mm_max_ps(Eight, Seven);
				__m128 ten = _mm_unpacklo_ps(Nine, _mm_setzero_ps());
				__m128 eleven = _mm_unpackhi_ps(Nine, _mm_setzero_ps());
				__m128 twelve = _mm_max_ps(eleven, ten);
				MINMAX.m128_f32[1] = twelve.m128_f32[1];
				if (twelve.m128_f32[1] > twelve.m128_f32[1]) {
					MINMAX.m128_f32[1] = twelve.m128_f32[0];
				}


			}
			{
				//__m128 AXIS = axis;
				//__m128 corner[8];
				corner[0] = _mm_mul_ps(axis, b[0]);
				corner[1] = _mm_mul_ps(axis, b[1]);
				corner[2] = _mm_mul_ps(axis, b[2]);
				corner[3] = _mm_mul_ps(axis, b[3]);
				corner[4] = _mm_mul_ps(axis, b[4]);
				corner[5] = _mm_mul_ps(axis, b[5]);
				corner[6] = _mm_mul_ps(axis, b[6]);
				corner[7] = _mm_mul_ps(axis, b[7]);
				//__m128 PROJ[4];
				PROJ[0] = _mm_hadd_ps(_mm_hadd_ps(corner[0], corner[1]), _mm_setzero_ps());
				PROJ[1] = _mm_hadd_ps(_mm_hadd_ps(corner[2], corner[3]), _mm_setzero_ps());
				PROJ[2] = _mm_hadd_ps(_mm_hadd_ps(corner[4], corner[5]), _mm_setzero_ps());
				PROJ[3] = _mm_hadd_ps(_mm_hadd_ps(corner[6], corner[7]), _mm_setzero_ps());
				////float proj[8]{
				//proj[0] = PROJ[0].m128_f32[1],
				//	proj[1] = PROJ[0].m128_f32[2],
				//	proj[2] = PROJ[1].m128_f32[1],
				//	proj[3] = PROJ[1].m128_f32[2],
				//	proj[4] = PROJ[2].m128_f32[1],
				//	proj[5] = PROJ[2].m128_f32[2],
				//	proj[6] = PROJ[3].m128_f32[1],
				//	proj[7] = PROJ[3].m128_f32[2],
				//	//};


				__m128 One = _mm_min_ps(PROJ[0], PROJ[1]);
				__m128 Two = _mm_min_ps(PROJ[2], PROJ[3]);
				__m128 Tree = _mm_min_ps(Two, One);
				__m128 Four = _mm_unpacklo_ps(Tree, _mm_setzero_ps());
				__m128 Five = _mm_unpackhi_ps(Tree, _mm_setzero_ps());
				__m128 Six = _mm_min_ps(Four, Five);
				MINMAX.m128_f32[2] = Six.m128_f32[1];
				if (Six.m128_f32[2] < Six.m128_f32[1]) {
					MINMAX.m128_f32[2] = Six.m128_f32[0];
				}


				__m128 Seven = _mm_max_ps(PROJ[0], PROJ[1]);
				__m128 Eight = _mm_max_ps(PROJ[2], PROJ[3]);
				__m128 Nine = _mm_max_ps(Eight, Seven);
				__m128 ten = _mm_unpacklo_ps(Nine, _mm_setzero_ps());
				__m128 eleven = _mm_unpackhi_ps(Nine, _mm_setzero_ps());
				__m128 twelve = _mm_max_ps(eleven, ten);
				MINMAX.m128_f32[3] = twelve.m128_f32[1];
				if (twelve.m128_f32[3] > twelve.m128_f32[1]) {
					MINMAX.m128_f32[3] = twelve.m128_f32[0];
				}


			}


			//ProjectOntoAxis(a, &axis, &MINMAX,-1);
			//ProjectOntoAxis(b, &axis, &MINMAX,1);

			return MINMAX.m128_f32[0] <= MINMAX.m128_f32[3] && MINMAX.m128_f32[1] >= MINMAX.m128_f32[2];
			//return min <= maxOther && max >= minOther;

		}

		bool intersect(Physics_Object* selfobj, Physics_Object* otherobj);


		void updateBox(Physics_Object* self);
	};
	class Physics_Object : public PHYSICS::Physics {
	public:
		_PhysicsObject* objlnkprnt;
		bool DrawCollider;
		bool disabledSkipp;
		bool isStatic;
		bool haschanged;
		bool isKinematic;
		int ID;
		int Compid;
		TS_P_Collider_box Collider_Boxes;



		void UpdatePhysics()override {
		}

	};
}

#endif // !_PHYSICS_MANAGER_
