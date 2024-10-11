#pragma once
#ifndef _BENCHMARK_
#define _BENCHMARK_
import std;
enum func_type {
	global,
	NS_M,
	NS_C_SM,
	NS_C_M,
	C_M,
	C_SM
};
enum vd {
	vdy,
	vdn
};
class Template_Filler {};

template<class T, func_type func, int count, vd iV, vd oV, class ... Args>
class Benchmark {

};


#pragma region globals



template<class T, int count, class ... Args>
class Benchmark<T, func_type::global, count, vd::vdn, vd::vdn, Args... > {

	typedef T(*funcptr)(Args...);
public:
};

template< int count, class ... Args>
class Benchmark<Template_Filler, func_type::global, count, vd::vdy, vd::vdn, Args... > {

	typedef void(*funcptr)(Args...);
public:
};


template<class T, int count>
class Benchmark<T, func_type::global, count, vd::vdn, vd::vdy > {

	typedef T(*funcptr)(void);
public:
};


template< int count >
class Benchmark<Template_Filler, func_type::global, count, vd::vdy, vd::vdy > {

	typedef void(*funcptr)(void);
public:

	Benchmark(funcptr prt) {
		auto a = std::chrono::high_resolution_clock::now();
		std::cout << "starting \n";
		for (int i = 0; i <= count; i++) {
			prt();

		}
		auto n = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(n - a).count();
		std::cout << dur << "micro seconds; " << dur / 1000 << "milli seconds   " << "\n";
	}
};



#pragma endregion


#pragma region namespace_members


template<class T, int count, class ... Args>
class Benchmark<T, func_type::NS_M, count, vd::vdn, vd::vdn, Args... > {

	typedef T(*funcptr)(Args...);
public:
};

template< int count, class ... Args>
class Benchmark<Template_Filler, func_type::NS_M, count, vd::vdy, vd::vdn, Args... > {

	typedef void(*funcptr)(Args...);
public:
};


template<class T, int count>
class Benchmark<T, func_type::NS_M, count, vd::vdn, vd::vdy > {

	typedef T(*funcptr)(void);
public:
};


template< int count >
class Benchmark<Template_Filler, func_type::NS_M, count, vd::vdy, vd::vdy > {

	typedef void(*funcptr)(void);
public:
	template<typename TT, class Obj>
	Benchmark(TT Obj::* prt, Obj* optr) {
		auto a = std::chrono::high_resolution_clock::now();
		std::cout << "starting \n";
		for (int i = 0; i <= count; i++) {
			((Obj*)optr)->prt();

		}
		auto n = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(n - a).count();
		std::cout << dur << "\n";
	}
};
#pragma endregion


#pragma region namespace_class_static_member


template<class T, int count, class ... Args>
class Benchmark<T, func_type::NS_C_SM, count, vd::vdn, vd::vdn, Args... > {

	typedef T(*funcptr)(Args...);
public:
};

template< int count, class ... Args>
class Benchmark<Template_Filler, func_type::NS_C_SM, count, vd::vdy, vd::vdn, Args... > {

	typedef void(*funcptr)(Args...);
public:
};


template<class T, int count>
class Benchmark<T, func_type::NS_C_SM, count, vd::vdn, vd::vdy > {

	typedef T(*funcptr)(void);
public:
};


template< int count >
class Benchmark<Template_Filler, func_type::NS_C_SM, count, vd::vdy, vd::vdy > {

	typedef void(*funcptr)(void);
public:
};


#pragma endregion
#pragma region namespace_class_members



template<class T, int count, class ... Args>
class Benchmark<T, func_type::NS_C_M, count, vd::vdn, vd::vdn, Args... > {

	typedef T(*funcptr)(Args...);
public:
};

template< int count, class ... Args>
class Benchmark<Template_Filler, func_type::NS_C_M, count, vd::vdy, vd::vdn, Args... > {

	typedef void(*funcptr)(Args...);
public:
};


template<class T, int count>
class Benchmark<T, func_type::NS_C_M, count, vd::vdn, vd::vdy > {

	typedef T(*funcptr)(void);
public:
};


template< int count >
class Benchmark<Template_Filler, func_type::NS_C_M, count, vd::vdy, vd::vdy > {

	typedef void(*funcptr)(void);
public:
};

#pragma endregion

#pragma region class_member


template<class T, int count, class ... Args>
class Benchmark<T, func_type::C_M, count, vd::vdn, vd::vdn, Args... > {

	typedef T(*funcptr)(Args...);
public:
};

template< int count, class ... Args>
class Benchmark<Template_Filler, func_type::C_M, count, vd::vdy, vd::vdn, Args... > {

	typedef void(*funcptr)(Args...);
public:
};


template<class T, int count>
class Benchmark<T, func_type::C_M, count, vd::vdn, vd::vdy > {

	typedef T(*funcptr)(void);
public:
};


template< int count >
class Benchmark<Template_Filler, func_type::C_M, count, vd::vdy, vd::vdy > {

	typedef void(*funcptr)(void);
	funcptr ptr;

public:
	template<typename TT, class Obj>
	Benchmark(TT Obj::* prt, Obj* optr) {
		auto a = std::chrono::high_resolution_clock::now();
		std::cout << "starting \n";
		for (int i = 0; i <= count; i++) {
			((Obj*)optr)->prt();

		}
		auto n = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(n - a).count();
		std::cout << dur << "\n";
	}

};


#pragma endregion
#pragma region class_static_members


template<class T, int count, class ... Args>
class Benchmark<T, func_type::C_SM, count, vd::vdn, vd::vdn, Args... > {

	typedef T(*funcptr)(Args...);
public:
};

template< int count, class ... Args>
class Benchmark<Template_Filler, func_type::C_SM, count, vd::vdy, vd::vdn, Args... > {

	typedef void(*funcptr)(Args...);
public:
};


template<class T, int count>
class Benchmark<T, func_type::C_SM, count, vd::vdn, vd::vdy > {

	typedef T(*funcptr)(void);
public:
};


template< int count >
class Benchmark<Template_Filler, func_type::C_SM, count, vd::vdy, vd::vdy > {

	typedef void(*funcptr)(void);
public:
};

#pragma endregion

#define BENCHMARK_CM(x,y,z,a)  {auto tmpfunc = []() {static  x tmpdnu; tmpdnu.z; };Benchmark<Template_Filler, func_type::global, a, vd::vdy, vd::vdy> y(tmpfunc);};
#define BENCHMARK_CSM(x,y,z,a)  {auto tmpfunc = []() {  x::z; };Benchmark<Template_Filler, func_type::global, a, vd::vdy, vd::vdy> y(tmpfunc);};
#define BENCHMARK_G(y,z,a)  {auto tmpfunc = []() { z; };Benchmark<Template_Filler, func_type::global, a, vd::vdy, vd::vdy> y(tmpfunc);};

#endif // !1
class t {
public:
	void ddd() {
		std::cout << "working......\n";
	}
};
void test() {
	//t rrr;
	//Benchmark<Template_Filler, func_type::C_M, 100, vd::vdy, vd::vdy> bm(&t::ddd, &rrr);

}