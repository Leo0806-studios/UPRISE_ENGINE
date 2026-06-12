// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "WINDOW_BASE.h"
#include <string>
#include "RENDER_BACKEND.h"
#include <memory>
#include <LOG.h>
namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {
    std::weak_ptr<Window> Window::CreateWindow(std::string Title, int Width, int Height)
    {
        auto it = RegisteredWindowTypes.find(RenderBackend::GetBackendType());
        if (it == RegisteredWindowTypes.end()) {
            DEBUG::Debug::Log("No window class for " + std::to_string(RenderBackend::GetBackendType()) + " exists");
            return {};  
        }
        std::shared_ptr window =(*it).second(Title, Width, Height); 
        RenderBackend::RegisterWindow(window);
        return std::weak_ptr(window);
    }
    void Window::RegisterWindowClass(Backend backend, CreatorFunk Creator)
    {
        auto [it,succsess] = RegisteredWindowTypes.try_emplace(backend, Creator);
        if (!succsess) {
            DEBUG::Debug::Log("couldnt register window for backend: " + std::to_string(backend) + " check for potential double insertions");
        }
    
    }
}