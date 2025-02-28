#include "DATATYPES/UUID/UUID.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
#include <Windows.h>

namespace UPRISE_ENGINE {
	namespace CORE {

		// Test UUID
        TEST(TestUUID_Uniqueness) {
            UUID uuid1 = UUID::Create();
            UUID uuid2 = UUID::Create();
            ASSERT_CONDITION(uuid1 != uuid2);

            //UUID WinUUid;
            //UUID uuid_cpy;
            
        }
		

	}
}