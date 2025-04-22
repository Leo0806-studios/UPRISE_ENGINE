// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module UPRISE_ENGINE_CORE:GC_CONTROLBLOCK;
import :CONTROL_BASE;
export namespace UPRISE_ENGINE {
    namespace CORE {
        class GC_CONTROL_BLOCK:public ControlBlock_Base {
        private:
        public:
            GC_CONTROL_BLOCK()noexcept = default;
            ~GC_CONTROL_BLOCK()noexcept = default;
            GC_CONTROL_BLOCK(const GC_CONTROL_BLOCK& other) = delete;
            GC_CONTROL_BLOCK(GC_CONTROL_BLOCK&& other) = delete;
            GC_CONTROL_BLOCK& operator=(const GC_CONTROL_BLOCK& other) = delete;
            GC_CONTROL_BLOCK& operator=(GC_CONTROL_BLOCK&& other) = delete;
        };
    }
}
