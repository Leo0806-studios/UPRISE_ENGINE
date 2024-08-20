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

 /*__inline glm::mat4 PAIN::Render_Camera::GetViewMatrix()
 {

	 
 }*/
