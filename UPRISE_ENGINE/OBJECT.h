#pragma once
#ifndef _OBJECT_
#define _OBJECT_

class Component;
namespace CORE {

	class Object {

	public :
		Object();;
		virtual ~Object();;
		void DestroyObj(Object* obj);
  };


}

#endif // !_OBJECT_
