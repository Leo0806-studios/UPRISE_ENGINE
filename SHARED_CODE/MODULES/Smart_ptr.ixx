export module SMART_PTR;
import std;
template<class _Ty>
class Smart_Ptr;
class Ref_Base {


public:
	unsigned	long long uses = 1;
	unsigned	long long weaks = 1;
	bool ISNULL = false;
	virtual void Decref() = 0;
	virtual void Incref() = 0;
	virtual void Destroy() = 0;
	virtual void Delete() = 0;
	virtual void Increw() = 0;
	virtual void Decrew() = 0;
	virtual void* Get() = 0;
};

template<class _Ty>
class ptr_Base {
public:
	_Ty* _Ptr;
	Ref_Base* _Ref;
	template <class _Ty0>
	friend class ptr_Base;
	
public:

	 void Decref() {
		_Ref->Decref();
	}
	 void Incref() {
		_Ref->Incref();
	}
	 void Destroy() {
		_Ref->Destroy();
	}
	 void Delete() {
		this->Delete();
	}
	 void Increw() {
		_Ref->Increw();
	}
	 void Decrew() {
		_Ref->Decrew();
	}
	__inline constexpr _Ty* get()const noexcept {
		return _Ptr;
	}
};
template<class _Ty>
class _Ref_ptr :public Ref_Base {
private :
	_Ty* _Ptr;
public:
	using Type = _Ty;
	_Ref_ptr(_Ty* _Val):Ref_Base(),_Ptr(_Val){

	}
	void* Get()override {
		return _Ptr;
	}
	void Decref() override {
		if ((this->Uses--) == 0) {
			Destroy();
			if ((this->Weaks--) == 0) {
				Delete();
			}
		}
	}
	void Incref() override {
		this->Uses++;
	}
	void Destroy() override {
		delete _Ptr;
	}
	void Delete() override {
		delete this;
	}
	void Increw()override {
		this->weaks++;
	}
	void Decrew()override {
		if ((this->weaks--) == 0) {
			this->Delete();
		}
	}
};
export template <class _Ty>
class Smart_ptr :public ptr_Base<_Ty> {
private:
public:
	void Create_activate(_Ty* ptr, Ref_Base* _Ref) {

	}

	 Smart_ptr()  = default;
	// Smart_ptr(nullptr_t)  {}
	template <class _Ux>
	Smart_ptr(_Ux& ux) {
		this->Incref();
	}
	template<class _Ty2>
	Smart_ptr(Smart_ptr<_Ty2>&& other) {
		this->_Ptr = other._Ptr;
		this->_Ref = other._Ref;
	}
	~Smart_ptr() {
		this->Decref();
		this->Decrew();
	}
	_Ty* Get() {
		return this->_Ptr;
	}
	__inline constexpr _Ty* operator->() const noexcept {
#ifdef DEBUGABE


		if (this->_Ref->ISNULL == true) {
			return _Ptr;
		}
		else {
			std::cout << "Object has been deleted" << "\n" << "Null Ref Exception\n";
			return nullptr;
		}
#else
		return this->get();
#endif // DEBUGABE

	}




public:



};

template <class _Ty>
class Ref_Obj1 : public Ref_Base {
private:
	_Ty Obj;
public:
	using Type = _Ty;
	Ref_Obj1(_Ty& _Val) {
		new(&Obj) _Ty();
		Obj = _Val;
	}
	void* Get()override {
		return &Obj;
	}
private:

public:
	void Decref() override {
		if ((this->Uses--) == 0) {
			Destroy();
			if ((this->Weaks--) == 0) {
				Delete();
			}
		}
	}
	void Incref() override {
		this->Uses++;
	}
	void Destroy() override {
		this->Obj.~_Ty();
	}
	void Delete() override {
		delete this;
	}
	void Increw()override {
		this->weaks++;
	}
	void Decrew()override {
		if ((this->weaks--) == 0) {
			this->Delete();
		}
	}

};


export { template <class _T>
Smart_ptr<_T> Create_Smart_ptr(_T& _Val) {
	Ref_Base* _Ref = (Ref_Base*)  new Ref_Obj1<_T>(_Val);
	Smart_ptr<_T> Ret;
	Ret.Create_activate((_T*)_Ref->Get(), _Ref);
}
}