// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module UPRISE_ENGINE_CORE:OBJECT;
import :WEAK_REF;
import :OWNED_REF;
import :SHARED_REF;
import <memory>;
import <string>;
import <vector>;
import <atomic>;
export {
#define UE_CORE_BUILD_
#include "OBJECT_INTERNAL.h"
}