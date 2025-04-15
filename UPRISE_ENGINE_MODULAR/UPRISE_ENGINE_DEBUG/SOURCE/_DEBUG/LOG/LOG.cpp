// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
import UPRISE_ENGINE_DEBUG;
//DEBUG::Error::Error(ErrorCode)
//{
//}
import UPRISE_ENGINE_EE;

namespace UPRISE_ENGINE {
    namespace DEBUG {
#ifndef UPRISE_TESTS
        LOG_STREAM   Debug::_internal_Stream;
#endif // !UPRISE_TESTS
    }

    void DEBUG::Debug::Log(std::string message)
    {
        std::time_t a = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string s = std::to_string(a);
        AccsesStaticVar(_internal_Stream) << "[" << s << "]" << message << "\n";
    }

    void DEBUG::Debug::LogException(std::exception Exception)
    {
        //TODO: implement
    }
     void DEBUG::Debug::LogException(UPRISE_ENGINE::EE::EXCEPTIONS::UPRISE_BASE_EXCEPTION Exception)
    {
         std::time_t a = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
         std::string s = std::to_string(a);
         AccsesStaticVar(_internal_Stream) << "[" << s << "]"  << Exception.What_UE() << "\n";
    }
}

