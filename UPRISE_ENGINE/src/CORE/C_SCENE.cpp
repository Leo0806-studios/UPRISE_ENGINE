#include "pch.h"
#include "HeaderE/CORE/C_SCENE.h"
#include "GAMEOBJECT.h"
CORE::Scene::Scene()
{
}

CORE::Scene::~Scene()
{
}
CORE::Scene CORE::Scene::activeScene_obj;
CORE::Scene CORE::Scene::Backups_SCENE_obj;
std::shared_ptr<CORE::Scene> CORE::Scene::activeScene=std::make_shared<CORE::Scene>(CORE::Scene::activeScene_obj);
std::shared_ptr<CORE::Scene> CORE::Scene::Backups_SCENE=std::make_shared<CORE::Scene>(CORE::Scene::Backups_SCENE_obj);
GameObject* CORE::Scene::FindObjectByName(const char* name)
{
	TrPr(ctx, __func__)
	int leengt = ObjectsInScene.size();
	for (int i = 0; i < leengt; i++) {
		if (ObjectsInScene[i]->name == name) {
			TrPrE(ctx);

			return ObjectsInScene[i].get();
		}
	}
	TrPrE(ctx);

	return NULL;
}

GameObject* CORE::Scene::FindObjectByUUID(UUID uuid)
{
	TrPr(ctx, __func__)
	int leengt = ObjectsInScene.size();
	for (int i = 0; i < leengt; i++) {
		if (ObjectsInScene[i]->uuid == uuid) {
			TrPrE(ctx);

			return ObjectsInScene[i].get();
		}
	}
	TrPrE(ctx);

	return NULL;
}

CORE::Scene CORE::Scene::Create()
{
	
	return Scene();
}
