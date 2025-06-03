#ifdef __INTELLISENSE__
#include "GL_CONTEXT_WIN32.h"
#include "gl/GL.h"
import UPRISE_ENGINE_DEBUG;
#else
#include "GL_CONTEXT_WIN32.h"
import UPRISE_ENGINE_DEBUG;
#endif // __INTELLISENSE__
using wglCreateContextAttribsARB_t= HGLRC(WINAPI* )(HDC, HGLRC, const int*);
using wglChoosePixelFormatARB_t= BOOL(WINAPI* )(HDC, const int*, const FLOAT*, UINT, int*, UINT*);
wglCreateContextAttribsARB_t wglCreateContextAttribsARB = nullptr;
wglChoosePixelFormatARB_t wglChoosePixelFormatARB = nullptr;
namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    CONTEXT_GL_WIN32::CONTEXT_GL_WIN32(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window)
    {
        WeakRef<OPENGL_WINDOW, true> OpenGLWindow = (Window);
        _window = OpenGLWindow;
        HWND hwnd = static_cast<HWND>(OpenGLWindow->OSGetWindowHandle());
        HDC hdc = GetDC(hwnd);
        this->HDC_ptr = hdc;
        if (!hdc) {
            DEBUG::Debug::Log("failed to Get HDC from Window Handle");
            DEBUG::Debug::FlushStream();
            Break_Or_Exit;
        }
        const PIXELFORMATDESCRIPTOR pfd = []() {
            PIXELFORMATDESCRIPTOR pfd;
            ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
            pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
            pfd.nVersion = 1;
            pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
            pfd.iPixelType = PFD_TYPE_RGBA;
            pfd.cColorBits = 32; //-V112  //TODO find a eplanation for disabeling this warning
            pfd.cDepthBits = 24;
            pfd.cStencilBits = 8;
            pfd.iLayerType = PFD_MAIN_PLANE;
            return pfd;
            }();

        const char* PDF = reinterpret_cast<const char*>(&pfd);
        this->PixelForatDescriptorHash = std::hash<std::string>{}(std::string(PDF, sizeof(PIXELFORMATDESCRIPTOR)));
        const  int pixelFormat = ChoosePixelFormat(hdc, &pfd);
        if (!pixelFormat)
        {
            DEBUG::Debug::Log("Failed to choose pixel format");
            DEBUG::Debug::FlushStream();
            Break_Or_Exit;
        }
        if (!SetPixelFormat(hdc, pixelFormat, &pfd))
        {
            DEBUG::Debug::Log("Failed to set pixel format");
            DEBUG::Debug::FlushStream();
            Break_Or_Exit;
        }
        HGLRC tempContext = wglCreateContext(hdc);
        if (!tempContext)
        {
            DEBUG::Debug::Log("Failed to create temporary OpenGL context");
            DEBUG::Debug::FlushStream();
            Break_Or_Exit;
        }
        if (!wglMakeCurrent(hdc, tempContext))
        {
            DEBUG::Debug::Log("Failed to make temporary OpenGL context current");
            DEBUG::Debug::FlushStream();
            Break_Or_Exit;
        }
        if (!wglCreateContextAttribsARB)
        {
            wglCreateContextAttribsARB = reinterpret_cast<wglCreateContextAttribsARB_t>(reinterpret_cast<void*>(wglGetProcAddress("wglCreateContextAttribsARB")));
            if (!wglCreateContextAttribsARB)
            {
                DEBUG::Debug::Log("Failed to get wglCreateContextAttribsARB function address");
                DEBUG::Debug::FlushStream();
                Break_Or_Exit;
            }
        }
        const int attribs[] = {
0x2091, 4,  // WGL_CONTEXT_MAJOR_VERSION_ARB
0x2092, 5,  // WGL_CONTEXT_MINOR_VERSION_ARB
0x2094, 1,  // WGL_CONTEXT_PROFILE_MASK_ARB (1 = Core Profile)
0
        };
        HGLRC context = wglCreateContextAttribsARB(hdc, 0, attribs);
        this->HGLRC_ptr = context;
        if (!context)
        {
            DEBUG::Debug::Log("Failed To create OpenGL Context");
            DEBUG::Debug::FlushStream();
            Break_Or_Exit;
        }
        if (!wglMakeCurrent(hdc, context))
        {
            DEBUG::Debug::Log("Failed to make OpenGL context current");
            DEBUG::Debug::FlushStream();
            Break_Or_Exit;

        }
        wglMakeCurrent(nullptr, nullptr);
        wglDeleteContext(tempContext);
        wglMakeCurrent(hdc, context);
    }

    CONTEXT_GL_WIN32::~CONTEXT_GL_WIN32()
    {
        if (HGLRC_ptr) {
            wglMakeCurrent(HDC_ptr, nullptr);
            wglDeleteContext(HGLRC_ptr);
            HGLRC_ptr = nullptr;
        }
        if (HDC_ptr) {
            ReleaseDC(static_cast<HWND>(_window->OSGetWindowHandle()), HDC_ptr);
            HDC_ptr = nullptr;
        }

    }

}
