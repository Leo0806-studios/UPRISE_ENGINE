// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_EVENT_QEUE_
#define UE_EVENT_QEUE_
import std; //-V3549 //-V2575
import REF_WRAPPER; //-V3549 //-V2575
#include "PROFILER/PROFILE_EVENTS/PROF_EVENT/PROF_EVENT.h"
namespace UPRISE_ENGINE {
    namespace PROFILER {
        class EVENT_QEUE {
        private:


            UPRISE_PROFILER_API static  std::vector<std::unique_ptr<EVENT_BASE>> qeue;
            UPRISE_PROFILER_API static std::vector<std::unique_ptr<EVENT_BASE>> UsedQeue;
        public:
            static inline size_t getUsedQeueSize() {
                return UsedQeue.size();
            }

          //static   void shrink_to_fit() {
          //      qeue.shrink_to_fit();
          //  }

            // UPRISE_PROFILER_API static std::mutex m;
            UPRISE_PROFILER_API static std::mutex& GetMutex();
            UPRISE_PROFILER_API static void Add_to_Qeue(std::unique_ptr<EVENT_BASE>&& event);
            UPRISE_PROFILER_API static void UseCurrentQeue();

            /// <summary>
            /// gets the first event and removes it from the qeue
            /// </summary>
            /// <returns></returns>
            UPRISE_PROFILER_API static std::unique_ptr<EVENT_BASE> Get_Last_Event();
            static size_t Get_Qeue_Size() {
                std::unique_lock<std::mutex> lock(GetMutex());
                return qeue.size();
            }
            EVENT_QEUE();
            ~EVENT_QEUE();
        };
    }
}

#endif // !_EVENT_QEUE_

