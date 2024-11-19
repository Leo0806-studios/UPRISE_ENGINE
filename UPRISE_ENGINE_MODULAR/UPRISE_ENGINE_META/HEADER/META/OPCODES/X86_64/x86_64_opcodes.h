#pragma once
#ifndef _x86_64_opcodes_
#define _x86_64_opcodes_
namespace META{
     enum   x86_64_opcodes:long long {
         // MOV Variations
         MOV_REG_TO_REG = 0x89,           /// MOV reg, reg
         MOV_IMM_TO_REG = 0xB8,           /// MOV reg, imm (0xB8 + reg)
         MOV_MEM_TO_REG = 0x8B,           /// MOV reg, [mem]
         MOV_REG_TO_MEM = 0x89,           /// MOV [mem], reg
         MOV_IMM_TO_MEM = 0xC7,           /// MOV [mem], imm

         // PUSH Variations
         PUSH_REG = 0x50,                 /// PUSH reg (0x50 + reg)
         PUSH_IMM8 = 0x6A,                /// PUSH imm8
         PUSH_IMM32 = 0x68,               /// PUSH imm32
         PUSH_MEM = 0xFF,                 /// PUSH [mem] (with modrm)

         // POP Variations
         POP_REG = 0x58,                  /// POP reg (0x58 + reg)
         POP_MEM = 0x8F,                  /// POP [mem] (with modrm)

         // ADD Variations
         ADD_REG_TO_REG = 0x01,           /// ADD reg, reg
         ADD_IMM_TO_REG = 0x83,           /// ADD reg, imm8 (0x83)
         ADD_IMM32_TO_REG = 0x81,         /// ADD reg, imm32
         ADD_REG_TO_MEM = 0x01,           /// ADD [mem], reg
         ADD_MEM_TO_REG = 0x03,           /// ADD reg, [mem]

         // SUB Variations
         SUB_REG_TO_REG = 0x29,           /// SUB reg, reg
         SUB_IMM_TO_REG = 0x83,           /// SUB reg, imm8
         SUB_IMM32_TO_REG = 0x81,         /// SUB reg, imm32
         SUB_REG_TO_MEM = 0x29,           /// SUB [mem], reg
         SUB_MEM_TO_REG = 0x2B,           /// SUB reg, [mem]

         // MUL Variations
         MUL_REG = 0xF7,                  /// MUL reg (opcode with modrm for different sizes)

         // DIV Variations
         DIV_REG = 0xF7,                  /// DIV reg (opcode with modrm for different sizes)

         // INC Variations
         INC_REG = 0x40,                  /// INC reg (0x40 + reg)
         INC_MEM = 0xFF,                  /// INC [mem] (with modrm)

         // DEC Variations
         DEC_REG = 0x48,                  /// DEC reg (0x48 + reg)
         DEC_MEM = 0xFF,                  /// DEC [mem] (with modrm)

         // AND Variations
         AND_REG_TO_REG = 0x21,           /// AND reg, reg
         AND_IMM_TO_REG = 0x83,           /// AND reg, imm8
         AND_IMM32_TO_REG = 0x81,         /// AND reg, imm32
         AND_REG_TO_MEM = 0x21,           /// AND [mem], reg
         AND_MEM_TO_REG = 0x23,           // AND reg, [mem]

         // OR Variations
         OR_REG_TO_REG = 0x09,            // OR reg, reg
         OR_IMM_TO_REG = 0x83,            // OR reg, imm8
         OR_IMM32_TO_REG = 0x81,          // OR reg, imm32
         OR_REG_TO_MEM = 0x09,            // OR [mem], reg
         OR_MEM_TO_REG = 0x0B,            // OR reg, [mem]

         // XOR Variations
         XOR_REG_TO_REG = 0x31,           // XOR reg, reg
         XOR_IMM_TO_REG = 0x83,           // XOR reg, imm8
         XOR_IMM32_TO_REG = 0x81,         // XOR reg, imm32
         XOR_REG_TO_MEM = 0x31,           // XOR [mem], reg
         XOR_MEM_TO_REG = 0x33,           // XOR reg, [mem]

         // NOT Variations
         NOT_REG = 0xF7,                  // NOT reg (opcode with modrm for different sizes)
         NOT_MEM = 0xF7,                  // NOT [mem] (with modrm)

