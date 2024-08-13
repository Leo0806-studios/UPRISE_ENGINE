#pragma once
#ifndef _SMART_POINTER_
#define _SMART_POINTER_



namespace UTILLS{
	template<class _Ty>
	class PTR_base {
	public:
		PTR_base() {

		}
		virtual ~PTR_base(){}
	};
	class REF_block {
	public:
		int ref_cout;
		REF_block():ref_cout(1){}
		void increment() { ++ref_cout; }
		void decrement() { --ref_cout; }
		int getCount() const { return ref_cout; }
	};
	template<class _Ty>
	class Shared_ptr   {
	public:
		using TYPE = _Ty;
		long Iptr;
		long* pointer;
		_Ty** Pointer;
		REF_block* ref_block;
		TYPE* GT() {
			return (TYPE*)(*pointer);
		}
		Shared_ptr() :Pointer(nullptr),ref_block(nullptr) {

		}
		Shared_ptr(_Ty* ptr) :  ref_block(new REF_block()) {
			//Iptr = (long)ptr;
			//pointer = &Iptr;
			Pointer = &ptr;

		}

		Shared_ptr(const Shared_ptr& other) : ref_block(other.ref_block) {
			this->Pointer = (TYPE**)(other.Pointer);
			*this->Pointer = *other.Pointer;
			if (ref_block) {
				ref_block->increment();
			}
		}

		template<class _Ty2>
		Shared_ptr( Shared_ptr<_Ty2>&& other) {
			this->Pointer = (TYPE**)(other.Pointer);
			*this->Pointer = *other.Pointer;

		}

		~Shared_ptr(){
			release();
		}
		template<class _Ty2>
		Shared_ptr& operator=(const Shared_ptr<_Ty2>&& other) {
			this->Pointer = (TYPE**)(other.Pointer);
			*this->Pointer = *other.Pointer;
			this->ref_block = other.ref_block;

		}
		template<class _Ty2>
		Shared_ptr(const Shared_ptr<_Ty2>& other, typename std::enable_if<std::is_convertible<_Ty2*, _Ty*>::value>::type* = nullptr)
			:  ref_block(other.ref_block) {
			this->Pointer = (TYPE**) (other.Pointer);
			*this->Pointer = *other.Pointer;
			if (ref_block) {
				ref_block->increment();
			}
		}
		template<class _Ty2>
		Shared_ptr& operator=(const Shared_ptr<_Ty2>& other) {
			if (this != reinterpret_cast<const void*>(&other)) {
				release();
				this->Pointer = (TYPE**)(other.Pointer);
				*this->Pointer = *other.Pointer;
				ref_block = other.ref_block;
				if (ref_block) {
					ref_block->increment();
				}
			}
			return *this;
		}
		_Ty* operator->() {
			return *Pointer;
		}

		void release() {
			if (ref_block) {
				ref_block->decrement();
				if (ref_block->getCount() == 0) {
					delete *Pointer;
					delete ref_block;
				}
			}
			Pointer = nullptr;
			ref_block = nullptr;
		}
	};

	template<class _Ty, class... Args>
	Shared_ptr<_Ty> Make_Shared(Args&&... args) {
		return Shared_ptr<_Ty>(new _Ty(std::forward<Args>(args)...));
	}
}
#endif // !_SMART_POINTER_
