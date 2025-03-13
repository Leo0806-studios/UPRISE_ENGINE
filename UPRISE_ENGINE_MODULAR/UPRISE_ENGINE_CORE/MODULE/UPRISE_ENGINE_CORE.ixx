export module UPRISE_ENGINE_CORE;

//CORE
export import :OBJECT;
export import :BEHAVIOUR;
export import :COMPONENT;
export import :CPUID;
export import :THREAD;

//DATATYPES
export import :ARRAY;
export import :LAYER;
export import :MAT4;
export import :QUATERION;
export import :TAG;
export import :UUID;
export import :VECTOR2;
export import :VECTOR3;
export import :VECTOR4;

#ifdef UPRISEENGINECORE_EXPORTS

//CORE
import :OBJECT_IMPL;
import :BEHAVIOUR_IMPL;
import :COMPONENT_IMPL;
import :CPUID_IMPL;
import :THREAD_IMPL;



//DATATYPES
//import :ARRAY_IMPL;
import :LAYER_IMPL;

import :UUID_IMPL;

#endif