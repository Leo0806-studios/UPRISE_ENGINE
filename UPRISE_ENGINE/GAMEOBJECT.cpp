#pragma once
#include "pch.h"
#include "HeaderE/CORE/CORE.h"
#include "GAMEOBJECT.h"
#include "_COMPONENT.h"
#include "CAMERA.h"
#include "RENDER_MATERIAL.h"
#include "Empty.h"
#include "MESH.h"
#include "HeaderE/CORE/C_SCENE.h"

::shared_ptr<GameObject> GameObject::Create(DATATYPES::TSPVector3 pos, void* mesh,int materialID) {
	TracyCZoneN(ctx, "Creating GameObject", true);

	GameObject tmp;
	UuidCreate(&tmp.uuid);
	Transform transf = Transform();
	transf.Position = pos;
	void* tra = &transf;
	tmp.msh = mesh;
	tmp.AddComponent(COMPONENTS::_Mesh(), mesh);
	//auto a = tmp.GetComponent(COMPONENTS::_Mesh());
	tmp.MESH = std::make_shared<COMPONENTS::_Mesh>(*(COMPONENTS::_Mesh*)tmp.Components[0]);
	//tmp.MESH = tmp.MesH;
	tmp.AddComponent(Transform(), tra);
	tmp.TrAnSfOrM = std::dynamic_pointer_cast<Transform>(tmp.behaviours[1]);
	tmp.MESH->MMLnik = std::make_shared<PAIN::MiniModel>(PAIN::MiniModel(tmp.MESH->Model, tmp.TrAnSfOrM, std::make_shared<bool>(tmp.Enabled), std::make_shared<bool>(tmp.isRemoved)));

	auto a = std::make_shared<GameObject>(tmp);
	if (materialID < PAIN::Render::mats.size() || PAIN::Render::mats.size() == 0) {
		PAIN::Render::mats[materialID].Object_ModelSubstitute.push_back(tmp.MESH->MMLnik);
	}
	CORE::Scene::activeScene->ObjectsInScene.push_back(a);
	std::dynamic_pointer_cast<Transform>(tmp.behaviours[1]).get()->UpdateDirections();
	TracyCZoneEnd(ctx);

	return a;

}
/// <summary>
/// Creates new GameObject 
/// </summary>
/// <param name="pos"></param>
/// <param name="mesh"></param>
/// <param name="materialID"></param>
/// <returns> "shared_ptr GameObject"</returns>
shared_ptr<GameObject> GameObject::Create(DATATYPES::TSPVector3 pos, Quaternion rot,std::shared_ptr<COMPONENTS::_Mesh> mesh, int materialID) {
	TracyCZoneN(ctx, "Creating GameObject", true);

	GameObject tmp;
	UuidCreate(&tmp.uuid);
	Transform transf = Transform();
	transf.Position = pos;
	transf.rotation = rot;
	tmp.TrAnSfOrM = std::make_shared<Transform>(transf);
	tmp.MESH = mesh;
	tmp.TrAnSfOrM->UpdateDirections();
	tmp.MESH->MMLnik = std::make_shared<PAIN::MiniModel>(PAIN::MiniModel(tmp.MESH->Model, tmp.TrAnSfOrM, std::make_shared<bool>(tmp.Enabled), std::make_shared<bool>(tmp.isRemoved)));

	auto a = std::make_shared<GameObject>(tmp);
	PAIN::Render::mats[materialID].objects.push_back(a);
	if (materialID < PAIN::Render::mats.size() || PAIN::Render::mats.size() == 0) {
		PAIN::Render::mats[materialID].Object_ModelSubstitute.push_back(tmp.MESH->MMLnik);

	}
	CORE::Scene::activeScene->ObjectsInScene.push_back(a);
	TracyCZoneEnd(ctx);

	return a;

}
GameObject GameObject::CreateEmpty(DATATYPES::TSPVector3 pos)
{
	GameObject tmp;
	UuidCreate(&tmp.uuid);
	Transform transf = Transform();
	transf.Position = pos;
	void* tra = &transf;
	Empty empt = Empty();
	tmp.AddComponent(Empty(), &empt);
	tmp.AddComponent(Transform(), tra);
	tmp.TrAnSfOrM = std::dynamic_pointer_cast<Transform>(tmp.behaviours[1]);
	std::dynamic_pointer_cast<Transform>(tmp.behaviours[1]).get()->UpdateDirections();

	return tmp;
}
GameObject GameObject::CreateCamera(DATATYPES::TSPVector3 pos, Quaternion rot)
{
	TracyCZoneN(ctx, "Creating Camera", true);

	GameObject tmp;
	UuidCreate(&tmp.uuid);
	Transform transf = Transform();
	transf.Position = pos;
	transf.rotation = rot;
	tmp.TrAnSfOrM = std::make_shared<Transform>(transf);
	//Empty empt = Empty();
	tmp.AddComponent(Empty());
	

	tmp.AddComponent(Camera(tmp.TrAnSfOrM));
	tmp.TrAnSfOrM->UpdateDirections();
	TracyCZoneEnd(ctx);

	return tmp;
}
 std::shared_ptr<CORE::Behaviour> GameObject::AddComponent(std::shared_ptr<CORE::Behaviour> component, std::string name) {

	auto tmp = component->Copy();
	if (tmp->uuID == GUID_NULL) {
		UUID uuid;
		UuidCreate(&uuid);


		//tmp->UUID = uuid;
		tmp->uuID = uuid;
	}
	tmp->Game_Object = this;
	tmp->TRANSFORM = this->TrAnSfOrM;
	tmp->compname = name;
	uuids.push_back(tmp->uuID);
	CORE::Behaviour::behaviours.push_back(tmp);
	CORE::Behaviour::AWAKES.push_back(tmp);
	CORE::Behaviour::Starts.push_back(tmp);
	behaviours.push_back(tmp);
	return tmp;
}
//void GameObject::AddComponent(void* component) {
//
//	Components.push_back(component);
//
//}
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


