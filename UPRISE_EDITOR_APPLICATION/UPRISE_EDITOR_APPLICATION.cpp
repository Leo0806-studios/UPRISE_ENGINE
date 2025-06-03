// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// UPRISE_EDITOR_APPLICATION.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef __INTELLISENSE__
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_RENDER_INTELLISENSE_FIX.h"
import UPRISE_ENGINE_DEBUG;
import UPRISE_ENGINE_PROFILER;
import <Windows.h>;
#else

import<iostream>;
import <Windows.h>;
import <chrono>;
import <deque>;
import <numeric>;
import <string>;
import <algorithm>;

import UPRISE_ENGINE_PROFILER;
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_DEBUG;
import UPRISE_ENGINE_ECS;
import UPRISE_ENGINE_RENDER;
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
#endif // __INTELLISENSE__


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
    UPRISE_ENGINE::RENDER::RENDER_COMMON::RENDER_BACKEND::PreFrameWork();
    UPRISE_ENGINE::RENDER::RENDER_COMMON::RENDER_BACKEND::PostFrameWork();
}
int main()
{
    UPRISE_ENGINE::PROFILER::PROFILER::Start_Profiler();
    UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME a(__FUNCSIG__, __FILE__, __FUNCTION__, __LINE__);


    UPRISE_ENGINE::DEBUG::Debug::Log("rjghaijfoaifjiogdjiuvioiijijijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
    UPRISE_ENGINE::DEBUG::Debug::Log ( "Editor Application startup");
    UPRISE_ENGINE::DEBUG::Debug::Log( "difiwreugjoeifjerowgewriofuoidiogjuopergksporefkiwrop5fikw9vtiaeopceriojoöerfjtrugwopgujoqwfujq49fujot");
    UPRISE_ENGINE::DEBUG::Debug::Log ( "Editor Application startup");

    UPRISE_ENGINE::RENDER::Render::RenderSetup::Setup(800, 600, "UPRISE_EDITOR", UPRISE_ENGINE::RENDER::Render_Backend::RB_OPENGL);
    FrameTimer frameTimer(10000);

    std::string s;
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
    
    std::cout << "destroying window";

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