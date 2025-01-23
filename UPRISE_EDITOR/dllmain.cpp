// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
//#include "pch.h"


#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include "HEADER/DLL_LINK.h"
#include "HEADER/H_IMGUI.h"
#include <windows.h>
import std;
import SCRIPT_EDITOR_MODULE_DEF;

ImGuiIO* io;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
void(*DRAWp)();
#define EX __declspec(dllexport)
extern "C" {

    EX void INIT(ImGuiContext* ctx) {
        std::cout << "EDITOR START";
        ImGui::SetCurrentContext(ctx);
        //ImGui::CreateContext();
        //io = &ImGui::GetIO();
        //io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        //io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        //io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Gamepad Controls
        //ImGui_ImplGlfw_InitForOpenGL(Window, true);
        //ImGui_ImplOpenGL3_Init();
    }
    EX void DRAW() {
        {
            
           // ImGui_ImplOpenGL3_NewFrame();
         //   ImGui_ImplGlfw_NewFrame();
          //  ImGui::NewFrame();
            std::cout << "EDITOR DRAW PLACEHOLDER";
            SCRIPT_EDITOR::Editor::DrawEditor();

            ImGui::Render();
            //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            ////if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            ////{
            //GLFWwindow* backup_current_context = glfwGetCurrentContext();
            //ImGui::UpdatePlatformWindows();
            //ImGui::RenderPlatformWindowsDefault();
            //glfwMakeContextCurrent(backup_current_context);
            //DRAWp();

        }
    }
    EX void SHUTDOWN() {

    }
    EX void UPDATE_FUNC_PTR(void(*drawptr)() ) {
        DRAWp = drawptr;
    }


}

