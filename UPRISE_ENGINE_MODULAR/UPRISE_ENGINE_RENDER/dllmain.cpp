// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "DEBUG/LOG/Log.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Log << "Attatching Render Module to procces\n";
        break;
    case DLL_THREAD_ATTACH:
        Log << "Attatching Render Module to thread\n";
        break;
    case DLL_THREAD_DETACH:
        Log << "Detatching Render Module from thread\n";
        break;
    case DLL_PROCESS_DETACH:
        Log << "Detatching Render Module\n";
        break;
    }
    return TRUE;
}

