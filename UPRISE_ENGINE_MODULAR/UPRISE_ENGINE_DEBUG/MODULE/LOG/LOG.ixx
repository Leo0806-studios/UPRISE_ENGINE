export module UPRISE_ENGINE_DEBUG:LOG;
import std;
import :LOG_STREAM;
import UPRISE_ENGINE_EE;
export namespace UPRISE_ENGINE {
    namespace DEBUG {
        class Debug {
            MockableStaticVar( _internal_Stream, LOG_STREAM); //-V1096
        public:
            UPRISE_DEBUG_API static void FlushStream();
            UPRISE_DEBUG_API static void Log(std::string message);
            UPRISE_DEBUG_API static void LogException(std::exception Exception);
            UPRISE_DEBUG_API static void LogException(UPRISE_ENGINE::EE::EXCEPTIONS::UPRISE_BASE_EXCEPTION Exception);
        };
    }
}