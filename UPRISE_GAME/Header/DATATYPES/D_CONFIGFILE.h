#pragma once
#ifndef _CONFIGFILE_
#define _CONFIGFILE_
#include "pch.h"

#ifndef _LOCK_
#define _LOCK_

#endif // !1

class Ressource;
class ConfigFile {

public:
	/// <summary>
	/// 
	/// </summary>
	enum ConfigType {
		Building,
		Vehicle,
		Projectile,
		Particle,
		Island,
		AiObject,
		Global,
		Manager,
		VertexShader,
		FragmentShader,
		GeometryShader,
		ComputeShader,
		Material
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
		case VertexShader: return "VertexShader";
		case FragmentShader: return "FragmentShader";
		case GeometryShader: return "GeometryShader";
		case ComputeShader: return "ComputeShader";
		case Material: return "Material";
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
		if (str == "VertexShader")return VertexShader;
		if (str == "FragmentShader")return FragmentShader;
		if (str == "GeometryShader")return GeometryShader;
		if (str == "ComputeShader")return ComputeShader;
		if (str == "Material") return Material;
		throw std::invalid_argument("Unknown ConfigType: " + str);
	}
	ConfigFile(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
	std::string Name;
	std::string Modelpath;
	std::vector<std::string> Texturepaths;
	ConfigType ConfigType_;
	//nlohmann::json Data;
	virtual void Palceholder() {};
	

};
class Buidling : public ConfigFile {
public:
	enum BuildingType {
		Residential,
		Needs,
		Production_Raw,
		Production_Not_Raw,
		Energy_In,
		Energy_I_W,
		Energy_R,
		Energy_R_W,
		Energy,
		Eco,
		Decoration,
		Military,
		Special,

		
	};
	enum SlotType {
		Ressource_O,
		Energy_O,
		Eco_O,
		None_O,
		Custom_O,
		Ressource_I,
		Energy_I,
		Eco_I,
		None_I,
		Custom_I
	};
	class Slot {
	public:
		std::shared_ptr<Ressource> Resource;
		int amount;
		SlotType slotType;
	};


	short InputCount;
	short OutputCount;
	std::vector < Slot > Input;
	std::vector<Slot> Output;
	int HittPoints;
	int EcoCost;
	int PowerCost;
	int Maintanece;
	int Mannpower;



	BuildingType buildinngType;

	Buidling(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
		
};
class Vehicle : public ConfigFile {
public:
	Vehicle(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class Projectile : public ConfigFile {
public:
	Projectile(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class Particle :public ConfigFile {
public:
	Particle(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class Island :public ConfigFile {
public:
	Island(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class AiObject : public ConfigFile {
public:
	AiObject(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class Global : public ConfigFile {
public:
	Global(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class Manager : public ConfigFile {
public:
	Manager(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class VertexShader : public ConfigFile {
public:
	std::string ShaderCode;
	VertexShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class FragmentShader : public ConfigFile {
public:
	std::string ShaderCode;

	FragmentShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class GeometryShader : public ConfigFile {
public:
	std::string ShaderCode;

	GeometryShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class ComputeShader : public ConfigFile {
public:
	std::string ShaderCode;

	ComputeShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class Material : public ConfigFile {
public:
	int ShaderCount;
	std::string VertexShader;
	std::string FragmentShader;
	std::string GeometryShader;
	
	Material(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data);
};
class SettingsFile {

};
#endif // !_CONFIGFILE_
