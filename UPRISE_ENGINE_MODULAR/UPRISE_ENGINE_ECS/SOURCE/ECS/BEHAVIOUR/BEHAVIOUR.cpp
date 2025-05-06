// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_ECS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_ECS;

#endif // __INTELLISENSE__




#ifndef UPRISE_TESTS
import UPRISE_ENGINE_DEBUG;
#endif
import std; //-V2575 //-V3549
 namespace UPRISE_ENGINE {
    
#ifndef UPRISE_TESTS
        std::vector<WeakRef<Behaviour, true>> Behaviour::behaviours;
        std::vector<WeakRef<Behaviour, true>> Behaviour::awakes;
        std::vector<WeakRef<Behaviour, true>> Behaviour::starts;

        std::unordered_map<__m128, std::unordered_map<unsigned long long, WeakRef<Behaviour, true>>> Behaviour::behaviours_;
        std::vector<WeakRef<Behaviour, true>> Behaviour::toBeRemovedAtEndoOfFrame;
        int Behaviour::currentUpdate = 0;

#endif
#pragma warning(push)
#pragma warning(disable:4273)
        void UPRISE_ENGINE::Behaviour::OnDestroyInt(WeakRef<Object, true> obj)
        {
            WeakRef<Behaviour, true> AsBehaviour = obj;
            WeakRef<GameObject,true> GamObj = AsBehaviour->gameObj;
            
            toBeRemovedAtEndoOfFrame.push_back(std::move(AsBehaviour));

        }


        void Behaviour::AfterFrameDestroyBehaviours()
        {
            Index R = toBeRemovedAtEndoOfFrame.size();
            Index i = toBeRemovedAtEndoOfFrame.size();
            for (; i > 0; i--) {
                if (i - 1 >= R) {
                    throw std::runtime_error("w");
                }
                WeakRef Obj = std::move(toBeRemovedAtEndoOfFrame[i - 1]);
                
                WeakRef<GameObject,true> GamObj = Obj->gameObj;
                FunctionTransporter::RemoveBehaviourFromGameobject__internal(GamObj.Get(), Obj);

            }
        }
#pragma warning(pop)
    
}