#pragma once
#ifndef UE_TEXTURE_INTERNAL_
#define UE_TEXTURE_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <string>
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    namespace RENDER {
        class Texture {
        private:
        public:
            std::string type;
            std::string path;
            unsigned int id = 0;
            char PAD[4];//TODO find a better way to align this or put data here //-V112  //NOSONAR
            Texture() = default;
            ~Texture() = default;
        };
    }
}

#endif




