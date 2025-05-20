#pragma once
#ifndef UE_OPENGL_WINDOW_INTERNAL_
#define UE_OPENGL_WINDOW_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_OPENGL_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    namespace RENDER{
        namespace OPENGL_RENDER {
            class OPENGL_CONTEXT;
            class WINDOW_Win32;
            class WINDOW_Linux;
            class WINDOW_APPLE;
            class WINDOW_UNIX;
#ifdef _WIN32
            using WINDOWW_PLATFORM = WINDOW_Win32;
#elif __linux__
            using WINDOWW_PLATFORM = WINDOW_Linux;
#elif __APPLE__
            using WINDOWW_PLATFORM = WINDOW_APPLE;
#elif __unix__
            using WINDOWW_PLATFORM = WINDOW_UNIX;
#endif // __unix__

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
}
#endif




