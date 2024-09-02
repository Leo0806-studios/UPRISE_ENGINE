#pragma once
#ifndef _SCENE_
#define _SCENE_
#include "pch.h"
#include "GAMEOBJECT.h"
#include "MODULE_IMPORTS.h"

class Gameobject;
namespace CORE {




	class Scene {
	private:

	public:
		//std::vector<std::shared_ptr < CORE::Object>> ObjectsInSScene;
		std::vector<std::shared_ptr<GameObject>> ObjectsInScene;
		static std::shared_ptr<Scene> activeScene;
		static Scene activeScene_obj;
		static Scene Backups_SCENE_obj;
		static std::shared_ptr<Scene> Backups_SCENE;
		std::vector<std::shared_ptr<GameObject>> ObjectsInBackupScene;

		Scene() ;
		virtual ~Scene() ;
		GameObject* FindObjectByName(const char* name);
		GameObject* FindObjectByUUID(UUID uuid);
		static Scene Create();


	};
}
#endif // !_SCENE_
