// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


// ============================================================================  
// File: WEAK_REF.ixx  
// Project: UPRISE_ENGINE_CORE  
// Module: CORE  
// Description: This file contains the implementation of the WeakRef class,  
//              which provides weak reference functionality for Owned or Shared  
//              references. It ensures that the object referred to is not kept  
//              alive but maintains the control block's lifecycle.  
//  
// Author: Sam Stamatelos
// Created: idk
// Updated: 2025-4-30
// Version: 0.2
//  
// Copyright (C) 2025 Sam Stamatelos. All rights reserved.  
// ============================================================================
module;

export module UPRISE_ENGINE_CORE:WEAK_REF;

import :WRAPPER_BASE;
import :CONTROL_BASE;
import <cstdint>;
import <utility>;
import <type_traits>;
#pragma warning(push)
#pragma warning(disable:4100)
export {
#define UE_CORE_BUILD_
#include "WEAK_REF_INTERNAL.h"
}
#pragma warning(pop)