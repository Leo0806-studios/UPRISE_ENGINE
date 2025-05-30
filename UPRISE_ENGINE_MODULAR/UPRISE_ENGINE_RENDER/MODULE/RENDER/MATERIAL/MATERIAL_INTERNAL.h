#pragma once
#ifndef UE_MATERIAL_INTERNAL_
#define UE_MATERIAL_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
namespace UPRISE_ENGINE {
    namespace RENDER {
        class Material {
        private:
        public:
            Material() = default;
            ~Material() {}
        };
    }
}


#endif




