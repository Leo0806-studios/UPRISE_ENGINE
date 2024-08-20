// UPRISE_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#pragma comment(linker, "/manifestdependency:\"name='Dll' version='1.0.0.0' type='win32'\"")

//#import "ManagedUtills.tlb" named_guids



#define TRACY_IMPORTS
#include "DEBUG_LOGGER.h"

#include "GLINCLUDES.h"
#include "pch.h"
//#include "glad.h"
//#include "glfw3.h"
//#include "pch.h"
//#include "Helpers.h"
#include "HeaderE/CORE/CORE.h"
#include "HeaderE/DATATYPES/D_DATATYPES.h"

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
#include "ECS.h"
#include "RENDER.h"
//#include "RENDER_DATATYPES.h"
//#include "RENDER_OBJECT_SPAWNING.h"
#include "MESSAGES.h"
//#include "HeaderE/CORE/CORE.h"
//#include "INPUT.h"
//#include "memory"
#include "TEST.h"
#include "RENDER_MATERIAL.h"
#include "PHYSICS.h"
#include "RENDERSETUP.h"
#include "HeaderE/CORE/C_SCENE.h"
#include "HeaderE/DATATYPES/D_TERRAIN_DATA.h"
#include <typeindex>
#define _INCLUDE_TYPE_
#define _INCLUDE_REFLECTION_
#include "HeaderE/CORE/C_REFLECTION.h"
#include "DLL-ENGINE-LINK.h"
#include <HeaderE/CORE/C_CONFIGLOADER.h>
#include "new"
#include "EDITOR.h"
#include "tracy/TracyOpenGL.hpp"
#include "D_MAT4.h"
//#include "C_SMART_POINTER.h"
//#include "HeaderE/CORE/C_BEHAVIOUR.h"
//#include "MESH.h"


extern "C" {
	// Math library functions
	 float extern dot_product(const float* a, const float* b, int* n);
	//extern void cross_product(const float* a, const float* b, float* c);
	//extern void matrix_multiply(const float* a, const float* b, float* c, int* m, int* n, int* p);

	// Physics system functions
	//extern void update_position(float* positions, const float* velocities, float* dt, int* n);
}
#define FUNC(x,y,z)(x)GetProcAddress(y,z);
//DATALINK* DATA;
bool GameRunning;
class Behaviour;
class Object;
class Input;
class Component;
class Scene;
class Startup;
int i = 10;
 std::unordered_map< std::string ,std::shared_ptr<CORE::Behaviour>> GlobalCompList;

MESSAGES::Message_Bus* Messagebus;

std::vector<DATATYPES::TSPVector3> VERTS;
bool spawned = false;

PAIN::Shader shader;

CORE::Scene scene;

//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}


