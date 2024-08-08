#ifndef _CORE_
#define _CORE_
#include "pch.h"

#include "Header/CORE/C_INPUT.h"
#include "Header/CORE/C_CPUFEATURES.h"
#include "Header/CORE/C_STARTUP.h"
#include "Header/CORE/C_COMPONENT.h"
#include "Header/CORE/C_OBJECT.h"

#include "Header/CORE/C_BEHAVIOUR.h"
#include "C_THREADING.h"
//#include "Header/DATATYPES/D_TS_P_VECTOR3.h"

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
