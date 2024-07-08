#pragma once
#ifndef _STARTUP_
#define _STARTUP_

//#include "CPUFEATURES.h"
#include "DATATYPES.h"
#include "MESSAGES.h"
#include "pch.h"
#include "PHYSICS.h"
#include "RENDER.h"
//#include "thread"
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
		static DATATYPES::Startup_Config Configure_Startup();
		static void Init_Startup(DATATYPES::Startup_Config config);
		static SYSTEMS  Start_Systems();

		static void Start_Game();

	};
}

#endif // !_STARTUP_
