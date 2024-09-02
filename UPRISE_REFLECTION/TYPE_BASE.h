#pragma once
#ifndef _TYPE_BASE_
#define _TYPE_BASE_
class Type_Base {
public :
	
};
template<typename _Tn>
class Type :public Type_Base{
public:
	using type = _Tn;
	
};
#endif // !_TYPE_BASE_
