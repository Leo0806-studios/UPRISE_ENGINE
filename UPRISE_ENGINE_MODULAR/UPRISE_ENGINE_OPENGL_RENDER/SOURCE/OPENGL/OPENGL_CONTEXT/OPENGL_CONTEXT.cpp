// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_OPENGL_INTELLISENSE_FIX.h"
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#include "UE_CORE_INTELLISENSE_FIX.h"
#ifdef _WIN32
#include "GL_CONTEXT_WIN32/GL_CONTEXT_WIN32.h"
#endif
import UPRISE_ENGINE_PROFILER;
#include <gl/GL.h>

#else
#define WIN_32_LEAN_AND_MEAN
#ifdef _WIN32
#include "GL_CONTEXT_WIN32/GL_CONTEXT_WIN32.h"
#endif
#include <gl/GL.h>
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import UPRISE_ENGINE_OPEN_GL_RENDER;
import UPRISE_ENGINE_PROFILER;

#endif // __INTELLISENSE__





//typedef HGLRC(WINAPI* wglCreateContextAttribsARB_t)(HDC, HGLRC, const int*);
//typedef BOOL(WINAPI* wglChoosePixelFormatARB_t)(HDC, const int*, const FLOAT*, UINT, int*, UINT*);
//wglCreateContextAttribsARB_t wglCreateContextAttribsARB = nullptr;
//wglChoosePixelFormatARB_t wglChoosePixelFormatARB = nullptr;
namespace UPRISE_ENGINE::RENDER {
    namespace OPENGL_RENDER {
        OwnedRef<RENDER_COMMON::CONTEXT_BASE> OPENGL_CONTEXT::_internal_create_context(WeakRef<RENDER_COMMON::WINDOW_BASE,true> Window)
        {
//
//           //TODO split into platform specific versions
//            void* handle=  Window->OSGetWindowHandle();
//#ifdef _WIN32
//
//            HDC hdc = GetDC(static_cast<HWND>(handle));
//            this->HDC_ptr = hdc;
//            if (!hdc)
//            {
//                throw std::exception("Failed to get device context");
//            }
//            const PIXELFORMATDESCRIPTOR pfd = []() {
//                PIXELFORMATDESCRIPTOR pfd;
//                ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
//                pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
//                pfd.nVersion = 1;
//                pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
//                pfd.iPixelType = PFD_TYPE_RGBA;
//                pfd.cColorBits = 32; //-V112  //TODO find a eplanation for disabeling this warning
//                pfd.cDepthBits = 24;
//                pfd.cStencilBits = 8;
//                pfd.iLayerType = PFD_MAIN_PLANE;
//                return pfd;
//                }();
//            const char* PDF = reinterpret_cast<const char*>(&pfd);
//
//            this->PixelForatDescriptorHash = std::hash<std::string>{}(std::string(PDF, sizeof(PIXELFORMATDESCRIPTOR)));
//          const  int pixelFormat = ChoosePixelFormat(hdc, &pfd);
//            if (!pixelFormat)
//            {
//                throw std::exception("Failed to choose pixel format");
//            }
//            if (!SetPixelFormat(hdc, pixelFormat, &pfd))
//            {
//                throw std::exception("Failed to set pixel format");
//            }
//            HGLRC tempContext = wglCreateContext(hdc);
//            if (!tempContext)
//            {
//                throw std::exception("Failed to create temporary context");
//            }
//            if (!wglMakeCurrent(hdc, tempContext))
//            {
//                throw std::exception("Failed to make temporary context current");
//            }
//            if (!wglCreateContextAttribsARB)
//            {
//                wglCreateContextAttribsARB = reinterpret_cast<wglCreateContextAttribsARB_t>(reinterpret_cast<void*>(wglGetProcAddress("wglCreateContextAttribsARB")));
//                if (!wglCreateContextAttribsARB)
//                {
//                    throw std::exception("Failed to get wglCreateContextAttribsARB");
//                }
//            }
//            const int attribs[] = {
//    0x2091, 4,  // WGL_CONTEXT_MAJOR_VERSION_ARB
//    0x2092, 5,  // WGL_CONTEXT_MINOR_VERSION_ARB
//    0x2094, 1,  // WGL_CONTEXT_PROFILE_MASK_ARB (1 = Core Profile)
//    0
//            };
//            HGLRC context = wglCreateContextAttribsARB(hdc, 0, attribs);
//            this->HGLRC_ptr = context;
//            if (!context)
//            {
//                throw std::exception("Failed to create context");
//            }
//            if (!wglMakeCurrent(hdc, context))
//            {
//                throw std::exception("Failed to make context current");
//            }
//            wglMakeCurrent(nullptr, nullptr);
//            wglDeleteContext(tempContext);
//            wglMakeCurrent(hdc, context);
//#endif // Win



          auto ctx=  OwnedRef<OPENGL_CONTEXT>::Create();
          ctx->_platform = OwnedRef<CONTEXT_GL_WIN32>::Create(Window);
          return ctx;
        }
        void OPENGL_CONTEXT::_internal_destroy_context()
        {
        }
        void OPENGL_CONTEXT::PostFrameWork() const
        {
            //SCOPED_TIME_

            SwapBuffers(reinterpret_cast<HDC>(this->HDC_ptr));
        }
        void OPENGL_CONTEXT::PreFrameWork()
        {
            //SCOPED_TIME_



            glClearColor(0.2f, 0.4f, 0.1f, 1.0f);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    }
}

