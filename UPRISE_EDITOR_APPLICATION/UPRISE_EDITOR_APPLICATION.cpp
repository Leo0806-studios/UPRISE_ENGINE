// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// UPRISE_EDITOR_APPLICATION.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import REF_WRAPPER;
#include <iostream>
#include "RENDER/MAINRENDER/Render.h"
#include "DEBUG/LOG/LOG.h"
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
#include "RENDER/WINDOW/WINDOW.h"
#include "PROFILER/PROFILER/PROFILER.h"
#include <Windows.h>
#include "PROFILER/PROFILER_OBJECTS/ALLOC/ALLOC_OBJECT.h"
#include <PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h>
#include <Windows.h>
#pragma comment(lib, "UPRISE_ENGINE_PROFILER.lib")
#pragma comment(lib, "UPRISE_ENGINE_DEBUG.lib")
#pragma comment(lib, "UPRISE_ENGINE_ECS.lib")
#pragma comment(lib, "UPRISE_ENGINE_CORE.lib")
#pragma comment(lib, "UPRISE_ENGINE_RENDER.lib")
#pragma comment(lib, "UPRISE_ENGINE_OPENGL_RENDER.lib")
#pragma comment(lib, "UPRISE_ENGINE_COMMON_RENDER_COMPS.lib")
#pragma comment(lib, "UPRISE_ENGINE_DX11_RENDER.lib")
#pragma comment(lib, "UPRISE_ENGINE_VULKAN_RENDER.lib")
#pragma comment(lib, "UPRISE_ENGINE_DX12_RENDER.lib")
class FrameTimer {
public:
    FrameTimer(size_t bufferSize = 100) : maxSamples(bufferSize) {}

    void recordFrame() {
        // Get current time
        auto now = std::chrono::high_resolution_clock::now();

        // Calculate frame time if we have a previous timestamp
        if (lastFrameTime.time_since_epoch().count() != 0) {
            double frameTime = std::chrono::duration<double, std::milli>(now - lastFrameTime).count();
            frameTimes.push_back(frameTime);
            auto a = frameTimes.size();
            if (a >= maxSamples) {
                frameTimes.pop_front();

            }
        }

        // Update last frame time
        lastFrameTime = now;
    }

    double getAverageFPS() const {
        if (frameTimes.empty()) return 0.0;

        double avgFrameTime = std::accumulate(frameTimes.begin(), frameTimes.end(), 0.0) / static_cast<double>(frameTimes.size());
        return 1000.0 / avgFrameTime; // Convert ms to FPS
    }

private:
    std::deque<double> frameTimes;
    size_t maxSamples;
    std::chrono::high_resolution_clock::time_point lastFrameTime;
};







void Frame() {
    SCOPED_TIME_
    UPRISE_ENGINE::RENDER_COMMON::RENDER_BACKEND::PreFrameWork();
    UPRISE_ENGINE::RENDER_COMMON::RENDER_BACKEND::PostFrameWork();
}
int main()
{
    //auto now = std::chrono::system_clock::now();
    //auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
    //    now.time_since_epoch()).count();
    //std::cout << timestamp << std::endl;
    //std::time_t timeInSeconds = timestamp / 1000;
 
    //std::tm localTime;
    //localtime_s(&localTime, &timeInSeconds);

    ////std::cout << "Local time: " << std::asctime(localTime) << std::endl;
    //char buffer[100];
    //std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",& localTime);
    //std::cout << "Formatted time: " << buffer << std::endl;
    //InstallHeapCallback();
    UPRISE_ENGINE::PROFILER::PROFILER::Start_Profiler();
    UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME a(__FUNCSIG__, __FILE__, __FUNCTION__, __LINE__);


    UPRISE_ENGINE::DEBUG::Debug::Log("rjghaijfoaifjiogdjiuvioiijijijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
    UPRISE_ENGINE::DEBUG::Log << "Editor Application startup";
    UPRISE_ENGINE::DEBUG::Log << "difiwreugjoeifjerowgewriofuoidiogjuopergksporefkiwrop5fikw9vtiaeopceriojoöerfjtrugwopgujoqwfujq49fujot";
    UPRISE_ENGINE::DEBUG::Log << "Editor Application startup";

    UPRISE_ENGINE::RENDER::Render::RenderSetup::Setup(800, 600, "UPRISE_EDITOR", UPRISE_ENGINE::RENDER::Render_Backend::RB_OPENGL);
    FrameTimer frameTimer(10000);

    std::string s;
    int conter = 0;
    MSG msg = { 0 };
    while (msg.message != WM_QUIT) {
        frameTimer.recordFrame();
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Frame();
        UPRISE_ENGINE::RENDER::Render::DisplayFpsInMainWindowTitle(frameTimer.getAverageFPS());

    }
    std::cin >> s; 
  /*  OwnedRef<UPRISE_ENGINE::RENDER::Window>wind = CreateRefs::CreateOwnedRef<UPRISE_ENGINE::RENDER::Window>();
    WeakRef<UPRISE_ENGINE::RENDER::Window, true> weakwind = wind.GetWeakRef();*/

    /*wind->SetWindow(std::move(window));*/
    
    std::cout << "destroying window";
   /* UPRISE_ENGINE::RENDER::Window::DestroyWindow(std::move(wind));*/

    UPRISE_ENGINE::RENDER::Render::RenderShutdown::Shutdown();

    std::cin >> s;
    //startup

    //load all modules

    //load all plugins

    //load all assets

    //load all scenes

    //load all scripts

    //load all prefabs

    //main loop
    //UPRISE_ENGINE::PROFILER::PROFILER::Shutdown_Profiler();
}
class shutdownprofiler { //-V2575 //-V3549
public:
    shutdownprofiler() = default;
    void ShutdwonLag() {
        UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME a(__FUNCSIG__, __FILE__, __FUNCTION__, __LINE__);
        //  Sleep(1000); improved shutdown time
    }
    ~ shutdownprofiler() {
        std::cout << "shutting down profiler";
        ShutdwonLag();
        UPRISE_ENGINE::PROFILER::PROFILER::Shutdown_Profiler();
    }
};
 shutdownprofiler eee; //-V2575 //-V3549
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file