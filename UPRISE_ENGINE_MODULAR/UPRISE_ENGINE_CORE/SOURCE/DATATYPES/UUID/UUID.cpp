// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "UUID/UUID.h"
#include <string.h>
#include <Windows.h>
#pragma comment(lib, "Rpcrt4.lib")
void UUIDCREATE(char* uuid)
{
    UUID uid;
    RPC_STATUS status = UuidCreate(&uid);
    if (status != RPC_S_OK) {
        // Handle error appropriately, for now we will just zero out the UUID
        memset(&uid, 0, sizeof(UUID));
    }
    memcpy(uuid, &uid, sizeof(UPRISE_ENGINE::UUID));
}
namespace UPRISE_ENGINE {
     UUID::UUID(const UUID& other) noexcept :Data(other.Data) {}

     UUID::UUID(UUID&& other) noexcept :Data(std::move(other.Data)) {}

     UUID& UUID::operator=(const UUID& other) noexcept {
        Data = other.Data;
        return *this;
    }

     UUID& UUID::operator=(UUID&& other) noexcept {
        Data = std::move(other.Data);
        return *this;
    }


    UPRISE_ENGINE::UUID UPRISE_ENGINE::UUID::Create()
    {
       UPRISE_ENGINE:: UUID Ret;
        constexpr int size = sizeof(UUID); // 16 bytes
          char  uuid[size]{}; // 16 bytes
          UUIDCREATE(uuid);
        memcpy(&Ret, static_cast<char*>(uuid), sizeof(UUID));
        return Ret;
    }

}