void bb() {
	GameObject_ TestObj;
	const  char* pth = "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\GAMEDATA\\untitled.glb";
	auto mod = COMPONENTS::_Mesh(pth);
	PAIN::Material mat = PAIN::Material(&shader);
	mat.ID = 0;
	PAIN::Render::mats.push_back(mat);
	TestObj = GameObject::Create(DATATYPES::TSPVector3(0, 0, 0), &mod, mat.ID);
	if (mat.ID < PAIN::Render::mats.size() || PAIN::Render::mats.size() == 0) {
		PAIN::Render::mats[mat.ID].objects.push_back(TestObj);
	}
	std::string s = "TESTOBJ";
	s.push_back(i + 48);
	TestObj->name = s;
	i++;
	auto ppp = Test();
	ppp.Game_Object = TestObj.get();
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
		TestObj = GameObject::Create(DATATYPES::TSPVector3(0, 0, 0), &mod, mat.ID);
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

void IncreasePlot(const char* name,int val) {
	TracyCPlot(name, val);
}
void DecreasePlot(const char* name, int val) {
	TracyCPlot(name, val);

}
class t {
public:
	int i;
	 t() {}
	 virtual  void test() {}

};
class tt :public t {
	void test() override {
		i = 5;
		Log << "DERIVED TT";
	}
};
class TTT :public t{
	void test() override {
		Log << "DERIVED TTT";
	}
};
class   test {
public :
	int i;

	static void Print(test* in){

	}
	virtual void prnt() {

	}
};
class e : public test {
public:
	void prnt()override {
		std::cout << "hello from derived. i is " << i;
	}
};

PAIN::Shader* CreateSHADER(const char* vertexPath, const char* fragmentPath) {

	PAIN::Shader* ret = new PAIN::Shader(vertexPath, fragmentPath);
	return ret;
}
void AddTORender(std::shared_ptr<PAIN::MiniModel> mm, int id) {
	PAIN::Render::mats[id].Object_ModelSubstitute.push_back(mm);
}
bool RemoveFromRender(std::shared_ptr<PAIN::MiniModel>& mm,int Material_ID) {
	auto index = std::find(PAIN::Render::mats[Material_ID].Object_ModelSubstitute.begin(), PAIN::Render::mats[Material_ID].Object_ModelSubstitute.end(), mm);
	PAIN::Render::mats[Material_ID].Object_ModelSubstitute.erase(index);
	PAIN::Render::Check_Removed = true;
	return true;
}
bool CreateMaterial(PAIN::Shader*  shader) {
	PAIN::Material mat = PAIN::Material(shader);
	mat.ID = 0;
	PAIN::Render::mats.push_back(mat);
	return true;
}
/// <summary>
/// Main Function
/// </summary>
/// <returns></returns>
int main()
{
	

	float aW[] = { 1.0, 2.0, 3.0 };
	float bW[] = { 4.0, 5.0, 6.0 };
	int nW = 3;
	float cW[3];
	float result = dot_product(aW, bW, &nW);
	std::cout << "Dot product: " << result << std::endl;

	Mat4 matf(1);
	std::cout << "mem adr of this " << &matf << " alingof i " << (((int)&(matf.row0)) - (int)(&matf))  << "mem addr of i " << &(matf.row0) << "\n";

	auto mm = matf[0];
	Log << mm.m128_f32[0] << " " << mm.m128_f32[1] << " " << mm.m128_f32[2] << " " << mm.m128_f32[3] << " \n";
	 mm = matf[1];
	Log << mm.m128_f32[0] << " " << mm.m128_f32[1] << " " << mm.m128_f32[2] << " " << mm.m128_f32[3] << " \n";
	mm = matf[2];
	Log << mm.m128_f32[0] << " " << mm.m128_f32[1] << " " << mm.m128_f32[2] << " " << mm.m128_f32[3] << " \n";
	mm = matf[3];
	Log << mm.m128_f32[0] << " " << mm.m128_f32[1] << " " << mm.m128_f32[2] << " " << mm.m128_f32[3] << " \n";



//	std::shared_ptr<tt> tptr = std::make_shared<tt>();
	//std::shared_ptr<t> tpter = tptr;
//	tt* chk;
//	{
//		auto tster = UTILLS::Make_Shared<tt>();
////		auto roererw = tster.GT();
//		//chk = tster.Pointer;
//		{
//			UTILLS::Shared_ptr<t> testst = tster;
//			{
//				auto ererwrwerw = testst;
//				Log << ererwrwerw.ref_block->ref_cout;
//				Log << tster.ref_block->ref_cout;
//
//			}
//			testst->test();
//			Log << tster.ref_block->ref_cout;
//
//		}
//		Log << tster.ref_block->ref_cout;
//	}
	//Log << chk->i;
	///Log << chk->i;
	IMPORTANT::LINK = new DATALINK();

	IMPORTANT::mode = GameMode::GameMode_Stoped;
	std::remove("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME_LOADED.dll");

	




	auto a =CORE::Filehandler::ApplicationPath();
	Log << "Startup....";


	CORE::SYSTEMS z;
	auto startcfg = CORE::Startup::Configure_Startup();
	CORE::Startup::Init_Startup(startcfg);
	z = CORE::Startup::Start_Systems();
	std::dynamic_pointer_cast<Camera>(PAIN::Render::CAM).get()->FOV = 45;
	scene = CORE::Scene::Create();
	CORE::Scene::activeScene.setPTR(&CORE::Scene::activeScene_obj);
	CORE::Scene::Backups_SCENE.setPTR(&CORE::Scene::Backups_SCENE_obj);
	CORE::Scene::activeScene->ObjectsInScene.push_back(std::make_shared<GameObject>(PAIN::RenderStup::Render_cam));
#ifdef DEBUG_Engine
	CORE::Startup::StartEditor(z.windw);

#endif // DEBUG_Engine

	auto aaa = CORE::Filehandler::ApplicationPath() + "\\GAMEDATA";
	shader = PAIN::Shader("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.vs", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.fs");

	CORE::ConfigLoader::LoadModels(std::filesystem::path(aaa));
	CORE::ConfigLoader::LoadConfigFiles(std::filesystem::path(aaa));
	CORE::ConfigLoader::LoadMaterials(std::filesystem::path(aaa));
	std::cout << "Hello World!\n";

	DATATYPES::TSPVector3 tmp = DATATYPES::TSPVector3(0, 0, 0);

	double lasttime = glfwGetTime();
	IMPORTANT::LINK->CAM = PAIN::Render::CAM;
	IMPORTANT::LINK->RenderCam = PAIN::Render::RenderCam;
	//DATA->VOID_OBJECTS_LINK =&PAIN::Render::voidobjects;
	//DATA->PTR_OBJECTS_LINK =&PAIN::Render::ptrobjects;
	//DATA->OBJECT_LINK =&PAIN::Render::objects;
	IMPORTANT::LINK->TERRAIN_LINK = std::make_shared<decltype(PAIN::Render::terrains)>(PAIN::Render::terrains);
	IMPORTANT::LINK->MATS_LINK = std::make_shared<std::vector<PAIN::Material>>(PAIN::Render::mats);
	IMPORTANT::LINK->M_DICT_LINK = std::make_shared<decltype(PAIN::Render::Modeldict)>(PAIN::Render::Modeldict);
	IMPORTANT::LINK->M_ID_LINK = std::make_shared<decltype(PAIN::Render::MaterialIdLinkDict)>(PAIN::Render::MaterialIdLinkDict);
	IMPORTANT::LINK->ACTIVE_SCENE = CORE::Scene::activeScene;
	IMPORTANT::LINK->window = PAIN::RenderStup::Windowvar;
	IMPORTANT::LINK->CreateSHADER = CreateSHADER;
	IMPORTANT::LINK->AddTORender = AddTORender;
	IMPORTANT::LINK->ConfigDatabase_LINK = std::make_shared<std::unordered_map<ConfigFile::ConfigType, std::unordered_map <std::string, std::shared_ptr<ConfigFile>>>>(CORE::ConfigLoader::ConfigDatabase);
	IMPORTANT::LINK->RemoveFromRender = RemoveFromRender;
	IMPORTANT::LINK->CreateMaterial = CreateMaterial;
	using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;

	IMPORTANT::LINK->creators_LINK = std::make_shared<std::map<std::string, CreatorFunc>>(fact::creators);
	
	IMPORTANT::LINK->inst_LINK = std::make_shared<decltype(fact::inst)>(fact::inst);
	IMPORTANT::LINK->III = (int*)& fact::inst;
	IMPORTANT::LINK->GetKey = CORE::Input::GetKey;
	IMPORTANT::LINK->PLOTADD = IncreasePlot;
	IMPORTANT::LINK->PLOTREMOVE = DecreasePlot;
	//auto llllll = std::make_shared<std::unordered_map<ConfigFile::ConfigType, std::unordered_map <std::string, std::shared_ptr<ConfigFile>>>>(CORE::ConfigLoader::ConfigDatabase);
	//DATA->ConfigDatabase_LINK = llllll;
/*	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenFramebuffers(1, &PAIN::Render::FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, PAIN::Render::FBO);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0)*/;


	while (!glfwWindowShouldClose(z.windw))
	{
		processInput(z.windw);
		//glBindFramebuffer(GL_FRAMEBUFFER, PAIN::Render::FBO);
		//TracyGpuNamedZone(ctxgpu, "DRAW", true);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glBindFramebuffer(GL_FRAMEBUFFER, 0);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		TrPr(ctx, "Script Update")
		if (IMPORTANT::mode == GameMode::GameMode_Play) {
			IMPORTANT::B_Up();
			IMPORTANT::B_Up_A();
			IMPORTANT::B_Up_S();
		}
		TrPrE(ctx)
		CORE::Behaviour::updateAllAWAKE();
		CORE::Behaviour::updateAllSTART();
		CORE::Behaviour::updateAll();
		PHYSICS::Physics::UpdateAllPhysics();
		//if (spawned == true) {
			//glBindFramebuffer(GL_FRAMEBUFFER, PAIN::Render::FBO);
		TrPr(ctx1,"Draw Scene")
			PAIN::Render::DrawAll();
			//glBindFramebuffer(GL_FRAMEBUFFER, 0);
		TrPrE(ctx1)
		//}
		TrPr(ctx2, "Draw Editor")
		EDITOR::Editor::DrawEditor();
		TrPrE(ctx2)
			//auto text = buffer;
		//{
		//	ImGui::Begin("SCENE");
		//	ImVec2 wsize = ImGui::GetWindowSize();
		//	ImGui::Image((ImTextureID)texture, wsize, ImVec2(0, 1), ImVec2(1, 0));
		//	//ImGui::GetWindowDrawList()->AddImage((void*)texture, ImVec2((float)(ImGui::GetCursorScreenPos().x + (float)(1600 / 2)), ImGui::GetCursorScreenPos().y + (float)(900 / 2)), ImVec2(0, 1), ImVec2(1, 0));
		//	ImGui::End();
		//}
		if (CORE::Input::GetKey(B)) {

			//Function();
			IMPORTANT::PRINT();
			//test ttErerewr;
			//memcpy(&ttErerewr, inst, sizeof(test));
			//int* tp = (int*)inst;
			//Log << *tp << "  " << tp << "\n";
			//tp = (int*)inst+1;
			//Log << *tp << "  " << tp << "\n";;
			//tp = (int*)inst+2;
			//Log <<*tp  <<"  "<<tp << "\n";
			////Log << *((int*)((long*)inst + 8)) << "  " << ((int*)inst + 8) << "\n";
			//tp = (int*)inst+3;
			//Log << *tp << "  " << tp << "\n";
			//tp = (int*)inst+4;
			//Log << *tp << "  " << tp << "\n";
			//tp = &((test*)inst)->i;
			//Log << *tp << "  " << tp << "\n";

		}

		


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		//if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		//{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		//}
		glfwSwapBuffers(z.windw);
		//TracyGpuCollect;
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
	std::remove("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\ENGINE\\UPRISE_GAME_LOADED.dll");
	return 0;

}
