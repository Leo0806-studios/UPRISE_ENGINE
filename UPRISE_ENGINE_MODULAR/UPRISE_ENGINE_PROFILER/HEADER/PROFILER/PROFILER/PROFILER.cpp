// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "PROFILER.h"
#include "PROFILER/EVENT_QEUE/EVENT_QEUE.h"
#include "PROFILER/PROFILE_STREAM/PROFILE_STREAM.h"
#include "PROFILER/PROFILER_INIT/PROFILER_INIT.h"
namespace  UPRISE_ENGINE {
    namespace PROFILER {
        PROFILE_STREAM ProfilerStream;
        std::atomic< bool> PROFILER::shudown = false;
        std::atomic<bool> PROFILER::shutdown_acknowledged = false;
        std::thread ProfilerThread;

        void ProfileLog(std::string message)
        {
   /*         std::time_t a = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            unsigned long long aaa = a;
            std::string s = std::to_string(a);*/
            ProfilerStream  << message << "\n";
        }
    }
}
 void UPRISE_ENGINE::PROFILER::PROFILER::Profiler_Loop()
 {
     std::cout << "Profiler loop started\n";
     ProfileLog("Profiler loop started");
     while (!shudown)
     {
         if (UPRISE_ENGINE::PROFILER::EVENT_QEUE::Get_Qeue_Size() > 0)
         {
             EVENT_QEUE::UseCurrentQeue();

             while (EVENT_QEUE::getUsedQeueSize() > 0)
             {
                // auto start = std::chrono::high_resolution_clock::now();
                 if (auto event = EVENT_QEUE::Get_Last_Event())
                 {
                     ProfileLog(event->What());
                 }
               //  auto end = std::chrono::high_resolution_clock::now();
               //  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
               //  std::cout << duration;

             }
         }
     }
     ProfileLog("Profiler loop ended");
     std::cout << "Profiler loop ended\n";
     shutdown_acknowledged = true;
 }
  void UPRISE_ENGINE::PROFILER::PROFILER::Shutdown_Profiler()
 {
      std::cout << "_____Shutting down profiler______\n";
      shudown = true;
      while (!shutdown_acknowledged) { //-V776
          std::cout << "Waiting for profiler to shutdown\n";
      }
      if (ProfilerThread.joinable())
      {
          ProfilerThread.join();
      }
 }
 void UPRISE_ENGINE::PROFILER::PROFILER::Start_Profiler()
 {
     ProfilerStream= std::move(PROFILE_STREAM(true));
     Profiler_started(1);
     CreateProfilerThread();
 }
 void UPRISE_ENGINE::PROFILER::PROFILER::CreateProfilerThread()
 {
     ProfilerThread = std::thread(Profiler_Loop);
     std::cout << "Profiler thread started\n";
     std::cout << "Profiler thread detached\n";
 }
 UPRISE_ENGINE::PROFILER::PROFILER::PROFILER()
 {
 }
 UPRISE_ENGINE::PROFILER::PROFILER::~PROFILER()
 {
 }
