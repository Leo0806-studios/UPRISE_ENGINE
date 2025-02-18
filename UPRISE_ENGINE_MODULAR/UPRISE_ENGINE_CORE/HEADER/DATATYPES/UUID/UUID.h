// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_UUID_
#define UE_UUID_
import std;
namespace UPRISE_ENGINE {
    struct  UUID  {
    private:
        struct  {
            unsigned char data[16]{0};
        } Data;
    public:

        UUID() = default;
        ~UUID() = default;
       UPRISE_CORE_API UUID(const UUID& other)noexcept;;
       UPRISE_CORE_API  UUID(UUID&& other) noexcept;;
       UPRISE_CORE_API UUID& operator=(const UUID& other)noexcept;
       UPRISE_CORE_API UUID& operator=(UUID&& other) noexcept;
        static UUID Create();
    };
}

#endif // !_UUID_
