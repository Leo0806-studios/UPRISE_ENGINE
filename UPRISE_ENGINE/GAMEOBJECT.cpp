#pragma once
#include "CORE.h"
#include "GAMEOBJECT.h"
#include "_COMPONENT.h"

#include "RENDER_MATERIAL.h"

GameObject GameObject::Create(DATATYPES::TS_P_Vector3 pos, void* mesh,int materialID) {

	GameObject tmp;
	Transform transf = Transform();
	transf.Position = pos;
	void* tra = &transf;
	tmp.msh = mesh;
	tmp.AddComponent(COMPONENTS::_Mesh(), mesh);
	//auto a = tmp.GetComponent(COMPONENTS::_Mesh());
	tmp.MesH = std::make_shared<COMPONENTS::_Mesh>(*(COMPONENTS::_Mesh*)tmp.Components[0]);
	tmp.AddComponent(Transform(), tra);
	std::dynamic_pointer_cast<Transform>(tmp.behaviours[1]).get()->UpdateDirections();
	return tmp;

}
void GameObject::AddComponent(void* component) {

	Components.push_back(component);

}
//template <class _Ty, class... _Types>

//void GameObject::AddComponent(_Ty arg, void* component) {
//	if (arg.UUID == GUID_NULL) {
//		UUID uuid;
//		UuidCreate(&uuid);
//
//
//		arg.UUID = uuid;
//		arg.uuID = arg.UUID;
//	}
//	uuids.push_back(arg.UUID);
//	auto aa = (_Ty*)component;
//	//aa->gameobject = this;
//	std::shared_ptr<CORE::Behaviour> a = std::make_shared<_Ty>(*aa);
//
//
//
//	CORE::Behaviour::behaviours.push_back(a);
//	behaviours.push_back(a);
//
//	Components.push_back(component);
//}

//template<class _Ty, class ..._Types>
//void GameObject::AddComponent(_Ty arg, std::shared_ptr<CORE::Behaviour> component,void* voidcomp)
//{
//	if (arg.UUID == GUID_NULL) {
//		UUID uuid;
//		UuidCreate(&uuid);
//
//
//		arg.UUID = uuid;
//		arg.uuID = arg.UUID;
//	}
//	uuids.push_back(arg.UUID);
//	CORE::Behaviour::behaviours.push_back(a);
//	behaviours.push_back(a);
//	Components.push_back(component);
//
//
//
//}

//template <class _Ty, class... _Types>
//_Ty* GameObject::GetComponent(_Ty arg) {
//
//
//	for (int i = 0; i < Components.size(); i++) {
//		if (arg.UUID == uuids[i]) {
//
//			std::cout << "found";
//			return (_Ty*)Components[i];
//		}
//
//
//	}
//}


