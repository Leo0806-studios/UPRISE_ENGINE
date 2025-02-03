#pragma once
#ifndef _SCOPED_TIME_EVENT_
#define _SCOPED_TIME_EVENT_
import std;
#include "PROFILER/PROFILE_EVENTS/PROF_EVENT/PROF_EVENT.h"
namespace UPRISE_ENGINE {
    namespace PROFILER {
        namespace TIMERS {
            class SCOPED_TIME_EVENT : public EVENT_BASE {
            private:
                const char* name;
                const char* file;
                const char* function;
                int line;
                long double duration;
                void* frames[maxFrames];
                int threadId;
                UPRISE_PROFILER_API std::string ResolveSybols() const;
              UPRISE_PROFILER_API  std::string GetStacktrace() const;

            public:
                SCOPED_TIME_EVENT() = default;

                UPRISE_PROFILER_API SCOPED_TIME_EVENT(const char* name, const char* file, const char* function, int line, long double duration, void** frames, size_t countFrames,int threadid);
                UPRISE_PROFILER_API  ~SCOPED_TIME_EVENT() = default;
                std::string What() override {
                    std::ostringstream s;
                    s << "=====================SCOPED_TIME_EVENT=====================\n"
                        << "Event: " << name << "\n"
                        << "Thread: " << std::to_string(threadId) << "\n"
                        << " in " << file << "\n"
                        << " at " << function << "\n"
                        << " at line " << std::to_string(line) << "\n"
                        << " took ";
                    if (duration < 1000) {
                        s << std::to_string(duration) << " nanoseconds"<< "\n";

                    }
                    else {
                        size_t dur = duration / 1000;
                        if (dur < 1000) {
                            s << std::to_string(dur) << " microseconds"<< "\n";

                        }
                        else {
                            s << std::to_string(dur / 1000) <<" milliseconds"<< "\n";


                        }
                    }
                    s << "Stacktrace:\n"
                   << ResolveSybols()
                     << "==========================================================\n";
                    return s.str();
                }
            };
        }
    }
}

#endif // !_SCOPED_TIME_EVENT_
