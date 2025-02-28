// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "CORE/OBJECT/OBJECT.h"
#include "CORE/BEHAVIOUR/BEHAVIOUR.h"

#include "CORE/COMPONENT/COMPONENT.h"
namespace UPRISE_ENGINE {
    namespace CORE {
        Object::Object(const Object& other):
            name(other.name),
            enabled(other.enabled.load()),
            PAD{ DEBUG_PAD_BITS_ZEROED }

        {
        }

        Object::Object(const Object& other, bool) //-V2537
        {
            this->enabled.store(other.enabled);
            this->name =std::string( other.name);
        }
        Object& CORE::Object::operator=(const Object& other)
        {
            this->enabled.store(other.enabled);
            this->name = other.name;
            return *this;
        }
        void CORE::Object::destroyBehaviour(SharedRef<CORE::Behaviour, true> Object)
        {
            Object->OnDestroyInt(Object);

        }

        void CORE::Object::destroyComponent(SharedRef<CORE::Component, true> Object)
        {
            Object->OnDestroyInt(Object);
        }
        void CORE::Object::destroyObject(SharedRef<CORE::Object, true> Object)
        {
            Object->OnDestroyInt(Object);
            ///TODO: implement object destruction
        }

    }
}

