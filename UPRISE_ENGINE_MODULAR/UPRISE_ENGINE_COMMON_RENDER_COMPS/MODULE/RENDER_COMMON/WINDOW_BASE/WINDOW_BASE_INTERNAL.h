#pragma once
#ifndef UE_WINDOW_BASE_INTERNAL_
#define UE_WINDOW_BASE_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_COMMON_COMPS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef UPRISEENGINECOMMONRENDERCOMPS_EXPORTS
#define UPRISE_COMMON_RENDER_COMPS_API __declspec(dllexport)
#endif // UPRISEENGINECOMMONRENDERCOMPS_EXPORTS


#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "CALLBACK_TYPEDEFS/CALLBACK_TYPEDEFS_INTERNAL.h"
#include <string>
#include <filesystem>
#endif // __INTELLISENSE__
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {
        class CONTEXT_BASE;
        typedef void* OSWindowHandle;
        class WINDOW_BASE {
        protected:
        private:
            struct {
                RENDER_COMMON::KeyInputCallback keyinput = nullptr;
                RENDER_COMMON::MouseButtonCallback mousebutton = nullptr;
                RENDER_COMMON::CursorPosCallback cursorpos = nullptr;
                RENDER_COMMON::ResizeCallback resize = nullptr;
                RENDER_COMMON::CursorEnterCallback cursor_enter = nullptr;
                RENDER_COMMON::ScrollCallback scroll = nullptr;
                RENDER_COMMON::WindowCloseCallback window_close = nullptr;
                RENDER_COMMON::WindowRefreshCallback window_refresh = nullptr;
                RENDER_COMMON::WindowFocusCallback window_focus = nullptr;
                RENDER_COMMON::WindowIconifyCallback window_iconify = nullptr;
                RENDER_COMMON::FramebufferSizeCallback framebuffer_size = nullptr;
                RENDER_COMMON::WindowMaximizeCallback window_maximize = nullptr;
                RENDER_COMMON::WindowContentScaleCallback window_content_scale = nullptr;
            } Callbacks;
        protected:

        public:
            WINDOW_BASE() = default;
            virtual ~WINDOW_BASE() = default;
            UPRISE_COMMON_RENDER_COMPS_API WINDOW_BASE(const WINDOW_BASE& other);
            UPRISE_COMMON_RENDER_COMPS_API WINDOW_BASE& operator=(const WINDOW_BASE& other);
#pragma region Virtual funcs

            UPRISE_COMMON_RENDER_COMPS_API  virtual void CreateWindow(int w, int h, const char* Title) = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void DestroyWindow() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void SetWindowShouldClose() = 0;
            virtual RENDER_COMMON::OSWindowHandle OSGetWindowHandle() = 0;
            void SetKeyInputCallback(KeyInputCallback callback) { Callbacks.keyinput = callback; }
            void SetMouseButtonCallback(MouseButtonCallback callback) { Callbacks.mousebutton = callback; }
            void SetCursorPosCallback(CursorPosCallback callback) { Callbacks.cursorpos = callback; }
            void SetResizeCallback(ResizeCallback callback) { Callbacks.resize = callback; }
            void SetCursorEnterCallback(CursorEnterCallback callback) { Callbacks.cursor_enter = callback; }
            void SetScrollCallback(ScrollCallback callback) { Callbacks.scroll = callback; }
            void SetWindowCloseCallback(WindowCloseCallback callback) { Callbacks.window_close = callback; }
            void SetWindowRefreshCallback(WindowRefreshCallback callback) { Callbacks.window_refresh = callback; }
            void SetWindowFocusCallback(WindowFocusCallback callback) { Callbacks.window_focus = callback; }
            void SetWindowIconifyCallback(WindowIconifyCallback callback) { Callbacks.window_iconify = callback; }
            void SetFramebufferSizeCallback(FramebufferSizeCallback callback) { Callbacks.framebuffer_size = callback; }
            void SetWindowMaximizeCallback(WindowMaximizeCallback callback) { Callbacks.window_maximize = callback; }
            void SetWindowContentScaleCallback(WindowContentScaleCallback callback) { Callbacks.window_content_scale = callback; }
            /// <summary>
            /// Sets the attatchet context for this window to context
            /// will throw if a context is already attached
            /// <exception cref="std::runtime_error"></exception>
            /// </summary>
            /// <param name="Context"></param>
            /// 
            /// <returns></returns>
            UPRISE_COMMON_RENDER_COMPS_API virtual void SetContext(OwnedRef<CONTEXT_BASE> Context) = 0;
            /// <summary>
            /// After this call The Context will be moved to a global Context pool
            /// or destroyed depending on the value of ShouldDestroyContext
            /// </summary>
            /// <returns></returns>
            UPRISE_COMMON_RENDER_COMPS_API virtual void UnsetContext(bool ShouldDestroyContext) = 0;
            UPRISE_COMMON_RENDER_COMPS_API virtual void DisplayFpsInWindowTitle(double Fps, std::string BaseName) = 0;
#pragma endregion
        private:
        };

    }
}

#endif