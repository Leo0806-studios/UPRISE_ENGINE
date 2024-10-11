#pragma once
#ifndef _REF_WRAPPER_
#define _REF_WRAPPER_
enum nullcheck{ NullCheck,noNullCheck};
template<class Return,class ... args>
class Function {
	typedef Return(*PTR)(...);
};
template<class _T>
class Wrapper_Base {

};

template<class T,nullcheck NC>
class Ref_Wrapper {
private:
	nullcheck chk = NS;
public:

#pragma region Opperators
	
	Ref_Wrapper<T, NC> operator= (T& other){

	}
	Ref_Wrapper<T, NC> operator= (Ref_Wrapper<T,NC>& other) {

	}
#pragma endregion

};
#endif // !_REF_WRAPPER_
