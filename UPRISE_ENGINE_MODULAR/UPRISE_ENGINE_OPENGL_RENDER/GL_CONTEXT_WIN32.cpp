// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "GL_CONTEXT_WIN32.h"
#include <string>
#include <Windows.h>
#include <LOG.h>
#include "OPENGL_WINDOW.h"
#include <MACROS.h>
#include <exception>


using wglCreateContextAttribsARB_t = HGLRC(WINAPI*)(HDC, HGLRC, const int*);
using wglChoosePixelFormatARB_t = BOOL(WINAPI*)(HDC, const int*, const FLOAT*, UINT, int*, UINT*);

wglCreateContextAttribsARB_t wglCreateContextAttribsARB = nullptr;
wglChoosePixelFormatARB_t wglChoosePixelFormatARB = nullptr;

namespace {
    static PIXELFORMATDESCRIPTOR CreateDefaultPFD()
    {
        PIXELFORMATDESCRIPTOR pfd{};
        ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
        pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32; //-V112
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        pfd.iLayerType = PFD_MAIN_PLANE;
        return pfd;
    }
}

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {

    ContextGlWin32::ContextGlWin32(std::weak_ptr<RENDER_COMMON::Window> Window)
    {
        // Lock and cast the incoming weak_ptr to the expected OpenGlWindow type
        auto sharedBase = Window.lock();
        if (!sharedBase) {
            DEBUG::Debug::Log("Window expired when creating GL context");
            DEBUG::Debug::FlushStream();
            throw std::exception("Window expired");
        }

        auto openGlWindow = std::dynamic_pointer_cast<OpenGlWindow>(sharedBase);
        if (!openGlWindow) {
            DEBUG::Debug::Log("Provided window is not an OpenGlWindow");
            DEBUG::Debug::FlushStream();
            throw std::exception("Invalid window type");
        }

        _window = openGlWindow;

        HWND hwnd = reinterpret_cast<HWND>(openGlWindow->OSGetWindowHandle());
        HDC hdc = GetDC(hwnd);
        this->HDC_ptr = hdc;
        if (!hdc) {
            DEBUG::Debug::Log("Failed to get HDC from window handle");
            DEBUG::Debug::FlushStream();
            throw std::exception("GetDC failed");
        }

        const auto pfd = CreateDefaultPFD();
        const char* PDF = reinterpret_cast<const char*>(&pfd);
        this->PixelForatDescriptorHash = std::hash<std::string>{}(std::string(PDF, sizeof(PIXELFORMATDESCRIPTOR)));

        const int pixelFormat = ChoosePixelFormat(hdc, &pfd);
        if (!pixelFormat) {
            DEBUG::Debug::Log("Failed to choose pixel format");
            DEBUG::Debug::FlushStream();
            throw std::exception("ChoosePixelFormat failed");
        }

        if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
            DEBUG::Debug::Log("Failed to set pixel format");
            DEBUG::Debug::FlushStream();
            throw std::exception("SetPixelFormat failed");
        }

        HGLRC tempContext = wglCreateContext(hdc);
        if (!tempContext) {
            DEBUG::Debug::Log("Failed to create temporary OpenGL context");
            DEBUG::Debug::FlushStream();
            throw std::exception("wglCreateContext failed");
        }

        if (!wglMakeCurrent(hdc, tempContext)) {
            DEBUG::Debug::Log("Failed to make temporary OpenGL context current");
            DEBUG::Debug::FlushStream();
            wglDeleteContext(tempContext);
            throw std::exception("wglMakeCurrent failed");
        }

        if (!wglCreateContextAttribsARB) {
            wglCreateContextAttribsARB = reinterpret_cast<wglCreateContextAttribsARB_t>(
                reinterpret_cast<void*>(wglGetProcAddress("wglCreateContextAttribsARB")));
            if (!wglCreateContextAttribsARB) {
                DEBUG::Debug::Log("Failed to get wglCreateContextAttribsARB function address");
                DEBUG::Debug::FlushStream();
                wglMakeCurrent(nullptr, nullptr);
                wglDeleteContext(tempContext);
                throw std::exception("wglGetProcAddress failed");
            }
        }

        const int attribs[] = {
            0x2091, 4,  // WGL_CONTEXT_MAJOR_VERSION_ARB
            0x2092, 6,  // WGL_CONTEXT_MINOR_VERSION_ARB
            0x2094, 1,  // WGL_CONTEXT_PROFILE_MASK_ARB (1 = Core Profile)
            0
        };

        HGLRC context = wglCreateContextAttribsARB(hdc, 0, attribs);
        this->HGLRC_ptr = context;
        if (!context) {
            DEBUG::Debug::Log("Failed to create OpenGL context");
            DEBUG::Debug::FlushStream();
            wglMakeCurrent(nullptr, nullptr);
            wglDeleteContext(tempContext);
            throw std::exception("wglCreateContextAttribsARB failed");
        }

        if (!wglMakeCurrent(hdc, context)) {
            DEBUG::Debug::Log("Failed to make OpenGL context current");
            DEBUG::Debug::FlushStream();
            wglMakeCurrent(nullptr, nullptr);
            wglDeleteContext(tempContext);
            wglDeleteContext(context);
            throw std::exception("wglMakeCurrent failed for final context");
        }

        // Replace temporary context with real one
        wglMakeCurrent(nullptr, nullptr);
        wglDeleteContext(tempContext);
        wglMakeCurrent(hdc, context);
    }

    ContextGlWin32::~ContextGlWin32()
    {
        if (HGLRC_ptr) {
            // Unbind and delete the GL context
            wglMakeCurrent(nullptr, nullptr);
            wglDeleteContext(HGLRC_ptr);
            HGLRC_ptr = nullptr;
        }

        if (HDC_ptr) {
            if (auto wnd = _window.lock()) {
                ReleaseDC(reinterpret_cast<HWND>(wnd->OSGetWindowHandle()), HDC_ptr);
            }
            HDC_ptr = nullptr;
        }
    }

}
