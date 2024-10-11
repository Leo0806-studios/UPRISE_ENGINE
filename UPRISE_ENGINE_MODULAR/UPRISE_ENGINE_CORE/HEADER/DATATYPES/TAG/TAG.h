#pragma once
#ifndef _TAG_
#define _TAG_
import std;
class Tag {
private:
	int id;
	std::string name;
public:
#pragma region constructor
	Tag() = default;
	Tag(int id, std::string name) :id(id), name(name) {};
#pragma endregion

	UPRISE_CORE_API __inline std::string& Name() { return name; }
	UPRISE_CORE_API __inline int ID() { return id; }
};
#endif // !1
