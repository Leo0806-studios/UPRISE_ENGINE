#include "SCENE.h"
#include "GAMEOBJECT.h"
CORE::Scene::Scene()
{
}

CORE::Scene::~Scene()
{
}

GameObject* CORE::Scene::FindObjectByName(const char* name)
{
	int leengt = ObjectsInSScene.size();
	for (int i = 0; i < leengt; i++) {
		if (ObjectsInSScene[i]->name == name) {
			return ObjectsInSScene[i].get();
		}
	}
	return NULL;
}

GameObject* CORE::Scene::FindObjectByUUID(UUID uuid)
{
	int leengt = ObjectsInSScene.size();
	for (int i = 0; i < leengt; i++) {
		if (ObjectsInSScene[i]->uuid == uuid) {
			return ObjectsInSScene[i].get();
		}
	}
	return NULL;
}

CORE::Scene CORE::Scene::Create()
{
	return Scene();
}
