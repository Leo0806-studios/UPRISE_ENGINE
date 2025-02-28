// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <tracy/Tracy.hpp>
#include <tracy/TracyC.h>
#include "PROFILER/PROFILE_EVENTS/PROF_EVENT/PROF_EVENT.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
#include "PROFILER/PROFILE_EVENTS/TIMERS/SCOPED/SCOPED_TIME_EVENT.h"
#include "PROFILER/EVENT_QEUE/EVENT_QEUE.h"
#include <Windows.h>
#include <cassert>
inline UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME::SCOPED_TIME(const char* name, const char* file, const char* function, int line) :
    start(std::chrono::high_resolution_clock::now()),
    name(name),
    file(file),
    function(function),
    line(line)

{
    CaptureStackBackTrace(1, maxFrames, frames, nullptr); //-V2547 //-V2578
}

inline UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME::~SCOPED_TIME() {

    auto dur = std::chrono::high_resolution_clock::now() - start;
    auto duration = dur;
    unsigned int id = std::this_thread::get_id()._Get_underlying_id();
    SCOPED_TIME_EVENT a(name, file, function, line, static_cast<unsigned long long>(duration.count()), frames, maxFrames, id, static_cast<unsigned long long>(start.time_since_epoch().count()));
    std::unique_ptr<EVENT_BASE> aa = std::make_unique<SCOPED_TIME_EVENT>(a);
     EVENT_QEUE::Add_to_Qeue(std::move(aa));
     assert(aa.get() == nullptr); //-V2570 //-V2528 //-V2578
}
