// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "CPUID.h"
#include <array>
#include <intrin.h>
#include <string>
// fuck this shit. im turning of warnings for the file


namespace UPRISE_ENGINE:: CORE {
        std::string CORE::InstructionSet::Vendor() noexcept {
            return CPU_Rep.vendor_;
        }

        std::string CORE::InstructionSet::Brand() noexcept {
            return CPU_Rep.brand_;
        }

        inline bool InstructionSet::SSE3() noexcept {
            return CPU_Rep.f_1_ECX_[0];
        }

        bool CORE::InstructionSet::PCLMULQDQ() noexcept {
            return CPU_Rep.f_1_ECX_[1];
        }

        bool CORE::InstructionSet::MONITOR() noexcept {
            return CPU_Rep.f_1_ECX_[3];
        }

        bool CORE::InstructionSet::SSSE3() noexcept {
            return CPU_Rep.f_1_ECX_[9];
        }

        bool CORE::InstructionSet::FMA() noexcept {
            return CPU_Rep.f_1_ECX_[12];
        }

        bool CORE::InstructionSet::CMPXCHG16B() noexcept {
            return CPU_Rep.f_1_ECX_[13];
        }

        bool CORE::InstructionSet::SSE41() noexcept {
            return CPU_Rep.f_1_ECX_[19];
        }

        bool CORE::InstructionSet::SSE42() noexcept {
            return CPU_Rep.f_1_ECX_[20];
        }

        bool CORE::InstructionSet::MOVBE()noexcept {
            return CPU_Rep.f_1_ECX_[22];
        }

        bool CORE::InstructionSet::POPCNT()noexcept {
            return CPU_Rep.f_1_ECX_[23];
        }

        bool CORE::InstructionSet::AES()noexcept {
            return CPU_Rep.f_1_ECX_[25];
        }

        bool CORE::InstructionSet::XSAVE()noexcept {
            return CPU_Rep.f_1_ECX_[26];
        }

        bool CORE::InstructionSet::OSXSAVE() noexcept {
            return CPU_Rep.f_1_ECX_[27];
        }

        bool CORE::InstructionSet::AVX() noexcept {
            return CPU_Rep.f_1_ECX_[28];
        }

        bool CORE::InstructionSet::F16C()noexcept {
            return CPU_Rep.f_1_ECX_[29];
        }

        bool CORE::InstructionSet::RDRAND()noexcept {
            return CPU_Rep.f_1_ECX_[30];
        }

        bool CORE::InstructionSet::MSR()noexcept {
            return CPU_Rep.f_1_EDX_[5];
        }

        bool CORE::InstructionSet::CX8()noexcept {
            return CPU_Rep.f_1_EDX_[8];
        }

        bool CORE::InstructionSet::SEP() noexcept {
            return CPU_Rep.f_1_EDX_[11];
        }

        bool CORE::InstructionSet::CMOV()noexcept {
            return CPU_Rep.f_1_EDX_[15];
        }

        bool CORE::InstructionSet::CLFSH()noexcept {
            return CPU_Rep.f_1_EDX_[19];
        }

        bool CORE::InstructionSet::MMX() noexcept {
            return CPU_Rep.f_1_EDX_[23];
        }

        bool CORE::InstructionSet::FXSR()noexcept {
            return CPU_Rep.f_1_EDX_[24];
        }

        bool CORE::InstructionSet::SSE() noexcept {
            return CPU_Rep.f_1_EDX_[25];
        }

        bool CORE::InstructionSet::SSE2() noexcept {
            return CPU_Rep.f_1_EDX_[26];
        }

        bool CORE::InstructionSet::FSGSBASE() noexcept {
            return CPU_Rep.f_7_EBX_[0];
        }

        bool CORE::InstructionSet::BMI1() noexcept {
            return CPU_Rep.f_7_EBX_[3];
        }

        bool CORE::InstructionSet::HLE() noexcept {
            return CPU_Rep.isIntel_ && CPU_Rep.f_7_EBX_[4];
        }

        bool CORE::InstructionSet::AVX2() noexcept {
            return CPU_Rep.f_7_EBX_[5];
        }

        bool CORE::InstructionSet::BMI2()noexcept {
            return CPU_Rep.f_7_EBX_[8];
        }

        bool CORE::InstructionSet::ERMS() noexcept {
            return CPU_Rep.f_7_EBX_[9];
        }

        bool CORE::InstructionSet::INVPCID() noexcept {
            return CPU_Rep.f_7_EBX_[10];
        }

        bool CORE::InstructionSet::RTM() noexcept {
            return CPU_Rep.isIntel_ && CPU_Rep.f_7_EBX_[11];
        }

        bool CORE::InstructionSet::AVX512F()noexcept {
            return CPU_Rep.f_7_EBX_[16];
        }

        bool CORE::InstructionSet::RDSEED() noexcept {
            return CPU_Rep.f_7_EBX_[18];
        }

        bool CORE::InstructionSet::ADX() noexcept {
            return CPU_Rep.f_7_EBX_[19];
        }

        bool CORE::InstructionSet::AVX512PF() noexcept {
            return CPU_Rep.f_7_EBX_[26];
        }

        bool CORE::InstructionSet::AVX512ER()noexcept {
            return CPU_Rep.f_7_EBX_[27];
        }

        bool CORE::InstructionSet::AVX512CD() noexcept {
            return CPU_Rep.f_7_EBX_[28];
        }

