// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "CORE/BEHAVIOUR/BEHAVIOUR.h"
#include "DEBUG/LOG/LOG.h"
import std; //-V2575 //-V3549
namespace UPRISE_ENGINE {
    std::vector<SharedRef<CORE::Behaviour, true>> CORE::Behaviour::behaviours;
    std::vector<SharedRef<CORE::Behaviour, true>> CORE::Behaviour::awakes;
    std::vector<SharedRef<CORE::Behaviour, true>> CORE::Behaviour::starts;



    namespace CORE {
        Behaviour::Behaviour(const Behaviour& other, bool) :Object(other, true)
        {
            gameObj = other.gameObj;
            transf = other.transf;
            uuid = other.uuid;
            id = other.id;
        }
   


        CORE::Behaviour::Behaviour(const Behaviour& other) :Object(other)
        {
            gameObj = other.gameObj;
            transf = other.transf;
            uuid = other.uuid;
            id = other.id;
        }
        /// <summary>
        /// updates all Scripts 
        /// </summary>
        /// <returns>void</returns>
        void CORE::Behaviour::UpdateAll()
        {
            for (Index i = behaviours.size(); i > 0; i--) {

                behaviours[i - 1]->Update();




            }

        }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        void CORE::Behaviour::UpdateAllAWAKE()
        {
            for (Index i = awakes.size(); i > 0; i--) {
                awakes[i - 1]->Awake();
                awakes.erase(awakes.begin() + static_cast<long long>(i - 1ULL));

            }
        }

        void CORE::Behaviour::UpdateAllSTART()
        {
            for (Index i = starts.size(); i > 0; i--) {
                starts[i - 1]->Start();
                CORE::Behaviour::AddToUpdate(starts[i - 1]);

                starts.erase((starts.begin() + static_cast<long long>(i - 1ULL)));

            }
        }

        void CORE::Behaviour::UpdateallParallel()
        {

        }

        bool CORE::Behaviour::AddToUpdate(SharedRef<CORE::Behaviour, true> behaviour)
        {
            behaviours.push_back(behaviour);
            return  true;
        }

        bool CORE::Behaviour::AddToStart(SharedRef<CORE::Behaviour, true> behaviour)
        {
            awakes.push_back(behaviour);
            return true;
        }

        bool CORE::Behaviour::AddToAwake(SharedRef<CORE::Behaviour, true> behaviour)
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

        void CORE::Behaviour::OnDestroyInt(SharedRef<Object, true> obj)
        {
            UPRISE_ENGINE::DEBUG::Debug::Log("Calling OnDestroy\n");
            OnDestroy();
            obj.Destroy();

        }
    }


}