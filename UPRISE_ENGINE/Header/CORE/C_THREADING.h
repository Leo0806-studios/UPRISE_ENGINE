#pragma once
#ifndef _THREADING_
#define _THREADING_

#include "pch.h"

//#include "thread"
namespace CORE {
	
	class Thread;
	class Thread_Manager {

	public:
		static std::vector<Thread*> Threads;
		Thread_Manager();

		static Thread CreateThread(std::function<void()> f);

		template<class _Fn, class ..._Args>
		static Thread CreateThreadWithArgs(_Fn&& _Fx, _Args&&... _Ax) {
			Thread tmp(_Fx, _Ax);

		}
	};
	class Thread {
	private:
		std::thread thread;
		std::function<void()> func;


	public:
		Thread(std::function<void()> f) : func(f) {};
		template<class _Fn, class ..._Args>

		Thread(_Fn&& _Fx, _Args&&... _Ax) {
			func = std::bind(std::forward<_Fn>(_Fx), std::forward<_Args>(_Ax)...);
			Thread_Manager::Threads.push_back(this);
		}
		//template<class _Fn, class ..._Args>

		//Thread(_Fn&& _Fx ) {

		//	func = _Fn;
		//	Thread_Manager::Threads.push_back(this);
		//}

		void Schedule() {

			this->thread = std::thread(func);

		}


	};





	class Threading_Interface {
	private:
		static std::mutex instanceMutex;
		static std::mutex staticMutex;

	public:

		template<class _CL, class _Var, class _Val>
		static void SetVar(_CL& obj, _Var _CL::* variable, _Val value) {
			std::lock_guard<std::mutex> lock(instanceMutex);
			obj.*variable = value;
		}

		template<class _CL, class _Var, class _Val>
		static void SetStaticVar(_Var& variable, _Val value) {
			std::lock_guard<std::mutex> lock(staticMutex);
			variable = value;
		}

		template<class _CL, class _Elem>
		static void AddToVector(std::vector<_Elem>& vec, const _Elem& element) {
			std::lock_guard<std::mutex> lock(instanceMutex);
			vec.push_back(element);
		}

		template<class _Elem>
		static void AddToStaticVector(std::vector<_Elem>& vec, const _Elem& element) {
			std::lock_guard<std::mutex> lock(staticMutex);
			vec.push_back(element);
		}

		template<class _CL, class _Elem, class _Fn>
		static void IterateVector(const std::vector<_Elem>& vec, _Fn func) {
			std::lock_guard<std::mutex> lock(instanceMutex);
			for (const auto& elem : vec) {
				func(elem);
			}
		}

		template<class _Elem, class _Fn>
		static void IterateStaticVector(const std::vector<_Elem>& vec, _Fn func) {
			std::lock_guard<std::mutex> lock(staticMutex);
			for (const auto& elem : vec) {
				func(elem);
			}
		}

	};
}
#endif // !_THREADING_
