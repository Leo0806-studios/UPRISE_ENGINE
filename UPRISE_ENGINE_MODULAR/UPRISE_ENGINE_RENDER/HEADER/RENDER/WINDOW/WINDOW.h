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
            OwnedRef<RENDER_COMMON::WINDOW_BASE> Windowvar;
        public:
            Window() = default;
            Window(const Window&) = delete;
            Window(Window&& other) :Windowvar(std::move(other.Windowvar)) {
            }
            Window& operator=(const Window&) = delete;
            Window& operator=(Window&& other) {
                Windowvar = std::move(other.Windowvar);
                return *this ;
            }
            UPRISE_RENDER_API  inline void SetWindow(OwnedRef<RENDER_COMMON::WINDOW_BASE> window) {

                SCOPED_TIME_
                    Windowvar = std::move(window);
            }
            UPRISE_RENDER_API inline WeakRef<RENDER_COMMON::WINDOW_BASE, true> GetInternalWeakRef() {
                return Windowvar.GetWeakRef();
            }
            UPRISE_RENDER_API static  OwnedRef<RENDER_COMMON::WINDOW_BASE> _CreateWindow(int w, int h, const char* title);
            UPRISE_RENDER_API static  void DestroyWindow(WeakRef<Window,true> window);
            UPRISE_RENDER_API void DisplayFpsInWindowTitle(double Fps, std::string BaseTitle);
        };
    }

}



#endif // !_WINDOW_