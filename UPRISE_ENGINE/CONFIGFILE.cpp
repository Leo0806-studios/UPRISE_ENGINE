#include "CONFIGFILE.h"

ConfigFile::ConfigFile(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, std::vector<std::string> data)
{
	Name = name;
	Modelpath = modelpath;
	Texturepaths = texturepath;
	ConfigType_ = configType;
	Data = data;
}
