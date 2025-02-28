#include "DATATYPES/VECTOR/VECTOR4/VECTOR4.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {
    TEST(Vector4Addition) {
        Vector4 a(1, 2, 3, 4);
        Vector4 b(5, 6, 7, 8);
        Vector4 c = a + b;
        ASSERT_FLOAT_EQ(c.x(), 6, 0.0001);
        ASSERT_FLOAT_EQ(c.y(), 8, 0.0001);
        ASSERT_FLOAT_EQ(c.z(), 10, 0.0001);
        ASSERT_FLOAT_EQ(c.w(), 12, 0.0001);
    }
    TEST(Vector4Subtraction) {
        Vector4 a(1, 2, 3, 4);
        Vector4 b(5, 6, 7, 8);
        Vector4 c = a - b;
        ASSERT_FLOAT_EQ(c.x(), (-4), 0.0001);
        ASSERT_FLOAT_EQ(c.y(), (-4), 0.0001);
        ASSERT_FLOAT_EQ(c.z(), (-4), 0.0001);
        ASSERT_FLOAT_EQ(c.w(), (-4), 0.0001);
    }
    TEST(Vector4Multiplication) {
        Vector4 a(1, 2, 3, 4);
        Vector4 b(5, 6, 7, 8);
        Vector4 c = a * b;
        ASSERT_FLOAT_EQ(c.x(), 5, 0.0001);
        ASSERT_FLOAT_EQ(c.y(), 12, 0.0001);
        ASSERT_FLOAT_EQ(c.z(), 21, 0.0001);
        ASSERT_FLOAT_EQ(c.w(), 32, 0.0001);
    }
    TEST(Vector4Division) {
        Vector4 a(1, 2, 3, 4);
        Vector4 b(5, 6, 7, 8);
        Vector4 c = a / b;
        ASSERT_FLOAT_EQ(c.x(), 0.2, 0.0001);
        ASSERT_FLOAT_EQ(c.y(), 0.333333, 0.0001);
        ASSERT_FLOAT_EQ(c.z(), 0.428571, 0.0001);
        ASSERT_FLOAT_EQ(c.w(), 0.5, 0.0001);
    }
    TEST(Vector4Setter) {
        Vector4 a(1, 2, 3, 4);
        a.x(5);
        a.y(6);
        a.z(7);
        a.w(8);
        ASSERT_FLOAT_EQ(a.x(), 5, 0.0001);
        ASSERT_FLOAT_EQ(a.y(), 6, 0.0001);
        ASSERT_FLOAT_EQ(a.z(), 7, 0.0001);
        ASSERT_FLOAT_EQ(a.w(), 8, 0.0001);
    }

}