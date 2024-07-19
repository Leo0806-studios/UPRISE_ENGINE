#pragma once
#ifndef _CONFIGLOADER_
#define _CONFIGLOADER_
#include "CONFIGFILE.h"
namespace CORE {

	class ConfigLoader {
	public:
		SettingsFile LoadSettingsFile(const char* path);
		static ConfigFile LoadCOnfigFile(const char* path);
		static void LoadModels(const std::filesystem::path path);
		bool safemode;
		static void LoadTerrains();
		template	<class _Ty, class _Arg>
		static _Ty GameobjectFromCFGFile(std::shared_ptr<ConfigFile> CFG);

	private:
		static void* internalObjSpawn() {


		}
	};
}
#endif // !_CONFIGLOADER_
