// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "CORE/BEHAVIOUR/BEHAVIOUR.h"

#ifndef UPRISE_TESTS
#include "DEBUG/LOG/LOG.h"
#endif
import std; //-V2575 //-V3549
namespace UPRISE_ENGINE {
#ifndef UPRISE_TESTS
    std::vector<SharedRef<CORE::Behaviour, true>> CORE::Behaviour::behaviours;
    std::vector<SharedRef<CORE::Behaviour, true>> CORE::Behaviour::awakes;
    std::vector<SharedRef<CORE::Behaviour, true>> CORE::Behaviour::starts;
    int CORE::Behaviour::currentUpdate = 0;

#endif



    namespace CORE {
        Behaviour::Behaviour(const Behaviour& other, bool) : //-V2537
            Object(other, true) ,
            gameObj(),//default construct the sahred ref so it doesnt complain and so that initialiaztion is done
            uuid(other.uuid),
            id(other.id),
            PAD{ DEBUG_PAD_BITS_ZEROED }
        {
            ///  gameObj = other.gameObj;we should not coppy the gameobject bc of recursive coppying

        }
   


        CORE::Behaviour::Behaviour(const Behaviour& other) :
            Object(other),
            gameObj(other.gameObj),//assignment in a shallow copy is not a problem
            uuid(other.uuid),
            id(other.id),
            PAD{ DEBUG_PAD_BITS_ZEROED }
        {

        }
        /// <summary>
        /// updates all Scripts 
        /// </summary>
        /// <returns>void</returns>
        void CORE::Behaviour::UpdateAll()
        {
            
            Index size = AccsesStaticVar(behaviours).size();
            for (Index i = size; i > 0; i--) {
                if (i >= size) {
                    throw std::out_of_range("Index out of range");
                }
                AccsesStaticVar(behaviours)[i - 1]->Update();




            }

        }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        void CORE::Behaviour::UpdateAllAWAKE()
        {
            Index size = AccsesStaticVar(awakes).size();
            for (Index i = AccsesStaticVar(awakes).size(); i > 0; i--) {
                if (i >= size) {
                    throw std::out_of_range("Index out of range");
                }
                AccsesStaticVar(awakes)[i - 1]->Awake();
                AccsesStaticVar(awakes).erase(AccsesStaticVar(awakes).begin() + static_cast<long long>(i - 1ULL));

            }
        }

        void CORE::Behaviour::UpdateAllSTART()
        {
            Index size = AccsesStaticVar(starts).size();
            for (Index i = AccsesStaticVar(starts).size(); i > 0; i--) {
                if (i >= size) {
                    throw std::out_of_range("Index out of range");
                }
                AccsesStaticVar(starts)[i - 1]->Start();
               const bool succsesfull= CORE::Behaviour::AddToUpdate(AccsesStaticVar(starts)[i - 1]);
               if (!succsesfull) {
                   throw std::exception("Failed to add to update");
               }

                AccsesStaticVar(starts).erase((AccsesStaticVar(starts).begin() + static_cast<long long>(i - 1ULL)));

            }
        }

        void CORE::Behaviour::UpdateallParallel()
        {

        }

        bool CORE::Behaviour::AddToUpdate(SharedRef<CORE::Behaviour, true> behaviour)
        {
            AccsesStaticVar(behaviours).push_back(behaviour);
            return  true;
        }

        bool CORE::Behaviour::AddToStart(SharedRef<CORE::Behaviour, true> behaviour)
        {
            AccsesStaticVar(awakes).push_back(behaviour);
            return true;
        }

        bool CORE::Behaviour::AddToAwake(SharedRef<CORE::Behaviour, true> behaviour)
        {
            AccsesStaticVar(starts).push_back(behaviour);
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


        void CORE::Behaviour::OnDestroyInt(SharedRef<Object, true> obj)
        {
            CallMockableMethod(UPRISE_ENGINE::DEBUG::Debug::Log("Calling OnDestroy\n")); //-V2578
            OnDestroy();
            obj.Destroy();

        }
    }


}