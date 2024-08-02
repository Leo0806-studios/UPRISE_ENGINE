#pragma once
#ifndef _STARTUP_
#define _STARTUP_

//#include "CPUFEATURES.h"
#include "DATATYPES.h"
#include "MESSAGES.h"
#include "pch.h"
#include "PHYSICS.h"
#include "RENDER.h"
#include "CONFIGLOADER.h"

//#include "thread"
namespace CORE {
	struct SYSTEMS {
	public:
		static GLFWwindow* windw;
		MESSAGES::Message_Bus* Bus;
		bool Render;


	};
	 class Startup {

	private:


	public:

		static DATATYPES::Startup_Config STARTUP_CONFIG;
		static bool StartupComplete;
		static DATATYPES::Startup_Config Configure_Startup();
		static void StartEditor(GLFWwindow* window);
		static void Init_Startup(DATATYPES::Startup_Config config);
		static SYSTEMS  Start_Systems();
		static ImGuiIO* io;

		static void Start_Game();

	};
}

#endif // !_STARTUP_
