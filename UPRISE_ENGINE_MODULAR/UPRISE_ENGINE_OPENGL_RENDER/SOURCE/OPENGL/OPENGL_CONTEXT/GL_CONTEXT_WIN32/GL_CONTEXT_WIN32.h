#pragma once
#ifndef GL_CONTEXT_WIN32
#define GL_CONTEXT_WIN32

#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_OPENGL_INTELLISENSE_FIX.h"
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#include <Windows.h>
#else
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_OPEN_GL_RENDER;
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import <Windows.h>;
#endif
#ifdef UPRISEENGINEOPENGLRENDER_EXPORTS
#define UPRISE_OPENGL_RENDER_API __declspec(dllexport)
#endif
namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    class CONTEXT_GL_WIN32 {
    private:
        using Context = CONTEXT_GL_WIN32;
        WeakRef<OPENGL_WINDOW, true> _window;
        unsigned long long PixelForatDescriptorHash = 0;
        HGLRC HGLRC_ptr = nullptr;
        HDC HDC_ptr = nullptr;
        HMODULE HMODULE_ptr = nullptr;
    public:
        CONTEXT_GL_WIN32() = default;
        UPRISE_OPENGL_RENDER_API CONTEXT_GL_WIN32(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window);
        UPRISE_OPENGL_RENDER_API ~CONTEXT_GL_WIN32();

    };
}
#endif // !GL_CONTEXT_WIN32
