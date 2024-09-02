#pragma once
#ifndef _EMPTY_
#define _EMPTY_
#include "HeaderE//CORE/C_BEHAVIOUR.h"
#include "MODULE_IMPORTS.h"
class Empty :public CORE::Behaviour {


public:
	static UUID UUID;
	COPY(Empty,)
		DEEP_COPY(Empty,,)
		I_WINDOW_E()
	void Awake()override;
	void Update()override;
	void Start()override;

};
#endif // !_EMPTY_

