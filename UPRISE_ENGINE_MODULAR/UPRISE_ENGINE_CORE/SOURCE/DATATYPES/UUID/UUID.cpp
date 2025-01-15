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
