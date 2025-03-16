// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Log_
#define UE_Log_
#include "DATATYPES/LOG_STREAM/LOG_STREAM.h"
#include <cstring>
#pragma warning (push)
#pragma warning (disable:4514)
#ifndef DEBUG_MODULE_BUILD
import std; //-V3549 //-V2575

#endif // !DEBUG_MODULE_BUILD

namespace UPRISE_ENGINE {
    namespace DEBUG {
        class Debug {
            MockableStaticVar(_internal_Stream, LOG_STREAM); //-V1096
            //static UPRISE_DEBUG_API LOG_STREAM _internal_Stream;
        public:

            UPRISE_DEBUG_API static void Log(std::string message);
            UPRISE_DEBUG_API static void LogException(std::exception Exception);
        };
    }
}
 
#pragma warning (pop)

#endif // !_Log_
