#pragma once
#ifndef _CONFIGFILE_
#define _CONFIGFILE_
#include "pch.h"

#ifndef _LOCK_
#define _LOCK_

#endif // !1


class ConfigFile {

public:
	enum ConfigType {
		Building,
		Vehicle,
		Projectile,
		Particle,
		Island,
		AiObject,
		Global,
		Manager,
	};
	static std::string toString(ConfigType type) {
		switch (type) {
		case Building: return "Building";
		case Vehicle: return "Vehicle";
		case Projectile: return "Projectile";
		case Particle: return "Particle";
		case Island: return "Island";
		case AiObject: return "AiObject";
		case Global: return "Global";
		case Manager: return "Manager";
		default: return "Unknown";
		}
	}

   static  ConfigType toConfigType(const std::string& str) {
		if (str == "Building") return Building;
		if (str == "Vehicle") return Vehicle;
		if (str == "Projectile") return Projectile;
		if (str == "Particle") return Particle;
		if (str == "Island") return Island;
		if (str == "AiObject") return AiObject;
		if (str == "Global") return Global;
		if (str == "Manager") return Manager;
		throw std::invalid_argument("Unknown ConfigType: " + str);
	}
	ConfigFile(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, std::vector<std::string> data);
	std::string Name;
	std::string Modelpath;
	std::vector<std::string> Texturepaths;
	ConfigType ConfigType_;
	std::vector<std::string> Data;
	virtual void Palceholder() {};
	

};
class Buidling : public ConfigFile {

};
class Vehicle : public ConfigFile {

};
class Projectile : public ConfigFile {

};
class Particle :public ConfigFile {

};
class Island :public ConfigFile {

};
class AiObject : public ConfigFile {

};
class Global : public ConfigFile {

};
class Manager : public ConfigFile {

};
class SettingsFile {

};
#endif // !_CONFIGFILE_
