#include "CORE/CPUID/CPUID.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {
	namespace CORE {
        TEST(TestAVX) {
            //assert(CORE::InstructionSet::AVX() == false);
            ASSERT_CONDITION(CORE::InstructionSet::AVX() == true);
        }
		

	}
}