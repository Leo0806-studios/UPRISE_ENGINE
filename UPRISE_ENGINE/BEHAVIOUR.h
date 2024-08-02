#ifndef _BEHAVIOUR_
#define _BEHAVIOUR_
#include "pch.h"
//#include "CORE.h"
//#include "ECS.h"
#include "DATATYPES.h"

#include "GAMEOBJECT.h"
//# include "Helpers.h"
//#include "pch.h"
#pragma comment(lib, "rpcrt4.lib")  // UuidCreate - Minimum supported OS Win 2000
#include <windows.h>

class GameObject;
namespace COMPONENTS {
	class _Mesh;
}
class Transform;

namespace CORE {
	

	class Behaviour {

	public:
		GameObject* gameobject;
		std::shared_ptr<Transform> TRANSFORM;
		std::shared_ptr<CORE::Behaviour> transf;

		static std::vector<std::shared_ptr<CORE::Behaviour>> objectss;
		static std::vector<std::shared_ptr<Behaviour>> behaviours;
		static std::vector<std::shared_ptr<Behaviour>> AWAKES;
		static std::vector<std::shared_ptr<Behaviour>> Starts;
		static std::vector<std::shared_ptr<Behaviour>> Parallel_Updates;
		UUID uuID;
		int id;
	//	static std::vector<Behaviour*> tester;
		//template <class _Ty, class... _Types>
		//static std::vector<_Ty> types;
		Behaviour();;
		Behaviour(GameObject* oobj, std::shared_ptr<CORE::Behaviour> trans);

		virtual void Update() {};
		virtual void Awake() {};
		virtual void Start() {};
		static void updateAll();
		static void updateAllAWAKE();
		static void updateAllSTART();
		static void updateallParallel();
		
	};
}
template<typename _T>
class Register {
public:
	//static std::vector < std::shared_ptr<Register> lisst;
	
	explicit Register(_T arg, const std::string className) {

		std::shared_ptr<CORE::Behaviour> aa = std::make_shared<_T>();
		fact::inst.push_back(aa);
		//fact::anys.push_back(arg);
		fact::creators[className] = []()->std::shared_ptr<CORE::Behaviour> {std::shared_ptr<CORE::Behaviour> a = std::make_shared<_T>(); return a; };
	}
};
#endif // !_BEHAVIOUR_