         // Shift and Rotate Instructions
         SHL_REG_CL = 0xD3,               // SHL reg, CL
         SHR_REG_CL = 0xD3,               // SHR reg, CL
         ROL_REG_CL = 0xD3,               // ROL reg, CL
         ROR_REG_CL = 0xD3,               // ROR reg, CL

         // Control Flow Instructions
         JMP_NEAR = 0xE9,                 // Near jump
         JMP_SHORT = 0xEB,                // Short jump
         CALL_NEAR = 0xE8,                // Call near procedure
         RET_NEAR = 0xC3,                 // Return
         JZ_SHORT = 0x74,                 // Jump if zero (short)
         JNZ_SHORT = 0x75,                // Jump if not zero (short)

         // Comparison Instructions
         CMP_REG_TO_REG = 0x39,           // CMP reg, reg
         CMP_IMM_TO_REG = 0x83,           // CMP reg, imm8
         CMP_IMM32_TO_REG = 0x81,         // CMP reg, imm32
         CMP_REG_TO_MEM = 0x39,           // CMP [mem], reg
         CMP_MEM_TO_REG = 0x3B,           // CMP reg, [mem]
         TEST_REG_TO_REG = 0x85,          // TEST reg, reg
         TEST_IMM_TO_REG = 0xF7,          // TEST reg, imm

         // String Operations
         MOVSB = 0xA4,                    // Move byte string
         MOVSW = 0xA5,                    // Move word string
         STOSB = 0xAA,                    // Store byte string
         STOSW = 0xAB,                     // Store word string



         // Control Flow Instructions
             JMP_NEAR = 0xE9,                 // Near jump (relative)
             JMP_SHORT = 0xEB,                // Short jump (relative)
             JMP_FAR = 0xEA,                  // Far jump
             CALL_NEAR = 0xE8,                // Call near procedure (relative)
             CALL_FAR = 0x9A,                 // Call far procedure
             RET_NEAR = 0xC3,                 // Return near
             RET_FAR = 0xCB,                  // Return far
             JZ_SHORT = 0x74,                 // Jump if zero (short)
             JNZ_SHORT = 0x75,                // Jump if not zero (short)
             JG_SHORT = 0x7F,                 // Jump if greater (short)
             JL_SHORT = 0x7C,                 // Jump if less (short)
             JGE_SHORT = 0x7D,                // Jump if greater or equal (short)
             JLE_SHORT = 0x7E,                // Jump if less or equal (short)

             // SIMD Instructions - SSE
             MOVAPS = 0x28,                   // Move aligned packed single-precision floats
             MOVUPS = 0x10,                   // Move unaligned packed single-precision floats
             ADDPS = 0x58,                    // Add packed single-precision floats
             SUBPS = 0x5C,                    // Subtract packed single-precision floats
             MULPS = 0x59,                    // Multiply packed single-precision floats
             DIVPS = 0x5E,                    // Divide packed single-precision floats
             SQRTPS = 0x51,                   // Square root of packed single-precision floats
             ANDPS = 0x54,                    // Bitwise AND packed single-precision floats
             ORPS = 0x56,                     // Bitwise OR packed single-precision floats
             XORPS = 0x57,                    // Bitwise XOR packed single-precision floats
             CMPPS = 0xC2,                    // Compare packed single-precision floats

             // SIMD Instructions - SSE2
             MOVAPD = 0x0000006600000028,            // Move aligned packed double-precision floats
             MOVUPD = 0x0000006600000010,            // Move unaligned packed double-precision floats
             ADDPD = 0x0000006600000058,             // Add packed double-precision floats
             SUBPD = 0x000000660000005C,             // Subtract packed double-precision floats
             MULPD = 0x0000006600000059,             // Multiply packed double-precision floats
             DIVPD = 0x000000660000005E,             // Divide packed double-precision floats
             SQRTPD = 0x0000006600000051,            // Square root of packed double-precision floats
             ANDPD = 0x0000006600000054,             // Bitwise AND packed double-precision floats
             ORPD = 0x0000006600000056,              // Bitwise OR packed double-precision floats
             XORPD = 0x0000006600000057,             // Bitwise XOR packed double-precision floats
             CMPPD = 0x00000066000000C2,             // Compare packed double-precision floats

