module;
#include "atomic"
export module REF_WRAPPER;
import std;

class controll_Base {
private:
	bool null;
	unsigned long long _Refs = 1;
	virtual void Incref() {

	}
	virtual void Decref() {

	}
public:
	virtual void* get() {};
	private:
	virtual void DeleteManualy(){}

public:
};
template<class TY, bool NullChk>
class Controll_Block :public controll_Base{
private:

};
export template<class T, bool NullChk>
class RefWrapper  {
private:
	
};


template<class T>
class Controll_Block<T, true> :public controll_Base {
private:
	T* Obj{ nullptr };
public:
	T* get()override {
		if (Obj == nullptr) {
			return Obj;

		}
		std::cout << "Null Ref Exception at : " << std::stacktrace::current() << "\n";
		return nullptr;
	}
private:
	void Destroy() {
		if (!null) {
			delete Obj;
			delete this;
			return void();
		}
		std::cout << "cant delete Object at: " << Obj<<"\n this can indicate a memory leak or a error upstream\n stacktrace: " << std::stacktrace::current() << "\n";
		delete this;
	}
	void Incref()override{
		_MT_INCR(_Refs);
		
	}
	void Decref()override{
		if (_MT_DECR(_Refs)==0) {

			Destroy();
		}
	}
	void DeleteManualy()override {
		if (!null) {
			delete Obj;
			null = true;

			return void();
		}
		std::cout << "cant delete Object at: " << Obj << "\n this can indicate a memory leak or a error upstream\n stacktrace: " << std::stacktrace::current() << "\n";
		delete this;

	}
public:
	Controll_Block() {
		Obj = new T;
	}
};
template<class T>
class Controll_Block<T, false> :public controll_Base {
private:
	T* Obj{ nullptr };
public:
	T* get()override {
		return Obj;
	}
	private:
	void Destroy() {
			delete Obj;
			delete this;

	}
	void Incref()override {
		_MT_INCR(_Refs);

	}
	void Decref()override {
		if (_MT_DECR(_Refs) == 0) {

			Destroy();
		}
	}
	void DeleteManualy()override {

			delete Obj;
			null = true;


	}
public:
	Controll_Block() {
		Obj = new T;
	}
};
template<class T, bool NullChk>
RefWrapper<T, NullChk> WrapRef() {}
void Activate() {

}
export {
	
	template<class T>
	class RefWrapper<T, true> {
	private:
		//friend RefWrapper<T, true> WrapRef();
	public:
		controll_Base* contrl{ nullptr };

		RefWrapper() {

		}
		void Destroy() {
			contrl->DeleteManualy();
		}
		template<class T2>
		RefWrapper<T, true> operator=(const RefWrapper<T2, true>& other) {
			contrl->Decref();
			contrl = other.contrl;
			contrl->Incref();

		}
		T* Get() {
			return (T*)contrl->get();
		}
		T* operator->() {
			return (T*)contrl->get();
		}

	};

	template<class T>
	class RefWrapper<T, false> {
	private:
		//friend RefWrapper<T, false> WrapRef();
	public:
		controll_Base* contrl{ nullptr };

		RefWrapper() {

		}
		void Destroy() {
			contrl->DeleteManualy();
		}
		template<class T2>
		RefWrapper<T, true> operator=(const RefWrapper<T2, true>& other) {
			contrl->Decref();
			contrl = other.contrl;
			contrl->Incref();
		}
		template<class T2>
		RefWrapper<T, true> operator=(const RefWrapper<T2, false>& other) {
			contrl->Decref();
			contrl = other.contrl;
			contrl->Incref();
		}
		T* Get() {
			return (T*)contrl->get();
		}
		T* operator->() {
			return (T*)contrl->get();
		}
	};
	template<class T>
	RefWrapper<T, true> WrapRef() {
		controll_Base* base = new Controll_Block<T, true>();
		RefWrapper<T, true> ret;
		ret.contrl = base;
	}
	template<class T>
	RefWrapper<T, false> WrapRef() {
		controll_Base* base = new Controll_Block<T, true>();
		RefWrapper<T, false> ret;
		ret.contrl = base;
	}

}
