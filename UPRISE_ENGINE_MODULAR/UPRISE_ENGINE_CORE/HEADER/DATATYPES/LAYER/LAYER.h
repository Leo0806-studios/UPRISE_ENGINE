#pragma once
#ifndef _LAYER_
#define _LAYER_
import std;
class Layer {
private:
	int id;
	std::string name;
public:
#pragma region constructor
	Layer() = default;
	Layer(int id, std::string name) :id(id), name(name) {};
#pragma endregion

	__inline UPRISE_CORE_API std::string& Name() { return name; }
	__inline UPRISE_CORE_API int ID() { return id; }
};
#endif // !1
