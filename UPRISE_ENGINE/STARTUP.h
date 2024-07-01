#pragma once
#include "CPUFEATURES.h"
#include "DATATYPES.h"
#include "MESSAGES.h"
#include "PHYSICS.h"
#include "RENDER.h"
#include "sysinfoapi.h"
#include "thread"
namespace CORE {
	struct SYSTEMS {
	public:
		MESSAGES::Message_Bus* Bus;
		PAIN::Render* Render;
		PHYSICS::Physics* Physics;


	};
	static class Startup {

	private:


	public:

		static DATATYPES::Startup_Config STARTUP_CONFIG;
		static bool StartupComplete;
		static DATATYPES::Startup_Config Configure_Startup() {
			if (StartupComplete == true) {


			}

			DATATYPES::Startup_Config Config;
			Config.CPU_Cores = std::thread::hardware_concurrency();
			Config.Supports_AVX = CORE::InstructionSet::AVX;
			Config.Supports_AVX2 = CORE::InstructionSet::AVX2;
			PULONGLONG ram;
			GetPhysicallyInstalledSystemMemory(ram);
			Config.RAMbytes = *ram;
			Config.RenderMode = 0;
			STARTUP_CONFIG = Config;

			return Config;

		}
		static void Init_Startup(DATATYPES::Startup_Config config) {}
		static SYSTEMS  Start_Systems() {

			SYSTEMS sys;
			MESSAGES::Message_Bus bus = MESSAGES::Message_Bus();
			bus.Exists = true;
			sys.Bus = &bus;
			return sys;

		}

		static void Start_Game(){}

	};
}