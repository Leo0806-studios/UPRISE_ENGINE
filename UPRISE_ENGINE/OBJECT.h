#pragma once

#include "COMPONENT.h"
#include "CORE.h"
#include"DATATYPES.h"
//#include "GAMEOBJECT.h"
namespace CORE {

	class Object {

	public :
		Object() {};
		virtual ~Object() {
		
		};
		void DestroyObj(Object* obj) {
			free(obj);
		}
  };


}