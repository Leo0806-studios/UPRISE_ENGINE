// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Log_
#define UE_Log_
//#include "../pch.h"
#include <cstring>
#pragma warning (push)
#pragma warning (disable:4514)
import std; //-V3549 //-V2575
namespace UPRISE_ENGINE {
    namespace DEBUG {
        class LOG_STREAM;
        class LOG_STREAM {
        private:
            std::mutex mutex;
            std::stringstream stream;
            unsigned long long length;
            unsigned long long autoFlushLength;
            std::filesystem::path LogPath;
            std::ofstream LogFile;
            bool autoFlush = true;
            char PAD[7];   //TODO find a better way to align this or find data to put here

        public:
            LOG_STREAM(const LOG_STREAM&) = delete;
            LOG_STREAM& operator=(const LOG_STREAM&) = delete;
            UPRISE_DEBUG_API void Flush();
            bool toggleAutoFlush();
            UPRISE_DEBUG_API LOG_STREAM();
            UPRISE_DEBUG_API ~LOG_STREAM();
            UPRISE_DEBUG_API LOG_STREAM& operator<<(const std::string& value);
            UPRISE_DEBUG_API LOG_STREAM& operator<<(const char* value);



        };
        class Debug {
            MockableStaticVar(LOG_STREAM, _internal_Stream); //-V1096
            //static UPRISE_DEBUG_API LOG_STREAM _internal_Stream;
        public:

            UPRISE_DEBUG_API static void Log(std::string message);
            UPRISE_DEBUG_API static void LogException(std::exception Exception);
        };
        
        UPRISE_DEBUG_API MockableGlobalVar(LOG_STREAM, Log);
        UPRISE_DEBUG_API MockableGlobalVar(LOG_STREAM, LogExeption);
        UPRISE_DEBUG_API MockableGlobalVar(LOG_STREAM, LogWarning);
        //UPRISE_DEBUG_API LOG_STREAM Log;
        //UPRISE_DEBUG_API LOG_STREAM LogExeption;
        //UPRISE_DEBUG_API LOG_STREAM LogWarning;

    }
    ;
    using Debug = UPRISE_ENGINE::DEBUG::Debug;
}
 
#pragma warning (pop)

#endif // !_Log_
