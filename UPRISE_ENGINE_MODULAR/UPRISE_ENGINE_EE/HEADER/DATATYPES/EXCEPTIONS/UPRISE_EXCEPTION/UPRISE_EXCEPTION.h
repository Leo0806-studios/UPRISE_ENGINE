#pragma once
#ifndef _UPRISE_EXCEPTION_
#define _UPRISE_EXCEPTION_
import std;
namespace UPRISE_ENGINE {

    namespace EE {
        namespace EXCEPTIONS {
            class UPRISE_EXCEPTION:public std::exception {
            private:
            public:
                UPRISE_EXCEPTION() = default;
                ~UPRISE_EXCEPTION() {}
                
            };
        }
    }
}


#endif // !_UPRISE_EXCEPTION_
