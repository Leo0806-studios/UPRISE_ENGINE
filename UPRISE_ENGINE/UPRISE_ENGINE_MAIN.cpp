// UPRISE_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#pragma comment(linker, "/manifestdependency:\"name='Dll' version='1.0.0.0' type='win32'\"")

//#import "ManagedUtills.tlb" named_guids
#include "DEBUG_LOGGER.h"

#include "GLINCLUDES.h"
#include "pch.h"
//#include "glad.h"
//#include "glfw3.h"
//#include "pch.h"
//#include "Helpers.h"
#include "Header/CORE/CORE.h"
#include "Header/DATATYPES/D_DATATYPES.h"

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
#include "ECS.h"
#include "RENDER.h"
//#include "RENDER_DATATYPES.h"
//#include "RENDER_OBJECT_SPAWNING.h"
#include "MESSAGES.h"
//#include "Header/CORE/CORE.h"
//#include "INPUT.h"
//#include "memory"
#include "TEST.h"
#include "RENDER_MATERIAL.h"
#include "PHYSICS.h"
#include "RENDERSETUP.h"
#include "Header/CORE/C_SCENE.h"
#include "Header/DATATYPES/D_TERRAIN_DATA.h"
#include <typeindex>
#define _INCLUDE_TYPE_
#define _INCLUDE_REFLECTION_
#include "Header/CORE/C_REFLECTION.h"
//#include "Header/CORE/C_BEHAVIOUR.h"
//#include "MESH.h"


bool GameRunning;
class Behaviour;
class Object;
class Input;
class Component;
class Scene;
class Startup;
int i = 10;
 std::unordered_map< std::string ,std::shared_ptr<CORE::Behaviour>> GlobalCompList;

std::shared_ptr<GameObject> SelectedObj;
MESSAGES::Message_Bus* Messagebus;

std::vector<DATATYPES::TS_P_Vector3> VERTS;
bool spawned = false;

PAIN::Shader shader;

CORE::Scene scene;

//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}

