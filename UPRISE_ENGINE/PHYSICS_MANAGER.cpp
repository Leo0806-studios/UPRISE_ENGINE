
#include "pch.h"

#include "PHYSICS_MANAGER.h"
#include "HeaderE/CORE/C_THREADING.h"
#include "TRANSFORM.h"
#include "PHYSICS_OBJECT.h"
#include "_PHYSICSOBJEC.h"
#include "GAMEOBJECT.h"
std::vector < std::shared_ptr<PHYSICS::Physics>> PHYSICS::Physics::physicsobjects;
void PHYSICS::Physics::UpdateAllPhysics()
{
	TrPr(ctx, __func__)
	std::vector<int> posses;
	posses.reserve(physicsobjects.size());
	int i = physicsobjects.size()-1;

	for (; i >= 0; i--) {
		auto a = physicsobjects[i];

		auto aa = CORE::Thread_Manager::CreateThread([a]() { a->UpdatePhysics(); });
		CORE::Thread_Manager::Threads.push_back(&aa);
		//auto o =std::function<void>(a->UpdatePhysics()) ;
		//CORE::Thread thread([a]() { a->UpdatePhysics(); });
		//CORE::Thread thread ([a]() { a->UpdatePhysics(); });
		//a->UpdatePhysics();
	}
	TrPrE(ctx);

}
// void PHYSICS::Physics_Object::ParallelUpdate() {
//	auto a = transf;
//}

 bool PHYSICS::Physics::intersect(Physics_Object* selfobj, Physics_Object* otherobj)
{
	TrPr(ctx, __func__)
	 auto self = selfobj->Collider_Boxes;
	 auto other = otherobj->Collider_Boxes;
	 auto selflnk = selfobj->objlnkprnt->Game_Object->TrAnSfOrM.get();
	 auto otherlnk = otherobj->objlnkprnt->Game_Object->TrAnSfOrM.get();
	__m128 SELFCOLBOX[8];
	SELFCOLBOX[0] = self.a;
	SELFCOLBOX[1] = self.b;
	SELFCOLBOX[2] = self.c;
	SELFCOLBOX[3] = self.d;
	SELFCOLBOX[4] = self.e;
	SELFCOLBOX[5] = self.f;
	SELFCOLBOX[6] = self.g;
	SELFCOLBOX[7] = self.h;

	__m128 OTHERCOLBOX[8];
	OTHERCOLBOX[0] = other.a;
	OTHERCOLBOX[1] = other.b;
	OTHERCOLBOX[2] = other.c;
	OTHERCOLBOX[3] = other.d;
	OTHERCOLBOX[4] = other.e;
	OTHERCOLBOX[5] = other.f;
	OTHERCOLBOX[6] = other.g;
	OTHERCOLBOX[7] = other.h;

	__m128 AXES[6];
	AXES[0] = selflnk->right;
	AXES[1] = selflnk->up;
	AXES[2] = selflnk->forward;
	AXES[3] = otherlnk->right;
	AXES[4] = otherlnk->right;
	AXES[5] = otherlnk->right;

	//std::vector<TS_Vector3> axses;
	//axses.reserve(6);
	//axses.push_back(selfdir->right);
	//axses.push_back(selfdir->up);
	//axses.push_back(selfdir->forward);
	//axses.push_back(otherdir->right);
	//axses.push_back(otherdir->up);
	//axses.push_back(otherdir->forward);
	//auto a = &axses;

	if (!OverlapOnAxis(SELFCOLBOX, OTHERCOLBOX, AXES[0])) {
		TrPrE(ctx);
		return false;
	}
	if (!OverlapOnAxis(SELFCOLBOX, OTHERCOLBOX, AXES[1])) {
		TrPrE(ctx);
		return false;
	}
	if (!OverlapOnAxis(SELFCOLBOX, OTHERCOLBOX, AXES[2])) {
		TrPrE(ctx);
		return false;
	}
	if (!OverlapOnAxis(SELFCOLBOX, OTHERCOLBOX, AXES[3])) {
		TrPrE(ctx);
		return false;
	}
	if (!OverlapOnAxis(SELFCOLBOX, OTHERCOLBOX, AXES[4])) {
		TrPrE(ctx);
		return false;
	}
	if (!OverlapOnAxis(SELFCOLBOX, OTHERCOLBOX, AXES[5])) {
		TrPrE(ctx);
		return false;
	}
	TrPrE(ctx);
	return true;



}

