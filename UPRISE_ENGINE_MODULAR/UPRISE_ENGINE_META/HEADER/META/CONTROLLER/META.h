// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _META_
#define _META_
#include "Windows.h"
#include "META//OPCODES/X86_64/x86_64_opcodes.h"
extern "C" {
    void _internal_Meta_Execute(void* ptr);
}
namespace UPRISE_ENGINE {
    namespace META
    {
        class Meta_Obj {
        private:
            void* m_data;
            size_t Size;
            friend class Meta;
            Meta_Obj(size_t init_size) {
                Size = init_size;
                m_data = VirtualAlloc(NULL, init_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
                VirtualProtect(m_data, init_size, PAGE_EXECUTE_READWRITE, NULL);
            }
            bool relocate(size_t new_size) {
                void* tmp = VirtualAlloc(NULL, new_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
                memccpy(tmp, m_data, new_size, Size);
                VirtualFree(m_data, 0, MEM_RELEASE);
                m_data = tmp;
                return true;
            }
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
            static void EmitOpcode(META::x86_64_opcodes opcode) {

            }
            static void EmitOpcode(META::x86_64_opcodes opcode, byte op0) {

            }
            static void EmitOpcode(META::x86_64_opcodes opcode, byte op0, byte op1) {

            }
            static void EmitOpcode(META::x86_64_opcodes opcode, byte op0, byte op1, byte op2) {

            }
            static void EmitOpcode(META::x86_64_opcodes opcode, byte op0, byte op1, byte op2, byte op3) {

            }
        };
    }
}

#endif // !_META_
