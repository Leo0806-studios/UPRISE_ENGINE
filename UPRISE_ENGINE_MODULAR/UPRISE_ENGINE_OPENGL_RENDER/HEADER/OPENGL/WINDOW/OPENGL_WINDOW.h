// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_OPENGL_WINDOW_
#define UE_OPENGL_WINDOW_
#include "RENDER_COMMON/WINDOW_BASE/WINDOW_BASE.h"

        /// <summary>
    /// FORWARD DECLARATIONS
    /// </summary>

class WINDOW_Win32; //-V3549 //-V2575
class WINDOW_Linux; //-V3549 //-V2575
class WINDOW_APPLE; //-V3549 //-V2575
class WINDOW_UNIX; //-V3549 //-V2575




#ifdef _WIN32

#define UE_GL_WIN_32_PLATFORM WINDOW_Win32
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


namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {




#define WINDOWW_PLATFORM UE_GL_WIN_32_PLATFORM  UE_GL_LINUX_PLATFORM  APPLE_PLATFORM  UNIX_PLATFORM

        /// <summary>
        /// OpenGL specific window class
        /// </summary>
        class OPENGL_WINDOW :public RENDER_COMMON::WINDOW_BASE {
        private:
            char MouseButtons[8];
            char keys[256];
        public:
            OPENGL_WINDOW() = default;
            ~OPENGL_WINDOW() = default;
            UPRISE_OPENGL_RENDER_API static SharedRef<RENDER_COMMON::WINDOW_BASE, true> _CreateWindow(int w, int h, const char* Title);


            void CreateWindow(int w, int h, const char* Title) override;
            void DestroyWindow() override;
            void SetWindowShouldClose() override;

        private:


            WINDOWW_PLATFORM* window;
        };

    }

}

#endif // !_OPENGL_WINDOW_
//implementation of OPENGL_WINDOW