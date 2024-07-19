#include "MESH.h"

 COMPONENTS::_Mesh::_Mesh() {}

 COMPONENTS::_Mesh::_Mesh(const char* pth) {

	 PAIN::Model mod = PAIN::Model(pth);
	 
	 Model =std::make_shared<PAIN::Model>( mod);
}

 COMPONENTS::_Mesh::_Mesh(std::shared_ptr<PAIN::Model> model) { Model = model; }
 GUID COMPONENTS::_Mesh::UUID = GUID_NULL;


 void COMPONENTS::_Mesh::SetModel(std::shared_ptr<PAIN::Model> m) {
	Model = m;
}

 void COMPONENTS::_Mesh::Update() {}

 void COMPONENTS::_Mesh::Awake() {}

 void COMPONENTS::_Mesh::Start() {}
