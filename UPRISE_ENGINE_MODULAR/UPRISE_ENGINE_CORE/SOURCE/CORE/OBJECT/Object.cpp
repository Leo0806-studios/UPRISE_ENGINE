// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "CORE/OBJECT/OBJECT.h";
#include "CORE/BEHAVIOUR/BEHAVIOUR.h";

#include "CORE/COMPONENT/COMPONENT.h";

void CORE::Object::destroyBehaviour(RefWrapper<CORE::Behaviour, true> Object)
{
    Object->OnDestroyInt(Object);

}

void CORE::Object::destroyComponent(RefWrapper<CORE::Component, true> Object)
{
    Object->OnDestroyInt(Object);
}
//template<> bool CORE::Object::Destroy(RefWrapper<CORE::Behaviour, true> Object) {
//    destroyBehaviour(Object);
//    return true;
//}
//template<> bool CORE::Object::Destroy(RefWrapper<CORE::Component, true> Object) {
//    destroyComponent(Object);
//    return true;
//}
//template<> bool CORE::Object::Destroy(RefWrapper<CORE::Object, true> Object) {
//    Object->OnDestroyInt(Object);
//    return true;
//}