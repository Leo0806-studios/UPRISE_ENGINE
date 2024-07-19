#include "SCENE.h"
#include "GAMEOBJECT.h"
CORE::Scene::Scene()
{
}

CORE::Scene::~Scene()
{
}
CORE::Scene CORE::Scene::activeScene;
GameObject* CORE::Scene::FindObjectByName(const char* name)
{
	int leengt = ObjectsInScene.size();
	for (int i = 0; i < leengt; i++) {
		if (ObjectsInScene[i]->name == name) {
			return ObjectsInScene[i].get();
		}
	}
	return NULL;
}

GameObject* CORE::Scene::FindObjectByUUID(UUID uuid)
{
	int leengt = ObjectsInScene.size();
	for (int i = 0; i < leengt; i++) {
		if (ObjectsInScene[i]->uuid == uuid) {
			return ObjectsInScene[i].get();
		}
	}
	return NULL;
}

CORE::Scene CORE::Scene::Create()
{
	return Scene();
}
