#pragma once
#ifndef _Render_
#define _Render_
#include "GLOBAL/GLINCLUDES.h"
import REF_WRAPPER;
import std;

namespace RENDER{
	class Material;
	class Render {
	private:
		static std::unordered_map<std::string, int> materialIDlinkdict;

	public:
		Render() = default;
		~Render() {}
	};
}
#endif // !_Render_
