#pragma once
#ifndef _CONFIGLOADER_
#define _CONFIGLOADER_
#include "CONFIGFILE.h"
namespace CORE {

	class ConfigLoader {
	public:
		ConfigFile LoadCOnfigFile(const char* path);
		bool safemode;

	};
}
#endif // !_CONFIGLOADER_
