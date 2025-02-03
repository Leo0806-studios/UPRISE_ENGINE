#pragma once
#ifndef UE_PROF_EVENT_
#define UE_PROF_EVENT_
import std; //-V3549 //-V2575
import REF_WRAPPER; //-V3549 //-V2575
#include "PROFILER/STACK_FRAMES/STACK_FRAMES.h"
namespace UPRISE_ENGINE {
    namespace PROFILER {
        
        class EVENT_BASE {
        private:
        public:
            EVENT_BASE() =default;
            virtual ~EVENT_BASE() =default;
            virtual std::string What() {
                return "atd::string what() is not overriden";
            }
        };
    }
}

#endif // !_PROF_EVENT_
