#pragma once
#ifndef _OPENGL_WINDOW_
#define _OPENGL_WINDOW_
#include "RENDER_COMMON/WINDOW_BASE/WINDOW_BASE.h"
class OPENGL_WINDOW:public WINDOW_BASE {
private:
public:
	OPENGL_WINDOW() = default;
	~OPENGL_WINDOW(){}


	RefWrapper<WINDOW_BASE, true> CreateWindow(int w, int h, const char* Title) override;
};
#endif // !_OPENGL_WINDOW_
//implementation of OPENGL_WINDOW