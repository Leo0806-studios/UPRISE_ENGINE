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

        }
    }
    
     SharedRef<Object, true> GameObject::Copy()
    {
         UE_THROW_NOT_IMPLEMENTED;
         SharedRef<GameObject, true> tmp = SharedRef<GameObject,true>::Create();

         return tmp;
    }
     SharedRef<Object, true> GameObject::DeepCopy()
     {
         //TODO Finish reimplementation
         return SharedRef<Object, true>();
     }
    UPRISE_ECS_API SharedRef<GameObject, true> GameObject::Create(Vector3 Position, Quaterion Rotation, SharedRef<Mesh, true> mesh)
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
