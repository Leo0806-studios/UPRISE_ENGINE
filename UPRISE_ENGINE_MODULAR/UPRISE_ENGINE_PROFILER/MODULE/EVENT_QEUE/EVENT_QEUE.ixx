export module UPRISE_ENGINE_PROFILER:EVENT_QEUE;
import :EVENT_BASE;
import <memory>;
import <vector>;
import <atomic>;
import <mutex>;

export namespace UPRISE_ENGINE {
    namespace PROFILER {
        class EVENT_QEUE {
        private:


            UPRISE_PROFILER_API static  std::vector<std::unique_ptr<EVENT_BASE>> qeue;
            UPRISE_PROFILER_API static std::vector<std::unique_ptr<EVENT_BASE>> UsedQeue;
            UPRISE_PROFILER_API static std::atomic<size_t> atomic_qeue_size;
        public:
            static inline size_t getUsedQeueSize() {
                return UsedQeue.size();
            }

            //static   void shrink_to_fit() {
            //      qeue.shrink_to_fit();
            //  }

              // UPRISE_PROFILER_API static std::mutex m;
            UPRISE_PROFILER_API static std::mutex& GetMutex();
            UPRISE_PROFILER_API static void Add_to_Qeue(std::unique_ptr<EVENT_BASE>&& event);
            UPRISE_PROFILER_API static void UseCurrentQeue();

            /// <summary>
            /// gets the first event and removes it from the qeue
            /// </summary>
            /// <returns></returns>
            UPRISE_PROFILER_API static std::unique_ptr<EVENT_BASE> Get_Last_Event();
            static size_t Get_Qeue_Size() {
                return atomic_qeue_size.load(std::memory_order_relaxed);
                //std::unique_lock<std::mutex> lock(GetMutex());
                //return qeue.size();
            }
            EVENT_QEUE();
            ~EVENT_QEUE();
        };
    }
}