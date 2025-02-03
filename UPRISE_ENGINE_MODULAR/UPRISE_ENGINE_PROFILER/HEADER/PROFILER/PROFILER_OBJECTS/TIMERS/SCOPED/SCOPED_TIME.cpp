#include "PROFILER/PROFILE_EVENTS/PROF_EVENT/PROF_EVENT.h"
#include "SCOPED_TIME.h"
#include "PROFILER/PROFILE_EVENTS/TIMERS/SCOPED/SCOPED_TIME_EVENT.h"
#include "PROFILER/EVENT_QEUE/EVENT_QEUE.h"
#include "Windows.h"
#include "cassert"
inline UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME::SCOPED_TIME(const char* name, const char* file, const char* function, int line) :
    name(name),
    file(file),
    function(function),
    line(line),
    start(std::chrono::high_resolution_clock::now())
{
    auto a = CaptureStackBackTrace(0, maxFrames, frames, nullptr);


    //std::cout << "SCOPED_TIME: " << name << " in " << file << " at " << function << " at line " << line << std::endl;
}

inline UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME::~SCOPED_TIME() {
    //auto dur = end - start;
    //std::cout << "dur    " << dur.count() << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
    //auto a = UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT(name, file, function, line, duration.count(), std::move(frames));
    int id = std::this_thread::get_id()._Get_underlying_id();
    //PROFILE_EVENT b(SCOPED_TIME_EVENT(name, file, function, line, duration.count(), frames, maxFrames, id));
    SCOPED_TIME_EVENT a(name, file, function, line, duration.count(), frames, maxFrames, id);
    std::unique_ptr<EVENT_BASE> aa = std::make_unique<SCOPED_TIME_EVENT>(a);
     EVENT_QEUE::Add_to_Qeue(std::move(aa));
     assert(aa.get() == nullptr);
}
