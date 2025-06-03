#pragma once
#ifndef UE_BEHAVIOUR_INTERNAL_
#define UE_BEHAVIOUR_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "OBJECT/OBJECT_INTERNAL.h"
#include <unordered_map>
#include <intrin.h>
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {

    class GameObject;
    class Transform;
        class Behaviour : public Object {//NOSONAR
        private:
        protected:
            UPRISE_ECS_API explicit Behaviour(const Behaviour& other);
            UPRISE_ECS_API explicit Behaviour(const Behaviour& other, bool);
            UPRISE_ECS_API Behaviour& operator=(const Behaviour& other) {
                Object::operator=(other); //-V2547
                this->gameObj = other.gameObj;
                this->uuid = other.uuid;
                this->id = other.id;

                return *this;
            };
        protected:
#pragma region NonStaticVars


            WeakRef<GameObject, true> gameObj;
            ///SharedRef<Behaviour, true> transf; MOVED TO GAMEOBJECT
            UE_SIMD_ALIGN__M128 UUID uuid;

            int id;
        private:


            char PAD[12];   //TODO find a better way to align this or find data to put here //-V112 //NOSONAR
#pragma endregion
#pragma region StaticVars

            MockableStaticVar(behaviours_, TypeMAcroCombiner(std::unordered_map<__m128, std::unordered_map<unsigned long long, WeakRef<Behaviour, true>>>)) //-V1096


                MockableStaticVar(behaviours, TypeMAcroCombiner(std::vector<WeakRef<Behaviour, true>>)) //-V1096
                MockableStaticVar(awakes, TypeMAcroCombiner(std::vector<WeakRef<Behaviour, true>>)) //-V1096
                MockableStaticVar(starts, TypeMAcroCombiner(std::vector<WeakRef<Behaviour, true>>)) //-V1096
                MockableStaticVar(currentUpdate, int) //-V1096
                MockableStaticVar(toBeRemovedAtEndoOfFrame, TypeMAcroCombiner(std::vector<WeakRef<Behaviour, true>>)) //-V1096

#pragma endregion


        public:
#pragma region Constructors
            /// <summary>
            /// constuctor that sets toBeRemoved(false)
            /// </summary>
            /// <returns></returns>
            inline   Behaviour() :Object(), gameObj(), uuid(), id(0), PAD{ DEBUG_PAD_BITS_ZEROED } {};




#pragma endregion
#pragma region destructor
            virtual ~Behaviour() {
                SetEnabled(false); //-V2547


            }
#pragma endregion
            //following region contains all functions
#pragma region funcs
#pragma region OPREATORS
            bool operator==(const Object& other) const {
                const Behaviour& otherBehaviour = static_cast<const  Behaviour&>(other);  //NOSONAR
                bool base = Object::operator==(otherBehaviour);
                return base;
            }

#pragma endregion

            UPRISE_ECS_API   void OnDestroyInt(WeakRef<Object, true> obj)  override;


            //following region contains all virtual member functions
#pragma region Virtual

            /// <summary>
            /// function for drawing the editor wiget
            /// will be removed later
            /// </summary>
            /// <returns></returns>
            virtual  void EditorWindow() = 0;
            /// <summary>
            /// main update function
            /// will be executet on every frame
            /// </summary>
            /// <returns></returns>
            virtual  void Update() = 0;
            /// <summary>
            /// awake function
            /// will be executet before the first update and start after the object is instantiated
            /// will be exectued immidiatly after instatiation
            /// </summary>
            /// <returns></returns>
            virtual  void Awake() = 0;
            /// <summary>
            /// replaces the first update of the object.
            /// is run on the next frame after awake
            /// </summary>
            /// <returns></returns>
            virtual  void Start() = 0;
            /// <summary>
            /// internal function to called to remove this obj from updates
            /// </summary>
            /// <returns></returns>
            UPRISE_ECS_API  bool RemoveFromUpdate();
            /// <summary>
            /// internal function to call to remove this obj from start 
            /// </summary>
            /// <returns></returns>
            UPRISE_ECS_API  bool RemoveFromStart();
            /// <summary>
            /// internal function to call to remove this obj from awake 
            /// </summary>
            /// <returns></returns>
            UPRISE_ECS_API   bool RemoveFromAwake();
            /// <summary>
            /// fujction to call when the object is destroyed
            /// </summary>
            UPRISE_ECS_API     virtual  void OnDestroy() {};

#pragma endregion
            //following region contains all static Member functions
#pragma region  StaticMember
        /// <summary>
        /// loops trough all scripts and calls Update()
        /// </summary>
        /// <returns></returns>
            UPRISE_ECS_API     static  void UpdateAll();
            /// <summary>
            /// loops trough all scripts and calls Awake()
            /// removes the script from the vector after call
            /// </summary>
            /// <returns></returns>
            UPRISE_ECS_API     static  void UpdateAllAWAKE();
            /// <summary>
            /// loops trough scripts and calls Start()
            ///  removes the script from the vector after call
            /// </summary>
            /// <returns></returns>
            UPRISE_ECS_API     static  void UpdateAllSTART();
            /// <summary>
            /// calls all update Parralel instances to update the scripts that derive from it
            /// </summary>
            /// <returns></returns>
            UPRISE_ECS_API     static  void UpdateallParallel();
            /// <summary>
            /// internal function to add script to update loop
            /// </summary>
            /// <param name="behaviour"></param>
            /// <returns></returns>
            UPRISE_ECS_API   static  bool AddToUpdate(SharedRef<Behaviour, true> behaviour);
            /// <summary>
            /// internal function to add script to start
            /// </summary>
            /// <param name="behaviour"></param>
            /// <returns></returns>
            UPRISE_ECS_API   static  bool AddToStart(SharedRef<Behaviour, true> behaviour);
            /// <summary>
            /// internal function to add script to Awake 
            /// will be removed later/moved to intended behaviour
            /// </summary>
            /// <param name="behaviour"></param>
            /// <returns></returns>
            UPRISE_ECS_API static  bool AddToAwake(SharedRef<Behaviour, true> behaviour);

            /// <summary>
            /// Dont Call in user code
            /// </summary>
            UPRISE_ECS_API static  void AfterFrameDestroyBehaviours();


#pragma endregion


#pragma endregion
        };

}

#endif