#pragma once
#ifndef _CPUFEATURES_
#define _CPUFEATURES_

#include <intrin.h>
#include "string.h"



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
          UPRISE_CORE_API InstructionSet_Internal() : nIds_{ 0 },
              nExIds_{ 0 },
              isIntel_{ false },
              isAMD_{ false },
              f_1_ECX_{ 0 },
              f_1_EDX_{ 0 },
              f_7_EBX_{ 0 },
              f_7_ECX_{ 0 },
              f_81_ECX_{ 0 },
              f_81_EDX_{ 0 },
              data_{},
              extdata_{}
          {
              //int cpuInfo[4] = {-1};
              std::array<int, 4> cpui;

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
              char vendor[0x20];
              memset(vendor, 0, sizeof(vendor));
              *reinterpret_cast<int*>(vendor) = data_[0][1];
              *reinterpret_cast<int*>(vendor + 4) = data_[0][3];
              *reinterpret_cast<int*>(vendor + 8) = data_[0][2];
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
                  f_1_ECX_ = data_[1][2];
                  f_1_EDX_ = data_[1][3];
              }

              // load bitset with flags for function 0x00000007
              if (nIds_ >= 7)
              {
                  f_7_EBX_ = data_[7][1];
                  f_7_ECX_ = data_[7][2];
              }

              // Calling __cpuid with 0x80000000 as the function_id argument
              // gets the number of the highest valid extended ID.
              __cpuid(cpui.data(), 0x80000000);
              nExIds_ = cpui[0];

              char brand[0x40];
              memset(brand, 0, sizeof(brand));

              for (int i = 0x80000000; i <= nExIds_; ++i)
              {
                  __cpuidex(cpui.data(), i, 0);
                  extdata_.push_back(cpui);
              }

              // load bitset with flags for function 0x80000001
              if (nExIds_ >= 0x80000001)
              {
                  f_81_ECX_ = extdata_[1][2];
                  f_81_EDX_ = extdata_[1][3];
              }

              // Interpret CPU brand string if reported
              if (nExIds_ >= 0x80000004)
              {
                  memcpy(brand, extdata_[2].data(), sizeof(cpui));
                  memcpy(brand + 16, extdata_[3].data(), sizeof(cpui));
                  memcpy(brand + 32, extdata_[4].data(), sizeof(cpui));
                  brand_ = brand;
              }
          };


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
const CORE::InstructionSet::InstructionSet_Internal CORE::InstructionSet::CPU_Rep;

#endif // !_CPUFEATURES_
