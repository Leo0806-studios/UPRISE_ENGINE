// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "DEBUG_LOGGER.h"
#include "filesystem"
#include "iostream"
//import std.filesystem;
#include "GAMEOBJECT.h"
#include "HeaderE/CORE/C_CONFIGLOADER.h"
#include "HeaderE/DATATYPES/D_CONFIGFILE.h"
#include "RENDER_MATERIAL.h"
#include "RENDER_MATERIAL.h"
#include "RENDER_SHADER_UTILLS.h"
 std::unordered_map<ConfigFile::ConfigType, std::unordered_map <std::string, std::shared_ptr<ConfigFile>>> CORE::ConfigLoader::ConfigDatabase;
SettingsFile CORE::ConfigLoader::LoadSettingsFile(const char* path)
{
    return SettingsFile();
}

void CORE::ConfigLoader::LoadConfigFiles(const std::filesystem::path path)
{
    TrPr(ctx, __func__)
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            if (std::filesystem::is_directory(entry.status())) {
                for (const auto& sub_entry : std::filesystem::directory_iterator(entry.path())) {
                    if (std::filesystem::is_directory(sub_entry.status())) {
                        if (sub_entry.path().filename() == "CONFIG") {
                            // Do something
                            for (const auto& ConfigFolders : std::filesystem::directory_iterator(sub_entry.path())) {
                                if (std::filesystem::is_directory(ConfigFolders.status())) {
                                    //for(const auto& innerConfigFolder:std::filesystem::directory_iterator(ConfigFolders.path())){}
                                    for (const auto& file : std::filesystem::directory_iterator(ConfigFolders.path())) {
                                        if (std::filesystem::is_regular_file(file.status())) {
                                            LoadCOnfigFile(file.path().string().c_str());
                                            Log << "Loaded ConfigFile: " << file.path().string() << "\n";
                                            //std::cout << "Found file: " << file.path().string() << std::endl;
                                        }
                                    }
                                }
                            }

                            //std::cout << "Found directory: " << sub_entry.path().string() << std::endl;
                        }
                    }
                }
            }
        }
    //std::cout << CORE::ConfigLoader::ConfigDatabase->size();
    TrPrE(ctx)
}

