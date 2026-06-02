#pragma once
#include <exception>
#include <IMPORT_DEFS.h>
namespace UPRISE_ENGINE {
    namespace EE {
        namespace EXCEPTIONS {
            class UPRISE_BASE_EXCEPTION :public std::exception {
            private:
                const char* _msg;
            public:
                UPRISE_BASE_EXCEPTION(const char* msg) :std::exception(msg), _msg(msg) {}
                virtual  ~UPRISE_BASE_EXCEPTION() = default;
                UPRISE_ENGINE_EE_API virtual const char* What_UE();
            };
        }
    }
}