// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
import UPRISE_ENGINE_CORE;
import REF_WRAPPER;
import std;
namespace UPRISE_ENGINE {
    FunctionTransporter::RemoveComponent FunctionTransporter::RemoveBehaviourFromGameobject__internal = nullptr;

    namespace CORE {



#ifndef UPRISE_TESTS
        std::vector<WeakRef<CORE::Object, true>> Object::ObjectsToBeDestroyedAtEndOfFrame;
#endif // !UPRISE_TESTS
        Object::Object(const Object& other) :
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
        Object& CORE::Object::operator=(const Object& other)
        {
            this->enabled.store(other.enabled);
            this->name = other.name;
            return *this;
        }
        void CORE::Object::destroyBehaviour(WeakRef<CORE::Behaviour, true> Object)
        {
            Object->OnDestroyInt(Object);

        }

        void CORE::Object::destroyComponent(WeakRef<CORE::Component, true> Object)
        {
            Object->OnDestroyInt(Object);
        }
        void CORE::Object::destroyObject(WeakRef<CORE::Object, true> Object)
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
}
