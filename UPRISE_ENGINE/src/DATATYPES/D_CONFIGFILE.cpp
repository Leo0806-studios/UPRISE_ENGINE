#include "pch.h"

#include "HeaderE/DATATYPES/D_CONFIGFILE.h"

ConfigFile::ConfigFile(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
{
	Name = name;
	Modelpath = modelpath;
	Texturepaths = texturepath;
	ConfigType_ = configType;
	//Data = data;
}



  Buidling::Buidling(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data) 
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
	 // buildinngType = data["BuildingType"];
	  switch (buildinngType) {
	  case Residential:
	  {
		  std::cout << "Building Type: Residential" << std::endl;
		  break;
	  }
	  case Needs:
	  {
		  std::cout << "Building Type: Needs" << std::endl;
		  break;
	  }
	  case Production_Raw:
	  {
		  std::cout << "Building Type: Production Raw Materials" << std::endl;
		  break;
	  }
	  case Production_Not_Raw:
	  {
		  std::cout << "Building Type: Production Non-Raw Materials" << std::endl;
		  break;
	  }
	  case Energy_In:
	  {
		  std::cout << "Building Type: Energy Industrial" << std::endl;
		  break;
	  }
	  case Energy_I_W:
	  {
		  std::cout << "Building Type: Energy Industrial with Waste" << std::endl;
		  break;
	  }
	  case Energy_R:
	  {
		  std::cout << "Building Type: Renewable Energy" << std::endl;
		  break;
	  }
	  case Energy_R_W:
	  {
		  std::cout << "Building Type: Renewable Energy with Waste" << std::endl;
		  break;
	  }
	  case Energy:
	  {
		  std::cout << "Building Type: General Energy" << std::endl;
		  break;
	  }
	  case Eco:
	  {
		  std::cout << "Building Type: Ecological" << std::endl;
		  break;
	  }
	  case Decoration:
		  std::cout << "Building Type: Decoration" << std::endl;
		  break;
	  case Military:
		  std::cout << "Building Type: Military" << std::endl;
		  break;
	  case Special:
		  std::cout << "Building Type: Special" << std::endl;
		  break;
	  default:
		  std::cout << "Unknown Building Type" << std::endl;
		  break;
	  }
  
  }

  Vehicle::Vehicle(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
  
  }

  Projectile::Projectile(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
  
  }

  Particle::Particle(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
  
  }

  Island::Island(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
  
  }

  AiObject::AiObject(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data) 
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
  
  }

  Global::Global(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data) 
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
  
  }

  Manager::Manager(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data) 
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
 
  }

  FragmentShader::FragmentShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data) 
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
	  string shadercode="";
	  for (string s : data["shaderCode"]) {
		  shadercode = shadercode + s+"\n";
	  }
	  ShaderCode = shadercode;
  
  }

  GeometryShader::GeometryShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
	  string shadercode = "";
	  for (string s : data["shaderCode"]) {
		  shadercode = shadercode + s;
	  }
	  ShaderCode = shadercode;
  }

  Material::Material(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data) 
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
	  string s = data["ShaderCount"];
	  ShaderCount = s.data()[0]-48;
	  VertexShader = data["VertexShader"];
	  FragmentShader = data["FragmentShader"];

	 // GeometryShader = Data[3];
  }

  VertexShader::VertexShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data) 
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
	  string shadercode = "";
	  for (string s : data["shaderCode"]) {
		  shadercode = shadercode + s+"\n";
	  }
	  ShaderCode = shadercode;

  }

  ComputeShader::ComputeShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	  : ConfigFile(name, modelpath, texturepath, configType, data) {
	  string shadercode = "";
	  for (string s : data["shaderCode"]) {
		  shadercode = shadercode + s;
	  }
	  ShaderCode = shadercode;

  }
