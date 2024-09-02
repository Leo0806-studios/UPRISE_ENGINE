#pragma once
#ifndef _NEED_
#define _NEED_
#include "pch.h"
#include "MODULE_IMPORTS.h"
enum NEED_TYPE {
	NEED_TYPE_Consumable,
	NEED_TYPE_Building
};
class Need {
public:
	std::string Name;
	NEED_TYPE Need_Type;

};
#endif