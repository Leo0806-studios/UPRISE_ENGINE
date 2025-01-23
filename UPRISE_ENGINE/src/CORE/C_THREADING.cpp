// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include <HeaderE/CORE/C_THREADING.h>

CORE::Thread_Manager::Thread_Manager()
{
}
std::vector<CORE::Thread*> CORE::Thread_Manager::Threads;

CORE::Thread CORE::Thread_Manager::CreateThread(std::function<void()> f)
{
	CORE::Thread tmp(f);


	return tmp;
}


