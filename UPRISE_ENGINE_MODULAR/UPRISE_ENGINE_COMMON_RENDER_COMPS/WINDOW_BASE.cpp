// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "WINDOW_BASE.h"
#include <string>
#include "RENDER_BACKEND.h"
#include <memory>
#include <LOG.h>
namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {
    std::weak_ptr<WINDOW_BASE> WINDOW_BASE::CreateWindow(std::string Title, int Width, int Height)
    {
        auto it = RegisteredWindowTypes.find(RENDER_BACKEND::GetBackendType());
        if (it == RegisteredWindowTypes.end()) {
            DEBUG::Debug::Log("No window class for " + std::to_string(RENDER_BACKEND::GetBackendType()) + " exists");
            return {};  
        }
    }
    void WINDOW_BASE::RegisterWindowClass(Backend backend, CreatorFunk Creator)
    {
        auto [it,succsess] = RegisteredWindowTypes.try_emplace(backend, Creator);
        if (!succsess) {
            DEBUG::Debug::Log("couldnt register window for backend: " + std::to_string(backend) + " check for potential double insertions");
        }
    
    }
}