#pragma once
#ifndef _OBJECT_
#define _OBJECT_
#include "pch.h"
#include "MODULE_IMPORTS.h"

class Component;
namespace CORE {

	class Object {

	public :
		Object();
		virtual ~Object();;
		void DestroyObj(Object* obj);
		UUID uuid;
  };


}

#endif // !_OBJECT_
