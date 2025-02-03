// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Error_
#define UE_Error_
namespace UPRISE_ENGINE {

    namespace EE {
        namespace ERRORS {
            enum ErrorCode {
                LowMemory,
                NoMatchinngComponentFoud,
            };
            class Error {
            private:
                ErrorCode code;

            public:
                /// <summary>
                /// consturctor
                /// </summary>
                Error() = default;
                /// <summary>
                /// constructor with errorcode
                /// </summary>
            /// <param name="errorCode"></param>
                Error(ErrorCode code);
                ~Error() = default;
            };
        }
    }
}

#endif // !_Error_
