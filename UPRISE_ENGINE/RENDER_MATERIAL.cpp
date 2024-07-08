#include "GLINCLUDES.h"
#include "RENDER_MATERIAL.h"
#include "DATATYPES.h"
 PAIN::Material::Material(Shader* shade) { shader = shade; }
 std::vector<PAIN::Material> PAIN::Render::mats;

inline void PAIN::Material::Draw() {
	shader->use();
	int i = objects.size() - 1;
	for (; i >= 0; i--) {

		if (objects[i]->Enabled >= 1) {
			glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
			glm::mat4 view = glm::mat4(1.0f);
			glm::mat4 projection = glm::mat4(1.0f);
			model = glm::rotate(model, glm::radians(-55.0f)* (float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));
			DATATYPES::TS_P_Vector3 pos = std::dynamic_pointer_cast<Transform>(objects[i]->behaviours[1]).get()->Position;
			auto poss = std::dynamic_pointer_cast<Transform>(objects[i]->behaviours[1]);
			auto ooo=poss.get();
			pos = ooo->Position;
			view = glm::translate(view, (glm::vec3)pos );
			projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
			// retrieve the matrix uniform locations
			unsigned int modelLoc = glGetUniformLocation(shader->ID, "model");
			unsigned int viewLoc = glGetUniformLocation(shader->ID, "view");
			// pass them to the shaders (3 different ways)
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
			shader->setMat4("projection", projection);
			//GameObject* e = objects[i];
			auto aa = std::dynamic_pointer_cast<COMPONENTS::_Mesh>(objects[i]->MesH);
			aa.get()->Model.Draw(*shader);
			//auto meesh = (COMPONENTS::_Mesh*)objects[i]->msh;
			//meesh->Model.Draw(*shader);
			//objects[i]->MesH.Model.Draw(*shader);
		}
	}
}

  void PAIN::Render::DrawAll() {
	int i = mats.size() - 1;
	for (; i >= 0; i--) {


		mats[i].Draw();
	}
}
