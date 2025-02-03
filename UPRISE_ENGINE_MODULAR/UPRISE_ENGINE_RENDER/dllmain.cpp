// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
#include "Windows.h"

#include "DEBUG/LOG/Log.h"

BOOL APIENTRY DllMain( HMODULE hModule, //-V2575 //-V2537 //-V3523 //-V3549
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        UPRISE_ENGINE::DEBUG::Debug::Log( "Attatching Render Module to procces\n");
        break;
    case DLL_THREAD_ATTACH:
        UPRISE_ENGINE::DEBUG::Debug::Log("Attatching Render Module to thread\n");
        break;
    case DLL_THREAD_DETACH:
        UPRISE_ENGINE::DEBUG::Debug::Log("Detatching Render Module from thread\n");
        break;
    case DLL_PROCESS_DETACH:
        UPRISE_ENGINE::DEBUG::Debug::Log("Detatching Render Module\n");
        break;
    }
    return TRUE;
}

