#include "CPUFEATURES.h"


// getters

 std::string CORE::InstructionSet::Vendor(void) { return CPU_Rep.vendor_; }

 std::string CORE::InstructionSet::Brand(void) { return CPU_Rep.brand_; }

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

 const CORE::InstructionSet::InstructionSet_Internal CORE::InstructionSet::CPU_Rep;