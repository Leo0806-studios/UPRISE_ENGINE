// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.

#include "GLINCLUDES.h"
#include "pch.h"
#include "Header/DEBUG/DEBUG_LOGGER.h"
#include "DLL-ENGINE-LINK.h"
#include "scripts/TEST_.h"
#include "Header/RENDER/RENDERSETUP.h"
#include "Header/RENDER/RENDER_MATERIAL.h"
#include "Header/CORE/C_CONFIGLOADER.h"
#include "Header/ECS/ENTITYS/GAMEOBJECT.h"
//#include "Header/CORE/C_SCENE.h	"
#include "C_SCENE.h"
//#include "scripts/Teleport.h"
#include "scripts/Empty.h"
#include "scripts/C_Building.h"
  ;
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

//static Register<Empty> Empty_Register(Empty(), "Empty");

void bb();
struct vecTupple {
	std::vector<int> a, b;
};
extern "C" {
	char* getObj(UUID uuid) {
		return (char*)IMPORTANT::DATA->ACTIVE_SCENE->FindObjectByUUIDP(uuid).get();

	}
	vecTupple GetVarPos(std::string typeName) {
		if (typeName == "C_Building") {
			vecTupple ret;
			ret.a.push_back(offsetof(C_Building, uuID));
			ret.a.push_back(offsetof(C_Building, Name));
			ret.a.push_back(offsetof(C_Building, HP));
			ret.b.push_back(offsetof(C_Building, HP));
			return ret;
		}
	}

	 class  __declspec(dllexport)   test  {
	public:
		int i=1;
		test() {
			i = i;
			std::cout << "mem test" << (int)((long)(void*)(this)+4)<<"\n";
			std::cout << "mem adr of this " << this << " alingof i " << (((int)&(this->i)) - (int)(this)) << "i is " << i << "mem addr of i " << &(this->i) << "\n";
		}
		//std::shared_ptr<test> der;
		static void Prinet() {
			//in->der->prnt();
		}
		virtual void prnt() {
			
		}
	};

	class __declspec(dllexport) Dtest :public test {
	public:
		void prnt()override {
			std::cout << "hello from derived. i is "<<i;
		}
	};
	
}
PAIN::Shader* shader;
int i = 10;
bool shadergood = false;
void bb() {
	GameObject_ TestObj;
	//const  char* pth = "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\GAMEDATA\\untitled.glb";
	//auto mod = COMPONENTS::_Mesh(pth);

	TestObj = GameObject::Create(DATATYPES::TSPVector3(0, 0, 0), DATATYPES::Quaternion(1, 0, 0, 0),std::make_shared<COMPONENTS::_Mesh>( COMPONENTS::_Mesh(PAIN::Render::Modeldict->operator[]("untitled.glb"))),0);
	//if (mat.ID < PAIN::Render::mats->size() || PAIN::Render::mats->size() == 0) {
	//	DATA->AddTORender(PAIN::MiniModel(TestObj->MESH->Model, TestObj->TrAnSfOrM), 0);
	//	;

	//}
	std::string s = "TESTOBJaweadsadawe";
	s.push_back(i + 48);
	TestObj->name = s;
	i++;
	auto ppp = Test();
	ppp.Game_Object = TestObj.get();
	ppp.oobj = TestObj.get();
	void* msc = &ppp;


	TestObj->AddComponent(Test());

	std::cout << "pressed O";


	//CORE::Scene::activeScene->ObjectsInScene.push_back(TestObj);
	CORE::Behaviour::updateAll();
	//spawned = true;
}


