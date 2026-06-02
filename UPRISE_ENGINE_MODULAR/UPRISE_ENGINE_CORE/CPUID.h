#pragma once

#include <bit>
#include <bitset>
#include <string>
#include <vector>
#include <IMPORT_DEFS.h>

namespace UPRISE_ENGINE {
    namespace CORE {
        /// <summary>
        /// contains cpu secs
        /// </summary>
        class   InstructionSet //NOSONAR
        {
            // forward declarations
            class InstructionSet_Internal;

        public:
            // getters
            UPRISE_CORE_API static  std::string Vendor()noexcept;
            UPRISE_CORE_API static  std::string Brand()noexcept;
            UPRISE_CORE_API static  bool SSE3()noexcept;
            UPRISE_CORE_API static  bool PCLMULQDQ()noexcept;
            UPRISE_CORE_API static  bool MONITOR()noexcept;
            UPRISE_CORE_API static  bool SSSE3()noexcept;
            UPRISE_CORE_API static  bool FMA()noexcept;
            UPRISE_CORE_API static  bool CMPXCHG16B()noexcept;
            UPRISE_CORE_API static  bool SSE41()noexcept;
            UPRISE_CORE_API static  bool SSE42()noexcept;
            UPRISE_CORE_API static  bool MOVBE()noexcept;
            UPRISE_CORE_API static  bool POPCNT()noexcept;
            UPRISE_CORE_API static  bool AES()noexcept;
            UPRISE_CORE_API static  bool XSAVE()noexcept;
            UPRISE_CORE_API static  bool OSXSAVE()noexcept;
            UPRISE_CORE_API static  bool AVX()noexcept;
            UPRISE_CORE_API static  bool F16C()noexcept;
            UPRISE_CORE_API static  bool RDRAND()noexcept;
            UPRISE_CORE_API static  bool MSR()noexcept;
            UPRISE_CORE_API static  bool CX8()noexcept;
            UPRISE_CORE_API static  bool SEP()noexcept;
            UPRISE_CORE_API static  bool CMOV()noexcept;
            UPRISE_CORE_API static  bool CLFSH()noexcept;
            UPRISE_CORE_API static  bool MMX()noexcept;
            UPRISE_CORE_API static  bool FXSR()noexcept;
            UPRISE_CORE_API static  bool SSE()noexcept;
            UPRISE_CORE_API static  bool SSE2()noexcept;
            UPRISE_CORE_API static  bool FSGSBASE()noexcept;
            UPRISE_CORE_API static  bool BMI1()noexcept;
            UPRISE_CORE_API static  bool HLE()noexcept;
            UPRISE_CORE_API static  bool AVX2()noexcept;
            UPRISE_CORE_API static bool BMI2()noexcept;
            UPRISE_CORE_API static  bool ERMS()noexcept;
            UPRISE_CORE_API static  bool INVPCID()noexcept;
            UPRISE_CORE_API static  bool RTM()noexcept;
            UPRISE_CORE_API static  bool AVX512F()noexcept;
            UPRISE_CORE_API static  bool RDSEED()noexcept;
            UPRISE_CORE_API static  bool ADX()noexcept;
            UPRISE_CORE_API static  bool AVX512PF()noexcept;
            UPRISE_CORE_API static  bool AVX512ER()noexcept;
            UPRISE_CORE_API static  bool AVX512CD()noexcept;
            UPRISE_CORE_API static  bool SHA()noexcept;
            UPRISE_CORE_API static  bool PREFETCHWT1()noexcept;
            UPRISE_CORE_API static  bool LAHF()noexcept;
            UPRISE_CORE_API static  bool LZCNT()noexcept;
            UPRISE_CORE_API static  bool ABM()noexcept;
            UPRISE_CORE_API static  bool SSE4a()noexcept;
            UPRISE_CORE_API static  bool XOP()noexcept;
            UPRISE_CORE_API static  bool TBM()noexcept;
            UPRISE_CORE_API static  bool SYSCALL()noexcept;
            UPRISE_CORE_API static  bool MMXEXT()noexcept;
            UPRISE_CORE_API static  bool RDTSCP()noexcept;
            UPRISE_CORE_API static  bool _3DNOWEXT()noexcept;
            UPRISE_CORE_API static  bool _3DNOW()noexcept;
        private:

            UPRISE_CORE_API static const InstructionSet_Internal CPU_Rep;

            class InstructionSet_Internal
            {
            public:

                UPRISE_CORE_API   InstructionSet_Internal()noexcept;


                int nIds_;
                int nExIds_;
                std::string vendor_;
                std::string brand_;

                std::bitset<32> f_1_ECX_;
                std::bitset<32> f_1_EDX_;
                std::bitset<32> f_7_EBX_;
                std::bitset<32> f_7_ECX_;
                std::bitset<32> f_81_ECX_;
                std::bitset<32> f_81_EDX_;
                std::vector<std::array<int, 4>> data_;
                std::vector<std::array<int, 4>> extdata_;
                bool isIntel_;
                bool isAMD_;
                char PAD[6]; // TODO find a better way to align this or put data here   //NOSONAR
            };
        };
    }
}