std::shared_ptr<ConfigFile> CORE::ConfigLoader::LoadCOnfigFile(const char* path)
{
    TrPr(ctx, __func__)
        std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open config file.");
    }
    nlohmann::json j;
    file >> j;
    auto Name = j["name"].get<std::string>();
    auto Modelpath = j["modelPath"].get<std::string>();
    ConfigFile::ConfigType ConnfigType = ConfigFile::toConfigType(j["configType"].get<std::string>());
    std::vector<std::string> Texturepaths;
    for (const auto& path : j["texturePaths"]) {
        Texturepaths.push_back(path.get<std::string>());
    }
    nlohmann::json Data = j["data"];

    //for (const auto& path : j["data"]) {
    //    //Texturepaths.push_back(path.get<std::string>());
    //   // std::string dataString = ;
    //    Data.push_back(path.get<std::string>());

    //}
    if (ConnfigType == ConfigFile::ConfigType::ConfigType_Building) { std::shared_ptr<ConfigFile> ret = std::make_shared<Building>(Building(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::ConfigType_Building)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::Vehicle) { std::shared_ptr<ConfigFile> ret = std::make_shared<Vehicle>(Vehicle(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase[ConfigFile::ConfigType::Vehicle][Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::Projectile) { std::shared_ptr<ConfigFile> ret = std::make_shared<Projectile>(Projectile(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase[ConfigFile::ConfigType::Projectile][Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::Particle) { std::shared_ptr<ConfigFile> ret = std::make_shared<Particle>(Particle(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::Particle)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::Island) { std::shared_ptr<ConfigFile> ret = std::make_shared<Island>(Island(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::Island)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::AiObject) { std::shared_ptr<ConfigFile> ret = std::make_shared<AiObject>(AiObject(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::AiObject)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::Global) { std::shared_ptr<ConfigFile> ret = std::make_shared<Global>(Global(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::Global)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::Manager) { std::shared_ptr<ConfigFile> ret = std::make_shared<Manager>(Manager(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::Manager)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::VertexShader) { std::shared_ptr<ConfigFile> ret = std::make_shared<VertexShader>(VertexShader(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::VertexShader)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::FragmentShader) { std::shared_ptr<ConfigFile> ret = std::make_shared<FragmentShader>(FragmentShader(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::FragmentShader)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::GeometryShader) { std::shared_ptr<ConfigFile> ret = std::make_shared<GeometryShader>(GeometryShader(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::GeometryShader)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::ComputeShader) { std::shared_ptr<ConfigFile> ret = std::make_shared<ComputeShader>(ComputeShader(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::ComputeShader)[Name] = ret; TrPrE(ctx) return ret; }
    if (ConnfigType == ConfigFile::ConfigType::ConfigType_Material) { std::shared_ptr<ConfigFile> ret = std::make_shared<Material>(Material(Name, Modelpath, Texturepaths, ConnfigType, Data)); CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::ConfigType_Material)[Name] = ret; TrPrE(ctx) return ret; }
}

void CORE::ConfigLoader::LoadModels(const std::filesystem::path path) {
    TrPr(ctx, __func__)

        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            if (std::filesystem::is_directory(entry.status())) {
                for (const auto& sub_entry : std::filesystem::directory_iterator(entry.path())) {
                    if (std::filesystem::is_directory(sub_entry.status())) {
                        if (sub_entry.path().filename() == "MODELS") {
                            // Do something
                            for (const auto& file : std::filesystem::directory_iterator(sub_entry.path())) {
                                if (std::filesystem::is_regular_file(file.status())) {
                                    // Do something with each file
                                    PAIN::Model model = PAIN::Model(file.path().string());
                                    PAIN::Render::Modeldict[file.path().filename().string()] = std::make_shared<PAIN::Model>(model);
                                    std::cout << "Found file: " << file.path().string() << std::endl;
                                }
                            }
                            std::cout << "Found directory: " << sub_entry.path().string() << std::endl;
                        }
                    }
                }
            }
        }
    TrPrE(ctx)
}


void CORE::ConfigLoader::LoadTerrains()
{

}
PAIN::Shader CORE::ConfigLoader::ShaderFromCFGFile(std::shared_ptr<ConfigFile> vertexshader, std::shared_ptr<ConfigFile>frgmentshader, std::shared_ptr<ConfigFile>geometryshader)
{
    return PAIN::Shader(*std::dynamic_pointer_cast<VertexShader>(vertexshader).get(), *std::dynamic_pointer_cast<FragmentShader> (frgmentshader).get(), *std::dynamic_pointer_cast<GeometryShader> (geometryshader).get());
}
PAIN::Shader* CORE::ConfigLoader::ShaderFromCFGFile(std::shared_ptr<ConfigFile> vertexshader, std::shared_ptr<ConfigFile> frgmentshader)
{
    auto ptr = new PAIN::Shader(std::dynamic_pointer_cast<VertexShader>(vertexshader), std::dynamic_pointer_cast<FragmentShader> (frgmentshader));
    PAIN::Render::Shader_Ptr.push_back(ptr);
    return ptr;
    
}
void CORE::ConfigLoader::LoadMaterials(const std::filesystem::path path)
{
    TrPr(ctx, __func__)
        int i = 0;
    for (const auto material : CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::ConfigType_Material)) {
        auto a = std::dynamic_pointer_cast<Material>(material.second).get();
        if (a->ShaderCount == 2) {
            auto oo = CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::VertexShader)[a->VertexShader];
            auto aa = CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::VertexShader)[a->FragmentShader];
            a->Mat_ID = PAIN::Render::mats.size();
            PAIN::Render::mats.push_back(PAIN::Material(ShaderFromCFGFile(CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::VertexShader)[a->VertexShader], CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::FragmentShader)[a->FragmentShader]), a->Mat_ID));

        }
        else if (a->ShaderCount == 3) {
            a->Mat_ID = PAIN::Render::mats.size();
            PAIN::Render::mats.push_back(ShaderFromCFGFile(CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::VertexShader)[a->VertexShader], CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::FragmentShader)[a->FragmentShader], CORE::ConfigLoader::ConfigDatabase.operator[](ConfigFile::ConfigType::GeometryShader)[a->GeometryShader]));


        }
        i++;
    }
    TrPrE(ctx)
}
#define CREATE_CASE(x) case ConfigFile::ConfigType::x:
//template	<class _Ty, class _Arg>
std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile(std::shared_ptr<ConfigFile> CFG, ConfigFile::ConfigType type) {
    GameObject tmp;
    switch (type) {
        CREATE_CASE(ConfigType_Building) {
            return std::dynamic_pointer_cast<Building>(CFG)->ref->CreateFromCFG();
            break;
        }
        CREATE_CASE(Vehicle) { break; }
        CREATE_CASE(Projectile) { break; }
        CREATE_CASE(Particle) { break; }
        CREATE_CASE(Island) { break; }
        CREATE_CASE(AiObject) { break; }
        CREATE_CASE(Global) { break; }
        CREATE_CASE(Manager) { break; }
        CREATE_CASE(VertexShader) { Log << "Error: Wrong ConfigType. got " << ConfigFile::toString(type); break; }
        CREATE_CASE(FragmentShader) { Log << "Error: Wrong ConfigType. got " << ConfigFile::toString(type); break; }
        CREATE_CASE(GeometryShader) { Log << "Error: Wrong ConfigType. got " << ConfigFile::toString(type); break; }
        CREATE_CASE(ComputeShader) { Log << "Error: Wrong ConfigType. got " << ConfigFile::toString(type); break; }
        CREATE_CASE(ConfigType_Material) { Log << "Error: Wrong ConfigType. got " << ConfigFile::toString(type); break; }

    }

    auto configCasted = CFG;


    if (configCasted->ConfigType_ == (ConfigFile::ConfigType::VertexShader || ConfigFile::ConfigType::GeometryShader || ConfigFile::ConfigType::ComputeShader || ConfigFile::ConfigType::FragmentShader || ConfigFile::ConfigType::ConfigType_Material)) {
        Log << "Error: Wrong ConfigType. got {0}.", configCasted->ConfigType_;
    }
    if (configCasted->ConfigType_ == (ConfigFile::ConfigType::AiObject || ConfigFile::ConfigType::Global || ConfigFile::ConfigType::Manager)) {

        //auto tmp = GameObject::CreateEmpty(TS_P_Vector3(0, 0, 0));
        return std::make_shared<GameObject>(tmp);
    }
    else {
        // auto tmp = GameObject::Create(TS_P_Vector3(0, 0, 0), PAIN::Render::Modeldict[configCasted->Modelpath],0);
        // auto tmp = GameObject::Create(DATATYPES::TS_P_Vector3(0,0,0),Quaternion(1,0,0,0),;

        return std::make_shared<GameObject>(tmp);
    }
    ;
}

//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Buidling>(std::shared_ptr<ConfigFile> CFG);
//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Vehicle>(std::shared_ptr<ConfigFile> CFG);
//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Projectile>(std::shared_ptr<ConfigFile> CFG);
//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Particle>(std::shared_ptr<ConfigFile> CFG);
//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Island>(std::shared_ptr<ConfigFile> CFG);
//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, AiObject>(std::shared_ptr<ConfigFile> CFG);
//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Global>(std::shared_ptr<ConfigFile> CFG);
//template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Manager>(std::shared_ptr<ConfigFile> CFG);

