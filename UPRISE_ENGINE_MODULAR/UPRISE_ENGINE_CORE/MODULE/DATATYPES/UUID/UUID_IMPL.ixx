module;
#include "Windows.h"
#pragma comment(lib, "Rpcrt4.lib")

export module UPRISE_ENGINE_CORE:UUID_IMPL;
import std;
import :UUID;
export namespace UPRISE_ENGINE {
    struct UUID_TRANSFER {
        unsigned int Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[8];
    };
    void UUID_CREATE(UUID_TRANSFER* uuid)
    {
        ::UUID uid;
        RPC_STATUS status = UuidCreate(&uid);
        if (status != RPC_S_OK) {
            // Handle error appropriately, for now we will just zero out the UUID
            uid.Data1 = 0;
            uid.Data2 = 0;
            uid.Data3 = 0;
            for (auto& a : uid.Data4) {
                a = 0;
            }
            //memset(&uid, 0, sizeof(UUID));
        }
        uuid->Data1 = uid.Data1;
        uuid->Data2 = uid.Data2;
        uuid->Data3 = uid.Data3;
        memcpy(uuid->Data4, uid.Data4, sizeof(uid.Data4));
    }
    UUID::UUID(const UUID& other) noexcept : Data1(other.Data1), Data2(other.Data2), Data3(other.Data3) {
        memcpy(Data4, other.Data4, sizeof(Data4));
    }
    UUID::UUID(UUID&& other) noexcept :Data1(other.Data1), Data2(other.Data2), Data3(other.Data3) {
        memcpy(Data4, other.Data4, sizeof(Data4));
        other.Data1 = 0;
        other.Data2 = 0;
        other.Data3 = 0;
        for (auto& a : other.Data4) {
            a = 0;
        }
    }

    UUID& UUID::operator=(const UUID& other) noexcept {
        Data1 = other.Data1;
        Data2 = other.Data2;
        Data3 = other.Data3;
        memcpy(Data4, other.Data4, sizeof(Data4));
        return *this;
    }

    UUID& UUID::operator=(UUID&& other) noexcept {
        Data1 = other.Data1;
        Data2 = other.Data2;
        Data3 = other.Data3;
        memmove(Data4, other.Data4, sizeof(Data4));
        other.Data1 = 0;
        other.Data2 = 0;
        other.Data3 = 0;
        for (auto& a : other.Data4) {
            a = 0;
        }
        return *this;
    }


    UPRISE_ENGINE::UUID UPRISE_ENGINE::UUID::Create()
    {
        UPRISE_ENGINE::UUID Ret{};
        UUID_TRANSFER Transf{};
        UUID_CREATE(&Transf);
        Ret.Data1 = Transf.Data1;
        Ret.Data2 = Transf.Data2;
        Ret.Data3 = Transf.Data3;
        memcpy(Ret.Data4, Transf.Data4, sizeof(Transf.Data4));
        return Ret;
    }
    bool UUID::operator==(const UUID& other) noexcept
    {
        return Data1 == other.Data1 && Data2 == other.Data2 && Data3 == other.Data3 && memcmp(Data4, other.Data4, sizeof(Data4)) == 0;
    }
    bool UUID::operator!=(const UUID& other) noexcept
    {
        return Data1 != other.Data1 || Data2 != other.Data2 || Data3 != other.Data3 || memcmp(Data4, other.Data4, sizeof(Data4)) != 0;
    }
}

