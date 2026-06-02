// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <Windows.h>
#include "UUID.h"
#pragma comment(lib, "Rpcrt4.lib")
namespace UPRISE_ENGINE::DATATYPES {
    UUID UUID::Create() {
        UUID uuid{};
        if (auto status =UuidCreate(reinterpret_cast<GUID*>(&uuid)); status != RPC_S_OK) {
            return { 0,0,0,{{0,0,0,0,0,0,0,0} } };
        }
        return uuid;
    }

}
