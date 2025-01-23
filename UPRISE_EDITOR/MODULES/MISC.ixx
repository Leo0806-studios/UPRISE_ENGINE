// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
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