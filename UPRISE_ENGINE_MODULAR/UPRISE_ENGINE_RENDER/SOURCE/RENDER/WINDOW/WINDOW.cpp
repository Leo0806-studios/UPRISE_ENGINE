// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifdef __INTELLISENSE__
import UPRISE_ENGINE_PROFILER;
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#include "UE_RENDER_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import UPRISE_ENGINE_RENDER;
import <string>;
import UPRISE_ENGINE_PROFILER;
import UPRISE_ENGINE_CORE;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE::RENDER {
    OwnedRef<RENDER_COMMON::WINDOW_BASE> RENDER::Window::_CreateWindow(int w, int h, const char* title) //-V3547
    {

        return  RENDER_COMMON::RENDER_BACKEND::_CreateWindow(w, h, title);
    }

    void RENDER::Window::DestroyWindow(WeakRef<Window,true> window)
    {
        SCOPED_TIME_

        RENDER_COMMON::RENDER_BACKEND::DestroyWindow(window->Windowvar.GetWeakRef());
    }
 void UPRISE_ENGINE::RENDER::Window::DisplayFpsInWindowTitle(double Fps, std::string BaseTitle)
    {
        Windowvar->DisplayFpsInWindowTitle(Fps,BaseTitle);
    }

}

