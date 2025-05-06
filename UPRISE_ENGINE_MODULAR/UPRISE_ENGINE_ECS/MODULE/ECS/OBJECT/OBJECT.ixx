// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

export module UPRISE_ENGINE_ECS:OBJECT;
import std;

import UPRISE_ENGINE_CORE;
//import <memory>;
//import <string>;
//import <vector>;
//import <atomic>;

export {
#define UE_ECS_BUILD_
#include "OBJECT_INTERNAL.h"
}