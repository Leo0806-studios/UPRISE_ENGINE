#pragma once
#ifndef _MESH_
#define _MESH_

#include "CORE.h"
#include "RENDER_DATATYPES.h"


namespace COMPONENTS {
	class _Mesh : public CORE::Behaviour {


	public: 
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

#endif // !_MESH_


