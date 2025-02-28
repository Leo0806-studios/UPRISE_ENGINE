// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL/WINDOW/OPENGL_WINDOW.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
#include "OPENGL/OPENGL_CONTEXT/OPENGL_CONTEXT.h"
import std; //-V2575 //-V3549


#define WINDW_PTR 
#ifdef _WIN32
#include "GL_WINDOW_WIN32/GL_WINDOW_WIN32.h"
#define WIDW_PTR UPRISE_ENGINE::OPENGL_RENDER::WINDOW_Win32*
#endif


#ifdef __linux__
#define WIDW_PTR WINDOW_Linux*
#endif


#ifdef __APPLE
#define WIDW_PTR WINDOW_APPLE*
#endif

namespace UPRISE_ENGINE {




 

    namespace OPENGL_RENDER {
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
        RENDER_COMMON::OSWindowHandle UPRISE_ENGINE::OPENGL_RENDER::OPENGL_WINDOW::OSGetWindowHandle()
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
                 throw std::exception("Not implemented");
             }
        }

    }
}







#ifdef __linux__
#include "X11/Xlib.h"

#endif
#ifdef __APPLE__
#include "Cocoa/Cocoa.h"

#endif
//namespace UPRISE_ENGIE {
//
//    namespace OPENGL_RENDER {



#ifdef __linux__

        class WINDOW_Linux {
            ///TODO: Implement Linux window class
        }
#endif

#ifdef __APPLE__
        class WINDOW_APPLE {
            ///TODO: Implement Apple window class
        }
#endif // __APPLE_


        




//    
//    }
//}





