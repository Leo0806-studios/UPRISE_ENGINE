// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <string>
#include <Windows.h>
#include <LOG.h>
#include "GL_WINDOW_BASE.h"
#include "GL_WINDOW_WIN32.h"
namespace {
    LRESULT CALLBACK DEFAULT_UE_WINDOW_MSG_CALLBACK(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg)
        {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    // Helper to convert UTF-8 string to wide string
    std::wstring Utf8ToWide(const std::string& utf8str) {
        int nameLength = MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), -1, nullptr, 0);
        std::wstring wideName(static_cast<size_t>(nameLength), 0);
        MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), -1, &wideName[0], nameLength); //-V2547 //-V3527
        return wideName;
    }
}

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
        void WindowGlWin32::RegisterWindowClass(const std::wstring& className) {
            WNDCLASS wc = {};
            wc.lpfnWndProc = DEFAULT_UE_WINDOW_MSG_CALLBACK;
            wc.hInstance = GetModuleHandle(nullptr); //-V2001
            wc.lpszClassName = className.c_str();

            if (!static_cast<bool>(RegisterClassW(&wc))) { //-V2001
                throw std::exception("Failed to register window class");
            }
        }

        WindowGlWin32::WindowGlWin32(int w, int h, const std::string& name)
            : handle(nullptr), width(w), height(h), cursorvisible(true), 
              maximized(false), transparent(false), bordersVisible(true)
        {

            std::wstring wideName = Utf8ToWide(name);
            RegisterWindowClass(wideName);

            handle = CreateWindowExW(0, wideName.c_str(), wideName.c_str(), 
                                    WS_OVERLAPPEDWINDOW, 0, 0, w, h, 
                                    nullptr, nullptr, nullptr, nullptr);

            if (!handle) {
                throw std::exception("Failed to create window");
            }

            auto showResult = ShowWindow(reinterpret_cast<HWND>(handle), SW_SHOW);
            if (!static_cast<bool>(showResult)) {
                DEBUG::Debug::Log("Warning: ShowWindow returned false. Error: " + std::to_string(GetLastError()));
            }
        }

        WindowGlWin32::~WindowGlWin32() noexcept {

            if (handle) {
                auto destroyResult = DestroyWindow(reinterpret_cast<HWND>(handle));
                if (!static_cast<bool>(destroyResult)) {
                    DEBUG::Debug::Log("Warning: Failed to destroy window. Error: " + std::to_string(GetLastError()));   
                }
                handle = nullptr;
            }
        }

        WindowGlWin32::WindowGlWin32(WindowGlWin32&& other) noexcept
            : handle(other.handle), width(other.width), height(other.height),
              cursorvisible(other.cursorvisible), maximized(other.maximized),
              transparent(other.transparent), bordersVisible(other.bordersVisible)
        {
            other.handle = nullptr;
        }

        WindowGlWin32& WindowGlWin32::operator=(WindowGlWin32&& other) noexcept {
            if (this != &other) {
                // Clean up existing window
                if (handle) {
                    DestroyWindow(reinterpret_cast<HWND>(handle));
                }

                // Move from other
                handle = other.handle;
                width = other.width;
                height = other.height;
                cursorvisible = other.cursorvisible;
                maximized = other.maximized;
                transparent = other.transparent;
                bordersVisible = other.bordersVisible;

                other.handle = nullptr;
            }
            return *this;
        }

        bool WindowGlWin32::IsVisible() const noexcept {
            if (!handle) return false;
            return static_cast<bool>(IsWindowVisible(reinterpret_cast<HWND>(handle)));
        }

        void WindowGlWin32::SetTitle(const std::string& title) const {
            if (!handle) return;
            SetWindowTextA(reinterpret_cast<HWND>(handle), title.c_str());
        }

        void WindowGlWin32::SetDimensions(int w, int h) {
            if (!handle) return;
            width = w;
            height = h;
            SetWindowPos(reinterpret_cast<HWND>(handle), nullptr, 0, 0, w, h, 
                        SWP_NOMOVE | SWP_NOZORDER);
        }

        void WindowGlWin32::SetPosition(int x, int y) const {
            if (!handle) return;
            SetWindowPos(reinterpret_cast<HWND>(handle), nullptr, x, y, 0, 0, 
                        SWP_NOSIZE | SWP_NOZORDER);
        }

        void WindowGlWin32::SetVisibility(bool visible) const {
            if (!handle) return;
            ShowWindow(reinterpret_cast<HWND>(handle), visible ? SW_SHOW : SW_HIDE);
        }

        void WindowGlWin32::ToggleVisibility() const {
            SetVisibility(!IsVisible());
        }

        void WindowGlWin32::SetCursorVisibility(bool visible) {
            cursorvisible = visible;
            ShowCursor(visible ? TRUE : FALSE);
        }

        void WindowGlWin32::ToggleCursorVisibility() noexcept {
            SetCursorVisibility(!cursorvisible);
        }

        void WindowGlWin32::SetTransparency(bool isTransparent) {
            if (!handle) return;
            transparent = isTransparent;

            if (isTransparent) {
                // Enable transparency
                LONG style = GetWindowLongW(reinterpret_cast<HWND>(handle), GWL_EXSTYLE);
                style |= WS_EX_TRANSPARENT | WS_EX_LAYERED;
                SetWindowLongW(reinterpret_cast<HWND>(handle), GWL_EXSTYLE, style);
                SetLayeredWindowAttributes(reinterpret_cast<HWND>(handle), RGB(0, 0, 0), 0, LWA_ALPHA);
            }
            else {
                // Disable transparency
                LONG style = GetWindowLongW(reinterpret_cast<HWND>(handle), GWL_EXSTYLE);
                style &= ~(WS_EX_TRANSPARENT | WS_EX_LAYERED);
                SetWindowLongW(reinterpret_cast<HWND>(handle), GWL_EXSTYLE, style);
            }
        }

        void WindowGlWin32::SetBorderless(bool borderless) {
            if (!handle) return;
            bordersVisible = !borderless;

            LONG style = GetWindowLongW(reinterpret_cast<HWND>(handle), GWL_STYLE);

            if (borderless) {
                style &= ~(WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
            }
            else {
                style |= (WS_CAPTION | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
            }

            SetWindowLongW(reinterpret_cast<HWND>(handle), GWL_STYLE, style);
            SetWindowPos(reinterpret_cast<HWND>(handle), nullptr, 0, 0, 0, 0,
                        SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
        }

        void WindowGlWin32::Maximize() {
            if (!handle) return;
            ShowWindow(reinterpret_cast<HWND>(handle), SW_MAXIMIZE);
            maximized = true;
        }

        void WindowGlWin32::Minimize() const {
            if (!handle) return;
            ShowWindow(reinterpret_cast<HWND>(handle), SW_MINIMIZE);
        }

        void WindowGlWin32::Restore() {
            if (!handle) return;
            ShowWindow(reinterpret_cast<HWND>(handle), SW_RESTORE);
            maximized = false;
        }

        void WindowGlWin32::Center() const {
            if (!handle) return;

            // Get screen dimensions
            int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            int screenHeight = GetSystemMetrics(SM_CYSCREEN);

            // Calculate centered position
            int x = (screenWidth - width) / 2;
            int y = (screenHeight - height) / 2;

            SetPosition(x, y);
        }
    }




