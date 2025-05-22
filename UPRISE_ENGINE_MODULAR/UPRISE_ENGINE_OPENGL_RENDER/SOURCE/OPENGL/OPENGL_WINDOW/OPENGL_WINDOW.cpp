// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


#ifdef __INTELLISENSE__
#include "UE_OPENGL_INTELLISENSE_FIX.h"
import UPRISE_ENGINE_PROFILER;
#include <string>
#else
import UPRISE_ENGINE_OPEN_GL_RENDER;
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import UPRISE_ENGINE_PROFILER;
import <string>;
#endif // __INTELLISENSE__


#ifdef _WIN32
#include "GL_WINDOW_WIN32/GL_WINDOW_WIN32.h"
namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    using WIDW_PTR = UPRISE_ENGINE::RENDER::OPENGL_RENDER::WINDOW_Win32;
}
#endif


#ifdef __linux__
namespace UPRISE_ENGINE::RENDE::OPENGL_RENDER {
#define WIDW_PTR WINDOW_Linux*
}
#endif


#ifdef __APPLE
namespace UPRISE_ENGINE::RENDE::OPENGL_RENDER {
#define WIDW_PTR WINDOW_APPLE*
}
#endif


namespace UPRISE_ENGINE ::RENDER::OPENGL_RENDER {



        inline OPENGL_WINDOW::~OPENGL_WINDOW() { if (window) delete window; }
        OPENGL_WINDOW::OPENGL_WINDOW(const OPENGL_WINDOW& other):
            WINDOW_BASE(other),
            window(other.window)
        {
            for (Index i = sizeof(keys); i > 0; i--) {
                //if ((i-1) >= 256) {
                //    throw std::runtime_error("array out of bounds");
                //}
                this->keys[i - 1] = other.keys[i - 1];
            }
            for (Index i = sizeof(MouseButtons); i > 0; i--) {
                //if (i >= 9) {
                //    throw std::runtime_error("array out of bounds");
                //}
                this->MouseButtons[i - 1] = other.MouseButtons[i - 1];

            }
            
        }
        OPENGL_WINDOW& OPENGL_WINDOW::operator=(const OPENGL_WINDOW& other)
        {
            static_cast<void>(RENDER_COMMON::WINDOW_BASE::operator=(other));
            for (Index i = sizeof(keys); i > 0; i--) {
                //if ((i-1) >= 256) {
                //    throw std::runtime_error("array out of bounds");
                //}
                this->keys[i-1] = other.keys[i-1];
            }
            for (Index i = sizeof(MouseButtons) ; i > 0; i--) {
                //if (i >= 9) {
                //    throw std::runtime_error("array out of bounds");
                //}
                this->MouseButtons[i-1] = other.MouseButtons[i-1];
         
            }
            return *this;
        }
        RENDER_COMMON::OSWindowHandle OPENGL_WINDOW::OSGetWindowHandle()
        {
#ifdef _WIN32
            return window->handle;
#endif
            
        }
        void OPENGL_WINDOW::CreateWindow(int w, int h, const char* Title)
        {
            PROFILER::TIMERS::SCOPED_TIME time("SetWindow", __FILE__, __FUNCTION__, __LINE__);

            window = new WINDOWW_PLATFORM();
            window->GL_CREATE_WINDOW(w, h, Title);
            
        }

        void OPENGL_WINDOW::DestroyWindow()
        {
            PROFILER::TIMERS::SCOPED_TIME time("SetWindow", __FILE__, __FUNCTION__, __LINE__);

            window->CLOSE_Window();

        }

        void OPENGL_WINDOW::SetWindowShouldClose()
        {
        }

         void OPENGL_WINDOW::SetContext(OwnedRef<RENDER_COMMON::CONTEXT_BASE> Context)
        {
             if (this->context)
             {
                 throw std::runtime_error("Context already set");
             }
             this->context = std::move(Context);
             
        }

         void OPENGL_WINDOW::UnsetContext(bool ShouldDestroyContext)
        {
             if (ShouldDestroyContext)
             {
                 OwnedRef ctx = std::move(this->context);
             }
             else
             {
                 //TODO: Move to global context pool
                /// this->context.release();
                 UE_THROW_NOT_IMPLEMENTED;

             }
        }

         void OPENGL_WINDOW::DisplayFpsInWindowTitle(double Fps, std::string BaseTitle)
         {
             const std::string NewTitle = [&]() {std::string retr = BaseTitle; retr.append(" FPS: "); retr.append(std::to_string(Fps)); return retr; }();
             window->ChangeWindowTitle(NewTitle);
         }

    }

















