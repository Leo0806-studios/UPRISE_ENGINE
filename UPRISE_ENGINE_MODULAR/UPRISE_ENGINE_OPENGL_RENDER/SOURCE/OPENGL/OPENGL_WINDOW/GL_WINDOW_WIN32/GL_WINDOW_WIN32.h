#pragma once
#ifndef UE_GL_WINDOW_WIN32_
#define UE_GL_WINDOW_WIN32_
namespace UPRISE_ENGINE {

    namespace  OPENGL_RENDER {
        typedef void* HWND_VoidPtr;
        typedef void* HINSTANCE_VoidPtr;
        typedef void* HICON_VoidPtr;
        class WINDOW_Win32 { //-V2575 //-V3549
        private:
        public:

            HWND_VoidPtr handle;
            HICON_VoidPtr icon;
            HICON_VoidPtr small_icon;

            int with, height;
            int lastcursorx, lastcursory;
            bool cursortracked;
            bool cursorvisible;
            bool maximized;
            bool transparent;
            bool scaleToMonitor;
            char PAD[3]{};//TODO find a better way to align this or put data here
            WINDOW_Win32() noexcept :
                handle(nullptr),
                icon(nullptr),
                small_icon(nullptr),
                with(0),
                height(0),
                lastcursorx(0),
                lastcursory(0),
                cursortracked(false),
                cursorvisible(false),
                maximized(false),
                transparent(false),
                scaleToMonitor(false)
            {
            }
            UPRISE_OPENGL_RENDER_API  void GL_CREATE_WINDOW(int w, int h, const char* name);
           UPRISE_OPENGL_RENDER_API void CLOSE_Window() const;
        };

    }
}
#endif // !UE_GL_WINDOW_WIN32_
