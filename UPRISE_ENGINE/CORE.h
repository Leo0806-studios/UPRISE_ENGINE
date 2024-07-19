#ifndef _CORE_
#define _CORE_
#include "pch.h"

#include "INPUT.h"
#include "CPUFEATURES.h"
#include "STARTUP.h"
#include "COMPONENT.h"
#include "OBJECT.h"

#include "BEHAVIOUR.h"
#include "THREADING.h"
//#include "TS_P_VECTOR3.h"

namespace CORE {
	
	class Behaviour;
	class Object;
	class Input;
	class Component;
	class Scene;
	class Startup;

	class Core {
		 
		

	};


	class Filehandler {

	private:
		static std::string Application_Path;
		static bool yes;

	public:

		static std::string ApplicationPath();
	};


	 class Applicytion {


	};
}

#endif // !_CORE_
