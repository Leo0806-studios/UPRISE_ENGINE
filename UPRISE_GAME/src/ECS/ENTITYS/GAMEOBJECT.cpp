#pragma once
#include "pch.h"
#include "Header/CORE/CORE.h"
#include "GAMEOBJECT.h"
#include "_COMPONENT.h"
#include "CAMERA.h"
#include "RENDER_MATERIAL.h"
#include "Empty.h"
#include "MESH.h"
#include "Header/CORE/C_SCENE.h"
#include "DLL-ENGINE-LINK.h"
//#include "CUSTOM_STD.h"

::shared_ptr<GameObject> GameObject::Create(DATATYPES::TSPVector3 pos, void* mesh, int materialID) {
	TracyCZoneN(ctx, "Creating GameObject", true);
	GOP;
	GameObject tmp;
	UuidCreate(&tmp.uuid);
	Transform transf = Transform();
	transf.Position = pos;
	void* tra = &transf;
	tmp.msh = mesh;
	tmp.AddComponent(COMPONENTS::_Mesh(), mesh);
	//auto a = tmp.GetComponent(COMPONENTS::_Mesh());
	tmp.MESH = std::make_shared<COMPONENTS::_Mesh>(*(COMPONENTS::_Mesh*)tmp.Components[0]);
	tmp.MESH->Material_ID = materialID;

	//tmp.MESH = tmp.MesH;
	tmp.AddComponent(Transform(), tra);
	tmp.TrAnSfOrM = std::dynamic_pointer_cast<Transform>(tmp.behaviours[1]);
	auto a = std::make_shared<GameObject>(tmp);
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
shared_ptr<GameObject> GameObject::Create(DATATYPES::TSPVector3 pos, Quaternion rot, std::shared_ptr<COMPONENTS::_Mesh> mesh, int materialID) {
	TracyCZoneN(ctx, "Creating GameObject", true);
	GOP;
	GameObject tmp;
	UuidCreate(&tmp.uuid);
	Transform transf = Transform();
	transf.Position = pos;
	transf.rotation = rot;
	tmp.TrAnSfOrM = std::make_shared<Transform>(transf);
	tmp.MESH = mesh;
	tmp.MESH->Material_ID = materialID;
	tmp.TrAnSfOrM->UpdateDirections();
	tmp.MESH->MMLnik = std::make_shared<PAIN::MiniModel>(PAIN::MiniModel(tmp.MESH->Model, tmp.TrAnSfOrM, std::make_shared<bool>(tmp.Enabled), std::make_shared<bool>(tmp.isRemoved)));
	auto a = std::make_shared<GameObject>(tmp);
	//auto enb = std::make_shared<bool>(a->Enabled);
	
	IMPORTANT::DATA->AddTORender((tmp.MESH->MMLnik), materialID);
	CORE::Scene::activeScene->ObjectsInScene.push_back(a);
	TracyCZoneEnd(ctx);

	return a;

}
GameObject GameObject::CreateEmpty(DATATYPES::TSPVector3 pos)
{
	GOP;
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
	GOP;
	GameObject tmp;
	tmp.IsCamera = true;
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
bool GameObject::Delete(std::shared_ptr<GameObject> Object)
{
	if (std::find(CORE::Scene::Backups_SCENE->ObjectsInScene.begin(), CORE::Scene::Backups_SCENE->ObjectsInScene.end(), Object) != CORE::Scene::Backups_SCENE->ObjectsInScene.end()){
		int cnt = Object->behaviours.size() - 1;
		IMPORTANT::DATA->RemoveFromRender(Object->MESH->MMLnik, Object->MESH->Material_ID);
		GOM;
		for (; cnt >= 0; cnt--) {
			RemoveComponent(Object->behaviours[cnt]);
		}
		*Object->MESH->MMLnik->_removed = true;
		//GameObject* Replacer = new GameObject(1);
		Object->isRemoved = true;
		auto a = Object.get();
		//delete a;
		Object.DESTROY();
		 Object.setPTR(nullptr);
		//auto a = std::make_shared<GameObject>(Replacer);
		//==//=;

		//Replacer->isRemoved = true;
		//auto aa = Object.get();
		//*aa = *Replacer;
	}


	return true;
}
bool GameObject::Delete(GameObject& Object)
{
	GameObject Replacer(1);
	Object.isRemoved = true;
	//IMPORTANT::DATA->RemoveFromRender();
	//auto a = std::make_shared<GameObject>(Replacer);
	Object = Replacer;
	return false;
}
bool GameObject::Delete(GameObject* Object)
{
	GameObject Replacer(1);
	Object->isRemoved = true;
	//IMPORTANT::DATA->RemoveFromRender();
	//auto a = std::make_shared<GameObject>(Replacer);
	Object = &Replacer;

	return false;
}
bool GameObject::RemoveComponent(std::shared_ptr<CORE::Behaviour> Component)
{

	Empty replacer;
	replacer.ToBeRemoved = true;
	std::shared_ptr<CORE::Behaviour> a = std::make_shared<Empty>(replacer);
	Component.swap(a);
	return false;
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


