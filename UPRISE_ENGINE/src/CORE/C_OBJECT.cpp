#pragma once
#include "pch.h"
#include "HeaderE/CORE/C_OBJECT.h"


namespace CORE {







	 Object::Object() {}

	 Object::~Object() {

	}

	 void Object::DestroyObj(Object* obj) {
		free(obj);
	}

}