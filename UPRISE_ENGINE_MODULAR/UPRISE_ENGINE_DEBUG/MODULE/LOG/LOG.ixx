export module UPRISE_ENGINE_DEBUG:LOG;
import std;
import :LOG_STREAM;
export namespace UPRISE_ENGINE {
    namespace DEBUG {
        class Debug {
            MockableStaticVar(LOG_STREAM, _internal_Stream); //-V1096
            //static UPRISE_DEBUG_API LOG_STREAM _internal_Stream;
        public:

            UPRISE_DEBUG_API static void Log(std::string message);
            UPRISE_DEBUG_API static void LogException(std::exception Exception);
        };
    }
}