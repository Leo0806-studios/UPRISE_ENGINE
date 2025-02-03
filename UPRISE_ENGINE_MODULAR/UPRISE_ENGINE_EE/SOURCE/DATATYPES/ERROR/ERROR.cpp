// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "../../../HEADER/DATATYPES/ERROR/Error.h"
namespace UPRISE_ENGINE {

    namespace EE {
        namespace ERRORS {
            Error::Error(ErrorCode error)
            {
                code = error;
            }
        }
    }
}