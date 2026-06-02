#pragma once
#include <string>
#include <exception>
#include "LOG_STREAM.h"
#include <IMPORT_DEFS.h>
#include <UPRISE_BASE_EXCEPTION.h>
namespace UPRISE_ENGINE {
    namespace DEBUG {
        class Debug {
            static LOG_STREAM _internal_Stream;
        public:
            UPRISE_DEBUG_API static void FlushStream();
            UPRISE_DEBUG_API static void Log(std::string message);
            UPRISE_DEBUG_API static void LogException(std::exception Exception);
            UPRISE_DEBUG_API static void LogException(UPRISE_ENGINE::EE::EXCEPTIONS::UPRISE_BASE_EXCEPTION Exception);
        };
    }
}