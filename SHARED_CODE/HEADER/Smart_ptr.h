#pragma once
#ifndef _SMART_PTR_
#define _SMART_PTR_
#include <type_traits>

namespace utills{
	struct _For_overwrite_tag {
		explicit _For_overwrite_tag() = default;
	};
	class CTR_base {
	public:
		unsigned long refcount = 1;
		virtual void Decrem() = 0;
		virtual void Destroy() = 0;
		virtual void Increm() = 0;
		virtual void Delete() = 0;
	};
	template<class _Ty>
	class Control_Block: public CTR_base {
	public:
		void Decrem()override {
			if ((this->refcount--) == 0) {
				this->Destroy();
				this->Delete();
			}
		}
		void Destroy()override {
			_Destroy_in_place(_PTR);
		}
		void Increm()override {
			this->refcount++;
		}
		void Delete()override {
			delete this;
		}
		template <class... _Types>
		Control_Block(_Types&&... arg) {
#if _HAS_CXX20
			if constexpr (sizeof...(_Types) == 1 && (is_same_v<_For_overwrite_tag, remove_cvref_t<_Types>> && ...)) {
				_STD _Default_construct_in_place(_PTR);
				((void)arg, ...);
			}
			else
#endif // _HAS_CXX20
			{
				_STD _Construct_in_place(_PTR, _STD forward<_Types>(arg)...);
			}
		}
		_Ty _PTR;
		unsigned long refcount = 1;
		
	};
	template<class _Ty>
	class Smart_ptr
	{
	public:
		_Ty* ptr;
		CTR_base* Ref;
		template<class _Ty2>
		Smart_ptr(Smart_ptr< _Ty2>&& other) {
			this->ptr = other.ptr;
			this->Ref = other.Ref;
			this->Ref->Increm();
		}
		Smart_ptr() {};
		~Smart_ptr() {
			this->Ref->Decrem();
		}

	};
	template <class _Ty>
	Smart_ptr<_Ty> make_shared(_Ty arg) {
		auto Block = new Control_Block<_Ty>(std::forward<_Ty>(arg));
		Smart_ptr<_Ty> Ret;
		Ret.ptr = _STD addressof(Block->_PTR);
		Ret.Ref = Block;

		return Ret;
			

	}
}

#endif