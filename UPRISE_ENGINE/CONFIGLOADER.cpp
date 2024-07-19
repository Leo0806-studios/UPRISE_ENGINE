#include "CONFIGLOADER.h"
#include "RENDER_MATERIAL.h"
#include "GAMEOBJECT.h"

SettingsFile CORE::ConfigLoader::LoadSettingsFile(const char* path)
{
    return SettingsFile();
}

ConfigFile CORE::ConfigLoader::LoadCOnfigFile(const char* path)
{
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
    std::vector<std::string> Data;

    for (const auto& path : j["data"]) {
        //Texturepaths.push_back(path.get<std::string>());
       // std::string dataString = ;
        Data.push_back(path.get<std::string>());

    }
    return ConfigFile(Name,Modelpath,Texturepaths,ConnfigType,Data);
}

void CORE::ConfigLoader::LoadModels(const std::filesystem::path path) {

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
}


void CORE::ConfigLoader::LoadTerrains()
{
}
template	<class _Ty, class _Arg>
_Ty CORE::ConfigLoader::GameobjectFromCFGFile(std::shared_ptr<ConfigFile> CFG) {

    auto configCasted = std::dynamic_pointer_cast<_Arg>(CFG).get();
    if (configCasted->ConfigType_ == (ConfigFile::ConfigType::AiObject || ConfigFile::ConfigType::Global || ConfigFile::ConfigType::Manager)) {

        auto tmp = GameObject::CreateEmpty(TS_P_Vector3(0, 0, 0));
        return std::make_shared<GameObject>(tmp);
    }
    else {
       // auto tmp = GameObject::Create(TS_P_Vector3(0, 0, 0), PAIN::Render::Modeldict[configCasted->Modelpath],0);
        auto tmp = GameObject::CreateEmpty(TS_P_Vector3(0, 0, 0));

        return std::make_shared<GameObject>(tmp);
    }
    ;
}

template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Buidling>(std::shared_ptr<ConfigFile> CFG);
template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Vehicle>(std::shared_ptr<ConfigFile> CFG);
template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Projectile>(std::shared_ptr<ConfigFile> CFG);
template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Particle>(std::shared_ptr<ConfigFile> CFG);
template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Island>(std::shared_ptr<ConfigFile> CFG);
template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, AiObject>(std::shared_ptr<ConfigFile> CFG);
template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Global>(std::shared_ptr<ConfigFile> CFG);
template std::shared_ptr<GameObject> CORE::ConfigLoader::GameobjectFromCFGFile<std::shared_ptr<GameObject>, Manager>(std::shared_ptr<ConfigFile> CFG);

