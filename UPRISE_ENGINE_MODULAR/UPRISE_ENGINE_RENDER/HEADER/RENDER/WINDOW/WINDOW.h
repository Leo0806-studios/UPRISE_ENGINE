// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _WINDOW_
#define _WINDOW_
import REF_WRAPPER;
import std;
namespace RENDER_COMMON {
    class WINDOW_BASE;
}

namespace RENDER {
    class Window {
    private:
         RefWrapper<RENDER_COMMON::WINDOW_BASE, true> Windowvar;
    public:
        UPRISE_RENDER_API  inline void SetWindow(RefWrapper<RENDER_COMMON::WINDOW_BASE, true> window) {
            Windowvar = window;
        }
        UPRISE_RENDER_API static inline RefWrapper<RENDER_COMMON::WINDOW_BASE, true> _CreateWindow(int w, int h, const char* title);
        UPRISE_RENDER_API static inline void DestroyWindow(RefWrapper<Window, true> window);
    };
}



#endif // !_WINDOW_