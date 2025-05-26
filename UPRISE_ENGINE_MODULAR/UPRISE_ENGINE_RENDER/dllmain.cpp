// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
import <Windows.h>;

import UPRISE_ENGINE_DEBUG;

#pragma warning(disable: 4100)


BOOL APIENTRY DllMain( HMODULE hModule, //-V2575 //-V2537 //-V3523 //-V3549
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        UPRISE_ENGINE::DEBUG::Debug::Log( "Attatching Render Module to procces\n");
        UPRISE_ENGINE::DEBUG::Debug::Log(std::string("\nreason: " + std::to_string(ul_reason_for_call)));
        break;
    case DLL_THREAD_ATTACH:
        UPRISE_ENGINE::DEBUG::Debug::Log("Attatching Render Module to thread\n");
        UPRISE_ENGINE::DEBUG::Debug::Log(std::string("\nreason: " + std::to_string(ul_reason_for_call)));

        break;
    case DLL_THREAD_DETACH:
        UPRISE_ENGINE::DEBUG::Debug::Log("Detatching Render Module from thread\n");
        UPRISE_ENGINE::DEBUG::Debug::Log(std::string("\n reason: " + std::to_string(ul_reason_for_call)));

        break;
    case DLL_PROCESS_DETACH:
        UPRISE_ENGINE::DEBUG::Debug::Log("Detatching Render Module\n");
        UPRISE_ENGINE::DEBUG::Debug::Log(std::string("\n reason: " + std::to_string(ul_reason_for_call)));

        break;
    }
    return TRUE;
}


#pragma warning(default: 4100)