#pragma once
#ifndef _TAG_LAYERS_
#define _TAG_LAYERS_
#include "pch.h"
class Tag {
public:
	Tag() = default;
	Tag(int id, std::string name);
};
class Layer {
public:
	Layer() = default;
	Layer(int id, std::string name);
};
#endif // !_TAG_LAYERS_
