// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



import UPRISE_ENGINE_CORE;

#ifndef UPRISE_TESTS
import UPRISE_ENGINE_DEBUG;
#endif
import std; //-V2575 //-V3549
 namespace UPRISE_ENGINE {
    namespace CORE {
#ifndef UPRISE_TESTS
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::behaviours;
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::awakes;
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::starts;
        std::unordered_map<__m128, std::unordered_map<unsigned long long, WeakRef<CORE::Behaviour, true>>> CORE::Behaviour::behaviours_;
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::toBeRemovedAtEndoOfFrame;
        int CORE::Behaviour::currentUpdate = 0;

#endif
#pragma warning(push)
#pragma warning(disable:4273)
        void UPRISE_ENGINE::CORE::Behaviour::OnDestroyInt(WeakRef<CORE::Object, true> obj)
        {
            WeakRef<CORE::Behaviour, true> AsBehaviour = obj;
            WeakRef<GameObject,true> GamObj = AsBehaviour->gameObj;
            
            toBeRemovedAtEndoOfFrame.push_back(std::move(AsBehaviour));

        }


        void Behaviour::AfterFrameDestroyBehaviours()
        {
            Index i = toBeRemovedAtEndoOfFrame.size();
            for (; i > 0; i--) {
                WeakRef Obj = std::move(toBeRemovedAtEndoOfFrame[i - 1]);
                
                WeakRef<GameObject,true> GamObj = Obj->gameObj;
                FunctionTransporter::RemoveBehaviourFromGameobject__internal(GamObj.get(), Obj);

            }
        }
#pragma warning(pop)
    }
}