#include "HeaderE/CORE/C_STARTUP.h"
#include "HeaderE/DATATYPES/D_DATATYPES.h"
#include "MESSAGES.h"
#include "pch.h"
#include "PHYSICS.h"
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
	ImGui::CreateContext();
	 io = &ImGui::GetIO();
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	ImGui_ImplGlfw_InitForOpenGL(Window, true);
	ImGui_ImplOpenGL3_Init();
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
	MESSAGES::Message_Bus bus = MESSAGES::Message_Bus();
	bus.Exists = true;
	sys.Bus = &bus; 
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