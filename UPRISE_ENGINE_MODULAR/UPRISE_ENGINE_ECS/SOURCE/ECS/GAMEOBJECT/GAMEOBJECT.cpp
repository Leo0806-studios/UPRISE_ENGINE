#include  "ECS/GAMEOBJECT/GAMEOBJECT.h";
#include "ECS/COMPONENTS/TRANSFORM/TRANSFORM.h";
import REF_WRAPPER;
UPRISE_ECS_API void GameObject::OnDestroyInt(RefWrapper<CORE::Object, true> obj)
{
    int i = behaviours.size() - 1;
    for (; i> 0; i--)
    {
        CORE::Object::Destroy(behaviours[i]);
    }
}
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
