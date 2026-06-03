#pragma once

#include <intrin.h>
#include <bit>
#include <string>
#include <format>
#include <array>
#include <cstring>
#include <cstdint>
#include "UTILITIES.h"
#include <MACROS.h>
namespace UPRISE_ENGINE::DATATYPES {
    /// <summary>
    /// UUID struct for the UPRISE ENGINE
    /// a fully zeroed UUID is considered invalid and should not be used
    /// </summary>
    struct UE_SIMD_ALIGN__M128 UUID {


        unsigned int Data1;
        unsigned short Data2;
        unsigned short Data3;
        alignas(alignof(unsigned int)) std::array<uint8_t,8> Data4; //NOSONAR


        UPRISE_CORE_API static UUID Create()noexcept;
    };
}

namespace std {

    template <>
    struct hash<UPRISE_ENGINE::DATATYPES::UUID>
    {
        std::size_t operator()(const UPRISE_ENGINE::DATATYPES::UUID& uuid) const noexcept
        {
            uint64_t hash = 0;
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<unsigned int>{}(uuid.Data1));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<unsigned short>{}(uuid.Data2));
            hash = UPRISE_ENGINE::HashCombine(hash, std::hash<unsigned short>{}(uuid.Data3));
            for (const uint8_t val : uuid.Data4) {
                hash = UPRISE_ENGINE::HashCombine(hash, std::hash<uint8_t>{}(val));
            }
            return hash;

        }
    };

    std::string to_string(UPRISE_ENGINE::DATATYPES::UUID _Val) {
        return std::format("UUID: {:08X}-{:04X}-{:04X}-{:02X}{:02X}-{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}",
            _Val.Data1, _Val.Data2, _Val.Data3,
            _Val.Data4[0], _Val.Data4[1], _Val.Data4[2], _Val.Data4[3], _Val.Data4[4], _Val.Data4[5], _Val.Data4[6], _Val.Data4[7]);
    }
}


