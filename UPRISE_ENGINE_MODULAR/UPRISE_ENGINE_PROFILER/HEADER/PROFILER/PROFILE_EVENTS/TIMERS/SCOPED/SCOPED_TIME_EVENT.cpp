#include "SCOPED_TIME_EVENT.h"
#include <cassert>
#include "Windows.h"
#include <DbgHelp.h>

//inline UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::SCOPED_TIME_EVENT(const SCOPED_TIME_EVENT& other) {
//    this->name = other.name;
//    this->file = other.file;
//    this->function = other.function;
//    this->line = other.line;
//    this->duration = other.duration;
//    this->frames = std::move(other.frames);
//}
//
//UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::SCOPED_TIME_EVENT(SCOPED_TIME_EVENT&& other) noexcept
//{
//    this->name = std::move(other.name);
//    this->file = std::move(other.file);
//    this->function = std::move(other.function);
//    this->line = std::move(other.line);
//    this->duration = std::move(other.duration);
//    this->frames = std::move(other.frames);
//    other.name = nullptr;
//    other.file = nullptr;
//    other.function = nullptr;
//    other.line = 0;
//    other.duration = 0;
//
//
//}
HANDLE getHandle() {
    static HANDLE h = GetCurrentProcess();
    return h;
}
std::string UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::ResolveSybols() const  
{  
   std::string result;  
   static bool symInitialized = false;  
   if (!symInitialized) {  
       SymInitialize(getHandle(), NULL, TRUE);  
       symInitialized = true;  
   }  
   static char symbolBuffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];  
   PSYMBOL_INFO symbol = reinterpret_cast<PSYMBOL_INFO>(symbolBuffer);  
   symbol->SizeOfStruct = sizeof(SYMBOL_INFO);  
   symbol->MaxNameLen = MAX_SYM_NAME;  
   static std::unordered_map<void*, std::string> symbolCache;
   for (size_t i = 0; i < maxFrames && frames[i] != nullptr; i++) {  
       if (symbolCache.find(frames[i]) != symbolCache.end()) {
           result += symbolCache[frames[i]];
           continue;
       }
       DWORD64 displacement = 0;  
       if (SymFromAddr(getHandle(), reinterpret_cast<DWORD64>(frames[i]), &displacement, symbol)) {  
           std::string symbolInfo = "Symbol: " + std::string(symbol->Name) + " Displacement: " + std::to_string(displacement) + "\n";
           result += symbolInfo;
           symbolCache[frames[i]] = symbolInfo;
       } else {  
           result += "Failed to get symbol\n";  
       }  
   }  
   return result;  
}
inline UPRISE_PROFILER_API std::string UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::GetStacktrace() const {
    std::ostringstream s;
    s << "Stacktrace:\n";
    for (size_t i = 0; i < maxFrames && frames[i] != nullptr; i++) {
        s << i << ": " << reinterpret_cast<size_t>(frames[i]) << "\n";
    }
    return s.str();
}

inline UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME_EVENT::SCOPED_TIME_EVENT(const char* name, const char* file, const char* function, int line, long double duration, void** frames, size_t countFrames,int threadid) :
    name(name),
    file(file),
    function(function),
    line(line),
    duration(duration),
    threadId(threadid)
{
    assert((countFrames ) <= maxFrames);
    for (size_t i = 0; i < countFrames; i++) {

        this->frames[i] = frames[i];
    }
}


