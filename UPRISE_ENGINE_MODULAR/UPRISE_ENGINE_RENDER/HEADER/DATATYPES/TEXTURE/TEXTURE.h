#pragma once
#ifndef _Texture_
#define _Texture_
import std;
namespace RENDER{
	class Texture {
	private:
	public:
		unsigned int id = 0;
		std::string type;
		std::string path;
		Texture() = default;
		~Texture() {}
	};
}
#endif // !_Texture_
