#pragma once
#ifndef _EMPTY_
#define _EMPTY_
#include "CORE.h"
class Empty :public CORE::Behaviour {
public:
	static UUID UUID;

	void Awake()override;
	void Update()override;
	void Start()override;

};
#endif // !_EMPTY_

