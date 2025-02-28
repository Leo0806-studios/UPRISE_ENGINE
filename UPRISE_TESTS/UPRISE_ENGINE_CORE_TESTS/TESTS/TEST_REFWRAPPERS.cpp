#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
import REF_WRAPPER;
#pragma warning (disable:4820)
namespace UPRISE_ENGINE {
    class Foo {
    public:
        Foo() {
            std::cout << "Foo created\n";
        }
        int i = 0;

        virtual SharedRef<Foo,true> Copy() = 0;
       virtual ~Foo() {
            std::cout << "Foo destroyed\n";
        }
       virtual bool IsSameValue(const Foo& other) {
           return this->i == other.i;
       }
       virtual bool operator==(const Foo& other) {
           return this->i==other.i;
       }
    };
    class Bar : public Foo {
    public:

        Bar() {
            std::cout << "Bar created\n";
        }
        ~Bar() {
            std::cout << "Bar destroyed\n";
        }
        long long l = 0;

        // Inherited via Foo
        SharedRef<Foo, true> Copy() override
        {
            return CreateSharedRef<Bar, true>(*this);
        }

        bool operator==(const Foo& other) override {
            Bar& otherBar = *static_cast<Bar*>(const_cast<Foo*>(&other));
            return Foo::operator==(other)&&this->l==otherBar.l;
        }
    };
    class Baz {
    public:
        int i = 0;
        bool operator==(const Baz& other) const noexcept{
            return this->i == other.i;
        }
    };

    TEST(CreateSharedRef_Default_NonPolymorphic) {
        SharedRef<Baz, true> ref = CreateSharedRef<Baz,true>();
        ASSERT_CONDITION(ref->i==0);
    }
    TEST(CreateSharedRef_Copy_NonPolymorphic) {
        Baz baz;
        baz.i = 5;
        SharedRef<Baz, true> ref = CreateSharedRef<Baz, true>(baz);

        ASSERT_CONDITION(ref->i==5);
        ASSERT_CONDITION((*ref.Get()) == baz);

    }
    TEST(CreateSharedRef_RValue_NonPolymorphic) {
        SharedRef<Baz, true> ref = CreateSharedRef<Baz, true>(Baz{5});
        ASSERT_CONDITION(ref->i == 5);
        

    }
    TEST(CreateSharedRef_Move_NonPolymorphic) {
        Baz baz;
        baz.i = 5;
        SharedRef<Baz, true> ref = CreateSharedRef<Baz, true>(std::move(baz));
        ASSERT_CONDITION(ref->i == 5);
        ASSERT_CONDITION((*ref.Get()) == baz);
    }
    TEST(CreateSharedRef_Default_Polymorphic_Base) {
        SharedRef<Foo, true> ref = CreateSharedRef<Foo, true>();
        ASSERT_CONDITION(ref.Get()==nullptr);
    }
    TEST(CreateSharedRef_Copy_Polymorphic_Derived) {
        Bar bar;
        bar.i = 5;
        SharedRef<Foo, true> ref = CreateSharedRef<Bar, true>(bar);
        ASSERT_CONDITION(ref->i == 5);
        ASSERT_CONDITION((*static_cast<Bar*>(ref.Get())) .operator==( bar));
    }
    TEST(CreateOwnedRef_Default_NonPolymorphic) {
        OwnedRef<Baz> ref = CreateOwnedRef<Baz>();
        ASSERT_CONDITION(ref);
    }
    TEST(CreateOwnedRef_Copy_NonPolymorphic) {
        Baz baz;
        baz.i = 5;
        OwnedRef<Baz> ref = CreateOwnedRef<Baz>(baz);
        ASSERT_CONDITION(ref->i == 5);
        ASSERT_CONDITION((*ref.Get()) == baz);
    }
    
}