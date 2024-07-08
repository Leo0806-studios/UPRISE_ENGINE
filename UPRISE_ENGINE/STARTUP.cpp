#include "STARTUP.h"
#include "DATATYPES.h"
#include "MESSAGES.h"
#include "pch.h"
#include "PHYSICS.h"
#include "RENDER.h"


bool CORE::Startup::StartupComplete;
DATATYPES::Startup_Config CORE::Startup::STARTUP_CONFIG;

DATATYPES::Startup_Config CORE::Startup::Configure_Startup() {

	if (StartupComplete == true) {


	}

	DATATYPES::Startup_Config Config;
	//Config.CPU_Cores = std::thread::hardware_concurrency();
	//Config.Supports_AVX = CORE::InstructionSet::AVX;
	//Config.Supports_AVX2 = CORE::InstructionSet::AVX2;
	PULONGLONG ram=0;
	GetPhysicallyInstalledSystemMemory(ram);
	Config.RAMbytes = *ram;
	Config.RenderMode = 0;
	STARTUP_CONFIG = Config;

	return Config;
}
void CORE::Startup::Init_Startup(DATATYPES::Startup_Config config) {

}
CORE::SYSTEMS CORE::Startup::Start_Systems() {
	SYSTEMS sys;
	MESSAGES::Message_Bus bus = MESSAGES::Message_Bus();
	bus.Exists = true;
	sys.Bus = &bus;

	return sys;
}