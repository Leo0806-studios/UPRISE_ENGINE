#pragma once
#include "CORE.h"
#include "DATATYPES.h"
#include "_COMPONENT.h"
#include "_MESH.h"
#include "RENDER.h"


namespace COMPONENTS {
	class _Mesh : CORE::Component {


	public: DATATYPES::Mesh mesh;
		  PAIN::Model Model;
		  _Mesh() {}
		  _Mesh(const char* pth) {
			  Model = PAIN::Model(pth);
		  }
		  _Mesh(PAIN::Model model) { Model = model; };


		  void SetMesh(DATATYPES::Mesh Mesh) {

			  mesh = Mesh;
		  }
		  void SetModel(PAIN::Model m) {
			  Model = m;
		  }

	};


}

