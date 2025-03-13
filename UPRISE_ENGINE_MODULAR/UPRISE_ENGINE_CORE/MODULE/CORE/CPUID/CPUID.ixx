export module UPRISE_ENGINE_CORE:CPUID;
import std;
export namespace UPRISE_ENGINE {
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
#pragma warning(push)
#pragma warning(disable: 4367)
                UPRISE_CORE_API   InstructionSet_Internal();
#pragma warning(pop)

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
}