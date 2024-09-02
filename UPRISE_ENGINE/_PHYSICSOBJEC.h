#pragma once
#include "MODULE_IMPORTS.h"
#include "HeaderE/CORE/C_BEHAVIOUR.h"
PHYSICS::Physics_Object;
class _PhysicsObject :public CORE::Behaviour {
public:
	COPY(_PhysicsObject, a->object = PHYSICS::Physics_Object();)
		DEEP_COPY(_PhysicsObject, a->object = this->object; , )
		I_WINDOW(
			ImGui::Checkbox("is Kinematic", &object.isKinematic);
			ImGui::Checkbox("disabledSkipp", &object.disabledSkipp);
			ImGui::Checkbox("haschanged", &object.haschanged);
			ImGui::Checkbox("is Static", &object.isStatic);
			ImGui::TreeNode("Colliderbox");
			ImGui::InputFloat3("bounds", &object.Collider_Boxes.bounds.x);
			ImGui::InputFloat3("A", &object.Collider_Boxes.a.x);
			ImGui::InputFloat3("b", &object.Collider_Boxes.b.x);
			ImGui::InputFloat3("c", &object.Collider_Boxes.c.x);
			ImGui::InputFloat3("d", &object.Collider_Boxes.d.x);
			ImGui::InputFloat3("e", &object.Collider_Boxes.e.x);
			ImGui::InputFloat3("f", &object.Collider_Boxes.f.x);
			ImGui::InputFloat3("g", &object.Collider_Boxes.g.x);
			ImGui::InputFloat3("h", &object.Collider_Boxes.h.x);
			ImGui::TreePop();
		)
	PHYSICS::Physics_Object object;
	void Awake()override;
	void Update()override;
	void Start()override;
};