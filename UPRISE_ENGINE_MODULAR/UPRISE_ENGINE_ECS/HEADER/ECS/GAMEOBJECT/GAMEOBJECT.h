#pragma once
#ifndef _GameObject_
#define _GameObject_
#include "GLOBAL/GLINCLUDES.h"
#include "OBJECT/OBJECT.h"
#include "TAG/TAG.h"
#include "LAYER/LAYER.h"
#include "VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include "QUTERION/QUATERION.h"
import std;
import REF_WRAPPER;
namespace CORE {
	class Behaviour;
}
class Transform;
class Mesh;
class GameObject :public CORE::Object{
private:
	Tag tag;
	Layer layer;
	RefWrapper<Transform, true> transform;
	RefWrapper<Mesh, true> mesh;
	std::vector < RefWrapper < CORE::Behaviour, true>> behaviours;
public:
#pragma region Constructors
	//default 
	GameObject() = default;
	GameObject(const GameObject& other)
		: 
		behaviours(other.behaviours)
	{
		Enabled() = other.Enabled();
		mesh = other.mesh;
		transform = other.transform;
		Name() = other.Name();
	}



#pragma endregion
#pragma region  Destructors
	~GameObject() {}

#pragma endregion
#pragma region Funcs
#pragma region Statics
	UPRISE_ECS_API static RefWrapper<GameObject, true> Create(Vector3 position,Quaternion Rotation,RefWrapper<Mesh,true> mesh, int materialID);

	
#pragma endregion

#pragma endregion


};
#endif // !_GameObject_
