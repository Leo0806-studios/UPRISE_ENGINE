#pragma once
#include <memory>
#include <WINDOW_BASE.h>
#include <RENDER_BACKEND.h>
#undef CreateWindow
#pragma message("Undef of Windows.h macro: CreateWindow . Use CreateWindowW or CreateWindowEX instead")

namespace UPRISE_ENGINE {
    namespace RENDER{
        namespace OPENGL_RENDER {
            class OpenGlContext;
            class WindowGlWin32;
            class WINDOW_Linux;
            class WINDOW_APPLE;
            class WINDOW_UNIX;
#ifdef _WIN32
            using WINDOWW_PLATFORM = WindowGlWin32;
#elif __linux__
            using WINDOWW_PLATFORM = WINDOW_Linux;
#elif __APPLE__
            using WINDOWW_PLATFORM = WINDOW_APPLE;
#elif __unix__
            using WINDOWW_PLATFORM = WINDOW_UNIX;
#endif // __unix__

            class OpenGlWindow :public RENDER_COMMON::Window {
            private:
                std::shared_ptr<OpenGlContext> context;
                std::array<uint8_t, 256> keys{};
                std::array<uint8_t, 8> MouseButtons{};
                std::unique_ptr<WINDOWW_PLATFORM> window;
            public:
                OpenGlWindow() = default;

                // Delete copy operations - window is a unique_ptr (move-only resource)
                OpenGlWindow(const OpenGlWindow&) = delete;
                OpenGlWindow& operator=(const OpenGlWindow&) = delete;

                // Allow move operations
                OpenGlWindow(OpenGlWindow&&) = default;
                OpenGlWindow& operator=(OpenGlWindow&&) = default;

                UPRISE_OPENGL_RENDER_API RENDER_COMMON::OSWindowHandle OSGetWindowHandle() override;
                UPRISE_OPENGL_RENDER_API ~OpenGlWindow();
                UPRISE_OPENGL_RENDER_API void DisplayFpsInWindowTitle(double Fps, std::string BaseTitle) override;
                static std::unique_ptr<OpenGlWindow> CreateWindow(int w, int h, const char* Title);
            };
            inline RENDER_COMMON::WindowClassRegistry<OpenGlWindow, RENDER_COMMON::Backend::B_OPENGL> OPENGLWindowRegistry;
        }
    }
}
