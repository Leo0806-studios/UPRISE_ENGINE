// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifdef __INTELLISENSE__
#include "UE_RENDER_INTELLISENSE_FIX.h"
#include "UE_OPENGL_INTELLISENSE_FIX.h"
import UPRISE_ENGINE_DEBUG;
import UPRISE_ENGINE_PROFILER;
#else
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import UPRISE_ENGINE_DEBUG;
import UPRISE_ENGINE_OPEN_GL_RENDER;
import UPRISE_ENGINE_PROFILER;
import UPRISE_ENGINE_RENDER;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE::RENDER {
    UPRISE_RENDER_API void UPRISE_ENGINE::RENDER::Render::DisplayFpsInMainWindowTitle(double Fps)
    {
        auto window = Windows.begin();
        window->second->DisplayFpsInWindowTitle(Fps, std::string(window->first));
    }
    void Render::SetRenderCamera(SharedRef<GameObject, true> cam)
    {
        UE_UNUSED_PARAMETER(cam);
    }

    Render::WindowDict Render::Windows;
    SharedRef<RENDER_COMMON::WINDOW_BASE, true> Render::Windowvar;

    UPRISE_RENDER_API void Render::RenderShutdown::Shutdown()
    {
        for (auto& window : Windows)
        {
            window.second->DestroyWindow(window.second.GetWeakRef());

        }
        Windows.clear();
    }



    void Render::RenderSetup::SetRenderBackend(Render_Backend backend)
    {
        PROFILER::TIMERS::SCOPED_TIME time("SetRenderBackend", __FILE__, __FUNCTION__, __LINE__);
        switch (backend)
        {
        case Render_Backend::RB_OPENGL:
            RENDER_COMMON::RENDER_BACKEND::_Create_Backend = UPRISE_ENGINE::RENDER::OPENGL_RENDER::OPENGL_BACKEND::GL_Create_Backend;
      
            break;
        case Render_Backend::RB_VULKAN:
            RENDER_COMMON::RENDER_BACKEND::_Create_Backend = nullptr;//-V1037
            break;
        case Render_Backend::RB_DIRECTX11:
            RENDER_COMMON::RENDER_BACKEND::_Create_Backend = nullptr;
            break;
        case Render_Backend::RB_DIRECTX12:
            RENDER_COMMON::RENDER_BACKEND::_Create_Backend = nullptr;
            break;
        default:
            throw std::exception("Backend not supported");
            break;
        }
    }
    void RENDER::Render::RenderSetup::CreateBackend()
    {
        PROFILER::TIMERS::SCOPED_TIME time("CreateBackend", __FILE__, __FUNCTION__, __LINE__);
        RENDER_COMMON::RENDER_BACKEND::_internal_backend = RENDER_COMMON::RENDER_BACKEND::CreateBackend();
    }
    WeakRef<RENDER_COMMON::CONTEXT_BASE, true> RENDER::Render::RenderSetup::CreateContext(WeakRef<RENDER_COMMON::WINDOW_BASE, true> window)
    {
        PROFILER::TIMERS::SCOPED_TIME time("CreateContext", __FILE__, __FUNCTION__, __LINE__);

        return RENDER_COMMON::RENDER_BACKEND::CreateContext(window);
    }
    UPRISE_RENDER_API OwnedRef<RENDER_COMMON::WINDOW_BASE> UPRISE_ENGINE::RENDER::Render::RenderSetup::Window(int w, int h, std::string Title)
    {
        PROFILER::TIMERS::SCOPED_TIME time("Window", __FILE__, __FUNCTION__, __LINE__);
        OwnedRef<RENDER_COMMON::WINDOW_BASE>windw = RENDER_COMMON::RENDER_BACKEND::_CreateWindow(w, h, Title.c_str());
        return  windw;
    }
    UPRISE_RENDER_API void UPRISE_ENGINE::RENDER::Render::RenderSetup::Setup(int w, int h, const char* Title, UPRISE_ENGINE::RENDER::Render_Backend backend)
    {
        std::cout << "Setting up render\n";
        CallMockableMethod(UPRISE_ENGINE::DEBUG::Debug::Log("Setting up render"));
        RENDER::Render::RenderSetup::SetRenderBackend(backend);
        RENDER::Render::RenderSetup::CreateBackend();
        OwnedRef<RENDER_COMMON::WINDOW_BASE> window = RENDER::Render::RenderSetup::Window(w, h, Title);
        OwnedRef<RENDER::Window> windowvar__ = OwnedRef<RENDER::Window>::Create(); //-V3547
        windowvar__->SetWindow(std::move(window));
        RENDER::Render::Windows[std::string(Title)] = std::move(windowvar__);
        CreateContext(Windows[std::string(Title)]->GetInternalWeakRef());

        std::cout << "Setting up render done\n";
        CallMockableMethod(UPRISE_ENGINE::DEBUG::Debug::Log("Setting up render done"));


    }
    SharedRef<RENDER_COMMON::WINDOW_BASE, true> RENDER::Render::GetWindow()
    {
        PROFILER::TIMERS::SCOPED_TIME time("GetWindow", __FILE__, __FUNCTION__, __LINE__);
        return Windowvar;
    }


}