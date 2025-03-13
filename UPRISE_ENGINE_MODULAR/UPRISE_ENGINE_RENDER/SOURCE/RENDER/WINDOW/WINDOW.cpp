// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER/WINDOW/WINDOW.h"
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
#include "RENDER_COMMON/WINDOW_BASE/WINDOW_BASE.h"
namespace UPRISE_ENGINE {
    OwnedRef<RENDER_COMMON::WINDOW_BASE> RENDER::Window::_CreateWindow(int w, int h, const char* title)
    {

        return  RENDER_COMMON::RENDER_BACKEND::_CreateWindow(w, h, title);
    }

    void RENDER::Window::DestroyWindow(WeakRef<Window,true> window)
    {
        SCOPED_TIME_

        RENDER_COMMON::RENDER_BACKEND::DestroyWindow(window->Windowvar.GetWeakRef());
    }

    UPRISE_RENDER_API void UPRISE_ENGINE::RENDER::Window::DisplayFpsInWindowTitle(double Fps, std::string BaseTitle)
    {
        Windowvar->DisplayFpsInWindowTitle(Fps,BaseTitle);
    }

}

