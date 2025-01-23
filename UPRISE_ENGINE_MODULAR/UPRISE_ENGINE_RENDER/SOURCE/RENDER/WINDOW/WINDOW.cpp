// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER/WINDOW/WINDOW.h"
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"


 RefWrapper<RENDER_COMMON::WINDOW_BASE, true> RENDER::Window::_CreateWindow(int w, int h, const char* title)
{

     return  RENDER_COMMON::RENDER_BACKEND::_CreateWindow(w, h, title);
}

  void RENDER::Window::DestroyWindow(RefWrapper<Window,true> window)
 {
      RENDER_COMMON::RENDER_BACKEND::DestroyWindow(window->Windowvar);
 }
