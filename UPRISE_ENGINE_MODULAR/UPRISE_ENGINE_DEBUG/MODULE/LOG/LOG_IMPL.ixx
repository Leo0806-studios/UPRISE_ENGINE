export module UPRISE_ENGINE_DEBUG:LOG_IMPL;
import :LOG;
export namespace UPRISE_ENGINE {
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
}