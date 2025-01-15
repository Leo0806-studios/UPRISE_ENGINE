#pragma once
#ifndef _UUID_
#define _UUID_
struct UUID {
private:
public:
	UUID() = default;
	~UUID(){}
    static UUID Create();
};
#endif // !_UUID_
