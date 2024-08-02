#pragma once
#ifndef _EVENT_
#define _EVENT_

#include "pch.h"
#include "GAMEOBJECT.h"
class Event {

public:
	Event()=default;
	template<class _Func, class... _Arg  >
	Event(std::shared_ptr<GameObject> TergetObj, _Func&& TergetFunc, _Arg&&... args):targetObject(targetObject), func(std::bind(std::forward<Func>(targetFunc), std::forward<Args>(args)...)) {}
	void Invoke()const {
		func();
	}
private:
	std::shared_ptr<GameObject> targetObject;
	std::function<void()> func;
};
#endif // !_EVENT_
