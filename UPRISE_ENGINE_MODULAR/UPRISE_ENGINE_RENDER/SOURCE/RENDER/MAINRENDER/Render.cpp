// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER/MAINRENDER/Render.h"
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
#include "OPENGL/OPENGL_BACKEND/OPENGL_BACKEND.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {

    }
    void RENDER::Render::SetRenderCamera(SharedRef<GameObject, true> cam)
    {
    }
    namespace RENDER {
        SharedRef<RENDER_COMMON::WINDOW_BASE, true> Render::Windowvar;

    }

    void RENDER::Render::RenderSetup::SetRenderBackend(Render_Backend backend)
    {
        PROFILER::TIMERS::SCOPED_TIME time("SetRenderBackend", __FILE__, __FUNCTION__, __LINE__);
        switch (backend)
        {
        case Render_Backend::RB_OPENGL:
            RENDER_COMMON::RENDER_BACKEND::_Create_Backend = OPENGL_BACKEND::GL_Create_Backend;
            // RENDER_BACKEND::OPENGL::OpenGLBackend::SetBackend();
            break;
        case Render_Backend::RB_VULKAN:
            RENDER_COMMON::RENDER_BACKEND::_Create_Backend = nullptr;
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
        auto a = RENDER_COMMON::RENDER_BACKEND::CreateBackend;
        RENDER_COMMON::RENDER_BACKEND::_internal_backend = RENDER_COMMON::RENDER_BACKEND::CreateBackend();
    }
     SharedRef<RENDER_COMMON::CONTEXT_BASE, true> RENDER::Render::RenderSetup::CreateContext()
     {
         PROFILER::TIMERS::SCOPED_TIME time("CreateContext", __FILE__, __FUNCTION__, __LINE__);
         SharedRef<RENDER_COMMON::CONTEXT_BASE, true> cont = RENDER_COMMON::RENDER_BACKEND::CreateContext();
         return cont;
    }
    SharedRef<RENDER_COMMON::WINDOW_BASE, true> RENDER::Render::RenderSetup::Window(int w, int h, std::string Title)
    {
        PROFILER::TIMERS::SCOPED_TIME time("Window", __FILE__, __FUNCTION__, __LINE__);
        SharedRef<RENDER_COMMON::WINDOW_BASE, true>windw = RENDER_COMMON::RENDER_BACKEND::_CreateWindow(w, h, Title.c_str());
        return  windw;
    }
    SharedRef<RENDER_COMMON::WINDOW_BASE, true> RENDER::Render::GetWindow()
    {
        PROFILER::TIMERS::SCOPED_TIME time("GetWindow", __FILE__, __FUNCTION__, __LINE__);
        return Windowvar;
    }
}

