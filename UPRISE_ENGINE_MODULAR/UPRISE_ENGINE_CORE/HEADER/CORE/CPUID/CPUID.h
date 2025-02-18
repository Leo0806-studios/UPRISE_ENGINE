// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_CPUFEATURES_
#define UE_CPUFEATURES_

#include <intrin.h>
#include <string.h>



import std; //-V2575
namespace UPRISE_ENGINE {
    namespace CORE {
        /// <summary>
        /// contains cpu secs
        /// </summary>
        class   InstructionSet
        {
            // forward declarations
            class InstructionSet_Internal;

        public:
            // getters
            UPRISE_CORE_API static  std::string Vendor(void);
            UPRISE_CORE_API static  std::string Brand(void);

            UPRISE_CORE_API static  bool SSE3(void) { return CPU_Rep.f_1_ECX_[0]; }
            UPRISE_CORE_API static  bool PCLMULQDQ(void);
            UPRISE_CORE_API static  bool MONITOR(void);
            UPRISE_CORE_API static  bool SSSE3(void);
            UPRISE_CORE_API static  bool FMA(void);
            UPRISE_CORE_API static  bool CMPXCHG16B(void);
            UPRISE_CORE_API static  bool SSE41(void);
            UPRISE_CORE_API static  bool SSE42(void);
            UPRISE_CORE_API static  bool MOVBE(void);
            UPRISE_CORE_API static  bool POPCNT(void);
            UPRISE_CORE_API static  bool AES(void);
            UPRISE_CORE_API static  bool XSAVE(void);
            UPRISE_CORE_API static  bool OSXSAVE(void);
            UPRISE_CORE_API static  bool AVX(void);
            UPRISE_CORE_API static  bool F16C(void);
            UPRISE_CORE_API static  bool RDRAND(void);

            UPRISE_CORE_API static  bool MSR(void);
            UPRISE_CORE_API static  bool CX8(void);
            UPRISE_CORE_API static  bool SEP(void);
            UPRISE_CORE_API static  bool CMOV(void);
            UPRISE_CORE_API static  bool CLFSH(void);
            UPRISE_CORE_API static  bool MMX(void);
            UPRISE_CORE_API static  bool FXSR(void);
            UPRISE_CORE_API static  bool SSE(void);
            UPRISE_CORE_API static  bool SSE2(void);

            UPRISE_CORE_API static  bool FSGSBASE(void);
            UPRISE_CORE_API static  bool BMI1(void);
            UPRISE_CORE_API static  bool HLE(void);
            UPRISE_CORE_API static  bool AVX2(void);
            UPRISE_CORE_API static bool BMI2(void);
            UPRISE_CORE_API static  bool ERMS(void);
            UPRISE_CORE_API static  bool INVPCID(void);
            UPRISE_CORE_API static  bool RTM(void);
            UPRISE_CORE_API static  bool AVX512F(void);
            UPRISE_CORE_API static  bool RDSEED(void);
            UPRISE_CORE_API static  bool ADX(void);
            UPRISE_CORE_API static  bool AVX512PF(void);
            UPRISE_CORE_API static  bool AVX512ER(void);
            UPRISE_CORE_API static  bool AVX512CD(void);
            UPRISE_CORE_API static  bool SHA(void);

            UPRISE_CORE_API static  bool PREFETCHWT1(void);

            UPRISE_CORE_API static  bool LAHF(void);
            UPRISE_CORE_API static  bool LZCNT(void);
            UPRISE_CORE_API static  bool ABM(void);
            UPRISE_CORE_API static  bool SSE4a(void);
            UPRISE_CORE_API static  bool XOP(void);
            UPRISE_CORE_API static  bool TBM(void);

            UPRISE_CORE_API static  bool SYSCALL(void);
            UPRISE_CORE_API static  bool MMXEXT(void);
            UPRISE_CORE_API static  bool RDTSCP(void);
            UPRISE_CORE_API static  bool _3DNOWEXT(void);
            UPRISE_CORE_API static  bool _3DNOW(void);
        private:

