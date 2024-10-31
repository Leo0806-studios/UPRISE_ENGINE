#include "CORE/OBJECT/OBJECT.h";
#include "CORE/BEHAVIOUR/BEHAVIOUR.h";

#include "CORE/COMPONENT/COMPONENT.h";

template<> bool CORE::Object::Destroy(RefWrapper<CORE::Behaviour, true> Object) {
    Object->OnDestroyInt(Object);
	return true;
}
template<> bool CORE::Object::Destroy(RefWrapper<CORE::Object, true> Object) {
    Object->OnDestroyInt(Object);
	return true;
}
template<> bool CORE::Object::Destroy(RefWrapper<CORE::Component, true> Object) {
	return true;
}