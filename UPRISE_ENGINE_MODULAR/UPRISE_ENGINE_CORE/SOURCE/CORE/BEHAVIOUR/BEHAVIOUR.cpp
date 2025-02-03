// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "CORE/BEHAVIOUR/BEHAVIOUR.h";
#include <DEBUG/LOG/LOG.h>
import std; //-V2575 //-V3549
namespace UPRISE_ENGINE {
    std::vector<RefWrapper<CORE::Behaviour, true>> CORE::Behaviour::behaviours;
    std::vector<RefWrapper<CORE::Behaviour, true>> CORE::Behaviour::awakes;
    std::vector<RefWrapper<CORE::Behaviour, true>> CORE::Behaviour::starts;




    /// <summary>
    /// updates all Scripts 
    /// </summary>
    /// <returns>void</returns>
    void CORE::Behaviour::UpdateAll()
    {
        TrPr(ctx, __func__)
            huge i = behaviours.size() - 1;
        for (; i >= 0; i--) {

            behaviours[i]->Update();




        }

        TrPrE(ctx);
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    void CORE::Behaviour::UpdateAllAWAKE()
    {
        TrPr(ctx, __func__)
            for (huge i = awakes.size() - 1; i >= 0; i--) {

                awakes[i]->Awake();
                awakes.erase(awakes.begin() + i);

            }
        TrPrE(ctx);
    }

    void CORE::Behaviour::UpdateAllSTART()
    {
        TrPr(ctx, __func__)
            for (huge i = starts.size() - 1; i >= 0; i--) {

                starts[i]->Start();
                CORE::Behaviour::AddToUpdate(starts[i]);
                starts.erase(starts.begin() + i);

            }
        TrPrE(ctx);
    }

    void CORE::Behaviour::UpdateallParallel()
    {

    }

    bool CORE::Behaviour::AddToUpdate(RefWrapper<CORE::Behaviour, true> behaviour)
    {
        behaviours.push_back(behaviour);
        return  true;
    }

    bool CORE::Behaviour::AddToStart(RefWrapper<CORE::Behaviour, true> behaviour)
    {
        awakes.push_back(behaviour);
        return true;
    }

    bool CORE::Behaviour::AddToAwake(RefWrapper<CORE::Behaviour, true> behaviour)
    {
        starts.push_back(behaviour);
        return true;
    }
    bool CORE::Behaviour::RemoveFromUpdate()
    {
        //behaviours.erase(behaviours.begin());
        //TODO: implement
        return true;

    }

    bool CORE::Behaviour::RemoveFromStart()
    {
        //TODO: implement

        return true;
    }
    bool CORE::Behaviour::RemoveFromAwake()
    {
        //TODO: implement

        return true;

    }
    void CORE::Behaviour::OnDestroy()
    {
        //TODO: implement
    }
    int CORE::Behaviour::currentUpdate = 0;

    void CORE::Behaviour::OnDestroyInt(RefWrapper<Object, true> obj)
    {
        UPRISE_ENGINE::DEBUG::Debug::Log( "Calling OnDestroy\n");
        OnDestroy();
        obj.Destroy();

    }
}


