#include "pch.h"

#include "HeaderE/DATATYPES/D_CONFIGFILE.h"
#include "GAMEOBJECT.h"
#include "MESH.h"
#include "RENDER_MATERIAL.h"
#include "HeaderE/CORE/C_CONFIGLOADER.h"
//#include "C_Building.h"
//#include "C_RESIDENTIAL.h"
ConfigFile::ConfigFile(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
{
	Name = name;
	Modelpath = modelpath;
	Texturepaths = texturepath;
	ConfigType_ = configType;
	//Data = data;
}



Building::Building(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
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

std::shared_ptr<GameObject> Building::CreateFromCFG() { return std::make_shared<GameObject>(GameObject(1)); }

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
	std::string  shadercode = "";
	for (std::string s : data["shaderCode"]) {
		shadercode = shadercode + s + "\n";
	}
	ShaderCode = shadercode;
	
		std::string Varname;
		std::string Vartype;
		for (auto& obj : data["Uniforms"].items()) {
			Vartype = obj.key();
			for (auto& var : obj.value()) {
				Varname = var;
				VarLocsU[Vartype].push_back(Varname);
			}
		}
		//for (auto& obj : data["LayoutVars"].items()) {
		//	Vartype = obj.key();
		//	VarLocsL[Vartype].push_back(FragmentShader::_internal_Pair(obj.value()["location"], obj.value()["type"]));

		//}

	

}

GeometryShader::GeometryShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	: ConfigFile(name, modelpath, texturepath, configType, data) {
	std::string shadercode = "";
	for (std::string s : data["shaderCode"]) {
		shadercode = shadercode + s;
	}
	ShaderCode = shadercode;
	
		std::string Varname;
		std::string Vartype;
		for (auto& obj : data["Uniforms"].items()) {
			Vartype = obj.key();
			for (auto& var : obj.value()) {
				Varname = var;
				VarLocsU[Vartype].push_back(Varname);
			}
		}
		for (auto& obj : data["LayoutVars"].items()) {
			Vartype = obj.key();
			VarLocsL[Vartype].emplace_back(GeometryShader::_internal_Pair((int)obj.value()["location"], obj.value()["type"]));

		}

	
}

Material::Material(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	: ConfigFile(name, modelpath, texturepath, configType, data) {
	std::string s = data["ShaderCount"];
	ShaderCount = s.data()[0] - 48;
	VertexShader = data["VertexShader"];
	FragmentShader = data["FragmentShader"];

	// GeometryShader = Data[3];
}

VertexShader::VertexShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	: ConfigFile(name, modelpath, texturepath, configType, data) {
	std::string shadercode = "";
	for (std::string s : data["shaderCode"]) {
		shadercode = shadercode + s + "\n";
	}
	ShaderCode = shadercode;
	
		std::string Varname;
		std::string Vartype;
		for (auto& obj : data["Uniforms"].items()) {
			Vartype = obj.key();
			for (auto& var : obj.value()) {
				Varname = var;
				VarLocsU[Vartype].push_back( Varname);
			}
		}
		for (auto& obj : data["LayoutVars"].items()) {
			Vartype = obj.key();
			auto a = obj.value();
			VarLocsL[Vartype].emplace_back(VertexShader::_internal_Pair(a["location"], a["type"]));
			
		}
	

}

ComputeShader::ComputeShader(std::string name, std::string modelpath, std::vector<std::string> texturepath, ConfigType configType, nlohmann::json data)
	: ConfigFile(name, modelpath, texturepath, configType, data) {
	std::string shadercode = "";
	for (std::string s : data["shaderCode"]) {
		shadercode = shadercode + s;
	}
	ShaderCode = shadercode;
	
		std::string Varname;
		std::string Vartype;
		for (auto& obj : data["Uniforms"].items()) {
			Vartype = obj.key();
			for (auto& var : obj.value()) {
				Varname = var;
				VarLocsU[Vartype].push_back(Varname);
			}
		}
		for (auto& obj : data["LayoutVars"].items()) {
			Vartype = obj.key();
			VarLocsL[Vartype].emplace_back(ComputeShader::_internal_Pair(obj.value()["location"], obj.value()["type"]));

		}

	

}

std::shared_ptr<GameObject> Residential::CreateFromCFG()
{
	//std::shared_ptr<GameObject> tmp = GameObject::Create(TSPVector3(0, 0, 0), Quaternion(1, 0, 0, 0), std::make_shared<COMPONENTS::_Mesh>(COMPONENTS::_Mesh(PAIN::Render::Modeldict[Modelpath])), dynamic_pointer_cast<Material>(CORE::ConfigLoader::ConfigDatabase->operator[](ConfigFile::ConfigType::ConfigType_Material)[_Material])->Mat_ID);
	//auto cmp = tmp->AddComponent(C_Building());
	//cmp->Main_Component = tmp->AddComponentD(C_Resitential());

	return std::shared_ptr<GameObject>();
}

std::shared_ptr<GameObject> Prodiction::CreateFromCFG()
{
	return std::shared_ptr<GameObject>();
}

std::shared_ptr<GameObject> Needs::CreateFromCFG()
{
	return std::shared_ptr<GameObject>();
}

std::shared_ptr<GameObject> Energy::CreateFromCFG()
{
	return std::shared_ptr<GameObject>();
}

std::shared_ptr<GameObject> Eco::CreateFromCFG()
{
	return std::shared_ptr<GameObject>();
}

std::shared_ptr<GameObject> Decoration::CreateFromCFG()
{
	return std::shared_ptr<GameObject>();
}

std::shared_ptr<GameObject> Military::CreateFromCFG()
{
	return std::shared_ptr<GameObject>();
}

std::shared_ptr<GameObject> Special::CreateFromCFG()
{
	return std::shared_ptr<GameObject>();
}
