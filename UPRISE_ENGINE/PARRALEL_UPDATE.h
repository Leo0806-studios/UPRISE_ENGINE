#pragma once
#ifndef _PARALLEL_UPDATE_
#define _PARALLEL_UPDATE_

#include "HeaderE/CORE/CORE.h"
#include "HeaderE/CORE/C_BEHAVIOUR.h"
#include "DEBUG_LOGGER.h"
#include "MODULE_IMPORTS.h"
namespace CORE {

	class Behaviour;
}
class Parallel_Update : public CORE::Behaviour {

public:
	void Awake()override;
	void Start()override;
	void Update()override;
	COPY(Parallel_Update, Log << "DONT!"; throw(std::exception());)
		DEEP_COPY(Parallel_Update, Log << "DONT!"; throw(std::exception());,)
		I_WINDOW_E()
		virtual void ParallelUpdate() {}
	virtual void ParallelStart() {}
	virtual void ParallelAwake() {}
};

#endif // !_PARALLEL_UPDATE_