extern "C" {
	
	//std::shared_ptr<DATALINK> DATA;
	__declspec(dllexport)void _PRINT() {
		//test::Print(in);
		bb();

		//std::cout << (*(*IMPORTANT::DATA).MATS_LINK)[0].Object_ModelSubstitute.size();
	}
		   __declspec(dllexport)void INITIALIZE(DATALINK* DATA) {
			   if (shadergood == false) {
				   //glfwMakeContextCurrent(DATA->window);
				   //if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
					  // std::cout << "womp womp";;
					  // exit(-1);
				   //}

				   shader = DATA->CreateSHADER("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.vs", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.fs");
				   //DATA->CreateMaterial( shader);

				   
				   shadergood = true;
			   }
			   //for (auto& a : tetsss) {
				  // DATA->creators_LINK->operator[](a()->compname) = a;
			   //}
			   
			    //DATA = std::make_shared<DATALINK>();
		}

		   __declspec(dllexport)void STOP() {
			   int i = CORE::Scene::activeScene->ObjectsInScene.size() - 1;
			   for (; i >= 0; i--) {
				   if (CORE::Scene::activeScene->ObjectsInScene[i]->IsCamera == false) {
					   GameObject::Delete(CORE::Scene::activeScene->ObjectsInScene[i]);

				   }
			   }
			   CORE::Scene::activeScene->ObjectsInScene.clear();

		   }
		   __declspec(dllexport)void _CREATE() {
			  // auto a = new test();
			   //std::cout << "mem adr of this " << a << " alingof i " << (((int)&(a->i)) - (int)(a)) << "i is " << a->i << "mem addr of i " << &(a->i) << "\n";
			  // a->der = std::make_shared< Dtest>();
			   //return a;
		   }

	

}
extern "C" {
	__declspec(dllexport) DATALINK* GetDatabase()
	{
		IMPORTANT::DATA->CAM =PAIN::Render::CAM;
		IMPORTANT::DATA->RenderCam =PAIN::Render::RenderCam;
		//DATA->VOID_OBJECTS_LINK =&PAIN::Render::voidobjects;
		//DATA->PTR_OBJECTS_LINK =&PAIN::Render::ptrobjects;
		//DATA->OBJECT_LINK =&PAIN::Render::objects;
		IMPORTANT::DATA->TERRAIN_LINK =PAIN::Render::terrains;
		//DATA->MATS_LINK =PAIN::Render::mats;
		IMPORTANT::DATA->M_DICT_LINK =PAIN::Render::Modeldict;
		IMPORTANT::DATA->M_ID_LINK =PAIN::Render::MaterialIdLinkDict;

		return IMPORTANT::DATA;
	}
	__declspec(dllexport) void SetDatabase(DATALINK* in) {

		IMPORTANT::DATA = in;
		(*IMPORTANT::DATA->creators) = *fact::links;

		PAIN::Render::CAM = in->CAM;
		PAIN::Render::RenderCam = in->RenderCam;
		PAIN::RenderStup::Windowvar = in->window;
		CORE::Scene::activeScene = in->ACTIVE_SCENE;
		CORE::Scene::Backups_SCENE = in->Backups_SCENE;
		//PAIN::Render::voidobjects = *in->VOID_OBJECTS_LINK;
		//PAIN::Render::ptrobjects = *in->PTR_OBJECTS_LINK;
		//PAIN::Render::objects = *in->OBJECT_LINK;
		if(in->TERRAIN_LINK  )PAIN::Render::terrains =in->TERRAIN_LINK;
		if(in->MATS_LINK)PAIN::Render::mats = in->MATS_LINK;
		if(in->M_DICT_LINK)PAIN::Render::Modeldict = in->M_DICT_LINK;
		if(in->M_ID_LINK)PAIN::Render::MaterialIdLinkDict = in->M_ID_LINK;
		if(in->ConfigDatabase_LINK)CORE::ConfigLoader::ConfigDatabase = in->ConfigDatabase_LINK;

//		factT::creators = IMPORTANT::DATA->creators_LINK;
		CORE::Input::Init(in->window);
		//factT::inst = IMPORTANT::DATA->inst_LINK;
		//AddTORender = in->AddTORender;
	}

}
extern "C" {
	__declspec(dllexport) void BEHAVIOUR_UPDATE() {
		CORE::Behaviour::updateAll();

	}
	__declspec(dllexport) void BEHAVIOUR_UPDATE_AWAKE() {
		CORE::Behaviour::updateAllAWAKE();

	}
	__declspec(dllexport) void BEHAVIOUR_UPDATE_START() {
		CORE::Behaviour::updateAllSTART();

	}
	__declspec(dllexport) void PHYSICS_UPDATE() {
		PHYSICS::Physics::UpdateAllPhysics();

	}
	__declspec(dllexport) void DRAW_EDITOR() {

	}
}

