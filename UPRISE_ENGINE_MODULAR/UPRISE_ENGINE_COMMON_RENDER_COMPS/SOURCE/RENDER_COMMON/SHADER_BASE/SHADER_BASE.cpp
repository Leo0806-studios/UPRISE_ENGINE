// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import <string>;
import <filesystem>;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {
        SHADER_BASE::SHADER_BASE(const SHADER_BASE& other): //-V2537
            Code(other.Code),
            Path(other.Path),
            shadertype(other.shadertype),
            PAD{ DEBUG_PAD_BITS_ZEROED }
        {
            

        }
        SHADER_BASE::SHADER_BASE(const std::filesystem::path& path)
        {
            this->Path = path.string();
        }
        SHADER_BASE::SHADER_BASE(const std::string& code): //-V2537
            Code(code),
            Path(""),
            shadertype(ShaderType::S_null),
            PAD{ DEBUG_PAD_BITS_ZEROED }

        {
        }

        SHADER_BASE& SHADER_BASE::operator=(const SHADER_BASE& other) {
            this->Code = other.Code;
            this->Path = other.Path;
            this->shadertype = other.shadertype;
            return *this;
        }
    }
