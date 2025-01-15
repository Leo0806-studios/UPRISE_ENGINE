#include "OPENGL/WINDOW/OPENGL_WINDOW.h"
namespace OPENGL_RENDER {
    RefWrapper<RENDER_COMMON::WINDOW_BASE, true> OPENGL_WINDOW::CreateWindow(int w, int h, const char* Title)
    {
        return RefWrapper<WINDOW_BASE, true>();
    }



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

        WINDOW_Win32() = default;
        ~WINDOW_Win32() {};
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




