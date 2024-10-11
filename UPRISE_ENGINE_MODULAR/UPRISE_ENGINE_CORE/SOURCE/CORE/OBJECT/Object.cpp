#include "OBJECT/OBJECT.h"
#include "BEHAVIOUR/BEHAVIOUR.h"

#include "COMPONENT/COMPONENT.h"

template<> bool CORE::Object::Destroy(RefWrapper<CORE::Behaviour, true> Object) {
	return true;
}
template<> bool CORE::Object::Destroy(RefWrapper<CORE::Object, true> Object) {
	return true;
}
template<> bool CORE::Object::Destroy(RefWrapper<CORE::Component, true> Object) {
	return true;
}