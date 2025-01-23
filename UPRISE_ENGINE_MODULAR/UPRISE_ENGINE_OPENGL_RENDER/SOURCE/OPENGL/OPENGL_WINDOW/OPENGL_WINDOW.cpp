
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL/WINDOW/OPENGL_WINDOW.h"
class WINDOW_Win32;
import std;
extern OPENGL_RENDER::WINDOW_Win32* NEW_WIN32_WINDOW();
extern void CoseWindow(OPENGL_RENDER::WINDOW_Win32* window);

extern void WIN32_CREATE_WINDOW_G(OPENGL_RENDER::WINDOW_Win32* window, int with, int height, const char* title);
namespace OPENGL_RENDER {
    RefWrapper<RENDER_COMMON::WINDOW_BASE, true> OPENGL_WINDOW::_CreateWindow(int w, int h, const char* Title)
    {
        return  RefWrapper<RENDER_COMMON::WINDOW_BASE, true>();
    }
    void OPENGL_WINDOW::CreateWindow(int w, int h, const char* Title)
    {
        window = NEW_WIN32_WINDOW();
        WIN32_CREATE_WINDOW_G(window, w, h, Title);

    }

    void OPENGL_WINDOW::DestroyWindow()
    {
        CoseWindow(window);

    }

    void OPENGL_WINDOW::SetWindowShouldClose()
    {
    }

}

namespace OPENGL_RENDER {

#ifdef _WIN32
#include "Windows.h"
    /// <summary>
    /// Win32 specific window class
    /// </summary>
    class WINDOW_Win32 {
    private:
    public:

        HWND handle;
        HICON icon;
        HICON small_icon;

        int with, height;
        int lastcursorx, lastcursory;
        bool cursortracked;
        bool cursorvisible;
        bool maximized;
        bool transparent;
        bool scaleToMonitor;
        void WIN32_CREATE_WINDOW(int w, int h, const char* name) {
            WNDCLASS wc = {  };
            wc.lpfnWndProc = DefWindowProc;  // Basic default message handler
            wc.hInstance = GetModuleHandle(nullptr); // Use current module instance
            int nameLength = MultiByteToWideChar(CP_UTF8, 0, name, -1, nullptr, 0);
            std::wstring wideName(nameLength, 0);
            MultiByteToWideChar(CP_UTF8, 0, name, -1, &wideName[0], nameLength);

            wc.lpszClassName = wideName.c_str();
            if (!RegisterClassW(&wc)) {
                throw std::exception("Failed to register window class");
            }
            with = w;
            height = h;
            handle = CreateWindowExW(0, wideName.c_str(), wideName.c_str(), WS_OVERLAPPEDWINDOW, 0, 0, w, h, nullptr, nullptr, nullptr, nullptr);
            if (!handle) {
                throw std::exception("Failed to create window");
            }
            std::cout << GetLastError() << "\n";
            ShowWindow(handle, SW_SHOW);

        }
        void CLOSE_Window() {
            DestroyWindow(handle);
        }
        WINDOW_Win32() = default;
        ~WINDOW_Win32() = default;
    };


#endif // _WIN32
#ifdef __linux__
#include "X11/Xlib.h"
    class WINDOW_Linux {
        ///TODO: Implement Linux window class
    }
#endif
#ifdef __APPLE__
#include "Cocoa/Cocoa.h"
    class WINDOW_APPLE {
        ///TODO: Implement Apple window class
    }
#endif // __APPLE__

}
#ifdef _WIN32
OPENGL_RENDER::WINDOW_Win32* NEW_WIN32_WINDOW()
{
    return new OPENGL_RENDER::WINDOW_Win32();

}
void CoseWindow(OPENGL_RENDER::WINDOW_Win32* window)
{
    window->CLOSE_Window();

}
void WIN32_CREATE_WINDOW_G(OPENGL_RENDER::WINDOW_Win32* window, int with, int height, const char* title)
{
    window->WIN32_CREATE_WINDOW(with, height, title);

}
#endif // _WIN32