void PHYSICS::Physics::updateBox(Physics_Object* self)
{
	TrPr(ctx, __func__)
	auto o = self->objlnkprnt->Game_Object->TrAnSfOrM.get();
	//float x = self->Collider_Boxes.bounds.x * 0.5f;
	//float y = self->Collider_Boxes.bounds.y * 0.5f;
	//float z = self->Collider_Boxes.bounds.z * 0.5f;
	__m128 bounds = _mm_setr_ps(self->Collider_Boxes.bounds.x * 0.5, self->Collider_Boxes.bounds.y * 0.5f, self->Collider_Boxes.bounds.z * 0.5f, 1);
	//	auto  r = directions->right;
	__m128 r = _mm_setr_ps(o->right.x, o->right.y, o->right.z, 0);
	//	auto u = directions->up;
	__m128 u = _mm_setr_ps(o->up.x, o->up.y, o->up.z, 0);
	//	auto f = directions->forward;
	__m128 Ff = _mm_setr_ps(o->forward.x, o->forward.y, o->forward.z, 0);
	//float fx = f.x * x, fy = f.y * y, fz = f.z * z;
	__m128 FF = _mm_mul_ps(Ff, bounds);
	//float rx = r.x * x, ry = r.y * y, rz = r.z * z;
	__m128 RR = _mm_mul_ps(r, bounds);
	//float ux = u.x * x, uy = u.y * y, uz = u.z * z;
	__m128 UU = _mm_mul_ps(u, bounds);
	//auto ox = self->Origin.x;
	//auto oy = self->Origin.y;
	//auto oz = self->Origin.z;
	__m128 Origin = _mm_setr_ps(o->Position.x, o->Position.y, o->Position.z, 0);

	__m128 a = _mm_sub_ps(_mm_sub_ps(FF, RR), _mm_add_ps(UU, Origin));
	__m128 b = _mm_sub_ps(_mm_add_ps(FF, RR), _mm_add_ps(UU, Origin));
	__m128 c = _mm_sub_ps(_mm_add_ps(_mm_sub_ps(_mm_setzero_ps(), FF), RR), _mm_add_ps(UU, Origin));
	__m128 d = _mm_sub_ps(_mm_sub_ps(_mm_sub_ps(_mm_setzero_ps(), FF), RR), _mm_add_ps(UU, Origin));
	__m128 e = _mm_add_ps(_mm_sub_ps(FF, RR), _mm_add_ps(UU, Origin));
	__m128 f = _mm_add_ps(_mm_add_ps(FF, RR), _mm_add_ps(UU, Origin));
	__m128 g = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_setzero_ps(), FF), RR), _mm_add_ps(UU, Origin));
	__m128 h = _mm_add_ps(_mm_sub_ps(_mm_sub_ps(_mm_setzero_ps(), FF), RR), _mm_add_ps(UU, Origin));
	_mm_storeu_ps(&self->Collider_Boxes.a.x, a);
	_mm_storeu_ps(&self->Collider_Boxes.b.x, b);
	_mm_storeu_ps(&self->Collider_Boxes.c.x, c);
	_mm_storeu_ps(&self->Collider_Boxes.d.x, d);
	_mm_storeu_ps(&self->Collider_Boxes.e.x, e);
	_mm_storeu_ps(&self->Collider_Boxes.f.x, f);
	_mm_storeu_ps(&self->Collider_Boxes.g.x, g);
	_mm_storeu_ps(&self->Collider_Boxes.h.x, h);


	TrPrE(ctx);
}
