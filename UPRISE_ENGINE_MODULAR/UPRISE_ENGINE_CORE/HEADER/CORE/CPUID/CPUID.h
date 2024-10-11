#pragma once
#ifndef _CPUFEATURES_
#define _CPUFEATURES_
#include <intrin.h>

import std;

namespace CORE {
    /// <summary>
    /// contains cpu secs
    /// </summary>
    class InstructionSet
    {
        // forward declarations
        class InstructionSet_Internal;

    public:
        // getters
        static UPRISE_CORE_API std::string Vendor(void);
        static UPRISE_CORE_API std::string Brand(void);

        static UPRISE_CORE_API bool SSE3(void) { return CPU_Rep.f_1_ECX_[0]; }
        static UPRISE_CORE_API bool PCLMULQDQ(void);
        static UPRISE_CORE_API bool MONITOR(void);
        static UPRISE_CORE_API bool SSSE3(void);
        static UPRISE_CORE_API bool FMA(void);
        static UPRISE_CORE_API bool CMPXCHG16B(void);
        static UPRISE_CORE_API bool SSE41(void);
        static UPRISE_CORE_API bool SSE42(void);
        static UPRISE_CORE_API bool MOVBE(void);
        static UPRISE_CORE_API bool POPCNT(void);
        static UPRISE_CORE_API bool AES(void);
        static UPRISE_CORE_API bool XSAVE(void);
        static UPRISE_CORE_API bool OSXSAVE(void);
        static UPRISE_CORE_API bool AVX(void);
        static UPRISE_CORE_API bool F16C(void);
        static UPRISE_CORE_API bool RDRAND(void);

        static UPRISE_CORE_API bool MSR(void);
        static UPRISE_CORE_API bool CX8(void);
        static UPRISE_CORE_API bool SEP(void);
        static UPRISE_CORE_API bool CMOV(void);
        static UPRISE_CORE_API bool CLFSH(void);
        static UPRISE_CORE_API bool MMX(void);
        static UPRISE_CORE_API bool FXSR(void);
        static UPRISE_CORE_API bool SSE(void);
        static UPRISE_CORE_API bool SSE2(void);

        static UPRISE_CORE_API bool FSGSBASE(void);
        static UPRISE_CORE_API bool BMI1(void);
        static UPRISE_CORE_API bool HLE(void);
        static UPRISE_CORE_API bool AVX2(void);
        static UPRISE_CORE_API bool BMI2(void);
        static UPRISE_CORE_API bool ERMS(void);
        static UPRISE_CORE_API bool INVPCID(void);
        static UPRISE_CORE_API bool RTM(void);
        static UPRISE_CORE_API bool AVX512F(void);
        static UPRISE_CORE_API bool RDSEED(void);
        static UPRISE_CORE_API bool ADX(void);
        static UPRISE_CORE_API bool AVX512PF(void);
        static UPRISE_CORE_API bool AVX512ER(void);
        static UPRISE_CORE_API bool AVX512CD(void);
        static UPRISE_CORE_API bool SHA(void);

        static UPRISE_CORE_API bool PREFETCHWT1(void);

        static UPRISE_CORE_API bool LAHF(void);
        static UPRISE_CORE_API bool LZCNT(void);
        static UPRISE_CORE_API bool ABM(void);
        static UPRISE_CORE_API bool SSE4a(void);
        static UPRISE_CORE_API bool XOP(void);
        static UPRISE_CORE_API bool TBM(void);

        static UPRISE_CORE_API bool SYSCALL(void);
        static UPRISE_CORE_API bool MMXEXT(void);
        static UPRISE_CORE_API bool RDTSCP(void);
        static UPRISE_CORE_API bool _3DNOWEXT(void);
        static UPRISE_CORE_API bool _3DNOW(void);

        static const InstructionSet_Internal CPU_Rep;

        class InstructionSet_Internal
        {
        public:
          UPRISE_CORE_API  InstructionSet_Internal();


            int nIds_;
            int nExIds_;
            std::string vendor_;
            std::string brand_;
            bool isIntel_;
            bool isAMD_;
            std::bitset<32> f_1_ECX_;
            std::bitset<32> f_1_EDX_;
            std::bitset<32> f_7_EBX_;
            std::bitset<32> f_7_ECX_;
            std::bitset<32> f_81_ECX_;
            std::bitset<32> f_81_EDX_;
            std::vector<std::array<int, 4>> data_;
            std::vector<std::array<int, 4>> extdata_;
        };
    };
}

#endif // !_CPUFEATURES_
