#pragma once
#ifndef _PARALLEL_UPDATE_
#define _PARALLEL_UPDATE_

#include "CORE.h"

class Parallel_Update : public CORE::Behaviour {

public:
	void Awake()override;
	void Start()override;
	void Update()override;
	virtual void ParallelUpdate() = 0;
};

#endif // !_PARALLEL_UPDATE_
