#include "GL_WINDOW_WIN32.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
#include "Windows.h"
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        void WINDOW_Win32::GL_CREATE_WINDOW(int w, int h, const char* name) {
            SCOPED_TIME_

                WNDCLASS wc = {};
            wc.lpfnWndProc = DefWindowProc;  // Basic default message handler
            wc.hInstance = GetModuleHandle(nullptr); // Use current module instance //-V2001
            int nameLength = MultiByteToWideChar(CP_UTF8, 0, name, -1, nullptr, 0);
            std::wstring wideName(static_cast<uhuge>(nameLength), 0);
            MultiByteToWideChar(CP_UTF8, 0, name, -1, &wideName[0], nameLength); //-V2547 //-V3527

            wc.lpszClassName = wideName.c_str();
            if (!static_cast<bool>(RegisterClassW(&wc))) { //-V2001
                throw std::exception("Failed to register window class");
            }
            with = w;
            height = h;
            handle = CreateWindowExW(0, wideName.c_str(), wideName.c_str(), WS_OVERLAPPEDWINDOW, 0, 0, w, h, nullptr, nullptr, nullptr, nullptr);
            if (!handle) {
                throw std::exception("Failed to create window");
            }
            std::cout << GetLastError() << "\n";
            auto a = ShowWindow(reinterpret_cast<HWND>(handle), SW_SHOW);
            if (!static_cast<bool>(a)) {
                std::cout << GetLastError() << "\n";
                //throw std::exception("Failed to show window");
            }
        }
        inline void WINDOW_Win32::CLOSE_Window() const {
            SCOPED_TIME_

                auto widwDestroyed = DestroyWindow(reinterpret_cast<HWND>(handle));
            if (!static_cast<bool>(widwDestroyed)) {
                throw std::exception("Failed to close window");
            }
        }
    }
}



