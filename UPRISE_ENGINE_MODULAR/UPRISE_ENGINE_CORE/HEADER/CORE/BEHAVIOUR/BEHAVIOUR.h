#pragma once
#ifndef _BEHAVIOUR_
#define _BEHAVIOUR_
#include "Windows.h"
//#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include "OBJECT/OBJECT.h"
import std;
import REF_WRAPPER;

class GameOject;
class Transform;
namespace CORE {
	class Behaviour:public CORE::Object {
	private:
#pragma region NonStaticVars
		RefWrapper<GameOject,true> gameObj;
		RefWrapper<Transform,true> transf;
		UUID uuid;
		int id;
		bool toBeRemoved;
		bool enabled;

#pragma endregion
#pragma region StaticVars
		static std::vector<RefWrapper<CORE::Behaviour,true>> behaviours;
		static std::vector<RefWrapper<CORE::Behaviour,true>> awakes;
		static std::vector<RefWrapper<CORE::Behaviour,true>> starts;
#pragma endregion



	public:
#pragma region Constructors
		/// <summary>
		/// constuctor that sets toBeRemoved(false)
		/// </summary>
		/// <returns></returns>
		UPRISE_CORE_API Behaviour() :toBeRemoved(false) {};
		/// <summary>
		/// constuctor that sets toBeRemoved(true)
		/// </summary>
		/// <param name="remove"></param>
		/// <returns></returns>
		UPRISE_CORE_API Behaviour(int remove) :toBeRemoved(true) {};

#pragma endregion
#pragma region destructor
		virtual ~Behaviour() {

		}
#pragma endregion
		//following region contains all functions
#pragma region funcs

		//following region contains all virtual member functions
#pragma region Virtual
		/// <summary>
		/// performs a shallow copy of the object
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API RefWrapper<CORE::Behaviour,true> Copy() = 0;
		/// <summary>
		/// performs a deepcopy of the object
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API RefWrapper<CORE::Behaviour,true> DeepCopy() = 0;
		/// <summary>
		/// function for drawing the editor wiget
		/// will be removed later
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API void EditorWindow() = 0;
		/// <summary>
		/// main update function
		/// will be executet on every frame
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API void Update() =0;
		/// <summary>
		/// awake function
		/// will be executet before the first update and start after the object is instantiated
		/// will be exectued immidiatly after instatiation
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API void Awake() =0;
		/// <summary>
		/// replaces the first update of the object.
		/// is run on the next frame after awake
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API void Start() =0;
		/// <summary>
		/// internal function to called to remove this obj from updates
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API bool RemoveFromUpdate();
		/// <summary>
		/// internal function to call to remove this obj from start 
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API bool RemoveFromStart();
		/// <summary>
		/// internal function to call to remove this obj from awake 
		/// </summary>
		/// <returns></returns>
		virtual UPRISE_CORE_API bool RemoveFromAwake();



#pragma endregion
		//following region contains all static Member functions
#pragma region  StaticMember
		/// <summary>
		/// loops trough all scripts and calls Update()
		/// </summary>
		/// <returns></returns>
		static UPRISE_CORE_API void UpdateAll();
		/// <summary>
		/// loops trough all scripts and calls Awake()
		/// removes the script from the vector after call
		/// </summary>
		/// <returns></returns>
		static UPRISE_CORE_API void UpdateAllAWAKE();
		/// <summary>
		/// loops trough scripts and calls Start()
		///  removes the script from the vector after call
		/// </summary>
		/// <returns></returns>
		static UPRISE_CORE_API void UpdateAllSTART();
		/// <summary>
		/// calls all update Parralel instances to update the scripts that derive from it
		/// </summary>
		/// <returns></returns>
		static UPRISE_CORE_API void UpdateallParallel();
		/// <summary>
		/// internal function to add script to update loop
		/// </summary>
		/// <param name="behaviour"></param>
		/// <returns></returns>
		static UPRISE_CORE_API bool AddToUpdate(RefWrapper<CORE::Behaviour,true> behaviour);
		/// <summary>
		/// internal function to add script to start
		/// </summary>
		/// <param name="behaviour"></param>
		/// <returns></returns>
		static UPRISE_CORE_API bool AddToStart(RefWrapper<CORE::Behaviour,true> behaviour);
		/// <summary>
		/// internal function to add script to Awake 
		/// will be removed later/moved to intended behaviour
		/// </summary>
		/// <param name="behaviour"></param>
		/// <returns></returns>
		static UPRISE_CORE_API bool AddToAwake(RefWrapper<CORE::Behaviour,true> behaviour);


#pragma endregion


#pragma endregion


	};
}

#endif // !1
