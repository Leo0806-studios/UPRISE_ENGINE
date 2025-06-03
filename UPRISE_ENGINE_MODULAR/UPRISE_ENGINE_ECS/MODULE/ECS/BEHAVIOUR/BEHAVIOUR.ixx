// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

module;
#include <intrin.h>

//#include "unordered_map"
export module UPRISE_ENGINE_ECS:BEHAVIOUR;
#ifndef __INTELLISENSE__
import UPRISE_ENGINE_CORE;
import :OBJECT;
import std;
//import <unordered_map>;
export {
#define UE_ECS_BUILD_
#include "BEHAVIOUR_INTERNAL.h"
}
#endif