            UPRISE_CORE_API static const InstructionSet_Internal CPU_Rep;

            class InstructionSet_Internal
            {
            public:
#pragma warning(disable: 4367)
                InstructionSet_Internal() : nIds_{ 0 },
                    nExIds_{ 0 },

                    f_1_ECX_{ 0 },
                    f_1_EDX_{ 0 },
                    f_7_EBX_{ 0 },
                    f_7_ECX_{ 0 },
                    f_81_ECX_{ 0 },
                    f_81_EDX_{ 0 },
                    data_{},
                    extdata_{},
                    isIntel_{ false },
                    isAMD_{ false }
                {
                    //int cpuInfo[4] = {-1};
                    std::array<int, 4> cpui{}; // cpui[0] is EAX, cpui[1] is EBX, etc.

                    // Calling __cpuid with 0x0 as the function_id argument
                    // gets the number of the highest valid function ID.
                    __cpuid(cpui.data(), 0);
                    nIds_ = cpui[0];

                    for (int i = 0; i <= nIds_; ++i)
                    {
                        __cpuidex(cpui.data(), i, 0);
                        data_.push_back(cpui);
                    }

                    // Capture vendor string
                    alignas(alignof(int)) char vendor[0x20];
                    memset(vendor, 0, sizeof(vendor));
                    *reinterpret_cast<int*>(vendor) = data_[0][1];
                    *reinterpret_cast<int*>(vendor + (sizeof(int)*1)) = data_[0][3];
                    *reinterpret_cast<int*>(vendor + (sizeof(int) * 2)) = data_[0][2];
                    vendor_ = vendor;
                    if (vendor_ == "GenuineIntel")
                    {
                        isIntel_ = true;
                    }
                    else if (vendor_ == "AuthenticAMD")
                    {
                        isAMD_ = true;
                    }

                    // load bitset with flags for function 0x00000001
                    if (nIds_ >= 1)
                    {
                        f_1_ECX_ = static_cast<unsigned __int64>( data_[1][2]);
                        f_1_EDX_ = static_cast<unsigned __int64>(data_[1][3]);
                    }

                    // load bitset with flags for function 0x00000007
                    if (nIds_ >= 7)
                    {
                        f_7_EBX_ = static_cast<unsigned __int64>(data_[7][1]);
                        f_7_ECX_ = static_cast<unsigned __int64>(data_[7][2]);
                    }
                    constexpr unsigned int intmax = 0x80000000;

                    // Calling __cpuid with 0x80000000 as the function_id argument
                    // gets the number of the highest valid extended ID.
                    __cpuid(cpui.data(), intmax);
                    nExIds_ = cpui[0];

                    char brand[0x40];
                    memset(brand, 0, sizeof(brand));
                    for (int i = intmax; i <= nExIds_; ++i)
                    {
                        __cpuidex(cpui.data(), i, 0);
                        extdata_.push_back(cpui);
                    }

                    // load bitset with flags for function 0x80000001
                    if (nExIds_ >= intmax)
                    {
                        f_81_ECX_ = static_cast<unsigned __int64>(extdata_[1][2]);
                        f_81_EDX_ = static_cast<unsigned __int64>(extdata_[1][3]);
                    }

                    // Interpret CPU brand string if reported
                    if (nExIds_ >= intmax)
                    {
                        memcpy(brand, extdata_[2].data(), sizeof(cpui));
                        memcpy(brand + (sizeof(char)*16), extdata_[3].data(), sizeof(cpui));
                        memcpy(brand + (sizeof(char)*32), extdata_[4].data(), sizeof(cpui));
                        brand_ = brand;
                    }
                };
#pragma warning(default: 4367)

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
                char PAD[6];
            };
        };
    }
    const CORE::InstructionSet::InstructionSet_Internal CORE::InstructionSet::CPU_Rep;
}

 

#endif // !_CPUFEATURES_
