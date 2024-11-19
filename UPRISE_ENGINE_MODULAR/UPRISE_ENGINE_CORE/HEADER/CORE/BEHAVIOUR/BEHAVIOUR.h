
#pragma once
#ifndef _BEHAVIOUR_
#define _BEHAVIOUR_

#include "Windows.h"
#include "OBJECT/OBJECT.h";








import std;
import REF_WRAPPER;

class GameOject;
class Transform;
 namespace CORE {
      class UPRISE_CORE_API Behaviour:public CORE::Object {
	private:
#pragma region NonStaticVars
		RefWrapper<GameOject,true> gameObj;
		RefWrapper<Transform,true> transf;
		UUID uuid;
		int id;
		bool toBeRemoved;
		//bool enabled;

#pragma endregion
#pragma region StaticVars
         static std::vector<RefWrapper<CORE::Behaviour,true>> behaviours;
         static std::vector<RefWrapper<CORE::Behaviour,true>> awakes;
         static std::vector<RefWrapper<CORE::Behaviour,true>> starts;
          static int currentUpdate;
#pragma endregion



	public:
#pragma region Constructors
		/// <summary>
		/// constuctor that sets toBeRemoved(false)
		/// </summary>
		/// <returns></returns>
         Behaviour() :toBeRemoved(false) {};
		/// <summary>
		/// constuctor that sets toBeRemoved(true)
		/// </summary>
		/// <param name="remove"></param>
		/// <returns></returns>
         Behaviour(int remove) :toBeRemoved(true) {};

#pragma endregion
#pragma region destructor
         virtual ~Behaviour() {
            toBeRemoved = true;
            Enabled() = false;
		}
#pragma endregion
		//following region contains all functions
#pragma region funcs
          void OnDestroyInt(RefWrapper<CORE::Object,true> obj) override;


		//following region contains all virtual member functions
#pragma region Virtual
		/// <summary>
		/// performs a shallow copy of the object
		/// </summary>
		/// <returns></returns>
          virtual  RefWrapper<CORE::Behaviour,true> Copy() = 0;
		/// <summary>
		/// performs a deepcopy of the object
		/// </summary>
		/// <returns></returns>
         	virtual  RefWrapper<CORE::Behaviour,true> DeepCopy() = 0;
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
          virtual  void Update() =0;
		/// <summary>
		/// awake function
		/// will be executet before the first update and start after the object is instantiated
		/// will be exectued immidiatly after instatiation
		/// </summary>
		/// <returns></returns>
		virtual  void Awake() =0;
		/// <summary>
		/// replaces the first update of the object.
		/// is run on the next frame after awake
		/// </summary>
		/// <returns></returns>
		virtual  void Start() =0;
		/// <summary>
		/// internal function to called to remove this obj from updates
		/// </summary>
		/// <returns></returns>
		  bool RemoveFromUpdate();
		/// <summary>
		/// internal function to call to remove this obj from start 
		/// </summary>
		/// <returns></returns>
		  bool RemoveFromStart();
		/// <summary>
		/// internal function to call to remove this obj from awake 
		/// </summary>
		/// <returns></returns>
		  bool RemoveFromAwake();
         /// <summary>
         /// fujction to call when the object is destroyed
         /// </summary>
         virtual  void OnDestroy();

#pragma endregion
		//following region contains all static Member functions
#pragma region  StaticMember
		/// <summary>
		/// loops trough all scripts and calls Update()
		/// </summary>
		/// <returns></returns>
		static  void UpdateAll();
		/// <summary>
		/// loops trough all scripts and calls Awake()
		/// removes the script from the vector after call
		/// </summary>
		/// <returns></returns>
		static  void UpdateAllAWAKE();
		/// <summary>
		/// loops trough scripts and calls Start()
		///  removes the script from the vector after call
		/// </summary>
		/// <returns></returns>
		static  void UpdateAllSTART();
		/// <summary>
		/// calls all update Parralel instances to update the scripts that derive from it
		/// </summary>
		/// <returns></returns>
		static  void UpdateallParallel();
		/// <summary>
		/// internal function to add script to update loop
		/// </summary>
		/// <param name="behaviour"></param>
		/// <returns></returns>
		static  bool AddToUpdate(RefWrapper<CORE::Behaviour,true> behaviour);
		/// <summary>
		/// internal function to add script to start
		/// </summary>
		/// <param name="behaviour"></param>
		/// <returns></returns>
		static  bool AddToStart(RefWrapper<CORE::Behaviour,true> behaviour);
		/// <summary>
		/// internal function to add script to Awake 
		/// will be removed later/moved to intended behaviour
		/// </summary>
		/// <param name="behaviour"></param>
		/// <returns></returns>
		static  bool AddToAwake(RefWrapper<CORE::Behaviour,true> behaviour);


#pragma endregion


#pragma endregion


	};
}




#endif // !1
