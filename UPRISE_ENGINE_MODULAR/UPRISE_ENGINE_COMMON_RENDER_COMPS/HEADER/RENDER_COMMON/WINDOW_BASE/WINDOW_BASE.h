// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _WINDOW_BASE_
#define _WINDOW_BASE_
#include "RENDER_COMMON/CALLBACK_TYPEDEFS/CALLBACK_TYPEDEFS.h"
import REF_WRAPPER;
namespace RENDER_COMMON {
    class WINDOW_BASE {
    private:
        struct {
           RENDER_COMMON:: KeyInputCallback keyinput = nullptr;
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

    public:
        WINDOW_BASE() = default;
        ~WINDOW_BASE() = default;
        
#pragma region Virtual funcs

        UPRISE_COMMON_RENDER_COMPS_API  virtual void CreateWindow(int w, int h, const char* Title) = 0;
        UPRISE_COMMON_RENDER_COMPS_API  virtual void DestroyWindow() = 0;
        UPRISE_COMMON_RENDER_COMPS_API  virtual void SetWindowShouldClose() = 0;
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


#pragma endregion
    private:
    };

}


#endif // !_WINDOW_BASE_
