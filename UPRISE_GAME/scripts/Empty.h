#pragma once
#ifndef _EMPTY_
#define _EMPTY_
#include "Header//CORE/C_BEHAVIOUR.h"
class Empty :public CORE::Behaviour {
public:
	static UUID UUID;
	COPY(Empty, )
		DEEP_COPY(Empty, , )
		I_WINDOW_E()
		void Awake()override;
	void Update()override;
	void Start()override;

};
#endif // !_EMPTY_

static Register<Empty> Empty_Register(Empty(), "Empty");
