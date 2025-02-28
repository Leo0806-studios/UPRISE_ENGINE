// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include  "ECS/GAMEOBJECT/GAMEOBJECT.h"
#include "ECS/COMPONENTS/TRANSFORM/TRANSFORM.h"
#include "DEBUG/LOG/Log.h"
import REF_WRAPPER; //-V2575
namespace UPRISE_ENGINE {
    UPRISE_ECS_API void GameObject::OnDestroyInt(SharedRef<CORE::Object, true> obj)
    {
        for (Index i =behaviours.size() ; i > 0; i--)
        {
            if (static_cast<long long>(i-1) < 0) {
                throw std::exception("Index out of range");
            }
            if (!CallMockableMethod(CORE::Object::Destroy(behaviours[i - 1]))) {
                DEBUG::Debug::Log("Failed to destroy behaviour");
            }
        }
    }
    
     SharedRef<CORE::Object, true> GameObject::Copy()
    {
         SharedRef<GameObject, true> tmp = CreateRefs::CreateSharedRef<GameObject, true>();
         tmp->tag = tag;
         tmp->layer = layer;
         tmp->transform = transform->Copy();
         tmp->mesh = mesh;
         for (auto& i : behaviours)
         {
             auto a = i->Copy();
             SharedRef<CORE::Behaviour, true> b = a;
             tmp->behaviours.push_back(b);
         }
         return tmp;
    }
     SharedRef<CORE::Object, true> GameObject::DeepCopy()
     {
         //TODO Finish reimplementation
         return SharedRef<CORE::Object, true>();
     }
    UPRISE_ECS_API SharedRef<GameObject, true> GameObject::Create(Vector3 Position, Quaternion Rotation, SharedRef<Mesh, true> mesh)
    {
        SharedRef<GameObject, true> tmp = CreateRefs::CreateSharedRef<GameObject, true>();;
        SharedRef<Transform, true> transf = CreateRefs::CreateSharedRef<Transform, true>();
        transf->SetRotation(Rotation);
        transf->SetPosition(Position);
        tmp->transform = transf;
        tmp->mesh = mesh;
        tmp->transform->UpdateDirections();
        //TODO Finish reimplementation
        return  tmp;
    }

}
