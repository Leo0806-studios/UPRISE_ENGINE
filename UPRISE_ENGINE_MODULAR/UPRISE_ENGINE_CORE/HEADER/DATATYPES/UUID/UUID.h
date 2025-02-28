// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_UUID_
#define UE_UUID_
import std;
namespace UPRISE_ENGINE {
    struct  UUID  {
#ifdef UPRISE_TESTS
    public:
#else
    private:
#endif
        unsigned int Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[8];
    public:

        UUID() = default;
        ~UUID() = default;
       UPRISE_CORE_API UUID(const UUID& other)noexcept;;
       UPRISE_CORE_API  UUID(UUID&& other) noexcept;;
       UPRISE_CORE_API UUID& operator=(const UUID& other)noexcept;
       UPRISE_CORE_API UUID& operator=(UUID&& other) noexcept;
       UPRISE_CORE_API bool operator==(const UUID& other)noexcept;
       UPRISE_CORE_API bool operator!=(const UUID& other)noexcept;

        static UUID Create();
    };
}

#endif // !_UUID_