void bb() {
	GameObject_ TestObj;
	const  char* pth = "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\GAMEDATA\\untitled.gltf";
	auto mod = COMPONENTS::_Mesh(pth);
	PAIN::Material mat = PAIN::Material(&shader);
	mat.ID = 0;
	PAIN::Render::mats.push_back(mat);
	TestObj = GameObject::Create(DATATYPES::TS_P_Vector3(0, 0, 0), &mod, mat.ID);
	if (mat.ID < PAIN::Render::mats.size() || PAIN::Render::mats.size() == 0) {
		PAIN::Render::mats[mat.ID].objects.push_back(TestObj);
	}
	std::string s = "TESTOBJ";
	s.push_back(i + 48);
	TestObj->name = s;
	i++;
	auto ppp = Test();
	ppp.gameobject = TestObj.get();
	ppp.oobj = TestObj.get();
	void* msc = &ppp;


	TestObj->AddComponent(Test());

	std::cout << "pressed O";


	scene.ObjectsInScene.push_back(TestObj);
	CORE::Behaviour::updateAll();
	spawned = true;
}
/// <summary>
/// basicly obsolete
/// </summary>
/// <param name="window"></param>
void processInput(GLFWwindow* window)
{
	if (CORE::Input::GetKey(A)) {
		std::cout << "pressed A";
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		GameObject_ TestObj;
		const  char* pth = "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\GAMEDATA\\untitled.gltf";
		auto mod = COMPONENTS::_Mesh(pth);
		PAIN::Material mat = PAIN::Material(&shader);
		mat.ID = 0;
		PAIN::Render::mats.push_back(mat);
		TestObj = GameObject::Create(DATATYPES::TS_P_Vector3(0, 0, 0), &mod, mat.ID);
		if (mat.ID < PAIN::Render::mats.size() || PAIN::Render::mats.size() == 0) {
			PAIN::Render::mats[mat.ID].objects.push_back(TestObj);
		}
		std::string s = "TESTOBJ";
		s.push_back(i+48);
		TestObj->name = s;
		i++;


	


		TestObj->AddComponent(Test());

		std::cout << "pressed O";


		scene.ObjectsInScene.push_back(TestObj);
		CORE::Behaviour::updateAll();
		spawned = true;
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


class t {
public:
	 t() {}
	 virtual  void test() {}

};
class tt :public t {
	void test() override {
		Log << "DERIVED TT";
	}
};
class TTT :public t{
	void test() override {
		Log << "DERIVED TTT";
	}
};

/// <summary>
/// Main Function
/// </summary>
/// <returns></returns>
int main()
{


	const WCHAR* addrs = L"C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME.dll";
	HINSTANCE handle = LoadLibrary(addrs);
	typedef void((*externFuction)());
	externFuction Function = (externFuction)symLoad(handle, "MAIN");
	Function();


	auto erer = fact::creators["Test"]();
	auto ooooooooooo = erer.get();
	void* awewe = malloc(sizeof(*erer.get()));
	auto ooooo = memcpy(awewe,erer.get(),sizeof(*erer.get()));
	CORE::Behaviour* bev = (CORE::Behaviour*)ooooo;
	//auto ewt = tt();
	//auto owowo = TTT();
	//
	//std::shared_ptr<t> w = std::make_shared<tt>();
	//std::shared_ptr<t> ewq = std::make_shared<TTT>();
	//ewq->test();
	//w->test();
	//auto instances = BaseFactory::getInstance().createAll();
	int i = fact::creators.size();
	//((auto wewe= fact::creators["Test"]();
	int ia = fact::inst.size();
	//for (auto& aa : fact::creators) {
	//	GlobalCompList[aa.first] = aa.second();
	//}
	auto a =CORE::Filehandler::ApplicationPath();
	Log << "Startup....";


	CORE::SYSTEMS z;
	auto startcfg = CORE::Startup::Configure_Startup();
	CORE::Startup::Init_Startup(startcfg);
	z = CORE::Startup::Start_Systems();
	std::dynamic_pointer_cast<Camera>(PAIN::Render::CAM).get()->FOV = 45;
	scene = CORE::Scene::Create();
	CORE::Scene::activeScene.ObjectsInScene.push_back(std::make_shared<GameObject>(PAIN::RenderStup::Render_cam));
#ifdef DEBUG_Engine
	CORE::Startup::StartEditor(z.windw);

#endif // DEBUG_Engine

	auto aaa = CORE::Filehandler::ApplicationPath() + "\\GAMEDATA";
	shader = PAIN::Shader("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.vs", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.fs");

	//CORE::ConfigLoader::LoadModels(std::filesystem::path(aaa));
	//CORE::ConfigLoader::LoadConfigFiles(std::filesystem::path(aaa));
	//CORE::ConfigLoader::LoadMaterials(std::filesystem::path(aaa));
	std::cout << "Hello World!\n";
	


	//auto a = Terrain_Data::Create("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\GAMEDATA\\UPRISE\\ASSETS\\Map1.png", 512, 512, 100, &shader);
	//PAIN::Render::terrains.push_back(std::make_shared<PAIN::TerrainModel>(a.get()->model));

	//auto aerwe = CORE::ConfigLoader::LoadCOnfigFile("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\GAMEDATA\\UPRISE\\CONFIG\\BUILDINGS\\TEST.CFG");

	//CORE::Type<Test,Test> erererereret;
	//auto aaaa = erererereret._Ptr;
	//CORE::Type<CORE::Behaviour, CORE::Behaviour> trA ( erererereret);
	//auto aaaaaw = trA._Ptr;


	//using twe = decltype(trA.get());


	//auto owo = CORE::Type(Test);
	DATATYPES::TS_P_Vector3 tmp = DATATYPES::TS_P_Vector3(0, 0, 0);

	double lasttime = glfwGetTime();
	while (!glfwWindowShouldClose(z.windw))
	{
		processInput(z.windw);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::ShowDemoWindow();
		{
			ImGui::Begin("TEST");


			ImGui::Text("This is some useful text.");
			if (ImGui::Button("Click Me")) {
				bb(); // Call the function when the button is clicked
			}
			ImGui::End();
		}
		CORE::Behaviour::updateAllAWAKE();
		CORE::Behaviour::updateAllSTART();
		CORE::Behaviour::updateAll();
		PHYSICS::Physics::UpdateAllPhysics();
		if (spawned == true) {
			PAIN::Render::DrawAll();
		}



		if (spawned == true) {
			ImGui::Begin("Editor");

			// Show Scene View
			ImGui::Text("Scene View");
			// Example: Replace with your scene rendering function
			//ImGui::Image((ImTextureID)your_scene_texture_id, ImVec2(500, 500));

			// Show Hierarchy Window
			ImGui::Begin("Hierarchy");

			for (const auto& obj : scene.activeScene.ObjectsInScene) {
				bool isSelected = false; //= (SelectedObj->uuid == &obj->uuid);

				// Highlight the selected item
				if (isSelected) {
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 0.0f, 1.0f)); // Yellow for selected
				}

				// Display the game object name and detect selection
				if (ImGui::Selectable(obj->name.c_str(), isSelected)) {
					SelectedObj = obj; // Update the selected object
				}

				if (isSelected) {
					ImGui::PopStyleColor();
				}
				if (ImGui::TreeNode(obj->name.c_str())) {
					// Display children if necessary
					ImGui::TreePop();
				}
			}
			ImGui::End();

			// Show Inspector Window
			if (SelectedObj) {
				ImGui::Begin("Inspector");
				ImGui::Text("Name: %s", SelectedObj->name.c_str());
				//char buff[100];
				//ImGui::InputText("NAME", SelectedObj->name,0,);
				// char buf1[32] = "template";
				 ImGui::InputText("default", SelectedObj->name.data(), 32);
				 //SelectedObj->name = buf1;
				 //Log << buf1;
				ImGui::Checkbox("Enabled", &SelectedObj->Enabled);
				// Add more properties as needed
				ImGui::DragFloat3("Position", &SelectedObj->TrAnSfOrM->Position.x);
				auto aa = SelectedObj->TrAnSfOrM->rotation.ToRotationVector();
				ImGui::InputFloat3("posa", &aa.x);
				// = SelectedObj->TrAnSfOrM->rotation.ToRotationVector();
				ImGui::SliderFloat3("Rotation", &SelectedObj->TrAnSfOrM->Vec3Rotation.x,-1.5f,1.5f);
				SelectedObj->TrAnSfOrM->SetRotation(SelectedObj->TrAnSfOrM->Vec3Rotation);
				if (ImGui::Button("update position")) {
					tmp = SelectedObj->TrAnSfOrM->rotation.ToRotationVector();
				}
				ImGui::SeparatorText("Components");
				for (auto& cmp : SelectedObj->behaviours) {
					ImGui::Text(cmp->compname.c_str());
					cmp->EditorWindow();
				}
				ImGui::SeparatorText("Add components");
				static bool open;
				if (ImGui::Button("Add Component")) {
			
					open = !open;

				}
				if (open) {
					ImGui::BeginChild("Component List");

					for (auto& a : fact::creators) {

						if (ImGui::Button(a.first.c_str())) {
							//tt te;
							//auto tert = std::make_shared<t>(te);
							// using t =decltype(tert->test());
							// std::any aaa = Test();
							// std::string nm = typeid(t).name();

							//auto a = fact::anys[0].type().name();
							SelectedObj->AddComponent(a.second(),a.first);
						}

					}
					ImGui::EndChild();
				}
				ImGui::End();
			}

			// Show Project Window
			//ImGui::Begin("Project");
			//for (const auto& asset : assets) {
			//	ImGui::Text(asset.c_str());
			//}
			//ImGui::End();

			// Show Toolbar
			ImGui::Begin("Toolbar");
			if (ImGui::Button("Play")) {
				// Toggle play mode
			}
			if (ImGui::Button("Pause")) {
				// Toggle pause mode
			}
			if (ImGui::Button("Stop")) {
				// Stop simulation
			}
			ImGui::End();

			ImGui::End();
		}



		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(z.windw);
		FrameMark;
		glfwPollEvents();
		while (glfwGetTime() < lasttime + 1.0 / 60) {
			// TODO: Put the thread to sleep, yield, or simply do nothing
		}
		lasttime += 1.0 / 60;
	}
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();

	return 0;

}
