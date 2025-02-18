#include "RENDER_COMMON/SHADER_BASE/SHADER_BASE.h"
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {
        SHADER_BASE::SHADER_BASE(const SHADER_BASE& other)
        {
            
            Code = other.Code;
            Path = other.Path;
            shadertype = other.shadertype;
        }
        SHADER_BASE::SHADER_BASE(const std::filesystem::path& path)
        {
            this->Path = path.string();
        }
        SHADER_BASE::SHADER_BASE(const std::string& code)
        {
            this->Code = code;
        }
    }
}