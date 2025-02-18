// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "PROFILER/EVENT_QEUE/EVENT_QEUE.h"
#include <cassert>
namespace UPRISE_ENGINE {
    namespace PROFILER {
        std::vector<std::unique_ptr<EVENT_BASE>> EVENT_QEUE::qeue;
      //  std::mutex EVENT_QEUE::m;
        std::vector<std::unique_ptr<EVENT_BASE>> EVENT_QEUE::UsedQeue;
       // PROFILE_EVENT* EVENT_QEUE::ptr_qeue = nullptr;

        std::unique_ptr<EVENT_BASE> UPRISE_ENGINE::PROFILER::EVENT_QEUE::Get_Last_Event()
        {
            //std::unique_lock<std::mutex> lock(GetMutex());
            //if (UsedQeue.capacity() - UsedQeue.size() > 1000000) {
            //    UsedQeue.shrink_to_fit();
            //}
            if (!UsedQeue.empty())
            {
                std::unique_ptr<EVENT_BASE> temp = std::move(UsedQeue.back());
                UsedQeue.pop_back();
                return temp;
            }

            return nullptr;
        }
        //std::unique_ptr<EVENT_BASE> UPRISE_ENGINE::PROFILER::EVENT_QEUE::Get_Last_Event()
        //{
        //    Index size = UsedQeue.size();
        //    if (size > 0)
        //    {
        //        std::unique_lock<std::mutex> lock(GetMutex());
        //        Index i = size - 1;
        //        std::unique_ptr<EVENT_BASE> temp = std::move(UsedQeue[i]);
        //        UsedQeue.pop_back();
        //        
        //      //  std::cout << "getting event    ";
        //       // std::cout << temp->What() << "   |||||\n";
        //        return temp;
        //    }

        //    return  std::unique_ptr<EVENT_BASE>();
        //}
        UPRISE_ENGINE::PROFILER::EVENT_QEUE::EVENT_QEUE()
        {
        }
        UPRISE_ENGINE::PROFILER::EVENT_QEUE::~EVENT_QEUE()
        {
        }

        // UPRISE_PROFILER_API static std::mutex m;

        inline std::mutex& UPRISE_ENGINE::PROFILER::EVENT_QEUE::GetMutex() {
            static std::mutex m;
            return m;
        }
        void UPRISE_ENGINE::PROFILER::EVENT_QEUE::Add_to_Qeue(std::unique_ptr<EVENT_BASE>&& event)
        {
            std::unique_lock<std::mutex> lock(GetMutex());
            qeue.push_back(std::move(event));
            assert(event.get() == nullptr); //-V2570 //-V2528 //-V2578 //-V3545 //-V3519 //-V3551

        }
        void UPRISE_ENGINE::PROFILER::EVENT_QEUE::UseCurrentQeue()
        {
            std::unique_lock<std::mutex> lock(GetMutex());
            if (qeue.size() > 0)
            {
                UsedQeue.clear();
                UsedQeue.shrink_to_fit();
                for (auto it = qeue.rbegin(); it != qeue.rend(); ++it) {
                    UsedQeue.push_back(std::move(*it));
                }
                qeue.clear();
                qeue.shrink_to_fit();
            }
        }
        /*void UPRISE_ENGINE::PROFILER::EVENT_QEUE::UseCurrentQeue()
        {
 
            std::unique_lock<std::mutex> lock(GetMutex());
            if (qeue.size() > 0)
            {
                UsedQeue.clear();
                UsedQeue.shrink_to_fit();
                
                for (auto& event : qeue) {
                    UsedQeue.push_back(std::move(event));
                }
                qeue.clear();
                qeue.shrink_to_fit();
            }

              

        }*/
    }
}


