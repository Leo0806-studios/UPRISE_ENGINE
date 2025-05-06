// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifdef __INTELLISENSE__
import UPRISE_ENGINE_DEBUG;
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_ECS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_DEBUG;
import UPRISE_ENGINE_ECS;
import UPRISE_ENGINE_CORE;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    UPRISE_ECS_API void GameObject::OnDestroyInt(WeakRef<Object, true> obj)
    {
        for (Index i =behaviours.size() ; i > 0; i--)
        {
            if (static_cast<long long>(i-1) < 0) {
                throw std::exception("Index out of range");
            }
            UE_THROW_NOT_IMPLEMENTED;
            //if (!Object::Destroy(behaviours[i - 1])) {
            //    DEBUG::Debug::Log("Failed to destroy behaviour");
            //}
        }
    }
    
     SharedRef<Object, true> GameObject::Copy()
    {
         SharedRef<GameObject, true> tmp = SharedRef<GameObject,true>::Create();
         tmp->tag = tag;
         tmp->layer = layer;
         tmp->transform = transform->Copy();
         tmp->mesh = mesh;
         for (auto& i : behaviours)
         {
             auto a = i->Copy();
             SharedRef<Behaviour, true> b = a;
             tmp->behaviours.push_back(b);
         }
         return tmp;
    }
     SharedRef<Object, true> GameObject::DeepCopy()
     {
         //TODO Finish reimplementation
         return SharedRef<Object, true>();
     }
    UPRISE_ECS_API SharedRef<GameObject, true> GameObject::Create(Vector3 Position, Quaternion Rotation, SharedRef<Mesh, true> mesh)
    {
        SharedRef<GameObject, true> tmp = SharedRef<GameObject, true>::Create();
        SharedRef<Transform, true> transf = SharedRef<GameObject, true>::Create();
        transf->SetRotation(Rotation);
        transf->SetPosition(Position);
        tmp->transform = transf;
        tmp->mesh = mesh;
        tmp->transform->UpdateDirections();
        //TODO Finish reimplementation
        return  tmp;
    }

}
