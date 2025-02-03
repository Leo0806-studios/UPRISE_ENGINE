// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_RenderCamera_
#define UE_RenderCamera_
#include "GLOBAL/GLINCLUDES.h"
import REF_WRAPPER; //-V3549 //-V2575
import std; //-V3549 //-V2575
namespace UPRISE_ENGINE {
    class Transform;
    namespace RENDER {
        class RenderCamera {
        private:


        public:
            float FOV;


            RefWrapper<Transform, true> transf;
            RenderCamera();
            static RenderCamera Create(RefWrapper<Transform, true> tr);

            __inline glm::mat4 GetViewMatrix();
            //{
            //	return glm::lookAt(Position, Position + Front, Up);
            //}

        };
    };

}

#endif // !_RenderCamera_
