export module UPRISE_ENGINE_CORE:GC_CONTROLBLOCK;
import :CONTROL_BASE;
export namespace UPRISE_ENGINE {
    namespace CORE {
        class GC_CONTROL_BLOCK:public ControlBlock_Base {
        private:
        public:
            GC_CONTROL_BLOCK() = default;
            ~GC_CONTROL_BLOCK() {
            }
        };
    }
}
