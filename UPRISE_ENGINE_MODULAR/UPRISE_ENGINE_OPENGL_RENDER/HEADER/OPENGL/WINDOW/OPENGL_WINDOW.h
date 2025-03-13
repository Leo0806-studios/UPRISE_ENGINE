// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_OPENGL_WINDOW_
#define UE_OPENGL_WINDOW_
#include "RENDER_COMMON/WINDOW_BASE/WINDOW_BASE.h"

        /// <summary>
    /// FORWARD DECLARATIONS
    /// </summary>








namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        class OPENGL_CONTEXT;
        class WINDOW_Win32;
        class WINDOW_Linux;
        class WINDOW_APPLE;
        class WINDOW_UNIX;
#ifdef _WIN32

#define UE_GL_WIN_32_PLATFORM UPRISE_ENGINE::OPENGL_RENDER::WINDOW_Win32
#define UE_GL_LINUX_PLATFORM
#define APPLE_PLATFORM
#define UNIX_PLATFORM

#endif // _WIN32



#ifdef __linux__

#define UE_GL_WIN_32_PLATFORM 
#define UE_GL_LINUX_PLATFORM WINDOW_Linux
#define APPLE_PLATFORM
#define UNIX_PLATFORM

#endif // __linux__


#ifdef __APPLE__

#define UE_GL_WIN_32_PLATFORM 
#define UE_GL_LINUX_PLATFORM
#define APPLE_PLATFORM WINDOW_APPLE
#define UNIX_PLATFORM

#endif // __APPLE__


#ifdef __unix__

#define UE_GL_WIN_32_PLATFORM 
#define UE_GL_LINUX_PLATFORM
#define APPLE_PLATFORM
#define UNIX_PLATFORM WINDOW_UNIX

#endif // __unix__



#define WINDOWW_PLATFORM UE_GL_WIN_32_PLATFORM  UE_GL_LINUX_PLATFORM  APPLE_PLATFORM  UNIX_PLATFORM

        /// <summary>
        /// OpenGL specific window class
        /// </summary>
        class OPENGL_WINDOW :public RENDER_COMMON::WINDOW_BASE {
        private:
            OwnedRef<OPENGL_CONTEXT> context;

            char MouseButtons[8]{};
            char keys[256]{};
        public:
            OPENGL_WINDOW() = default;
            UPRISE_OPENGL_RENDER_API ~OPENGL_WINDOW();
            UPRISE_OPENGL_RENDER_API static SharedRef<RENDER_COMMON::WINDOW_BASE, true> _CreateWindow(int w, int h, const char* Title);
            UPRISE_OPENGL_RENDER_API OPENGL_WINDOW(const OPENGL_WINDOW& other);
            UPRISE_OPENGL_RENDER_API OPENGL_WINDOW& operator=(const OPENGL_WINDOW& other);
            UPRISE_OPENGL_RENDER_API RENDER_COMMON::OSWindowHandle OSGetWindowHandle() override;

            UPRISE_OPENGL_RENDER_API  void CreateWindow(int w, int h, const char* Title) override;
            UPRISE_OPENGL_RENDER_API  void DestroyWindow() override;
            UPRISE_OPENGL_RENDER_API  void SetWindowShouldClose() override;

            // Inherited via WINDOW_BASE
            UPRISE_OPENGL_RENDER_API void SetContext(OwnedRef<RENDER_COMMON::CONTEXT_BASE> Context) override;
            UPRISE_OPENGL_RENDER_API void UnsetContext(bool ShouldDestroyContext) override;
            UPRISE_OPENGL_RENDER_API void DisplayFpsInWindowTitle(double Fps, std::string BaseTitle) override;
        private:


            WINDOWW_PLATFORM* window{ nullptr };

        };

    }

}

#endif // !_OPENGL_WINDOW_
//implementation of OPENGL_WINDOW