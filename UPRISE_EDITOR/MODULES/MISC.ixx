module;
#include "vector"
#include "memory"
export module MISC;
//import std;

export {
	class Dll_Link;
	class LINK {
		std::shared_ptr<Dll_Link> DATA_LINK;
	};
	template<class _T1, class _T2>
	struct Vector_Tupple {
	public:
		std::vector<_T1> A;
		std::vector<_T2> B;
	};
}