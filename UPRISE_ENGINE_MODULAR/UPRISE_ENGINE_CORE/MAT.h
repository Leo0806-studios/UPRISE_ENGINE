#pragma once
#include <ANOTATIONS.h>
#include "UTILITIES.h"
#include <array>
namespace UPRISE_ENGINE::DATATYPES {
    template<typename T, size_t N>
    class Matrix {
        std::array<std::array<T, N>, N> Data;
    public:
        NODISCARD T& operator[](size_t x, size_t y) {
            ASSERT_MSG(x < N && y < N, "index out of range");
            return Data[x][y];
        }
        NODISCARD const T& at(size_t x, size_t y) const {
            ASSERT_MSG(x < N && y < N, "index out of range");
            return Data[x][y];
        }
        void PerformOperation(auto operation) {
            for (auto& row : Data) {
                for (auto& element : row) {
                    operation(element);
                }
            }
        }
    };

}