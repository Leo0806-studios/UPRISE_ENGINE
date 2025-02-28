#include "DATATYPES/VECTOR/VECTOR2/VECTOR2.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {
    TEST(Vector2Addition) {
        Vector2 a(1, 2);
        Vector2 b(3, 4);
        Vector2 c = a + b;
        ASSERT_FLOAT_EQ(c.x(), 4, 0.0001);
        ASSERT_FLOAT_EQ(c.y(), 6, 0.0001);
    }
    TEST(Vector2Subtraction) {
        Vector2 a(1, 2);
        Vector2 b(3, 4);
        Vector2 c = a - b;
        ASSERT_FLOAT_EQ(c.x(), ( - 2), 0.0001);
        ASSERT_FLOAT_EQ(c.y(), ( - 2), 0.0001);
    }
    TEST(Vector2Multiplication) {
        Vector2 a(1, 2);
        Vector2 b(3, 4);
        Vector2 c = a * b;
        ASSERT_FLOAT_EQ(c.x(), 3, 0.0001);
        ASSERT_FLOAT_EQ(c.y(), 8, 0.0001);
    }
    TEST(Vector2Division) {
        Vector2 a(1, 2);
        Vector2 b(3, 4);
        Vector2 c = a / b;
        ASSERT_FLOAT_EQ(c.x(), 0.333333, 0.0001);
        ASSERT_FLOAT_EQ(c.y(), 0.5, 0.0001);
    }
    TEST(Vector2CrossProduct) {
        Vector2 a(1, 2);
        Vector2 b(3, 4);
        Vector2 c = a ^ b;
        ASSERT_FLOAT_EQ(c.x(), 0, 0.0001);
        ASSERT_FLOAT_EQ(c.y(), 0, 0.0001);
    }
    TEST(Vector2Setter) {
        Vector2 a(1, 2);
        a.x(3);
        a.y(4);
        ASSERT_FLOAT_EQ(a.x(), 3, 0.0001);
        ASSERT_FLOAT_EQ(a.y(), 4, 0.0001);
    }
    TEST(Vector2Setter2) {
        Vector2 a(1, 2);
        a.xx(3);
        a.yy(4);
        ASSERT_FLOAT_EQ(a.xx(), 3, 0.0001);
        ASSERT_FLOAT_EQ(a.yy(), 4, 0.0001);
    }   

}