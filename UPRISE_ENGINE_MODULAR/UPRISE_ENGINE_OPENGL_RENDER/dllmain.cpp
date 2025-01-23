// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
#include "Windows.h"
import std;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::cout << "attatching OPENGL render module to process \n";
        break;
    case DLL_THREAD_ATTACH:
        std::cout << "attatching OPENGL render module to thread\n";
        break;
    case DLL_THREAD_DETACH:
        std::cout << "detatching OPENGL render module from thread\n";
        break;
    case DLL_PROCESS_DETACH:
        std::cout << "detatching OPENGL render module\n";
        break;
    }
    return TRUE;
}

