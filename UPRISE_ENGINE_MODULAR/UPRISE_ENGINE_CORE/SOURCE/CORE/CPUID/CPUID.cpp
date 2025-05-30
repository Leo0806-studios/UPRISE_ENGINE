// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include <array>
#else
import UPRISE_ENGINE_CORE;
import <intrin.h>;
import std;
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    namespace CORE {
        std::string CORE::InstructionSet::Vendor(void) { return CPU_Rep.vendor_; }

        std::string CORE::InstructionSet::Brand(void) { return CPU_Rep.brand_; }

        inline bool InstructionSet::SSE3(void) { return CPU_Rep.f_1_ECX_[0]; }

        bool CORE::InstructionSet::PCLMULQDQ(void) { return CPU_Rep.f_1_ECX_[1]; }

        bool CORE::InstructionSet::MONITOR(void) { return CPU_Rep.f_1_ECX_[3]; }

        bool CORE::InstructionSet::SSSE3(void) { return CPU_Rep.f_1_ECX_[9]; }

        bool CORE::InstructionSet::FMA(void) { return CPU_Rep.f_1_ECX_[12]; }

        bool CORE::InstructionSet::CMPXCHG16B(void) { return CPU_Rep.f_1_ECX_[13]; }

        bool CORE::InstructionSet::SSE41(void) { return CPU_Rep.f_1_ECX_[19]; }

        bool CORE::InstructionSet::SSE42(void) { return CPU_Rep.f_1_ECX_[20]; }

        bool CORE::InstructionSet::MOVBE(void) { return CPU_Rep.f_1_ECX_[22]; }

        bool CORE::InstructionSet::POPCNT(void) { return CPU_Rep.f_1_ECX_[23]; }

        bool CORE::InstructionSet::AES(void) { return CPU_Rep.f_1_ECX_[25]; }

        bool CORE::InstructionSet::XSAVE(void) { return CPU_Rep.f_1_ECX_[26]; }

        bool CORE::InstructionSet::OSXSAVE(void) { return CPU_Rep.f_1_ECX_[27]; }

        bool CORE::InstructionSet::AVX(void) { return CPU_Rep.f_1_ECX_[28]; }

        bool CORE::InstructionSet::F16C(void) { return CPU_Rep.f_1_ECX_[29]; }

        bool CORE::InstructionSet::RDRAND(void) { return CPU_Rep.f_1_ECX_[30]; }

        bool CORE::InstructionSet::MSR(void) { return CPU_Rep.f_1_EDX_[5]; }

        bool CORE::InstructionSet::CX8(void) { return CPU_Rep.f_1_EDX_[8]; }

        bool CORE::InstructionSet::SEP(void) { return CPU_Rep.f_1_EDX_[11]; }

        bool CORE::InstructionSet::CMOV(void) { return CPU_Rep.f_1_EDX_[15]; }

        bool CORE::InstructionSet::CLFSH(void) { return CPU_Rep.f_1_EDX_[19]; }

        bool CORE::InstructionSet::MMX(void) { return CPU_Rep.f_1_EDX_[23]; }

        bool CORE::InstructionSet::FXSR(void) { return CPU_Rep.f_1_EDX_[24]; }

        bool CORE::InstructionSet::SSE(void) { return CPU_Rep.f_1_EDX_[25]; }

        bool CORE::InstructionSet::SSE2(void) { return CPU_Rep.f_1_EDX_[26]; }

        bool CORE::InstructionSet::FSGSBASE(void) { return CPU_Rep.f_7_EBX_[0]; }

        bool CORE::InstructionSet::BMI1(void) { return CPU_Rep.f_7_EBX_[3]; }

        bool CORE::InstructionSet::HLE(void) { return CPU_Rep.isIntel_ && CPU_Rep.f_7_EBX_[4]; }

        bool CORE::InstructionSet::AVX2(void) { return CPU_Rep.f_7_EBX_[5]; }

        bool CORE::InstructionSet::BMI2(void) { return CPU_Rep.f_7_EBX_[8]; }

        bool CORE::InstructionSet::ERMS(void) { return CPU_Rep.f_7_EBX_[9]; }

        bool CORE::InstructionSet::INVPCID(void) { return CPU_Rep.f_7_EBX_[10]; }

        bool CORE::InstructionSet::RTM(void) { return CPU_Rep.isIntel_ && CPU_Rep.f_7_EBX_[11]; }

        bool CORE::InstructionSet::AVX512F(void) { return CPU_Rep.f_7_EBX_[16]; }

        bool CORE::InstructionSet::RDSEED(void) { return CPU_Rep.f_7_EBX_[18]; }

        bool CORE::InstructionSet::ADX(void) { return CPU_Rep.f_7_EBX_[19]; }

        bool CORE::InstructionSet::AVX512PF(void) { return CPU_Rep.f_7_EBX_[26]; }

        bool CORE::InstructionSet::AVX512ER(void) { return CPU_Rep.f_7_EBX_[27]; }

        bool CORE::InstructionSet::AVX512CD(void) { return CPU_Rep.f_7_EBX_[28]; }

        bool CORE::InstructionSet::SHA(void) { return CPU_Rep.f_7_EBX_[29]; }

        bool CORE::InstructionSet::PREFETCHWT1(void) { return CPU_Rep.f_7_ECX_[0]; }

        bool CORE::InstructionSet::LAHF(void) { return CPU_Rep.f_81_ECX_[0]; }

        bool CORE::InstructionSet::LZCNT(void) { return CPU_Rep.isIntel_ && CPU_Rep.f_81_ECX_[5]; }

        bool CORE::InstructionSet::ABM(void) { return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[5]; }

        bool CORE::InstructionSet::SSE4a(void) { return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[6]; }

        bool CORE::InstructionSet::XOP(void) { return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[11]; }

        bool CORE::InstructionSet::TBM(void) { return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[21]; }

        bool CORE::InstructionSet::SYSCALL(void) { return CPU_Rep.isIntel_ && CPU_Rep.f_81_EDX_[11]; }

        bool CORE::InstructionSet::MMXEXT(void) { return CPU_Rep.isAMD_ && CPU_Rep.f_81_EDX_[22]; }

        bool CORE::InstructionSet::RDTSCP(void) { return CPU_Rep.isIntel_ && CPU_Rep.f_81_EDX_[27]; }

        bool CORE::InstructionSet::_3DNOWEXT(void) { return CPU_Rep.isAMD_ && CPU_Rep.f_81_EDX_[30]; }

        bool CORE::InstructionSet::_3DNOW(void) { return CPU_Rep.isAMD_ && CPU_Rep.f_81_EDX_[31]; }
        CORE::InstructionSet::InstructionSet_Internal::InstructionSet_Internal() : nIds_{ 0 },
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
            alignas(alignof(int)) char vendor[0x20]{};

            char* const _vendor = vendor;
            memset(_vendor, 0, sizeof(vendor)); //-V2547
            *reinterpret_cast<int*>(vendor) = data_[0][1];
            *reinterpret_cast<int*>(vendor + (sizeof(int) * 1)) = data_[0][3]; //-V2563
            *reinterpret_cast<int*>(vendor + (sizeof(int) * 2)) = data_[0][2]; //-V2563
            vendor_ = vendor;
            if (vendor_ == "GenuineIntel")
            {
                isIntel_ = true;
            }
            else if (vendor_ == "AuthenticAMD")
            {
                isAMD_ = true;
            }
            else
            {
                isAMD_ = false;
                isIntel_ = false;
            }
            // load bitset with flags for function 0x00000001
            if (nIds_ >= 1)
            {
                f_1_ECX_ = static_cast<unsigned __int64>(data_[1][2]);
                f_1_EDX_ = static_cast<unsigned __int64>(data_[1][3]);
            }

            // load bitset with flags for function 0x00000007
            if (nIds_ >= 7)
            {
                f_7_EBX_ = static_cast<unsigned __int64>(data_[7][1]);
                f_7_ECX_ = static_cast<unsigned __int64>(data_[7][2]);
            }
            constexpr unsigned int intmax = 0x80000000U; //-V112

            // Calling __cpuid with 0x80000000 as the function_id argument
            // gets the number of the highest valid extended ID.
            __cpuid(cpui.data(), intmax);
            nExIds_ = cpui[0];

            char brand[0x40]{};
            char* const _brand = brand;
            memset(_brand, 0, sizeof(brand)); //-V2547
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
                // Interpret CPU brand string if reported

                std::memcpy(&brand, extdata_[2].data(), sizeof(cpui));
                memcpy(brand + (sizeof(char) * 16), extdata_[3].data(), sizeof(cpui));
                memcpy(brand + (sizeof(char) * 32), extdata_[4].data(), sizeof(cpui));
                brand_ = brand;
            }


        };

#ifndef UPRISE_TESTS
        const UPRISE_ENGINE::CORE::InstructionSet::InstructionSet_Internal CORE::InstructionSet::CPU_Rep;

#endif // !UPRISE_TESTS

    }
}
