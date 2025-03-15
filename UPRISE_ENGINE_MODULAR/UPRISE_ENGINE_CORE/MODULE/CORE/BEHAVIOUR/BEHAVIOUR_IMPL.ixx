module;
#include <intrin.h>
export module UPRISE_ENGINE_CORE:BEHAVIOUR_IMPL;
import std;
import :OBJECT;
import :BEHAVIOUR;
export namespace UPRISE_ENGINE {
    namespace CORE {
#ifndef UPRISE_TESTS
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::behaviours;
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::awakes;
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::starts;
        std::unordered_map<__m128, std::unordered_map<unsigned long long, WeakRef<CORE::Behaviour, true>>> CORE::Behaviour::behaviours_;
        std::vector<WeakRef<CORE::Behaviour, true>> CORE::Behaviour::toBeRemovedAtEndoOfFrame;
        int CORE::Behaviour::currentUpdate = 0;

#endif
        void UPRISE_ENGINE::CORE::Behaviour::OnDestroyInt(WeakRef<CORE::Object, true> obj) 
        {
            WeakRef<CORE::Behaviour, true> AsBehaviour = obj;
            WeakRef GamObj = AsBehaviour->gameObj;
            toBeRemovedAtEndoOfFrame.push_back(std::move(AsBehaviour));

        }


        void Behaviour::AfterFrameDestroyBehaviours()
        {
            Index i = toBeRemovedAtEndoOfFrame.size();
            for (; i > 0; i--) {
                WeakRef Obj = std::move(toBeRemovedAtEndoOfFrame[i - 1]);
                WeakRef GamObj = Obj->gameObj;
                FunctionTransporter::RemoveBehaviourFromGameobject__internal(GamObj.Get(), Obj);

            }
        }
    }
}