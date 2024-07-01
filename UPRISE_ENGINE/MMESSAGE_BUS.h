#pragma once

#include "vector"
#include "DATATYPES.h"
//using namespace DATATYPES;
#include "MSG_MESSAGE.h"
using namespace std;

namespace MESSAGES {


	class Message_Bus {

	public:
		vector <DATATYPES::Mesage> messages;
		 vector <DATATYPES::slow_Message> slow_Messages;
		 vector <DATATYPES::Urgent_Message> Urgent_Messages;



	};
}