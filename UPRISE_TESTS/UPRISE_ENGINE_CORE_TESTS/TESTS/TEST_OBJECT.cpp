#include "CORE/OBJECT/OBJECT.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {
	namespace CORE {
        class TestObject:public CORE::Object {
            // Inherited via Object
            void OnDestroyInt(SharedRef<CORE::Object, true> obj) override
            {
                obj.Destroy();
            }
            SharedRef<CORE::Object, true> Copy() override
            {
                SharedRef ref = CreateSharedRef<TestObject, true>(TestObject());
                return ref;
            }
            SharedRef<CORE::Object, true> DeepCopy() override
            {
                SharedRef ref = CreateSharedRef<TestObject, true>(TestObject());
                    return ref;
            }
        };
        TEST(CreateObj_Default) {
            SharedRef ref = CreateSharedRef<TestObject, true>();
            SharedRef<Object, true> refobj = ref;
            ASSERT_CONDITION(refobj);
        }
        TEST(CopyObject) {
            SharedRef<Object,true> ref1 = CreateSharedRef<TestObject, true>();
            SharedRef<Object, true> ref2 = ref1->Copy();
            ASSERT_CONDITION(ref2.IsSameValue(ref1));



        }
        TEST(DeepCopyObject) {

        }
        TEST(DestroyObject) {
            SharedRef<Object, true> ref = CreateSharedRef<TestObject, true>();
            ASSERT_CONDITION(ref);
            Object::Destroy(ref);
            ASSERT_CONDITION(!ref);
        }
        TEST(ObjectGeTName) {
            SharedRef<Object, true> ref = CreateSharedRef<TestObject, true>();
            ASSERT_CONDITION(ref->Name() == std::string(""));
        }
        TEST(ObjectSetNAme) {
            SharedRef < Object, true > ref= CreateSharedRef<TestObject, true>();
            ref->SetName("TestName");
            ASSERT_CONDITION(ref->Name() == "TestName");
        }
		// Test TEST_OBJECT
		

	}
}