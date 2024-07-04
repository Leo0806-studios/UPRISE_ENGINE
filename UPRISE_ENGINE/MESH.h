#pragma once
#ifndef _MESH_
#define _MESH_

#include "_MESH.h"
#include "CORE.h"
#include "DATATYPES.h"
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

#endif // !_MESH_


