// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL/WINDOW/OPENGL_WINDOW.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
import std; //-V2575 //-V3549


#define WINDW_PTR 
#ifdef _WIN32

#define WIDW_PTR WINDOW_Win32*
#endif


#ifdef __linux__
#define WIDW_PTR WINDOW_Linux*
#endif


#ifdef __APPLE
#define WIDW_PTR WINDOW_APPLE*
#endif
class WINDOW_Win32;
class WINDOW_Linux;
class WINDOW_Apple; //-V2575 //-V3549
extern "C" WIDW_PTR NEW_WIN32_WINDOW();
extern "C" void CoseWindow(WIDW_PTR window);


extern "C" void WIN32_CREATE_WINDOW_G(WIDW_PTR window, int with, int height, const char* title);
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {


    }



 

    namespace OPENGL_RENDER {


        void OPENGL_WINDOW::CreateWindow(int w, int h, const char* Title)
        {
            PROFILER::TIMERS::SCOPED_TIME time("SetWindow", __FILE__, __FUNCTION__, __LINE__);

            window = NEW_WIN32_WINDOW();
            WIN32_CREATE_WINDOW_G(window, w, h, Title);

        }

        void OPENGL_WINDOW::DestroyWindow()
        {
            PROFILER::TIMERS::SCOPED_TIME time("SetWindow", __FILE__, __FUNCTION__, __LINE__);

            CoseWindow(window);

        }

        void OPENGL_WINDOW::SetWindowShouldClose()
        {
        }

    }
}





#ifdef _WIN32
#include "Windows.h"

#endif
#ifdef __linux__
#include "X11/Xlib.h"

#endif
#ifdef __APPLE__
#include "Cocoa/Cocoa.h"

#endif
//namespace UPRISE_ENGIE {
//
//    namespace OPENGL_RENDER {

#ifdef _WIN32
        /// <summary>
        /// Win32 specific window class
        /// </summary>
        class WINDOW_Win32 { //-V2575 //-V3549
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
            char PAD[3]{};//TODO find a better way to align this or put data here
            void WIN32_CREATE_WINDOW(int w, int h, const char* name) {
                SCOPED_TIME_

                WNDCLASS wc = {  };
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
                auto a = ShowWindow(handle, SW_SHOW);
                if (!static_cast<bool>(a)) {
                    std::cout << GetLastError() << "\n";
                    //throw std::exception("Failed to show window");
                }

            }
            void CLOSE_Window() const{
                SCOPED_TIME_

                auto widwDestroyed =DestroyWindow(handle);
                if (!static_cast<bool>(widwDestroyed)) {
                    throw std::exception("Failed to close window");
                }
            }
            WINDOW_Win32() = default;
            ~WINDOW_Win32() = default;
        };

        
#endif // _WIN32

#ifdef __linux__

        class WINDOW_Linux {
            ///TODO: Implement Linux window class
        }
#endif

#ifdef __APPLE__
        class WINDOW_APPLE {
            ///TODO: Implement Apple window class
        }
#endif // __APPLE_


        




//    
//    }
//}





#ifdef _WIN32
extern "C" WIDW_PTR NEW_WIN32_WINDOW()
{
    return new WINDOW_Win32(); //-V2511
}
extern "C" void CoseWindow(WIDW_PTR window)
{
    SCOPED_TIME_

    window->CLOSE_Window();

}
extern "C" void WIN32_CREATE_WINDOW_G(WIDW_PTR window, int with, int height, const char* title)
{
    SCOPED_TIME_
    window->WIN32_CREATE_WINDOW(with, height, title);

}

#endif // _WIN32