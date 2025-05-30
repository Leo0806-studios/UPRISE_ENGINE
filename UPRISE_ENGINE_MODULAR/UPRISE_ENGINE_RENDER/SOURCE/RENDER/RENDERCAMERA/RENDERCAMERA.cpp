// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_RENDER_INTELLISENSE_FIX.h"
#include "UE_ECS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_RENDER;
import UPRISE_ENGINE_ECS;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE::RENDER {
    RenderCamera::RenderCamera()
    {
    }
    RenderCamera RenderCamera::Create(SharedRef<Transform, true> tr)
    {
        UE_UNUSED_PARAMETER(tr);
        UE_THROW_NOT_IMPLEMENTED;
        return RenderCamera();
    }
    inline Mat4 RENDER::RenderCamera::GetViewMatrix() {
        //TrPr(ctx, __func__)
        //	TrPrE(ctx);
        //return Mat4::Look_At(transf->Position, (transf->Position + transf->forward), transf->up).operator glm::mat<4, 4, float, glm::packed_highp>();

        return Mat4::Look_At(transf->Position(), (transf->Position() + transf->Forward()), transf->Up());
        //return glm::mat4(1);
        //return glm::lookAt((glm::vec3)transf->Position, (glm::vec3)(transf->Position + transf->forward), (glm::vec3)transf->up);
    }

}
