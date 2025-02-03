// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_WINDOW_
#define UE_WINDOW_
import REF_WRAPPER; //-V2575 //-V3549
import std; //-V3549 //-V2575
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {
        class WINDOW_BASE;
    }

    namespace RENDER {
        class Window {
        private:
            RefWrapper<RENDER_COMMON::WINDOW_BASE, true> Windowvar;
        public:
            UPRISE_RENDER_API  inline void SetWindow(RefWrapper<RENDER_COMMON::WINDOW_BASE, true> window) {

                SCOPED_TIME_
                Windowvar = window;
            }
            UPRISE_RENDER_API static inline RefWrapper<RENDER_COMMON::WINDOW_BASE, true> _CreateWindow(int w, int h, const char* title);
            UPRISE_RENDER_API static inline void DestroyWindow(RefWrapper<Window, true> window);
        };
    }

}



#endif // !_WINDOW_