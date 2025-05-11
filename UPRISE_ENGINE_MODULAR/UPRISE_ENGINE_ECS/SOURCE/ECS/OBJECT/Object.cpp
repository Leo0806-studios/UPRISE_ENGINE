// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_ECS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_ECS;

#endif
import std; //-V3549
namespace UPRISE_ENGINE {
    FunctionTransporter::RemoveComponent FunctionTransporter::RemoveBehaviourFromGameobject__internal = nullptr; //-V3547



#ifndef UPRISE_TESTS
        std::vector<WeakRef<Object, true>> Object::ObjectsToBeDestroyedAtEndOfFrame;
#endif // !UPRISE_TESTS
        Object::Object(const Object& other) : //-V2537 //-V3523
            name(other.name),
            enabled(other.enabled.load()),
            PAD{ DEBUG_PAD_BITS_ZEROED }

        {
        }

        Object::Object(const Object& other, bool) //-V2537
        {
            this->enabled.store(other.enabled);
            this->name = std::string(other.name);
        }
        Object& Object::operator=(const Object& other)
        {
            this->enabled.store(other.enabled);
            this->name = other.name;
            return *this;
        }
        void Object::destroyBehaviour(WeakRef<Behaviour, true> Object)
        {
            
            Object->OnDestroyInt(Object);

        }

        void Object::destroyComponent(WeakRef<Component, true> Object)
        {
            Object->OnDestroyInt(Object);
        }
        void Object::destroyObject(WeakRef<Object, true> Object)
        {
            //try cast to behaviour or component using dynamic cast
            //if fails treats it as generic object

            if (auto beh = dynamic_cast<Behaviour*>(Object.Get())) {
                destroyBehaviour(Object);
            }
            else if (auto comp = dynamic_cast<Component*>(Object.Get())) {
                destroyComponent(Object);
            }
            else {
                Object->OnDestroyInt(Object);
            }
        }
        void Object::AfterFrameDestroy()
        {

        }

    
}
