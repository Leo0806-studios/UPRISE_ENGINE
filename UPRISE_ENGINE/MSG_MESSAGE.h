#pragma once
#ifndef _MSG_MESSAGE_

#define _MSG_MESSAGE_

#include "pch.h"

namespace DATATYPES {

	

	struct Mesage {

	public :std::string messagestring;

		   short from;
		   short type;
		   short to;

	};

	struct  Urgent_Message
	{


	public :
		std::string messagestring;
		short from;
		short type;
		short to;
	};


	struct slow_Message {

	public:
		std::string messagestring;
		short from;
		short type;
		short to;


	};
}

#endif // !_MSG_MESSAGE_
