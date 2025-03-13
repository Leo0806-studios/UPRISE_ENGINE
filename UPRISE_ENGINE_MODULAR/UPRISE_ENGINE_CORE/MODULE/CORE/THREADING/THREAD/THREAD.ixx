export module UPRISE_ENGINE_CORE:THREAD;
import std;
export namespace UPRISE_ENGINE {
    namespace THREADING {
        class Thread {
        private:
            long unsigned long thread_id = 0;

        public:
            UE_NODISCARD Thread() = default;

            ~Thread() {}
        };
    }
}