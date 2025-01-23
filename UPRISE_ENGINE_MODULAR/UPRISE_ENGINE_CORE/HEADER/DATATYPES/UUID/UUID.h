// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
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
