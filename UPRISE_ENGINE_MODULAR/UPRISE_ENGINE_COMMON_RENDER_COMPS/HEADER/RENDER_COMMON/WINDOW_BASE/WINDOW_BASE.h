#pragma once
#ifndef _WINDOW_BASE_
#define _WINDOW_BASE_
import REF_WRAPPER;
class WINDOW_BASE {
private:
public:
	WINDOW_BASE() = default;
	~WINDOW_BASE(){}

#pragma region Virtual funcs

    virtual RefWrapper<WINDOW_BASE,true> CreateWindow(int w, int h, const char* Title) = 0;
    virtual void DestroyWindow() = 0;
    virtual void SetWindowShouldClose() = 0;
     

#pragma endregion

};
#endif // !_WINDOW_BASE_
