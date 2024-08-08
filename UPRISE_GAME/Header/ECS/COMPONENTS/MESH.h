#pragma once
#ifndef _MESH_
#define _MESH_

#include "Header/CORE/CORE.h"
#include "RENDER_DATATYPES.h"


namespace COMPONENTS {
	class _Mesh : public CORE::Behaviour {


	public:
		I_WINDOW(
			ImGui::Text("Model");
		)
			COPY(_Mesh, a->Model = PAIN::Model::Empty(););
		DEEP_COPY(_Mesh, a->Model = this->Model; , )
			static UUID UUID;
		GameObject* oobj = nullptr;
		std::shared_ptr<PAIN::Model> Model;
		_Mesh();
		_Mesh(const char* pth);
		_Mesh(std::shared_ptr<PAIN::Model> model);


		void SetModel(std::shared_ptr<PAIN::Model> m);
		void Update()override;
		void Awake()override;
		void Start()override;
	};


}
//static Registrar<COMPONENTS::_Mesh> _Mesh("_Mesh");

#endif // !_MESH_


