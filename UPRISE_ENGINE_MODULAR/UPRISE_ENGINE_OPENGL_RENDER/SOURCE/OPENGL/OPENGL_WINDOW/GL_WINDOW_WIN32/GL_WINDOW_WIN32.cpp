// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifdef __INTELLISENSE__
import UPRISE_ENGINE_PROFILER;
#include "GL_WINDOW_WIN32.h"
#include <Windows.h>
#include "stdexcept"
#include <iostream>
#else
import UPRISE_ENGINE_PROFILER;
#include "GL_WINDOW_WIN32.h"
import <Windows.h>;
import <stdexcept>;
import <iostream>;
#endif // __INTELLISENSE__



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

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
        void WINDOW_Win32::GL_CREATE_WINDOW(int w, int h, const char* name) {
            SCOPED_TIME_

                WNDCLASS wc = {};
            wc.lpfnWndProc = DEFAULT_UE_WINDOW_MSG_CALLBACK;  // Basic default message handler
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
        inline void WINDOW_Win32::CLOSE_Window()  {
            SCOPED_TIME_

                auto widwDestroyed = DestroyWindow(reinterpret_cast<HWND>(handle));
            if (!static_cast<bool>(widwDestroyed)) {
                throw std::exception("Failed to close window");
            }
        }
        void WINDOW_Win32::ChangeWindowTitle(const std::string& title) 
        {
            SetWindowTextA(reinterpret_cast<HWND>(this->handle), title.c_str());
        }
    }




