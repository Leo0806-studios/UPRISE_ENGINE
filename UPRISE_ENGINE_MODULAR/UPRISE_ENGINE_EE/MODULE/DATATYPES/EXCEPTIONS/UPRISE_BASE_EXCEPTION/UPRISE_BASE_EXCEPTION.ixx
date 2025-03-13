export module UPRISE_ENGINE_EE:UPRISE_BASE_EXCEPTION;
import std;
export namespace UPRISE_ENGINE {
    namespace EE {
        namespace EXCEPTIONS {
            class UPRISE_BASE_EXCEPTION :public std::exception {
            private:
                const char* _msg;
            public:
                UPRISE_BASE_EXCEPTION(const char* msg) :std::exception(msg), _msg(msg) {}
                virtual  ~UPRISE_BASE_EXCEPTION() {}
                virtual const char* What_UE() {
                    return _msg;

                };
            };
        }
    }
}