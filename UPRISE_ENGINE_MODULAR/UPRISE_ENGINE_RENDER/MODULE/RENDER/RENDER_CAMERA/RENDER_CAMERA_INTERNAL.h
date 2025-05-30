#pragma once
#ifndef UE_RENDER_CAMERA_INTERNAL_
#define UE_RENDER_CAMERA_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    class Transform;
    namespace RENDER {
        class RenderCamera {
        private:


        public:
            float FOV;
            char PAD[4]{};//TODO find a way to aling this better or put data here //-V112  //NOSONAR


            SharedRef<Transform, true> transf;
            RenderCamera();
            static RenderCamera Create(SharedRef<Transform, true> tr);

          UPRISE_RENDER_API  Mat4 GetViewMatrix();


        };
    };

}

#endif




