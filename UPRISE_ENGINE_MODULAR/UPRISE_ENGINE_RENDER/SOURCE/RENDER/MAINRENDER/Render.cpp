// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER/MAINRENDER/Render.h"
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
#include "OPENGL/OPENGL_BACKEND/OPENGL_BACKEND.h"
namespace RENDER_COMMON {

}
void RENDER::Render::SetRenderCamera(RefWrapper<GameObject, true> cam)
{
}
namespace RENDER {
    RefWrapper<RENDER_COMMON::WINDOW_BASE,true> Render::Windowvar ;

}

void RENDER::Render::RenderSetup::SetRenderBackend(Render_Backend backend)
{
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
        break;
    }
}
 void RENDER::Render::RenderSetup::CreateBackend()
{
     auto a = RENDER_COMMON::RENDER_BACKEND::CreateBackend;
    RENDER_COMMON::RENDER_BACKEND::_internal_backend= RENDER_COMMON::RENDER_BACKEND::CreateBackend();
}
  RefWrapper<RENDER_COMMON::WINDOW_BASE, true> RENDER::Render::RenderSetup::Window(int w, int h, const char* Title)
 {
      RefWrapper<RENDER_COMMON::WINDOW_BASE, true>windw = RENDER_COMMON::RENDER_BACKEND::_CreateWindow(w, h, Title);
      return  windw;
 }
RefWrapper<RENDER_COMMON::WINDOW_BASE, true> RENDER::Render::GetWindow()
{
    return Windowvar;
}
