export module UPRISE_ENGINE_EE:ERROR_BASE;

namespace UPRISE_ENGINE {
    namespace ERRORS {
        class ERROR_BASE {
            const char* _msg;
        public:
            ERROR_BASE() = default;
            virtual ~ERROR_BASE() = default;
            virtual const char* What() = 0;
        };
    }
}