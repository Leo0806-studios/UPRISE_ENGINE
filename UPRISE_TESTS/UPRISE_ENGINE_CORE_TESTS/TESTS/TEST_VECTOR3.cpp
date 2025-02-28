#include "DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"

namespace UPRISE_ENGINE {
    TEST(Vector3AddWithVector3) {
        Vector3 a(1.0F, 2.0F, 3.0F);
        Vector3 b(4.0F, 5.0F, 6.0F);
        Vector3 c = a + b;
        ASSERT_CONDITION(c.x() == 5.0F);
        ASSERT_CONDITION(c.y() == 7.0F);
        ASSERT_CONDITION(c.z() == 9.0F);
    }

    TEST(Vector3Addwith__m128) {
        Vector3 a(1.0F, 2.0F, 3.0F);
        __m128 b = _mm_setr_ps(4.0F, 5.0F, 6.0F, 0.0F);
        Vector3 c = a + b;
        ASSERT_CONDITION(c.x() == 5.0F);
        ASSERT_CONDITION(c.y() == 7.0F);
        ASSERT_CONDITION(c.z() == 9.0F);
    }

    TEST(Vector3SubWithVector3) {
        Vector3 a(4.0F, 5.0F, 6.0F);
        Vector3 b(1.0F, 2.0F, 3.0F);
        Vector3 c = a - b;
        ASSERT_CONDITION(c.x() == 3.0F);
        ASSERT_CONDITION(c.y() == 3.0F);
        ASSERT_CONDITION(c.z() == 3.0F);
    }

    TEST(Vector3SubWith__m128) {
        Vector3 a(4.0F, 5.0F, 6.0F);
        __m128 b = _mm_setr_ps(1.0F, 2.0F, 3.0F, 0.0F);
        Vector3 c = a - b;
        ASSERT_CONDITION(c.x() == 3.0F);
        ASSERT_CONDITION(c.y() == 3.0F);
        ASSERT_CONDITION(c.z() == 3.0F);
    }

    TEST(Vector3MulWithVector3) {
        Vector3 a(1.0F, 2.0F, 3.0F);
        Vector3 b(4.0F, 5.0F, 6.0F);
        Vector3 c = a * b;
        ASSERT_CONDITION(c.x() == 4.0F);
        ASSERT_CONDITION(c.y() == 10.0F);
        ASSERT_CONDITION(c.z() == 18.0F);
    }

    TEST(Vector3MulWith__m128) {
        Vector3 a(1.0F, 2.0F, 3.0F);
        __m128 b = _mm_setr_ps(4.0F, 5.0F, 6.0F, 0.0F);
        Vector3 c = a * b;
        ASSERT_CONDITION(c.x() == 4.0F);
        ASSERT_CONDITION(c.y() == 10.0F);
        ASSERT_CONDITION(c.z() == 18.0F);
    }

    TEST(Vector3MulWithFloat) {
        Vector3 a(1.0F, 2.0F, 3.0F);
        float f = 2.0F;
        Vector3 c = a * f;
        ASSERT_CONDITION(c.x() == 2.0F);
        ASSERT_CONDITION(c.y() == 4.0F);
        ASSERT_CONDITION(c.z() == 6.0F);
    }

    TEST(Vector3DivWithVector3) {
        Vector3 a(4.0F, 6.0F, 8.0F);
        Vector3 b(2.0F, 3.0F, 4.0F);
        Vector3 c = a / b;
        ASSERT_CONDITION(c.x() == 2.0F);
        ASSERT_CONDITION(c.y() == 2.0F);
        ASSERT_CONDITION(c.z() == 2.0F);
    }

    TEST(Vector3DivWith__m128) {
        Vector3 a(4.0F, 6.0F, 8.0F);
        __m128 b = _mm_setr_ps(2.0F, 3.0F, 4.0F, 0.0F);
        Vector3 c = a / b;
        ASSERT_FLOAT_EQ(c.x(), 2.0F,0.00000001F);
        ASSERT_FLOAT_EQ(c.y(), 2.0F, 0.00000001F);
        ASSERT_FLOAT_EQ(c.z(), 2.0F, 0.00000001F);

    }

    TEST(Vector3DivWithFloat) {
        Vector3 a(4.0F, 6.0F, 8.0F);
        float f = 2.0F;
        Vector3 c = a / f;
        ASSERT_CONDITION(c.x() == 2.0F);
        ASSERT_CONDITION(c.y() == 3.0F);
        ASSERT_CONDITION(c.z() == 4.0F);
    }

    TEST(Vector3CrossProduct) {
        Vector3 a(1.0F, 0.0F, 0.0F);
        Vector3 b(0.0F, 1.0F, 0.0F);
        Vector3 c = a ^ b;
        ASSERT_CONDITION(c.x() == 0.0F);
        ASSERT_CONDITION(c.y() == 0.0F);
        ASSERT_CONDITION(c.z() == 1.0F);
    }

    TEST(Vector3Magnitude) {
        Vector3 a(3.0F, 4.0F, 0.0F);
        float magnitude = a.Magnitude();
        ASSERT_CONDITION(magnitude == 5.0F);
    }

    TEST(Vector3Normalized) {
        Vector3 a(3.0F, 4.0F, 0.0F);
        Vector3 b = a.Normalized();
        ASSERT_CONDITION(b.x() == 0.6F);
        ASSERT_CONDITION(b.y() == 0.8F);
        ASSERT_CONDITION(b.z() == 0.0F);
    }

    TEST(Vector3DotProduct) {
        Vector3 a(1.0F, 2.0F, 3.0F);
        Vector3 b(4.0F, 5.0F, 6.0F);
        float dotProduct = a.Point(b);
        ASSERT_CONDITION(dotProduct == 32.0F);
    }

}