#pragma once
#include <chrono>
#include <MACROS.h>

namespace UPRISE_ENGINE {
    namespace PROFILER {
        namespace TIMERS {
#pragma warning(push)
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
#pragma warning(pop)
        }
    }
    using ScopedTimer = PROFILER::TIMERS::SCOPED_TIME;
}