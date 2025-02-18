// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_BEHAVIOUR_
#define UE_BEHAVIOUR_

#include "UUID/UUID.h"
#include "OBJECT/OBJECT.h"








import std; //-V2575 //-V3549
import REF_WRAPPER; //-V2575 //-V3549
namespace UPRISE_ENGINE {
    class GameOject;
    class Transform;
    namespace CORE {
        
        class  Behaviour :public CORE::Object {
        private:
        protected:
           UPRISE_CORE_API explicit Behaviour(const Behaviour& other);
           UPRISE_CORE_API explicit Behaviour(const Behaviour& other,bool);
           UPRISE_CORE_API Behaviour& operator=(const Behaviour& other);
        private:
#pragma region NonStaticVars


            SharedRef<GameOject, true> gameObj;
            SharedRef<Transform, true> transf;
            UUID uuid;

            int id = 0;
            char PAD[4];   //TODO find a better way to align this or find data to put here
#pragma endregion
#pragma region StaticVars
            UPRISE_CORE_API   static std::vector<SharedRef<CORE::Behaviour, true>> behaviours;
            UPRISE_CORE_API  static std::vector<SharedRef<CORE::Behaviour, true>> awakes;
            UPRISE_CORE_API static std::vector<SharedRef<CORE::Behaviour, true>> starts;
            UPRISE_CORE_API  static int currentUpdate;
#pragma endregion



        public:
#pragma region Constructors
            /// <summary>
            /// constuctor that sets toBeRemoved(false)
            /// </summary>
            /// <returns></returns>
            Behaviour()=default;




#pragma endregion
#pragma region destructor
            virtual ~Behaviour() {
                SetEnabled(false);
            }
#pragma endregion
            //following region contains all functions
#pragma region funcs
#pragma region OPREATORS

#pragma endregion

            UPRISE_CORE_API   void OnDestroyInt(SharedRef<CORE::Object, true> obj) override;


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
            UPRISE_CORE_API  bool RemoveFromUpdate();
            /// <summary>
            /// internal function to call to remove this obj from start 
            /// </summary>
            /// <returns></returns>
            UPRISE_CORE_API  bool RemoveFromStart();
            /// <summary>
            /// internal function to call to remove this obj from awake 
            /// </summary>
            /// <returns></returns>
            UPRISE_CORE_API   bool RemoveFromAwake();
            /// <summary>
            /// fujction to call when the object is destroyed
            /// </summary>
            UPRISE_CORE_API     virtual  void OnDestroy();

#pragma endregion
            //following region contains all static Member functions
#pragma region  StaticMember
        /// <summary>
        /// loops trough all scripts and calls Update()
        /// </summary>
        /// <returns></returns>
            UPRISE_CORE_API     static  void UpdateAll();
            /// <summary>
            /// loops trough all scripts and calls Awake()
            /// removes the script from the vector after call
            /// </summary>
            /// <returns></returns>
            UPRISE_CORE_API     static  void UpdateAllAWAKE();
            /// <summary>
            /// loops trough scripts and calls Start()
            ///  removes the script from the vector after call
            /// </summary>
            /// <returns></returns>
            UPRISE_CORE_API     static  void UpdateAllSTART();
            /// <summary>
            /// calls all update Parralel instances to update the scripts that derive from it
            /// </summary>
            /// <returns></returns>
            UPRISE_CORE_API     static  void UpdateallParallel();
            /// <summary>
            /// internal function to add script to update loop
            /// </summary>
            /// <param name="behaviour"></param>
            /// <returns></returns>
            UPRISE_CORE_API   static  bool AddToUpdate(SharedRef<CORE::Behaviour, true> behaviour);
            /// <summary>
            /// internal function to add script to start
            /// </summary>
            /// <param name="behaviour"></param>
            /// <returns></returns>
            UPRISE_CORE_API   static  bool AddToStart(SharedRef<CORE::Behaviour, true> behaviour);
            /// <summary>
            /// internal function to add script to Awake 
            /// will be removed later/moved to intended behaviour
            /// </summary>
            /// <param name="behaviour"></param>
            /// <returns></returns>
            UPRISE_CORE_API static  bool AddToAwake(SharedRef<CORE::Behaviour, true> behaviour);


#pragma endregion


#pragma endregion


        };
    }
}





#endif // !1
