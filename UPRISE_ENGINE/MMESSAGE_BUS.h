#pragma once
#ifndef _MESSAGE_BUS_
#define _MESSAGE_BUS_
#include "pch.h"
#include "MODULE_IMPORTS.h"
#include "HeaderE/DATATYPES/D_DATATYPES.h"
using namespace std;

namespace MESSAGES {


	 class Message_Bus {

	public:

		bool Exists = false;
		static vector <DATATYPES::Mesage> messages;
		static vector <DATATYPES::slow_Message> slow_Messages;
		static vector <DATATYPES::Urgent_Message> Urgent_Messages;
		



	};
}

#endif // !_MESSAGE_BUS_
