#ifndef _BEHAVIOUR_
#define _BEHAVIOUR_
#include "pch.h"
//#include "Header/CORE/CORE.h"
//#include "ECS.h"
//#include "Header/DATATYPES/D_TS_P_VECTOR3.h"

//#include "GAMEOBJECT.h"
//# include "Helpers.h"
//#include "pch.h"
#pragma comment(lib, "rpcrt4.lib")  // UuidCreate - Minimum supported OS Win 2000
#include <windows.h>
namespace DATATYPES {
	struct TSPVector3;
}

class GameObject;
namespace COMPONENTS {
	class _Mesh;
}
class Transform;

namespace CORE {
	

	class Behaviour {

	public:
		GameObject* Game_Object;
		std::shared_ptr<Transform> TRANSFORM;
		std::shared_ptr<CORE::Behaviour> transf;
		std::string compname;

		static std::vector<std::shared_ptr<CORE::Behaviour>> objectss;
		static std::vector<std::shared_ptr<Behaviour>> behaviours;
		static std::vector<std::shared_ptr<Behaviour>> AWAKES;
		static std::vector<std::shared_ptr<Behaviour>> Starts;
		static std::vector<std::shared_ptr<Behaviour>> Parallel_Updates;
		UUID uuID;
		int id;
		bool ToBeRemoved;
		bool enabled;
	//	static std::vector<Behaviour*> tester;
		//template <class _Ty, class... _Types>
		//static std::vector<_Ty> types;
		Behaviour();
		Behaviour(int remove);
		Behaviour(GameObject* oobj, std::shared_ptr<CORE::Behaviour> trans);
		virtual std::shared_ptr<CORE::Behaviour> Copy() = 0;
		virtual std::shared_ptr<CORE::Behaviour> DeepCopy() = 0;
		virtual void EditorWindow() = 0;
		virtual void Update() {};
		virtual void Awake() {};
		virtual void Start() {};
		static void updateAll();
		static void updateAllAWAKE();
		static void updateAllSTART();
		static void updateallParallel();

		
	};
}
using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;
static VEC(CreatorFunc) tetsss;

using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;
class factT {
public:
	//static VEC(std::shared_ptr<CORE::Behaviour>)* inst;
	static VEC(std::any) anys;
	//static std::function<std::unique_ptr<Behaviour>()> CreatorFunc;
	using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;


	static std::shared_ptr<std::map<std::string, CreatorFunc>> creators;
	static std::map<std::string, CreatorFunc> creatorS;

};
template<typename _T>
class Register {
public:

	
	
	explicit Register(_T arg, const std::string className) {
		if (arg.UUID == GUID_NULL) {
			UUID uuid;
			UuidCreate(&uuid);


			arg.UUID = uuid;
			arg.uuID = arg.UUID;
			std::shared_ptr<CORE::Behaviour> aa = std::make_shared<_T>();
			tetsss.push_back([]()->std::shared_ptr<CORE::Behaviour> {std::shared_ptr<CORE::Behaviour> a = std::make_shared<_T>(); return a; });
			//factT::creatorS[className] = []()->std::shared_ptr<CORE::Behaviour> {std::shared_ptr<CORE::Behaviour> a = std::make_shared<_T>(); return a; };
			//fact::inst->push_back(aa);
			
			//auto aq = []()->std::shared_ptr<CORE::Behaviour> {std::shared_ptr<CORE::Behaviour> a = std::make_shared<_T>(); return a; }
			//(*fact::creators)[className] = aq;
		}

	}


};
#define COPY(x,Member_Copy) std::shared_ptr<CORE::Behaviour> Copy() override{auto a = std::make_shared<x>();Member_Copy;std::shared_ptr<CORE::Behaviour> ret=a;return ret;};
#define DEEP_COPY(x,Member_Copy,y) std::shared_ptr<CORE::Behaviour> DeepCopy() override{auto a = std::make_shared<x>();Member_Copy;std::shared_ptr<CORE::Behaviour> ret=a;return ret;};
#define I_WINDOW_E() void EditorWindow() override{};
#define I_WINDOW(x) void EditorWindow() override{x};
#endif // !_BEHAVIOUR_
