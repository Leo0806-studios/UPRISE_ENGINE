module;
#include "atomic"
export module REF_WRAPPER;
import std;
template<class T, bool NC>  class Controll_Block;
template <class T, bool NC> class RefWrapper;;
class controll_Base {
private:
	bool null;
	 template<class T,bool NC> friend class Controll_Block;
	 template<class T, bool NC> friend class RefWrapper;

	unsigned long long _Refs = 1;
	virtual void Incref() {

	}
	virtual void Decref() {

	}
public:
	virtual void* get() { return nullptr; };
	private:
		virtual void DeleteManualy() = 0;

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
	template<class T, bool NC> friend class RefWrapper;

public:
	void* get()override {
		if (Obj != nullptr) {
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
		//std::cout << "incref\n";
	  //  std::cout << "old" << _Refs << "\n";
		_MT_INCR(_Refs);
	  //  std::cout << "new" << _Refs << "\n";
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
	template<class T, bool NC> friend class RefWrapper;
public:
	void* get()override {
		return Obj;
	}
	private:
	void Destroy() {
			delete Obj;
			delete this;

	}
	void Incref()override {
	   // std::cout << "incref\n";
		//std::cout <<"old" << _Refs << "\n";
		_MT_INCR(_Refs);
	   // std::cout << "new" << _Refs << "\n";

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

export {
	template<class T, bool NullChk>
	RefWrapper<T, NullChk> WrapRef(const T&& __val) {
		controll_Base* base = new Controll_Block<T, NullChk>();
		RefWrapper<T, NullChk> ret;
		ret.contrl = base;
		memcpy(ret.Get(), &__val, sizeof(T));
		//ret.Get() = __val;
		return ret;
	}
	template<class T, bool NullChk>
	RefWrapper<T, NullChk> WrapRef() {
		controll_Base* base = new Controll_Block<T, NullChk>();
		RefWrapper<T, NullChk> ret;
	   
		ret.contrl = base;
		return ret;
	}
	//template<class T>
	//RefWrapper<T, true> WrapRef<T, false>() {
	//    controll_Base* base = new Controll_Block<T, true>();
	//    RefWrapper<T, true> ret;
	//    ret.contrl = base;
	//}
	//template<class T>
	//RefWrapper<T, false> WrapRef<T, true>() {
	//    controll_Base* base = new Controll_Block<T, true>();
	//    RefWrapper<T, false> ret;
	//    ret.contrl = base;
	//}

	void Activate() {

	}
	template<class T>
	class RefWrapper<T, true> {
	private:
		//friend RefWrapper<T, true> WrapRef();
	public:
		controll_Base* contrl{ nullptr };

		RefWrapper() {
		   // std::cout << "creating illegaly w nullchk\n";
			//contrl->Incref();

		}
		template<class T2>
		RefWrapper(const RefWrapper<T2, true>& other) {
			contrl = other.contrl;
			contrl->Incref();
		}
		template<class T2>
		RefWrapper(const RefWrapper<T2, false>& other) {
			contrl = other.contrl;
			contrl->Incref();
		}
		RefWrapper(const RefWrapper<T, true>& other) {
			contrl = other.contrl;
			contrl->Incref();
		}

		RefWrapper(const RefWrapper<T, false>& other) {
			contrl = other.contrl;
			contrl->Incref();
		}
		~RefWrapper() {
		  //  std::cout << "deleting with nullchk\n";

			contrl->Decref();
		}
		void Destroy() {
			contrl->DeleteManualy();
		}
		RefWrapper<T, false> operator=(const RefWrapper<T, false>& other) {
			//contrl->Decref();
		   // std::cout << "assigning\n";

			contrl = other.contrl;
			contrl->Incref();
			return*this;
		}
		RefWrapper& operator=(const RefWrapper<T, true>& other) {
			//contrl->Decref();
		 //   std::cout << "assigning\n";

			contrl = other.contrl;
			contrl->Incref();
			return*this;

		}

		template<class T2>
		RefWrapper<T, true> operator=(const RefWrapper<T2, true>& other) {
			//contrl->Decref();
		   // std::cout << "assigning\n";

			contrl = other.contrl;
			contrl->Incref();
			return*this;


		}

		//RefWrapper<T, true> operator=(const T& other) {
		//	*(T*)contrl->get() = other;
		//}
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
		   // std::cout << "creating illegaly wo nullchk\n";
		  // // contrl->Incref();


		}
		~RefWrapper() {
		   // std::cout << "deleting wtihuout nullchk\n";
			contrl->Decref();
		}
		void Destroy() {
			contrl->DeleteManualy();
		}
		RefWrapper<T, true> operator=(const RefWrapper<T, true>& other) {
			//contrl->Decref();
		   // std::cout << "assigning\n";

			contrl = other.contrl;
			contrl->Incref();
			return*this;

		}
		RefWrapper<T, false> operator=(const RefWrapper<T, false>& other) {
			//contrl->Decref();
			//std::cout << "assigning\n";
			contrl = other.contrl;
			contrl->Incref();
			return*this;

		}
		template<class T2>
		RefWrapper<T, true> operator=(const RefWrapper<T2, true>& other) {
			//contrl->Decref();
		   // std::cout << "assigning\n";

			contrl = other.contrl;
			contrl->Incref();
			return*this;

		}
		template<class T2>
		RefWrapper<T, true> operator=(const RefWrapper<T2, false>& other) {
			//contrl->Decref();
		   // std::cout << "assigning\n";

			contrl = other.contrl;
			contrl->Incref();
			return*this;

		}
		template<class T2>
		RefWrapper(const RefWrapper<T2, false>& other) {
			contrl = other.contrl;
			contrl->Incref();
		}
		RefWrapper(const RefWrapper<T, false>& other) {
			contrl = other.contrl;
			contrl->Incref();
		}
		//RefWrapper<T, true> operator=(const T& other) {
		//	*(T*)contrl->get() = other;
		//}
		T* Get() {
			return (T*)contrl->get();
		}
		T* operator->() {
			return (T*)contrl->get();
		}
	};

}
