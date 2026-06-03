#pragma once
#include <cassert>
#include "UTILITIES.h"
#include <array>
#include <MACROS.h>
namespace UPRISE_ENGINE::DATATYPES {

    template <typename T,size_t dims>
    class Vector {
        std::array<T, dims> data;
    public:
        T& operator[](size_t index) {
            ASSERT_MSG(index < dims, "index out of range");
            return data[index];
        }
        const T& at(size_t index) const noexcept{
            ASSERT_MSG(index < dims, "index out of range");
            return data[index];
        }
    };
}

