#pragma once


#include "TS_P_VECTOR3.h"
//using namespace  DATATYPES;
namespace DATATYPES {



	struct  Mesh {

	public:
		std::vector<DATATYPES::TS_P_Vector3> Vertecies;
		  Mesh() = default;
		  Mesh(const std::vector < DATATYPES:: TS_P_Vector3 > & vertecies) : Vertecies(vertecies) {}

		  // If needed, declare and define the copy constructor and assignment operator explicitly
		  Mesh(const Mesh& other) = default;
		  Mesh& operator=(const Mesh& other) = default;

		  ~Mesh() = default;
		  //int id;


		
	
	};
}