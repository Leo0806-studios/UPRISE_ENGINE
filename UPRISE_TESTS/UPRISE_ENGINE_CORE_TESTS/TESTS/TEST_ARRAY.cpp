#include "DATATYPES/ARRAY/ARRAY.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {

    TEST(ArrayHeapCreate) {
        Array<int, 10, heap> arr;
        ASSERT_CONDITION(arr.SoH == heap);
    }
    TEST(ArrayStackCreate) {
        Array<int, 10, stack> arr;
        ASSERT_CONDITION(arr.SoH == stack);
    }
    TEST(ArrayHeapOP_Brackets) {
        Array<int, 10, heap> arr;
        arr[0] = 1;
        ASSERT_CONDITION(arr[0] == 1);
    }
    TEST(ArrayHeapGet) {
        Array<int, 10, heap> arr;
        arr[0] = 1;
        ASSERT_CONDITION(arr.get<0>() == 1);
    }
    TEST(ArrayStackOP_Brackets) {
        Array<int, 10, stack> arr;
        arr[0] = 1;
        ASSERT_CONDITION(arr[0] == 1);
    }
    TEST(ArrayStackGet) {
        Array<int, 10, stack> arr;
        arr[0] = 1;
        ASSERT_CONDITION(arr.get<0>() == 1);
    }
    TEST(ArrayHeapCopy) {
        Array<int, 10, heap> arr;
        arr[0] = 1;
        Array<int, 10, heap> arr2 = arr;
        ASSERT_CONDITION(arr2[0] == 1);
    }
    TEST(ArrayStackCopy) {
        Array<int, 10, stack> arr;
        arr[0] = 1;
        Array<int, 10, stack> arr2 = arr;
        ASSERT_CONDITION(arr2[0] == 1);
    }
    TEST(ArrayHeapAssign) {
        Array<int, 10, heap> arr;
        arr[0] = 1;
        Array<int, 10, heap> arr2;
        arr2 = arr;
        ASSERT_CONDITION(arr2[0] == 1);
    }
    TEST(ArrayStackAssign) {
        Array<int, 10, stack> arr;
        arr[0] = 1;
        Array<int, 10, stack> arr2;
        arr2 = arr;
        ASSERT_CONDITION(arr2[0] == 1);
    }
    TEST(ArrayStackOP_Brackets_OutOfBounds) {
        Array<int, 10, stack> arr;
        ASSERT_EXCEPTION(arr[10] = 1, std::out_of_range);
    }
    TEST(ArrayHeapOP_Brackets_OutOfBounds) {
        Array<int, 10, heap> arr;
        ASSERT_EXCEPTION(arr[10] = 1, std::out_of_range);
    }
    TEST(ArrayHeapGet_OutOfBounds) {
        Array<int, 10, heap> arr;
        ASSERT_EXCEPTION(arr.get<10>(), std::out_of_range);
    }
    TEST(ArrayStackGet_OutOfBounds) {
        Array<int, 10, stack> arr;
        ASSERT_EXCEPTION(arr.get<10>(), std::out_of_range);
    }

}
