#pragma once
#include "CORE.h"
#include "DATATYPES.h"
#include "_COMPONENT.h"
#include "_MESH.h"


namespace COMPONENTS {
	class _Mesh : CORE::Component {


	public: DATATYPES::Mesh mesh;
		  _Mesh() {}


		  void SetMesh(DATATYPES::Mesh Mesh) {

			  mesh = Mesh;
		  }

	};


}

