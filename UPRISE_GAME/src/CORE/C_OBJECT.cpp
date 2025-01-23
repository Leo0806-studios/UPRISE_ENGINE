// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#include "pch.h"
#include "Header/CORE/C_OBJECT.h"


namespace CORE {







	 Object::Object() {}

	 Object::~Object() {

	}

	 void Object::DestroyObj(Object* obj) {
		free(obj);
	}

}