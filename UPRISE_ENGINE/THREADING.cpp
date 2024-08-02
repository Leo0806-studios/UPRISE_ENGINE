#include "pch.h"
#include "THREADING.h"

CORE::Thread_Manager::Thread_Manager()
{
}
std::vector<CORE::Thread*> CORE::Thread_Manager::Threads;

CORE::Thread CORE::Thread_Manager::CreateThread(std::function<void()> f)
{
	CORE::Thread tmp(f);


	return tmp;
}


