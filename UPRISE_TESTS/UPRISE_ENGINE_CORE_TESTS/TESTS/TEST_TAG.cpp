#include "DATATYPES/TAG/TAG.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {
    TEST(TagConstrucDefault) {
        Tag tag{};
        ASSERT_CONDITION(tag.ID() == 0);
        ASSERT_CONDITION(tag.Name() == "");
    }
    TEST(TagConstrucValues) {
        Tag tag( 1,"test" );
        ASSERT_CONDITION(tag.ID() == 1);
        ASSERT_CONDITION(tag.Name() == "test");
    }
    TEST(TagSetName) {
        Tag tag{};
        tag.Name() = "test";
        ASSERT_CONDITION(tag.Name() == "test");
    }
    TEST(TagSetID) {
        Tag tag{};
        tag.SetID(1);
        ASSERT_CONDITION(tag.ID() == 1);
    }
    TEST(TagSetIDAndName) {
        Tag tag{};
        tag.SetID(1);
        tag.Name() = "test";
        ASSERT_CONDITION(tag.ID() == 1);
        ASSERT_CONDITION(tag.Name() == "test");
    }


}