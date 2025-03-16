module;
#include <intrin.h>
#include <string.h>
#include <GLOBAL/GLINCLUDES.h>
export module UPRISE_ENGINE_CORE;
import std;
import REF_WRAPPER;
#define CORE_MODULE_BUILD
#pragma warning (push)
#pragma warning(disable:4005)
#define UE_IMPORT(Name)
#pragma warning(pop)
//CORE

export{
#include "CORE/BEHAVIOUR/BEHAVIOUR.h"
#include "CORE/COMPONENT/COMPONENT.h"
#include "CORE/CPUID/CPUID.h"
#include "CORE/OBJECT/OBJECT.h"
#include "CORE/THREADING/THREAD/THREAD.h"

}


//DATATYPES
export{
#include "DATATYPES/ARRAY/ARRAY.h"
#include "DATATYPES/LAYER/LAYER.h"
#include "DATATYPES/MAT4/Mat4.h"
#include "DATATYPES/QUTERION/QUATERION.h"
#include "DATATYPES/STRING/SMALL/SMALL_STRING.h"
#include "DATATYPES/TAG/TAG.h"
#include "DATATYPES/UUID/UUID.h"
#include "DATATYPES/VECTOR/VECTOR2/VECTOR2.h"
#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include "DATATYPES/VECTOR/VECTOR4/VECTOR4.h"
}

