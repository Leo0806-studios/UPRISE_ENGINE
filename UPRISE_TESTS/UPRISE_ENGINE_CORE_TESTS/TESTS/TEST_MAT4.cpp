#include "DATATYPES/MAT4/Mat4.h"
#include "TEST_FRAMEWORK_MAIN/TEST_FRAMEWORK_MAIN.h"
namespace UPRISE_ENGINE {

    TEST(Mat4ConstrucDefault) {
        Mat4 mat{};
        ASSERT_CONDITION(mat(0, 0) == 1);
        ASSERT_CONDITION(mat(0, 1) == 0);
        ASSERT_CONDITION(mat(0, 2) == 0);
        ASSERT_CONDITION(mat(0, 3) == 0);
        ASSERT_CONDITION(mat(1, 0) == 0);
        ASSERT_CONDITION(mat(1, 1) == 1);
        ASSERT_CONDITION(mat(1, 2) == 0);
        ASSERT_CONDITION(mat(1, 3) == 0);
        ASSERT_CONDITION(mat(2, 0) == 0);
        ASSERT_CONDITION(mat(2, 1) == 0);
        ASSERT_CONDITION(mat(2, 2) == 1);
        ASSERT_CONDITION(mat(2, 3) == 0);
        ASSERT_CONDITION(mat(3, 0) == 0);
        ASSERT_CONDITION(mat(3, 1) == 0);
        ASSERT_CONDITION(mat(3, 2) == 0);
        ASSERT_CONDITION(mat(3, 3) == 1);


    }
    TEST(Mat4ConstrucDiagonal) {
        Mat4 mat{ 2.0F };
        ASSERT_CONDITION(mat(0, 0) == 2);
        ASSERT_CONDITION(mat(0, 1) == 0);
        ASSERT_CONDITION(mat(0, 2) == 0);
        ASSERT_CONDITION(mat(0, 3) == 0);
        ASSERT_CONDITION(mat(1, 0) == 0);
        ASSERT_CONDITION(mat(1, 1) == 2);
        ASSERT_CONDITION(mat(1, 2) == 0);
        ASSERT_CONDITION(mat(1, 3) == 0);
        ASSERT_CONDITION(mat(2, 0) == 0);
        ASSERT_CONDITION(mat(2, 1) == 0);
        ASSERT_CONDITION(mat(2, 2) == 2);
        ASSERT_CONDITION(mat(2, 3) == 0);
        ASSERT_CONDITION(mat(3, 0) == 0);
        ASSERT_CONDITION(mat(3, 1) == 0);
        ASSERT_CONDITION(mat(3, 2) == 0);
        ASSERT_CONDITION(mat(3, 3) == 2);
    }
    TEST(Mat4ConstrucQuaterion) {
        Quaternion quat{ 1,2,3,4 };
        Mat4 mat{ quat };

        throw std::runtime_error("Not implemented" + std::string(
            std::string(__FUNCSIG__) 
            + std::string(" ")
            + std::string(__FILE__) 
            + std::string(" ") 
            + std::to_string(__LINE__)));
    }
    TEST(Mat4LookAt) {
        Vector3 eye{ 1,2,3 };
        Vector3 center{ 4,5,6 };
        Vector3 up{ 7,8,9 };
        Mat4 mat = Mat4::Look_At(eye, center, up);
        glm::mat4 glmMat = Mat4::Look_At_GLM(eye, center, up);
        glm::mat4 conv = mat;
        ASSERT_FLOAT_EQ(conv[0][0], glmMat[0][0], 0.0001F);
        ASSERT_FLOAT_EQ(conv[0][1], glmMat[0][1], 0.0001F);
        ASSERT_FLOAT_EQ(conv[0][2], glmMat[0][2], 0.0001F);
        ASSERT_FLOAT_EQ(conv[0][3], glmMat[0][3], 0.0001F);
        ASSERT_FLOAT_EQ(conv[1][0], glmMat[1][0], 0.0001F);
        ASSERT_FLOAT_EQ(conv[1][1], glmMat[1][1], 0.0001F);
        ASSERT_FLOAT_EQ(conv[1][2], glmMat[1][2], 0.0001F);
        ASSERT_FLOAT_EQ(conv[1][3], glmMat[1][3], 0.0001F);
        ASSERT_FLOAT_EQ(conv[2][0], glmMat[2][0], 0.0001F);
        ASSERT_FLOAT_EQ(conv[2][1], glmMat[2][1], 0.0001F);
        ASSERT_FLOAT_EQ(conv[2][2], glmMat[2][2], 0.0001F);
        ASSERT_FLOAT_EQ(conv[2][3], glmMat[2][3], 0.0001F);
        ASSERT_FLOAT_EQ(conv[3][0], glmMat[3][0], 0.0001F);
            
        ASSERT_FLOAT_EQ(conv[3][1], glmMat[3][1], 0.0001F);
        ASSERT_FLOAT_EQ(conv[3][2], glmMat[3][2], 0.0001F);
        ASSERT_FLOAT_EQ(conv[3][3], glmMat[3][3], 0.0001F);

    }
    TEST(Mat4ToGlmMat) {
        Mat4 mat{ 1.0F };
        glm::mat4 glmMat = mat.ToMat4glm();
        glm::mat4 glmMat2{ 1 };
        ASSERT_CONDITION(glmMat == glmMat2);
        Mat4 mat2{ 2.0F };
        glmMat = mat2.ToMat4glm();
        glmMat2 = glm::mat4{ 2 };
        ASSERT_CONDITION(glmMat == glmMat2);
        Mat4 mat3{ 3.0F };
        glmMat = mat3.ToMat4glm();
        glmMat2 = glm::mat4{ 3 };
        ASSERT_CONDITION(glmMat == glmMat2);
        Mat4 mat4(4.2F);
        glmMat = mat4.ToMat4glm();
        glmMat2 = glm::mat4{ 4.2F };
        ASSERT_CONDITION(glmMat == glmMat2);
    }
    TEST(Mat4Perspective) {
        Mat4 mat = Mat4::Perspective(90, 1, 0.1F, 100.0F);
        glm::mat4 glmMat = glm::perspective(90.0F, 1.0F, 0.1F, 100.0F);
        glm::mat4 conv = mat;
        ASSERT_CONDITION(conv == glmMat);
    }
    TEST(Mat4OPGlmmat4) {
        Mat4 mat{ 1.0F };
        glm::mat4 glmMat = mat;
        glm::mat4 glmMat2{ 1 };
        ASSERT_CONDITION(glmMat == glmMat2);
        Mat4 mat2{ 2.0F };
        glmMat = mat2;
        glmMat2 = glm::mat4{ 2 };
        ASSERT_CONDITION(glmMat == glmMat2);
        Mat4 mat3{ 3.0F };
        glmMat = mat3;
        glmMat2 = glm::mat4{ 3 };
        ASSERT_CONDITION(glmMat == glmMat2);
        Mat4 mat4(4.2F);
        glmMat = mat4;
        glmMat2 = glm::mat4{ 4.2F };
        ASSERT_CONDITION(glmMat == glmMat2);
    }
    
}