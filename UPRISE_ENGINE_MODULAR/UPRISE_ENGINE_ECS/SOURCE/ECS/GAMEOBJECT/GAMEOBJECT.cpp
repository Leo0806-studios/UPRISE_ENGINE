#include "GAMEOBJECT/GAMEOBJECT.h"
#include "COMPONENTS/TRANSFORM/TRANSFORM.h"

UPRISE_ECS_API RefWrapper<GameObject, true> GameObject::Create(Vector3 Position, Quaternion Rotation, RefWrapper<Mesh, true> mesh, int materialID)
{
	RefWrapper<GameObject, true> tmp = WrapRef<GameObject,true>();;
	RefWrapper<Transform, true> transf=WrapRef<Transform,true>();
	transf->SetRotation(Rotation);
	transf->SetPosition(Position);
	tmp->transform = transf;
	tmp->mesh = mesh;
	tmp->transform->UpdateDirections();
	//TODO Finish reimplementation
	return  tmp;
}
