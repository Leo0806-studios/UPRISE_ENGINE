// UPRISE_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#import "ManagedUtills.tlb" named_guids
#include "DEBUG_LOGGER.h"

#include "GLINCLUDES.h"
#include "pch.h"
//#include "glad.h"
//#include "glfw3.h"
//#include "pch.h"
//#include "Helpers.h"
#include "CORE.h"
#include "DATATYPES.h"

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
#include "ECS.h"
#include "RENDER.h"
//#include "RENDER_DATATYPES.h"
//#include "RENDER_OBJECT_SPAWNING.h"
#include "MESSAGES.h"
//#include "CORE.h"
//#include "INPUT.h"
//#include "memory"
#include "TEST.h"
#include "RENDER_MATERIAL.h"
#include "PHYSICS.h"
#include "RENDERSETUP.h"
#include "SCENE.h"
#include "TERRAIN_DATA.h"
//#include "BEHAVIOUR.h"
//#include "MESH.h"



class Behaviour;
class Object;
class Input;
class Component;
class Scene;
class Startup;



MESSAGES::Message_Bus* Messagebus;

std::vector<DATATYPES::TS_P_Vector3> VERTS;
bool spawned = false;

PAIN::Shader shader;

CORE::Scene scene;
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
void processInput(GLFWwindow* window)
{
	if (CORE::Input::GetKey(A)) {
		std::cout << "pressed A";
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		GameObject TestObj;
		const  char* pth = "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\GAMEDATA\\quit.glb";
		auto mod = COMPONENTS::_Mesh(pth);
		PAIN::Material mat = PAIN::Material(&shader);
		mat.ID = 0;
		PAIN::Render::mats.push_back(mat);
		TestObj = GameObject::Create(DATATYPES::TS_P_Vector3(0, 0, 0), &mod, mat.ID);
		if (mat.ID < PAIN::Render::mats.size() || PAIN::Render::mats.size() == 0) {
			PAIN::Render::mats[mat.ID].objects.push_back(std::make_shared<GameObject>(TestObj));
		}

		TestObj.name = (char*)"TEST OBJECT";



		auto ppp = Test();
		ppp.gameobject = &TestObj;
		ppp.oobj = &TestObj;
		void* msc = &ppp;


		TestObj.AddComponent(Test());

		std::cout << "pressed O";

		//auto base =CORE::Behaviour();
		auto ppppppp = std::make_shared<GameObject>(TestObj);

		scene.ObjectsInScene.push_back(std::make_shared<GameObject>(TestObj));
		CORE::Behaviour::updateAll();
		spawned = true;
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{
	auto a =CORE::Filehandler::ApplicationPath();
	Log << "Startup....";


	CORE::SYSTEMS z;
	auto startcfg = CORE::Startup::Configure_Startup();
	CORE::Startup::Init_Startup(startcfg);
	z = CORE::Startup::Start_Systems();
	std::dynamic_pointer_cast<Camera>(PAIN::Render::CAM).get()->FOV = 45;
	scene = CORE::Scene::Create();
	auto aaa = CORE::Filehandler::ApplicationPath() + "\\GAMEDATA";
	CORE::ConfigLoader::LoadModels(std::filesystem::path(aaa));
	std::cout << "Hello World!\n";
	


	shader = PAIN::Shader("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.vs", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.fs");
	//auto a = Terrain_Data::Create("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\GAMEDATA\\UPRISE\\ASSETS\\Map1.png", 512, 512, 100, &shader);
	//PAIN::Render::terrains.push_back(std::make_shared<PAIN::TerrainModel>(a.get()->model));

	//auto aerwe = CORE::ConfigLoader::LoadCOnfigFile("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\GAMEDATA\\UPRISE\\CONFIG\\BUILDINGS\\TEST.CFG");






	double lasttime = glfwGetTime();
	while (!glfwWindowShouldClose(z.windw))
	{
		processInput(z.windw);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		CORE::Behaviour::updateAllAWAKE();
		CORE::Behaviour::updateAllSTART();
		CORE::Behaviour::updateAll();
		PHYSICS::Physics::UpdateAllPhysics();
		if (spawned == true) {
			PAIN::Render::DrawAll();
		}
		glfwSwapBuffers(z.windw);
		FrameMark;
		glfwPollEvents();
		while (glfwGetTime() < lasttime + 1.0 / 60) {
			// TODO: Put the thread to sleep, yield, or simply do nothing
		}
		lasttime += 1.0 / 60;
	}
	glfwTerminate();

	return 0;

}
