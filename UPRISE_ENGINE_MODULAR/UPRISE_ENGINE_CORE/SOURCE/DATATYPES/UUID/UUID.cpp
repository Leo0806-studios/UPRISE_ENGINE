// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "UUID/UUID.h"
#include "UUID_INT/UUID_INT.h"
#include "string.h"
UUID UUID::Create()
{
    UUID Ret;
    constexpr int size = sizeof(UUID); // 16 bytes
    static  char  uuid[size]{}; // 16 bytes
    INTERNALS__::createUUID(uuid);
    memcpy(&Ret, uuid, sizeof(UUID));
    return UUID();
}