             // SIMD Instructions - AVX
             VMOVAPS = 0x0000C50000000028,           // Move aligned packed single-precision floats
             VMOVUPS = 0x0000C50000000010,           // Move unaligned packed single-precision floats
             VADDPS = 0x0000C50000000058,            // Add packed single-precision floats
             VSUBPS = 0x0000C5000000005C,            // Subtract packed single-precision floats
             VMULPS = 0x0000C50000000059,            // Multiply packed single-precision floats
             VDIVPS = 0x0000C5000000005E,            // Divide packed single-precision floats
             VSQRTPS = 0x0000C50000000051,           // Square root of packed single-precision floats
             VANDPS = 0x0000C50000000054,            // Bitwise AND packed single-precision floats
             VORPS = 0x0000C50000000056,             // Bitwise OR packed single-precision floats
             VXORPS = 0x0000C50000000057,            // Bitwise XOR packed single-precision floats
             VCMPPS = 0x0000C500000000C2,            // Compare packed single-precision floats

             // SIMD Instructions - AVX2
             VADDPD = 0x0000C50000000058,            // Add packed double-precision floats
             VSUBPD = 0x0000C5000000005C,            // Subtract packed double-precision floats
             VMULPD = 0x0000C50000000059,            // Multiply packed double-precision floats
             VDIVPD = 0x0000C5000000005E,            // Divide packed double-precision floats
             VANDPD = 0x0000C50000000054,            // Bitwise AND packed double-precision floats
             VORPD = 0x0000C50000000056,             // Bitwise OR packed double-precision floats
             VXORPD = 0x0000C50000000057,            // Bitwise XOR packed double-precision floats

             // SIMD Instructions - AVX512 (example)
             VADDPS_512 = 0x62F17C0000000058,        // Add packed single-precision floats (AVX-512)
             VSUBPS_512 = 0x62F17C000000005C,        // Subtract packed single-precision floats (AVX-512)
             VMULPS_512 = 0x62F17C0000000059,        // Multiply packed single-precision floats (AVX-512)
             VDIVPS_512 = 0x62F17C000000005E ,        // Divide packed single-precision floats (AVX-512)
             // Floating-Point Instructions (x87 FPU)
             FLD_ST0 = 0x00000000000000D9C0,          // Load ST(0) with a value from memory
             FST_ST0 = 0x00000000000000DDD0,          // Store ST(0) to memory
             FSTP_ST0 = 0x00000000000000DDD8,         // Store and pop ST(0) to memory
             FADD_ST0_ST1 = 0x00000000000000D8C1,     // Add ST(0) and ST(1), store result in ST(0)
             FSUB_ST0_ST1 = 0x00000000000000D8E1,     // Subtract ST(1) from ST(0), store result in ST(0)
             FSUBR_ST0_ST1 = 0x00000000000000D8E9,    // Subtract ST(0) from ST(1), store result in ST(0)
             FMUL_ST0_ST1 = 0x00000000000000D8C9,     // Multiply ST(0) and ST(1), store result in ST(0)
             FDIV_ST0_ST1 = 0x00000000000000D8F1,     // Divide ST(0) by ST(1), store result in ST(0)
             FDIVR_ST0_ST1 = 0x00000000000000D8F9,    // Divide ST(1) by ST(0), store result in ST(0)
             FABS = 0x00000000000000D9E1,             // Absolute value of ST(0)
             FSQRT = 0x00000000000000D9FA,            // Square root of ST(0)
             FSIN = 0x00000000000000D9FE,             // Sine of ST(0)
             FCOS = 0x00000000000000D9FF,             // Cosine of ST(0)
             FTAN = 0x00000000000000D9F2,             // Tangent of ST(0)
             F2XM1 = 0x00000000000000D9F0,            // 2^ST(0) - 1
             FYL2X = 0x00000000000000D9F1,            // y * log2(x) with y = ST(1) and x = ST(0)
             FCHS = 0x00000000000000D9E0,             // Change sign of ST(0)

             // Floating-Point Comparison Instructions
             FCOM_ST0 = 0x00000000000000D8D0,         // Compare ST(0) with ST(1)
             FCOMP_ST0 = 0x00000000000000D8D8,        // Compare ST(0) with ST(1) and pop
             FCOMPP = 0x00000000000000DED9,           // Compare ST(0) with ST(1) and pop twice

             // Floating-Point Stack Management
             FINCSTP = 0x00000000000000D9F7,          // Increment FPU stack pointer
             FDECSTP = 0x00000000000000D9F6,          // Decrement FPU stack pointer
             FFREE_ST0 = 0x00000000000000DDC0,        // Free ST(0)
             FNOP = 0x00000000000000D9D0

     };
    }

#endif // !_x86_64_opcodes_
