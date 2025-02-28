#include "DATATYPES//LAYER/LAYER.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {
    TEST(LayerCreate) {
        Layer layer;
        ASSERT_CONDITION(layer.Name() == "");
        ASSERT_CONDITION(layer.ID() == -1);
    }
    TEST(LayerCreateWithName) {
        Layer layer(0, "test");
        ASSERT_CONDITION(layer.Name() == "test");
        ASSERT_CONDITION(layer.ID() == 0);
    }
    TEST(LayerSetName) {
        Layer layer;
        layer.Name() = "test";
        ASSERT_CONDITION(layer.Name() == "test");
    }
    TEST(LayerSetID) {
        Layer layer;
        layer.Name() = "test";
        layer.SetID(0);
        ASSERT_CONDITION(layer.ID() == 0);
    }


}