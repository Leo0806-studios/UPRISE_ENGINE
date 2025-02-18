// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_SCOPED_TIME_
#define UE_SCOPED_TIME_
import std; //-V2575
namespace  UPRISE_ENGINE {
    namespace PROFILER {
        namespace TIMERS {
#pragma warning(disable: 4820)
            class SCOPED_TIME {
            private:
                std::chrono::time_point<std::chrono::high_resolution_clock> start;
                const char* name;
                const char* file;
                const char* function;
                void* frames[maxFrames];
                int line;

            public:
                SCOPED_TIME() = default;
               UPRISE_PROFILER_API SCOPED_TIME(const char* name, const char* file, const char* function, int line);
               UPRISE_PROFILER_API  ~SCOPED_TIME();
            };
#pragma warning(default: 4820)
        }
    }
    using ScopedTimer = PROFILER::TIMERS::SCOPED_TIME;
}
#define SCOPED_TIME_  UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME scoped_time(__FUNCSIG__,__FILE__,__FUNCTION__,__LINE__);
#endif // !_SCOPED_TIME_
