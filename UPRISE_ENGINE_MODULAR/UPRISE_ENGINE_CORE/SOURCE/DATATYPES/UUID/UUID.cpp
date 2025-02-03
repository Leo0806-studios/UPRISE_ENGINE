// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "UUID/UUID.h"
#include "UUID_INT/UUID_INT.h"
#include "string.h"
namespace UPRISE_ENGINE {
    UUID UUID::Create()
    {
        UUID Ret;
        constexpr int size = sizeof(UUID); // 16 bytes
          char  uuid[size]{}; // 16 bytes
        INTERNALS__::createUUID(static_cast<char*>(uuid));
        memcpy(&Ret, static_cast<char*>(uuid), sizeof(UUID));
        return Ret;
    }

}
