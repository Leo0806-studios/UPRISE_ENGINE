// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// UPRISE_EDITOR_APPLICATION.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RENDER/MAINRENDER/Render.h"
#include "DEBUG/LOG/LOG.h"
#include <RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h>
#include <RENDER/WINDOW/WINDOW.h>

int main()
{
    DEBUG::Log << "Editor Application startup";
    DEBUG::Log << "difiwreugjoeifjerowgewriofuoidiogjuopergksporefkiwrop5fikw9vtiaeopceriojoöerfjtrugwopgujoqwfujq49fujot";
    Log << "Editor Application startup";
    RENDER::Render::RenderSetup::SetRenderBackend(RENDER::Render_Backend::RB_OPENGL);
    RENDER::Render::RenderSetup::CreateBackend();
   auto window= RENDER::Render::RenderSetup::Window(800, 600, "UPRISE_EDITOR");
   std::cout << "Window created";

    std::string s;
    std::cin >> s; 
    RefWrapper<RENDER::Window, true>wind = WrapRef<RENDER::Window, true>();
    wind->SetWindow(window);
    std::cout << "destroying window";
    RENDER::Window::DestroyWindow(wind);

    std::cin >> s;
    //startup

    //load all modules

    //load all plugins

    //load all assets

    //load all scenes

    //load all scripts

    //load all prefabs

    //main loop
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file