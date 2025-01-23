// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _Error_
#define _Error_
enum ErrorCode {
	LowMemory,
	NoMatchinngComponentFoud,
};
class Error {
private:
	ErrorCode code;
	
public:
	/// <summary>
	/// consturctor
	/// </summary>
	Error() = default;
	/// <summary>
	/// constructor with errorcode
	/// </summary>
/// <param name="errorCode"></param>
	Error(ErrorCode code);
	~Error(){}
};
#endif // !_Error_
