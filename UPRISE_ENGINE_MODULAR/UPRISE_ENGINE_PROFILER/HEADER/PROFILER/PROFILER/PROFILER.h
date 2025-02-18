#pragma once
#ifndef UE_PROFILER_
#define UE_PROFILER_
import std; //-V2575 //-V3549
namespace UPRISE_ENGINE {
    namespace PROFILER {
        class PROFILER {
        private:
            static std::atomic< bool> shudown;
            static std::atomic<bool> shutdown_acknowledged;
             
           UPRISE_PROFILER_API static void CreateProfilerThread(); 
        public:
            UPRISE_PROFILER_API PROFILER();
            UPRISE_PROFILER_API ~PROFILER();
            UPRISE_PROFILER_API static void Start_Profiler();
            UPRISE_PROFILER_API  static void Profiler_Loop();
            UPRISE_PROFILER_API static void Shutdown_Profiler();
            UPRISE_PROFILER_API static void PrintSummary();

        };
    }

}

#endif // !_PROFILER_
