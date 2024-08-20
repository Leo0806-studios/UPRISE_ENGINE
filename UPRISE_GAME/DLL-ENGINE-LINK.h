#pragma once
#pragma once
#ifndef _DLL_ENGINE_LINK_

#define _DLL_ENGINE_LINK_
#include "pch.h"
#include "GLINCLUDES.h"
#include "Header/RENDER/RENDER_MATERIAL.h"
#include "Header/ECS/COMPONENTS/CAMERA.h"
#include "Header/CORE/C_BEHAVIOUR.h"
namespace CORE {
	class Scene;
}
class Mesh_LINK {
public:

};
class Model_LINK {
	VEC(Mesh_LINK) Meshes;
};
class DATALINK {
public:

	//SCENE
	std::shared_ptr<CORE::Scene> ACTIVE_SCENE;
	std::shared_ptr<CORE::Scene> Backups_SCENE;


	//RENDER
	PAIN::Shader*(*CreateSHADER)(const char* vertexPath, const char* fragmentPath);
	void(*AddTORender)(std::shared_ptr<PAIN::MiniModel> mm, int id);
	bool(*RemoveFromRender)(std::shared_ptr<PAIN::MiniModel>& ToRemnove, int Material_ID);
	bool(*CreateMaterial)( PAIN::Shader*  Shader);


	GLFWwindow* window;
	std::shared_ptr<std::unordered_map<std::string, int>> M_ID_LINK;
	unsigned int M_ID_LINK_LENGTH;
	std::shared_ptr<std::unordered_map<std::string, std::shared_ptr<PAIN::Model>>> M_DICT_LINK;
	unsigned int M_DICT_LINK_LENGTH;
	std::shared_ptr <std::vector<PAIN::Material>> MATS_LINK;
	unsigned int MATS_LINK_LENGTH;
	std::shared_ptr<std::vector<std::shared_ptr<PAIN::TerrainModel>>> TERRAIN_LINK;
	unsigned int TERRAIN_LINK_LENGTH;
	std::shared_ptr<std::vector< std::shared_ptr<GameObject> >> OBJECT_LINK;
	unsigned int OBJECT_LINK_LENGTH;
	
	std::shared_ptr<std::vector< std::shared_ptr<CORE::Object> >> PTR_OBJECTS_LINK;
	unsigned int PTR_OBJECTS_LINK_LENGTH;
	std::shared_ptr<std::vector< void* >> VOID_OBJECTS_LINK;
	unsigned int VOID_OBJECTS_LINK_LENGTH;
	PAIN::Render_Camera* RenderCam;
	std::shared_ptr<Camera> CAM;

	//BEHAVIOUR

	std::vector<std::shared_ptr<CORE::Behaviour>> objectss_LINK;
	std::vector<std::shared_ptr<CORE::Behaviour>> behaviours_LINK;
	std::vector<std::shared_ptr<CORE::Behaviour>> AWAKES_LINK;
	std::vector<std::shared_ptr<CORE::Behaviour>> Starts_LINK;
	std::vector<std::shared_ptr<CORE::Behaviour>> Parallel_Updates_LINK;


	//CONFIGFILES
	std::shared_ptr<std::unordered_map<ConfigFile::ConfigType, std::unordered_map <std::string, std::shared_ptr<ConfigFile>>>> ConfigDatabase_LINK;


	//Editor
	using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;

	std::shared_ptr<std::map<std::string, CreatorFunc>> creators_LINK;
	std::shared_ptr<VEC(std::shared_ptr<CORE::Behaviour>)> inst_LINK;
	int* III;

	//CORE

	int (*GetKey)(int key);


	//Profiling
	void(*PLOTADD)(const char* name, int value);
	void(*PLOTREMOVE)(const char* name, int value);

};




#endif // !_DLL_ENGINE_LINK_
