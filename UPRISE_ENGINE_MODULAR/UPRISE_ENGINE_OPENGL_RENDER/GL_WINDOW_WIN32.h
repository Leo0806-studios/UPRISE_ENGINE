#pragma once
#include <memory>
#include <string>

#include <MACROS.h>
#include "GL_WINDOW_BASE.h"


namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
        typedef void* HWND_VoidPtr;
        typedef void* HINSTANCE_VoidPtr;
        typedef void* HICON_VoidPtr;

        /// RAII wrapper for Win32 window management
        /// Automatically creates window on construction and destroys on destruction
        /// Inherits from WindowBase<WindowGlWin32> for CRTP-based interface
        class WindowGlWin32 : public WindowBase<WindowGlWin32> { //-V2575 //-V3549
        private:
            HWND_VoidPtr handle;
            int width;
            int height;
            bool cursorvisible;
            bool maximized;
            bool transparent;
            bool bordersVisible;

            // Helper method to register window class
            static void RegisterWindowClass(const std::wstring& className);

        public:
            // RAII - Constructor creates window, Destructor destroys it
            UPRISE_OPENGL_RENDER_API WindowGlWin32(int w, int h, const std::string& name);

            // Destructor - cleanup
            UPRISE_OPENGL_RENDER_API ~WindowGlWin32() noexcept;

            // Delete copy operations - window handles are not copyable
            WindowGlWin32(const WindowGlWin32&) = delete;
            WindowGlWin32& operator=(const WindowGlWin32&) = delete;

            // Allow move operations
            UPRISE_OPENGL_RENDER_API WindowGlWin32(WindowGlWin32&& other) noexcept;
            UPRISE_OPENGL_RENDER_API WindowGlWin32& operator=(WindowGlWin32&& other) noexcept;

            // Window property accessors
            UPRISE_OPENGL_RENDER_API HWND_VoidPtr GetHandle() const noexcept { return handle; }
            UPRISE_OPENGL_RENDER_API int GetWidth() const noexcept { return width; }
            UPRISE_OPENGL_RENDER_API int GetHeight() const noexcept { return height; }
            UPRISE_OPENGL_RENDER_API bool IsVisible() const noexcept;
            UPRISE_OPENGL_RENDER_API bool IsMaximized() const noexcept { return maximized; }
            UPRISE_OPENGL_RENDER_API bool IsTransparent() const noexcept { return transparent; }

            // Window manipulation methods
            UPRISE_OPENGL_RENDER_API void SetTitle(const std::string& title) const;
            UPRISE_OPENGL_RENDER_API void SetDimensions(int w, int h);
            UPRISE_OPENGL_RENDER_API void SetPosition(int x, int y) const;
            UPRISE_OPENGL_RENDER_API void SetVisibility(bool visible) const;
            UPRISE_OPENGL_RENDER_API void ToggleVisibility() const;
            UPRISE_OPENGL_RENDER_API void SetCursorVisibility(bool visible);
            UPRISE_OPENGL_RENDER_API void ToggleCursorVisibility() noexcept;
            UPRISE_OPENGL_RENDER_API void SetTransparency(bool transparent);
            UPRISE_OPENGL_RENDER_API void SetBorderless(bool borderless);
            UPRISE_OPENGL_RENDER_API void Maximize();
            UPRISE_OPENGL_RENDER_API void Minimize() const;
            UPRISE_OPENGL_RENDER_API void Restore();
            UPRISE_OPENGL_RENDER_API void Center() const;
        };


}



