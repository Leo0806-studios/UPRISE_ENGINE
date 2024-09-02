#pragma once
#ifndef __MESH_

#define __MESH_
#include "pch.h"
#include "MODULE_IMPORTS.h"
#include "HeaderE/DATATYPES/D_TS_P_VECTOR3.h"
using namespace  DATATYPES;
namespace DATATYPES {



	struct  Mesh {

	public:
		std::vector<DATATYPES::TSPVector3> Vertecies;
		  Mesh() = default;
		  Mesh(const std::vector < DATATYPES:: TSPVector3 > & vertecies);

		  // If needed, declare and define the copy constructor and assignment operator explicitly
		  Mesh(const Mesh& other) = default;
		  Mesh& operator=(const Mesh& other) = default;

		  ~Mesh() = default;
		  //int id;


		
	
	};
}

#endif // !__MESH_
