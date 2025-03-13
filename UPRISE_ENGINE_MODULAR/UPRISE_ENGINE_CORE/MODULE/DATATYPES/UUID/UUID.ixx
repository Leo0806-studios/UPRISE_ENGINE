module;
#include <intrin.h>
export module UPRISE_ENGINE_CORE:UUID;
import std;
export namespace UPRISE_ENGINE {
    struct UE_SIMD_ALIGN__M128 UUID {
#ifdef UPRISE_TESTS
    public:
#else
    private:
#endif
        unsigned int Data1;
        unsigned short Data2;
        unsigned short Data3;
       alignas(alignof(unsigned int)) unsigned char Data4[8];
    public:

        UUID()noexcept :Data1(0), Data2(0), Data3(0) {
            for (auto& a : Data4) {
                a = 0;
            }
        }
        UPRISE_CORE_API UUID(const UUID& other)noexcept;;
        UPRISE_CORE_API  UUID(UUID&& other) noexcept;;
        UPRISE_CORE_API UUID& operator=(const UUID& other)noexcept;
        UPRISE_CORE_API UUID& operator=(UUID&& other) noexcept;
        UPRISE_CORE_API bool operator==(const UUID& other)noexcept;
        UPRISE_CORE_API bool operator!=(const UUID& other)noexcept;
        UPRISE_CORE_API __m128 __vectorcall StoreinM128()const noexcept {
            float data1 = std::bit_cast<float>(Data1);
            unsigned TmpData2AndData3 = static_cast<unsigned int>(Data2);
            TmpData2AndData3 = TmpData2AndData3 << 16;
            TmpData2AndData3 = TmpData2AndData3 | Data3;
            float data2 = std::bit_cast<float>(TmpData2AndData3);
            const unsigned int* Data4ptr = reinterpret_cast<const unsigned int*>(Data4);
            
            float Data4Part1 = std::bit_cast<float>(Data4ptr[0]);
            float Data4Part2 = std::bit_cast<float>(Data4ptr[1]);
            return _mm_setr_ps(data1, data2, Data4Part1, Data4Part2);
        }


        static UUID Create();
    };
}


export namespace std {
    template<>
    struct hash<__m128>
    {
        std::size_t _vectorcall operator()(const __m128 other) const
        {
            return std::hash<float>{}(other.m128_f32[0]) ^ std::hash<float>{}(other.m128_f32[1]) ^ std::hash<float>{}(other.m128_f32[2]) ^ std::hash<float>{}(other.m128_f32[3]);
        }
    };
}