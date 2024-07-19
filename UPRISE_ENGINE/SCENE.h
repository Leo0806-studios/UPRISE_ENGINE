#pragma once
#ifndef _SCENE_
#define _SCENE_
#include "pch.h"
#include "GAMEOBJECT.h"
namespace CORE {




	class Scene {
	private:

	public:
		//std::vector<std::shared_ptr < CORE::Object>> ObjectsInSScene;
		std::vector<std::shared_ptr<GameObject>> ObjectsInScene;
		static Scene activeScene;
		Scene() ;
		virtual ~Scene() ;
		GameObject* FindObjectByName(const char* name);
		GameObject* FindObjectByUUID(UUID uuid);
		static Scene Create();


	};
}
#endif // !_SCENE_
