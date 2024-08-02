//#pragma once
//#include "pch.h"
//#ifndef _REFLECTION_
//#define _REFLECTION_
//
//namespace CORE {
//	class Behaviour;
//#ifdef _INCLUDE_TYPE_
//	class TT {
//
//	};
//	template <class _Ty>
//	class TypeBase {
//
//	public:
//		using element_type = remove_extent_t<_Ty>;
//		element_type* _Ptr{ nullptr };
//		_Ref_count_base* _Rep{ nullptr };
//		template <class _Ty2>
//		void _Move_construct_from(_Ptr_base<_Ty2>&& _Right) noexcept {
//			// implement shared_ptr's (converting) move ctor and weak_ptr's move ctor
//			_Ptr = _Right._Ptr;
//			_Rep = _Right._Rep;
//
//			_Right._Ptr = nullptr;
//			_Right._Rep = nullptr;
//		}
//
//	};
//	template<typename _Ty, class _TY0>
//	class Type : public CORE::TypeBase<_Ty>{
//	public:
//		using type = _TY0;
//		type ltype;
//		UUID uuid;
//		std::string name;
//		
//		Type() {
//
//			//return type;
//			//ltype = _Ty;
//		}
//		type get() {
//			return type;
//		}
//	
//
//
//		template <class _Ty2,class _Ty1, enable_if_t<_SP_pointer_compatible<_Ty2, _Ty>::value, int> = 0>
//		Type(Type<_Ty2, _Ty1>&& _Right) noexcept { // construct shared_ptr object that takes resource from _Right
//			this->_Move_construct_from(_STD move(_Right));
//		}
//
//		template <class _Ty2,class _Ty1, enable_if_t<std::is_base_of<_Ty, _Ty2>::value, int> = 0>
//		Type(const Type<_Ty2, _Ty1 >& _Right) noexcept {
//			//Type<_Ty2, _Ty> ret;
//			this->_Ptr = _Right._Ptr;
//			this->_Rep = _Right._Rep;
//			this->ltype = _Right.ltype;
//			
//			//return ret;
//			//auto ret = Type<_Ty2, decltype(_Right.ltype)>();
//				//*this =&ret ;
//		}
//		//template <class _Ty2, enable_if_t<std::is_base_of<_Ty, _Ty2>::value, int> = 0>
//
//
//
//		std::shared_ptr<CORE::Behaviour> Instance;
//		template <class _Ty2, class _Ty1>
//		Type& operator=(const Type<_Ty2,_Ty1>* _Right) noexcept {
//			Type<_Ty2, decltype(this->ltype)> t;
//			return &t;
//		}
//
//
//
//
//
//
//
//	};
//#endif // _INCLUDE_TYPE_
//#ifdef _INCLUDE_REFLECTION_
//	class Reflection {
//		
//};
//#endif // _INCLUDE_REFLECTION_
//
//
//
//}
//#endif // !_REFLECTION_
