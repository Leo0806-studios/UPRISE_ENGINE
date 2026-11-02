// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "OPENGL_WINDOW.h"
#ifdef _WIN32
#include "GL_WINDOW_WIN32.h"
#endif

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
    OpenGlWindow::~OpenGlWindow() {
    }

    void OpenGlWindow::SetWindowShouldClose()
    {
        UE_THROW_NOT_IMPLEMENTED;
    }

    RENDER_COMMON::OSWindowHandle OpenGlWindow::OSGetWindowHandle() {
        if (!window) {
            return nullptr;
        }
#ifdef _WIN32
        return window->GetHandle();
#else
        return nullptr; // TODO: Implement for other platforms
#endif
    }

    std::unique_ptr<RENDER_COMMON::Window> OpenGlWindow::CreateWindow(std::string Title, int Width, int Height) {
        std::unique_ptr<OpenGlWindow> ret = std::make_unique<OpenGlWindow>();

#ifdef _WIN32
        try {
            ret->window = std::make_unique<WindowGlWin32>(Width, Height, Title);
        }
        catch (const std::exception& e) {
            std::ignore = e; 
            return nullptr;
        }
#endif

        return ret;
    }

    void OpenGlWindow::DisplayFpsInWindowTitle(double Fps, std::string BaseTitle) {
        if (!window) {
            return;
        }

        const std::string NewTitle = [&]() {
            std::string retr = BaseTitle;
            retr.append(" FPS: ");
            retr.append(std::to_string(Fps));
            return retr;
        }();

        window->SetTitle(NewTitle);
    }
}

















