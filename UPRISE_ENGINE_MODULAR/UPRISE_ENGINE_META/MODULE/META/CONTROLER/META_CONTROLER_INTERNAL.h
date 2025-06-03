#pragma once
#ifndef UE_META_CONTROLER_INTERNAL_
#define UE_META_CONTROLER_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_META_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif

#ifdef __INTELLISENSE__
#include "OPCODES/X86_64/AVX/X86_64_AVX_OPCODES_INTERNAL.h"
#include "OPCODES/X86_64/AVX2/X86_64_AVX2_OPCODES_INTERNAL.h"
#include "OPCODES/X86_64/GENERAL_PURPOSE/X86_64_GP_OPCODES_INTERNAL.h"
#include "OPCODES/X86_64/SSE/X86_64_SSE_OPCODES_INTERNAL.h"
#include "OPCODES/X86_64/X87/X87_OPCODES_INTERNAL.h"
#endif // __INTELLISENSE__

extern "C" {
    void _internal_Meta_Execute(void* ptr);
}
namespace UPRISE_ENGINE {
    namespace META
    {
        struct X86_64_LegacyPrefixes {
            unsigned char Prefixes[4]{ 0,0,0,0 };
            unsigned char PrefixCount = 0;
        };
        struct X86_64_MandatoryPrefix {
            unsigned char Prefix = 0;
            bool IsMandatory = false;
        };
        struct X86_64_REXPrefix {
            ubyte REX = 0b01000000;
            void ToggleB() {
                REX = REX ^ (1U << 0U);
            }
            void ToggleX() {
                REX = REX ^ (1U << 1U);
            }
            void ToggleR() {
                REX = REX ^ (1U << 2U);
            }
            void ToggleW() {
                REX = REX ^ (1U << 3U);
            }
            bool GetB() const {
                return (REX >> 0U) & 1U;
            }
            bool GetX() const {
                return (REX >> 1U) & 1U;
            }
            bool GetR() const {
                return (REX >> 2U) & 1U;
            }
            bool GetW() const {
                return (REX >> 3U) & 1U;
            }

        };
        struct X86_64_FullOpcode
        {
            X86_64_MandatoryPrefix MandatoryPrefix;
        private:
            char PAD[5];//TODO find a better way to align this
        public:
            X86_64_REXPrefix REX;
            struct Type {
                enum class OpcodeType: unsigned long long
                {
                    avx,
                    avx2,
                    gp,
                    sse,
                    x87

                } OpcodeType;
                union RealOpcode {
                    x86_64_avx2_opcodes AVX2;
                    x86_64_avx_opcodes AVX;
                    x86_64_GP_opcodes GP;
                    x86_64_SSE_opcodes SSE;
                    x87_opcodes X87;

                } Opcode;

            }Opcode;

            void SetOpcode(x86_64_avx2_opcodes opcode) {
                Opcode.OpcodeType = Type::OpcodeType::avx2;
                Opcode.Opcode.AVX2 = opcode;
            }
            void SetOpcode(x86_64_avx_opcodes opcode) {
                Opcode.OpcodeType = Type::OpcodeType::avx;
                Opcode.Opcode.AVX = opcode;
            }
            void SetOpcode(x86_64_GP_opcodes opcode) {
                Opcode.OpcodeType = Type::OpcodeType::gp;
                Opcode.Opcode.GP = opcode;
            }
            void SetOpcode(x86_64_SSE_opcodes opcode) {
                Opcode.OpcodeType = Type::OpcodeType::sse;
                Opcode.Opcode.SSE = opcode;
            }
            void SetOpcode(x87_opcodes opcode) {
                Opcode.OpcodeType = Type::OpcodeType::x87;
                Opcode.Opcode.X87 = opcode;
            }
            auto GetOpCodeType() const {
                return Opcode.OpcodeType;
            }
            unsigned long long GetOpCode() const {
                switch (Opcode.OpcodeType) {
                case Type::OpcodeType::avx2:
                {
                    return Opcode.Opcode.AVX2;
                    break;
                }
                case Type::OpcodeType::avx:
                {
                    return Opcode.Opcode.AVX;
                    break;
                }
                case Type::OpcodeType::gp:
                {
                    return Opcode.Opcode.GP;
                    break;
                }
                case Type::OpcodeType::sse:
                {
                    return Opcode.Opcode.SSE;
                    break;
                }
                case Type::OpcodeType::x87:
                {
                    return Opcode.Opcode.X87;
                    break;
                }
                default: {
                    __assume(false); // This should never happen, but just in case
                }
                }
            }
        };
        struct X86_64_instruction {
            X86_64_LegacyPrefixes Prefixes;
        };
        class Meta_Obj {
        private:
            void* m_data=nullptr;
            size_t Size;
            friend class Meta;
           UPRISE_META_API Meta_Obj(size_t init_size);
            bool relocate(size_t new_size);
            void execute() {
                _internal_Meta_Execute(m_data);
            }
            ~Meta_Obj() {};
        public:
            void operator()() {
                execute();
            }
        };
        class Meta {
        private:
        public:
            Meta() = default;
            ~Meta() {}
            static Meta_Obj* CreateMetaObject(size_t init_size) {
                return new Meta_Obj(init_size);
            }

            static void Execute(Meta_Obj* obj) {
                obj->execute();
            }
            static void EmitOpcode(X86_64_instruction Instruction) {
                (void)Instruction;
                UE_THROW_NOT_IMPLEMENTED;
            }

        };
    }
}
#endif