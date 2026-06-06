#pragma once
#include "CALLBACK_TYPEDEFS.h"
#include <IMPORT_DEFS.h>
#include <memory>
#include <string>
#include <filesystem>
#include <unordered_map>
#include "RENDER_BACKEND.h"
namespace UPRISE_ENGINE::RENDER:: RENDER_COMMON {

        class CONTEXT_BASE;
        using OSWindowHandle = void *; //NOSONAR
        class WINDOW_BASE {
        public:
            using CreatorFunk = std::unique_ptr<WINDOW_BASE>(*)(std::string Title, int Width, int Height);
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
            UPRISE_COMMON_RENDER_COMPS_API static std::unordered_map<Backend, CreatorFunk> RegisteredWindowTypes;
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

            UPRISE_COMMON_RENDER_COMPS_API virtual void DisplayFpsInWindowTitle(double Fps, std::string BaseName) = 0;
            UPRISE_COMMON_RENDER_COMPS_API static std::weak_ptr<WINDOW_BASE> CreateWindow(std::string Title, int Width, int Height);
            static void RegisterWindowClass(Backend backend, CreatorFunk Creator);

#pragma endregion
        private:
        };


        template <typename T, Backend backend>
            requires std::derived_from<T, WINDOW_BASE>&& requires (std::string Title, int Width, int Height) {
                {
                    T::CreateWindow(Title, Width, Height)
                } -> std::same_as<std::unique_ptr<WINDOW_BASE>>;
        }
        struct WindowClassRegistry {
        public:
            WindowClassRegistry() {
                WINDOW_BASE::RegisterWindowClass(backend, [](std::string Title, int Width, int Height) -> std::unique_ptr<WINDOW_BASE> {
                    return T::CreateWindow(Title, Width, Height);
                });
            }
        };
    }


