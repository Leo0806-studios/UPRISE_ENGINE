#pragma once
#ifndef _PARALLEL_UPDATE_
#define _PARALLEL_UPDATE_

#include "CORE.h"

namespace CORE {

	class Behaviour;
}
class Parallel_Update : public CORE::Behaviour {

public:
	void Awake()override;
	void Start()override;
	void Update()override;
	virtual void ParallelUpdate() = 0;
	virtual void ParallelStart() = 0;
	virtual void ParallelAwake() = 0;
};

#endif // !_PARALLEL_UPDATE_
