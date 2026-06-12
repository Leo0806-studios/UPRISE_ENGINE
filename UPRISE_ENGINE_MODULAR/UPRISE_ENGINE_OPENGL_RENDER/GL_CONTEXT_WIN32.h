#pragma once
#include <memory>
#include <Windows.h>

#include <IMPORT_DEFS.h>
#include "OPENGL_WINDOW.h"
namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    class ContextGlWin32 {
    private:
        using Context = ContextGlWin32;
        std::weak_ptr<OpenGlWindow> _window;
        unsigned long long PixelForatDescriptorHash = 0;
        HGLRC HGLRC_ptr = nullptr;
        HDC HDC_ptr = nullptr;
        HMODULE HMODULE_ptr = nullptr;
    public:
        ContextGlWin32() = default;
        UPRISE_OPENGL_RENDER_API ContextGlWin32(std::weak_ptr<RENDER_COMMON::Window> Window);
        UPRISE_OPENGL_RENDER_API ~ContextGlWin32();

    };
}
    