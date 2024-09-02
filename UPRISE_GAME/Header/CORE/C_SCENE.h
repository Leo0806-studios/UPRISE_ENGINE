#pragma once
#ifndef _SCENE_
#define _SCENE_
#include "pch.h"
#include "GAMEOBJECT.h"
class Gameobject;
namespace CORE {




	class Scene {
	private:

	public:
		//std::vector<std::shared_ptr < CORE::Object>> ObjectsInSScene;
		std::vector<std::shared_ptr<GameObject>> ObjectsInScene;
		static std::shared_ptr<Scene> activeScene;

		//std::vector<std::shared_ptr<GameObject>> ObjectsInBackupScene;
		static std::shared_ptr<Scene> Backups_SCENE;
		Scene() ;
		virtual ~Scene() ;
		GameObject* FindObjectByName(const char* name);
		GameObject* FindObjectByUUID(UUID uuid);
		std::shared_ptr<GameObject> FindObjectByNameP(const char* name);
		std::shared_ptr<GameObject> FindObjectByUUIDP(UUID uuid);
		static Scene Create();


	};
}
#endif // !_SCENE_
