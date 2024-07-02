#pragma once

#include "vector"
#include "DATATYPES.h"
//using namespace DATATYPES;
#include "MSG_MESSAGE.h"
using namespace std;

namespace MESSAGES {


	static class Message_Bus {

	public:

		bool Exists = false;
		static vector <DATATYPES::Mesage> messages;
		static vector <DATATYPES::slow_Message> slow_Messages;
		static vector <DATATYPES::Urgent_Message> Urgent_Messages;



	};
}