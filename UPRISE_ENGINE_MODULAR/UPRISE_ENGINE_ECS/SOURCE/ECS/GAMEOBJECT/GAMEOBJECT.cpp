// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include  "ECS/GAMEOBJECT/GAMEOBJECT.h";
#include "ECS/COMPONENTS/TRANSFORM/TRANSFORM.h";
#include "DEBUG/LOG/Log.h"
import REF_WRAPPER; //-V2575
namespace UPRISE_ENGINE {
    UPRISE_ECS_API void GameObject::OnDestroyInt(RefWrapper<CORE::Object, true> obj)
    {
        Index i = behaviours.size() - 1;
        for (; i > 0; i--)
        {
            
            if(!CORE::Object::Destroy(behaviours[i])){
                DEBUG::Debug::Log("Failed to destroy behaviour");
            }
        }
    }
    UPRISE_ECS_API RefWrapper<GameObject, true> GameObject::Create(Vector3 Position, Quaternion Rotation, RefWrapper<Mesh, true> mesh, int materialID)
    {
        RefWrapper<GameObject, true> tmp = WrapRef<GameObject, true>();;
        RefWrapper<Transform, true> transf = WrapRef<Transform, true>();
        transf->SetRotation(Rotation);
        transf->SetPosition(Position);
        tmp->transform = transf;
        tmp->mesh = mesh;
        tmp->transform->UpdateDirections();
        //TODO Finish reimplementation
        return  tmp;
    }

}