        bool CORE::InstructionSet::SHA() noexcept {
            return CPU_Rep.f_7_EBX_[29];
        }

        bool CORE::InstructionSet::PREFETCHWT1()noexcept {
            return CPU_Rep.f_7_ECX_[0];
        }

        bool CORE::InstructionSet::LAHF()noexcept {
            return CPU_Rep.f_81_ECX_[0];
        }

        bool CORE::InstructionSet::LZCNT() noexcept {
            return CPU_Rep.isIntel_ && CPU_Rep.f_81_ECX_[5];
        }

        bool CORE::InstructionSet::ABM() noexcept {
            return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[5];
        }

        bool CORE::InstructionSet::SSE4a() noexcept {
            return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[6];
        }

        bool CORE::InstructionSet::XOP()noexcept {
            return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[11];
        }

        bool CORE::InstructionSet::TBM()noexcept {
            return CPU_Rep.isAMD_ && CPU_Rep.f_81_ECX_[21];
        }

        bool CORE::InstructionSet::SYSCALL()noexcept {
            return CPU_Rep.isIntel_ && CPU_Rep.f_81_EDX_[11];
        }

        bool CORE::InstructionSet::MMXEXT()noexcept {
            return CPU_Rep.isAMD_ && CPU_Rep.f_81_EDX_[22];
        }

        bool CORE::InstructionSet::RDTSCP()noexcept {
            return CPU_Rep.isIntel_ && CPU_Rep.f_81_EDX_[27];
        }

        bool CORE::InstructionSet::_3DNOWEXT()noexcept {
            return CPU_Rep.isAMD_ && CPU_Rep.f_81_EDX_[30];
        }

        bool CORE::InstructionSet::_3DNOW()noexcept {
            return CPU_Rep.isAMD_ && CPU_Rep.f_81_EDX_[31];
        }
#pragma warning(push)
#pragma warning(disable:26486)
        CORE::InstructionSet::InstructionSet_Internal::InstructionSet_Internal()noexcept : nIds_{ 0 },
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
            isAMD_{ false },
            PAD{ 0 }
        {

            std::array<int, 4> cpui{}; // cpui[0] is EAX, cpui[1] is EBX, etc.

            // Calling __cpuid with 0x0 as the function_id argument
            // gets the number of the highest valid function ID.
            __cpuid(cpui.data(), 0);
            nIds_ = cpui[0];

            for (int i = 0; i <= nIds_; ++i)
            {
                __cpuidex(cpui.data(), i, 0);
#pragma warning(suppress:26487)
                data_.push_back(cpui);
            }

            // Capture vendor string
            std::array<char, 0x20> vendor{};
            std::array<int, 0x20/sizeof(int)> vendor_cpui{};
            
            memset(vendor_cpui.data(), 0, sizeof(vendor_cpui)); //-V2547
#pragma warning(push)
#pragma warning(disable :26823)
            vendor_cpui[0] = data_[0][1]; // EBX
            vendor_cpui[1] = data_[0][3]; // EDX
            vendor_cpui[2] = data_[0][2]; // ECX
#pragma warning(pop)
            vendor = std::bit_cast<std::array<char, 0x20>>(vendor_cpui);
            vendor_ = vendor.data();
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
#pragma warning(push)
#pragma warning(disable :26823)
                f_1_ECX_ = static_cast<unsigned __int64>(data_[1][2]);
                f_1_EDX_ = static_cast<unsigned __int64>(data_[1][3]);
#pragma warning(pop)
            }

            // load bitset with flags for function 0x00000007
            if (nIds_ >= 7)
            {
#pragma warning(push)
#pragma warning(disable :26823)
                f_7_EBX_ = static_cast<unsigned __int64>(data_[7][1]);
                f_7_ECX_ = static_cast<unsigned __int64>(data_[7][2]);
#pragma warning(pop)
            }
            constexpr unsigned int intmax = 0x80000000U; //-V112

            // Calling __cpuid with 0x80000000 as the function_id argument
            // gets the number of the highest valid extended ID.
            __cpuid(cpui.data(), intmax);
            nExIds_ = cpui[0];

            char brand[0x40]{};
            char* const _brand = &brand[0];
            memset(_brand, 0, sizeof(brand)); //-V2547
            for (int i = intmax; i <= nExIds_; ++i)
            {
                __cpuidex(cpui.data(), i, 0);
#pragma warning(suppress:26487)
                extdata_.push_back(cpui);
            }

            // load bitset with flags for function 0x80000001
            if (nExIds_ >= intmax)
            {
                f_81_ECX_ = static_cast<unsigned __int64>(extdata_[1][2]);
                f_81_EDX_ = static_cast<unsigned __int64>(extdata_[1][3]);
                // Interpret CPU brand string if reported

                std::memcpy(&brand[0], extdata_[2].data(), sizeof(cpui));
                memcpy(&brand[16], extdata_[3].data(), sizeof(cpui));
                memcpy(&brand[32], extdata_[4].data(), sizeof(cpui));
                brand_ = &brand[0];
            }
#pragma warning(pop)

        };

#ifndef UPRISE_TESTS
        const UPRISE_ENGINE::CORE::InstructionSet::InstructionSet_Internal CORE::InstructionSet::CPU_Rep;

#endif // !UPRISE_TESTS

    }

     