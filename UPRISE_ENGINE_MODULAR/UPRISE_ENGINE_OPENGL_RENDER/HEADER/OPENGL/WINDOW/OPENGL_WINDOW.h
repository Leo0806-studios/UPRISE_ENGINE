// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _OPENGL_WINDOW_
#define _OPENGL_WINDOW_
#include "RENDER_COMMON/WINDOW_BASE/WINDOW_BASE.h"

namespace OPENGL_RENDER {

    /// <summary>
/// FORWARD DECLARATIONS
/// </summary>

    class WINDOW_Win32;
    class WINDOW_Linux;
    class WINDOW_APPLE;
    class WINDOW_UNIX;

#define WIN__32_PLATFORM 
#define LINUX_PLATFORM
#define APPLE_PLATFORM
#define UNIX_PLATFORM
#ifdef _WIN32
#define WIN__32_PLATFORM WINDOW_Win32

#endif // _WIN32
#ifdef __linux__
#define LINUX_PLATFORM WINDOW_Linux
#endif // __linux__
#ifdef __APPLE__
#define APPLE_PLATFORM WINDOW_APPLE
#endif // __APPLE__
#ifdef __unix__
#define UNIX_PLATFORM WINDOW_UNIX
#endif // __unix__


#define WINDOWW_PLATFORM WIN__32_PLATFORM  LINUX_PLATFORM  APPLE_PLATFORM  UNIX_PLATFORM

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
        UPRISE_OPENGL_RENDER_API static RefWrapper<RENDER_COMMON::WINDOW_BASE, true> _CreateWindow(int w, int h, const char* Title);


         void CreateWindow(int w, int h, const char* Title) override;
         void DestroyWindow() override;
         void SetWindowShouldClose() override;

    private:


        WINDOWW_PLATFORM * window;
    };

}

#endif // !_OPENGL_WINDOW_
//implementation of OPENGL_WINDOW