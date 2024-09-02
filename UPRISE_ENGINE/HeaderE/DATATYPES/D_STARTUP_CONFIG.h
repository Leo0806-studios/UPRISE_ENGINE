#pragma once
#ifndef _STARTUP_CONFIG_
#define _STARTUP_CONFIG_

#include "MODULE_IMPORTS.h"
namespace DATATYPES {

	struct Startup_Config {


	public :
		unsigned long long RAMbytes;
		bool Supports_AVX2;
		bool Supports_AVX;
		bool Is_IGPU;
		unsigned short CPU_Cores;
		unsigned short GPU_Cores;
		/// <summary>
		/// accepts 0 opengl,1vulkan,2 dx11 and 2 dx12
		/// </summary>
		unsigned short RenderMode;
		Startup_Config();


	};


}

#endif // !_STARTUP_CONFIG_
