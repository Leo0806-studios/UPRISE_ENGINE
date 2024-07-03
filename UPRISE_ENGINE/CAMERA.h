#pragma once
#include "BEHAVIOUR.h"
#include "memory"


	class Camera: public CORE::Behaviour {
	public:
		float FOV;
		static UUID UUID;
		int wo=0;

		void Update()override {

			std::cout << "test" << wo << "\n";
		}

		void Awake()override {}
		void Start()override {}


	};
