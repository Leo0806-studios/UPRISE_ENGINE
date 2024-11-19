#pragma once
#ifndef _OPENGL_BACKEND_
#define _OPENGL_BACKEND_
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
class OPENGL_BACKEND : public RENDER_BACKEND{
private:
public:
	OPENGL_BACKEND() = default;
	~OPENGL_BACKEND(){}
};
#endif // !_OPENGL_BACKEND_
