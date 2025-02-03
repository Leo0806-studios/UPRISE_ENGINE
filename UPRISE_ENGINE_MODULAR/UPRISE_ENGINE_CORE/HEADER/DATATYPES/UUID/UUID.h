// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_UUID_
#define UE_UUID_
namespace UPRISE_ENGINE {
    struct  UUID  {
    private:
        struct  {
            unsigned char data[16]{0};
        } Data;
    public:

        UUID() = default;
        ~UUID() = default;
        static UUID Create();
    };
}

#endif // !_UUID_
