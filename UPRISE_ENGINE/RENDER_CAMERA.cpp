#include "RENDER_CAMERA.h"

 PAIN::Render_Camera::Render_Camera() {}

 PAIN::Render_Camera PAIN::Render_Camera::Create() 
 {
	 auto cam = Render_Camera();
	 cam.FOV = 45;
	 return cam;
 }

 glm::mat4 PAIN::Render_Camera::GetViewMatrix()
 {
	 return glm::lookAt((glm::vec3)transform->Position, (glm::vec3)(transform->Position + transform->forward), (glm::vec3)transform->up);
	 
 }
