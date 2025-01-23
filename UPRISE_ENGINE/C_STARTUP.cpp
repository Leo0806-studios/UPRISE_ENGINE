// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "MISC.h"
#include "pch.h"

#include "MODULE_IMPORTS.h"
//#include "MODULE_IMPORTS.h"

#include "HeaderE/CORE/C_STARTUP.h"

#include "HeaderE/DATATYPES/D_DATATYPES.h"
//#include "MESSAGES.h"
//#include "PHYSICS.h"
#include "HeaderE/CORE/C_CPUFEATURES.h"
#include "RENDERSETUP.h"
#include "DEBUG_LOGGER.h"

bool CORE::Startup::StartupComplete;
DATATYPES::Startup_Config CORE::Startup::STARTUP_CONFIG;
GLFWwindow* CORE::SYSTEMS::windw;
ImGuiIO* CORE::Startup::io;

DATATYPES::Startup_Config CORE::Startup::Configure_Startup() {
	TracyCZoneN(ctx, "Configure Startup", true);

	if (StartupComplete == true) {


	}
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);

	GlobalMemoryStatusEx(&statex);

	DATATYPES::Startup_Config Config;
	Log << "getting Hardware supports...";
	Config.CPU_Cores = std::thread::hardware_concurrency();
	Log<<"	- CPU Threads: " << Config.CPU_Cores;
	Config.Supports_AVX = CORE::InstructionSet::AVX;
	Log<<"	- AVX support :" << Config.Supports_AVX;
	Config.Supports_AVX2 = CORE::InstructionSet::AVX2;
	Log<<"	- AVX2 support :" << Config.Supports_AVX2;
	PULONGLONG* ram=0;
	//GetPhysicallyInstalledSystemMemory(*ram);
	Config.RAMbytes = statex.ullTotalPhys;;
	Log<<"	- innstalled Ram :" << Config.RAMbytes;
	Log<<"	- Setting Rennder to OpenGL (0)";
	Config.RenderMode = 0;
	STARTUP_CONFIG = Config;
	Log<<"	- Connfig finished";
	Log<<"	- returnning...";
	TracyCZoneEnd(ctx);

	return Config;
}
void CORE::Startup::StartEditor(GLFWwindow* Window)
{
	TracyCZoneN(ctx, "Startup Editor", true);

	IMGUI_CHECKVERSION();
	auto ctxx =ImGui::CreateContext();
	 io = &ImGui::GetIO();
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; 
	io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Gamepad Controls
	ImGui_ImplGlfw_InitForOpenGL(Window, true);
	ImGui_ImplOpenGL3_Init();
	std::rename("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\EDITOR\\UPRISE_EDITOR.dll", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\UPRISE\\EDITOR\\UPRISE_EDITOR_LOADED.dll");
	
	EDITOR_IMPORTANT::EDITORHANDLE= LoadLibrary(EDITOR_IMPORTANT::addrs);
	if (!EDITOR_IMPORTANT::EDITORHANDLE) {
		Log << "EDITOR DLL FAILED TO LOAD";
	}
#define FUNCH(x,y,z)(EDITOR_IMPORTANT::x)GetProcAddress(EDITOR_IMPORTANT::y,z);
	EDITOR_IMPORTANT::init_EDITOR = (EDITOR_IMPORTANT::INIT)GetProcAddress(EDITOR_IMPORTANT::EDITOR_IMPORTANT::EDITORHANDLE, "INIT");;
	EDITOR_IMPORTANT::Shutdown_Editor = FUNCH(SHUTDOWN, EDITOR_IMPORTANT::EDITORHANDLE, "SHUTDOWN");
	EDITOR_IMPORTANT::Draw_EDITOR = FUNCH(DRAW, EDITOR_IMPORTANT::EDITORHANDLE, "DRAW");
	EDITOR_IMPORTANT::init_EDITOR(ctxx);
	TracyCZoneEnd(ctx);

}
void CORE::Startup::Init_Startup(DATATYPES::Startup_Config config) {
	TracyCZoneN(ctx, __FUNCTION__, true);

	Log << "Init Startup...";
	TracyCZoneEnd(ctx);


}
CORE::SYSTEMS CORE::Startup::Start_Systems() {
	//const ZoneNamedN(startup, "Startup", true);
	TracyCZoneN(ctx, "startig Systems", true);

	Log << "startig Systems...";
	SYSTEMS sys;
	Log << "	- Starting Message Bus";
	//MESSAGES::Message_Bus bus = MESSAGES::Message_Bus();
	//bus.Exists = true;
	//sys.Bus = &bus; 
	Log << "	- Message Bus started.";
	Log << "	- Startig Render";
	PAIN::RenderStup::Setup(1920, 1080, "UPRISE");
	Log << "	- Started Render";
	sys.windw = PAIN::RenderStup::Windowvar;
	Log << "	- Init Input System";
	CORE::Input::Init(PAIN::RenderStup::Windowvar);
	TracyCZoneEnd(ctx);
	return sys;
}