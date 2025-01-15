

#include "RENDERCAMERA/RENDERCAMERA.h"

#include "COMPONENTS/TRANSFORM/TRANSFORM.h"
#include <MAT4/Mat4.h>
inline glm::mat4 RENDER::RenderCamera::GetViewMatrix() {
	ZoneScoped;
	//TrPr(ctx, __func__)
	//	TrPrE(ctx);
	//return Mat4::Look_At(transf->Position, (transf->Position + transf->forward), transf->up).operator glm::mat<4, 4, float, glm::packed_highp>();
	return Mat4::Look_At_GLM(transf->Position(), (transf->Position() + transf->Forward()), transf->Up());
    //return glm::mat4(1);
	//return glm::lookAt((glm::vec3)transf->Position, (glm::vec3)(transf->Position + transf->forward), (glm::vec3)transf->up);
}
