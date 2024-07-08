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
		  PAIN::Model Model;
		  _Mesh();
		  _Mesh(const char* pth);
		  _Mesh(PAIN::Model model);


		  void SetModel(PAIN::Model m);
		  void Update()override;
		  void Awake()override;
		  void Start()override;
	};


}

#endif // !_MESH_


