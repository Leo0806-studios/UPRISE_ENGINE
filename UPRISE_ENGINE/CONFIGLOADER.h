#pragma once
#ifndef _CONFIGLOADER_
#define _CONFIGLOADER_
#include "pch.h"
#include "CONFIGFILE.h"
namespace PAIN {
	class Shader;
}
namespace CORE {

	class ConfigLoader {
	public:
		static std::unordered_map<ConfigFile::ConfigType,std::unordered_map <std::string,std::shared_ptr<ConfigFile>>> ConfigDatabase;
		SettingsFile LoadSettingsFile(const char* path);
		static void LoadConfigFiles(const std::filesystem::path path);
		static std::shared_ptr<ConfigFile > LoadCOnfigFile(const char* path);
		static void LoadModels(const std::filesystem::path path);
		bool safemode;
		static void LoadTerrains();
		template	<class _Ty, class _Arg>
		static _Ty GameobjectFromCFGFile(std::shared_ptr<ConfigFile> CFG);
		static PAIN::Shader ShaderFromCFGFile(std::shared_ptr<ConfigFile> vertexshader, std::shared_ptr<ConfigFile>frgmentshader, std::shared_ptr<ConfigFile>geometryshader);
		static PAIN::Shader ShaderFromCFGFile(std::shared_ptr<ConfigFile> vertexshader, std::shared_ptr<ConfigFile>frgmentshader);
		static void LoadMaterials(const std::filesystem::path path);

	private:

	};
}
#endif // !_CONFIGLOADER_
