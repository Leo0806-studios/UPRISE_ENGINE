// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Texture_
#define _Texture_
import std;
namespace UPRISE_ENGINE {
    namespace RENDER {
        class Texture {
        private:
        public:
            unsigned int id = 0;
            std::string type;
            std::string path;
            Texture() = default;
            ~Texture() {}
        };
    }
}

#endif // !_Texture_
