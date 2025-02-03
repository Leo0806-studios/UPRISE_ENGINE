// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_EVENT_BASE_
#define UE_EVENT_BASE_
#include "PROFILER/PROFILE_EVENTS/PROF_EVENT/PROF_EVENT.h"
import std; //-V3549 //-V2575
namespace UPRISE_ENGINE {
    namespace PROFILER {


        /*class PROFILE_EVENT {
        private:

            EVENT_BASE* event{ nullptr };
        public:
            EVENT_BASE* get() {
                return event;
            }
           inline std::string What() {
                return event->What();
            }
          inline  bool isNull() {
                return event == nullptr;
            }
          PROFILE_EVENT() = default;
           UPRISE_PROFILER_API void Delete();
            template<typename T>
            PROFILE_EVENT(const T& obj) {
                static_assert(std::is_base_of<EVENT_BASE, T>::value, "T must derive from EVENT_BASE");
                event = new T();;
 
                *(static_cast<T*>(event)) = obj;

            }
           UPRISE_PROFILER_API ~PROFILE_EVENT();


            /// <summary>
            /// deleted because it contains a raw pointer
            /// </summary>
            /// <param name="other"></param>
            PROFILE_EVENT(const PROFILE_EVENT& other) = delete;
            /// <summary>
            /// deleted because it contains a raw pointer
            /// </summary>
            /// <param name="other"></param>
            PROFILE_EVENT& operator=(const PROFILE_EVENT& other) = delete;



            UPRISE_PROFILER_API PROFILE_EVENT(PROFILE_EVENT&& other) noexcept;
           UPRISE_PROFILER_API PROFILE_EVENT& operator=(PROFILE_EVENT&& other) noexcept;
        };*/
    }
}

#endif // !_EVENT_BASE_
