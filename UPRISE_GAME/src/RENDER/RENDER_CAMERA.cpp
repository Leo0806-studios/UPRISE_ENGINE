// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "RENDER_CAMERA.h"

PAIN::Render_Camera::Render_Camera() {}

PAIN::Render_Camera PAIN::Render_Camera::Create(std::shared_ptr<Transform> tr)
{
	TrPr(ctx, __func__)
		auto cam = Render_Camera();
	cam.FOV = 45;

	cam.transf = tr;
	TrPrE(ctx);
	return cam;
}

glm::mat4 PAIN::Render_Camera::GetViewMatrix()
{
	TrPr(ctx, __func__)
		TrPrE(ctx);
	return glm::lookAt((glm::vec3)transf->Position, (glm::vec3)(transf->Position + transf->forward), (glm::vec3)transf->up);

}
