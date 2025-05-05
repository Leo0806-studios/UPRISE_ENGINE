#pragma once
#ifndef UE_ARRAY_INTERNAL_
#define UE_ARRAY_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <type_traits>
#include <stdexcept>


#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
#pragma warning(push)
#pragma warning(disable:4820)
    /// <summary>
    /// array type 
    /// stack or heap
    /// </summary>
    enum Array_Type { stack, heap };
    /// <summary>
    /// class wrapper for arrays
    /// provides a compile time way to create arrays on the stack or heap
    /// provides compile and runntime bounds checking
    /// provides compile and runntime index access
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="i"></typeparam>
    /// <typeparam name="t"></typeparam>
    template<class Type, int Size, Array_Type t>
    class UPRISE_CORE_API Array {
    private:
        /// <summary>
        /// the arry or pointer to array
        /// </summary>
        typename std::conditional<t == stack, Type[Size], Type*>::type data;
        /// <summary>
        /// lengt of array
        /// </summary>
        const long long size = Size;
    public:
        /// <summary>
        /// the type
        /// stack or heap
        /// </summary>
        const Array_Type SoH = t;
        /// <summary>
        /// consturctor that allocates the array on the heap if t==heap
        /// </summary>
        __inline Array() {
            if constexpr (t == heap) {
                data = new Type[Size];
            }
            else {

            }
        }
        __inline Array(const Array& other) {
            if constexpr (t == heap) {
                data = new Type[Size];
                for (size_t j = 0; j < Size; j++) {
                    data[j] = other.data[j];
                }
            }
            else {
                for (size_t j = 0; j < Size; j++) {
                    data[j] = other.data[j];
                }
            }
        }
        /// <summary>
        /// destructor that deletes the array if t==heap
        /// </summary>
        __inline ~Array() {
            if constexpr (t == heap) {
                delete[]data;
            }
            else {

            }
        }

        Array& operator=(const Array& other) {
            if constexpr (t == heap) {
                data = new Type[Size];
                for (size_t j = 0; j < Size; j++) {
                    data[j] = other.data[j];
                }
            }
            else {
                for (size_t j = 0; j < Size; j++) {
                    data[j] = other.data[j];
                }
            }
            return *this;
        }
        /// <summary>
        /// runtime index access with runtime bounds checking
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        __inline  Type& operator[](const long long index) {
            if (index >= size && index >= 0) {
                throw std::out_of_range("Index out of bounds");
            }
            if constexpr (t == heap) {
                return data[index];

            }
            else {
                return data[index];

            }

        }
        /// <summary>
        /// compile time index access with compile time bounds checking
        /// apparaenty this is not working. will make it a runtime check
        /// </summary>
        /// <typeparam name="ind"></typeparam>
        /// <returns></returns>
        template<long long ind>
        __inline constexpr Type& get() {
            if (ind >= size && ind >= 0) {
                //static_assert(ind>=size&&ind>=0,"Array out of bounds");
                throw std::out_of_range("Index out of bounds");
            }
            if constexpr (t == heap) {
                return data[ind];

            }
            else {
                return data[ind];

            }

        }

    };
#pragma warning(pop)
}

#endif