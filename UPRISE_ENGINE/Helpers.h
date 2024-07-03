#pragma once
#include "pch.h"
// From DXSampleHelper.h 

// Source: https://github.com/Microsoft/DirectX-Graphics-Samples


inline void ThrowIfFailed(HRESULT hr)

{


    if (FAILED(hr))


    {


        throw std::exception();


    }

}

using TypeInfoRef = std::reference_wrapper<const std::type_info>;

struct Hasher
{
    std::size_t operator()(TypeInfoRef code) const
    {
        return code.get().hash_code();
    }
};

struct EqualTo
{
    bool operator()(TypeInfoRef lhs, TypeInfoRef rhs) const
    {
        return lhs.get() == rhs.get();
    }
};