#include "CORE/BEHAVIOUR/BEHAVIOUR.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {
    class Transform :public CORE::Behaviour {
        // Inherited via Behaviour
        SharedRef<CORE::Object, true> Copy() override
        {
            return SharedRef<CORE::Object, true>();
        }
        SharedRef<CORE::Object, true> DeepCopy() override
        {
            return SharedRef<CORE::Object, true>();
        }
        void EditorWindow() override
        {
        }
        void Update() override
        {
        }
        void Awake() override
        {
        }
        void Start() override
        {
        }
    };
    class GameOject :public CORE::Object {
        // Inherited via Object
        SharedRef<CORE::Object, true> Copy() override
        {
            return SharedRef<CORE::Object, true>();
        }
        SharedRef<CORE::Object, true> DeepCopy() override
        {
            return SharedRef<CORE::Object, true>();
        }
        void OnDestroyInt(SharedRef<CORE::Object, true> obj) override
        {
        }
    };
	namespace CORE {

        class TestBehaviour : public Behaviour {

        public:
            TestBehaviour() : Behaviour() {}
            TestBehaviour(const TestBehaviour& other) : Behaviour(other) {}
            TestBehaviour(const TestBehaviour& other, bool) : Behaviour(other, true) {}
            TestBehaviour& operator=(const TestBehaviour& other) { Behaviour::operator=(other); return *this; }

            void SetGameObject(SharedRef<GameOject, true> GameObj) {
                this->gameObj = GameObj;
            }
            // Inherited via Behaviour
            SharedRef<CORE::Object, true> Copy() override
            {
                return CreateSharedRef<TestBehaviour,true>(TestBehaviour(*this));
            }
            SharedRef<CORE::Object, true> DeepCopy() override
            {
                return CreateSharedRef<TestBehaviour, true>(TestBehaviour(*this, true));
            }
            void EditorWindow() override
            {
            }
            void Update() override
            {
            }
            void Awake() override
            {
            }
            void Start() override
            {
            }
        };

		// Test BEHAVIOUR
        TEST(CreateBehaviour) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;

            ASSERT_CONDITION(testBehaviour);

        }
        TEST(BehaviourCopy) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;
            SharedRef<Behaviour, true> testBehaviourCopy = testBehaviour->Copy();
            ASSERT_CONDITION(testBehaviourCopy.IsSameValue(testBehaviour));
        }
        TEST(BehaviourDeepCopy) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;
            SharedRef<Behaviour, true> testBehaviourCopy = testBehaviour->DeepCopy();
            ASSERT_CONDITION(testBehaviourCopy.IsSameValue(testBehaviour));
        }
        TEST(BehaviourDestroy) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;
            testBehaviour.Destroy();
            ASSERT_CONDITION(!testBehaviour);
        }
        TEST(BehaviourEnabled) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;
            ASSERT_CONDITION(testBehaviour->Enabled());
        }
        TEST(BehaviourSetEnabled) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;
            testBehaviour->SetEnabled(false);
            ASSERT_CONDITION(!testBehaviour->Enabled());
        }
        TEST(BehaviourName) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;
            ASSERT_CONDITION(testBehaviour->Name() == "");
        }
        TEST(BehaviourSetName) {
            SharedRef ref = CreateSharedRef<TestBehaviour, true>();
            ref->SetEnabled(true);
            ref->SetGameObject(CreateSharedRef<GameOject, true>());
            SharedRef<Behaviour, true> testBehaviour = ref;
            testBehaviour->SetName("TestBehaviour");
            ASSERT_CONDITION(testBehaviour->Name() == "TestBehaviour");
        }

		

	}
}