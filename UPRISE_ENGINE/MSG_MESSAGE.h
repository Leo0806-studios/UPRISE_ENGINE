#pragma once

#include "string"


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