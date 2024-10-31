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
