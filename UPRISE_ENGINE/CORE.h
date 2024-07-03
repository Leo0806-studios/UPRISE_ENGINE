#pragma once
#include "BEHAVIOUR.h"
#include "COMPONENT.h"
#include "INPUT.h"
#include "OBJECT.h"
#include "pch.h"
#include "SCENE.h"
#include "STARTUP.h"
//#include "TS_P_VECTOR3.h"
namespace CORE {
	


	class Core {
		 
		

	};


	class Filehandler {

	private:
		std::string Application_Path;

	public:

		std::string ApplicationPath() {

			if (Application_Path.data() == NULL) {


				Application_Path = std::filesystem::current_path().string();
			}
		}
	};


	static class Applicytion {


	};
}