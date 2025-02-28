#include "DATATYPES//QUTERION/QUATERION.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {

    TEST(QauterionConstrucDefault) {
        Quaternion quat{};
        ASSERT_CONDITION(quat.w() == 1);
        ASSERT_CONDITION(quat.x() == 0);
        ASSERT_CONDITION(quat.y() == 0);
        ASSERT_CONDITION(quat.z() == 0);
    }
    TEST(QauterionConstrucValues) {
        Quaternion quat{ 1,2,3,4 };
        ASSERT_CONDITION(quat.w() == 1);
        ASSERT_CONDITION(quat.x() == 2);
        ASSERT_CONDITION(quat.y() == 3);
        ASSERT_CONDITION(quat.z() == 4);
    }
    TEST(QauterionFromEulerAngle) {
        Vector3 vec{ 1,2,3 };
        Quaternion quat{}; 
        quat = Quaternion::FromEulerAngles(vec);
   
        ASSERT_CONDITION(quat.w() == 0);
        ASSERT_CONDITION(quat.x() == 1);
        ASSERT_CONDITION(quat.y() == 2);
        ASSERT_CONDITION(quat.z() == 3);
    }
    TEST(QauterionRotate) {
        Quaternion quat{ 1,2,3,4 };
        Vector3 vec{ 1,2,3 };
        Vector3 result = quat.Rotate(vec);
        ASSERT_CONDITION(result.x() == 1);
        ASSERT_CONDITION(result.y() == 2);
        ASSERT_CONDITION(result.z() == 3);
    }
    TEST(QauterionToMat4) {
        Quaternion quat{ 1,2,3,4 };
        glm::mat4 mat = quat.ToMat4();
        throw std::runtime_error("Not implemented" + std::string(
            std::string(__FUNCSIG__)
            + std::string(" ")
            + std::string(__FILE__)
            + std::string(" ")
            + std::to_string(__LINE__)));
    }
    TEST(QuaterionOP_Mul_Quat) {
        Quaternion quat{ 1,2,3,4 };
        Quaternion quat2{ 1,2,3,4 };
        Quaternion result = quat * quat2;
        ASSERT_CONDITION(result.w() == -28);
        ASSERT_CONDITION(result.x() == 4);
        ASSERT_CONDITION(result.y() == 6);
        ASSERT_CONDITION(result.z() == 8);
    }
}