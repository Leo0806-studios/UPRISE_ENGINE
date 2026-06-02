// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "LOG.h"
#include "LOG_STREAM.h"
#include <UPRISE_BASE_EXCEPTION.h>
#include <ANOTATIONS.h>

namespace UPRISE_ENGINE {
    namespace DEBUG {
        LOG_STREAM   Debug::_internal_Stream;
    }

     void DEBUG::Debug::FlushStream()
    {
         _internal_Stream.Flush();
    }

    void DEBUG::Debug::Log(std::string message)
    {
        std::time_t a = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string s = std::to_string(a);
        _internal_Stream << "[" << s << "]" << message << "\n";
    }

    void DEBUG::Debug::LogException(std::exception Exception)
    {
        UE_UNUSED_PARAMETER(Exception);
        //TODO: implement
    }
     void DEBUG::Debug::LogException(UPRISE_ENGINE::EE::EXCEPTIONS::UPRISE_BASE_EXCEPTION Exception)
    {
         std::time_t a = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
         std::string s = std::to_string(a);
         _internal_Stream << "[" << s << "]"  << Exception.What_UE() << "\n";
    }
}

