// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _ARRAY_
#define _ARRAY_
import std;

namespace UPRISE_ENGINE {/// <summary>
/// array type 
/// stack or heap
/// </summary>
    enum type { stack, heap };
    /// <summary>
    /// class wrapper for arrays
    /// provides a compile time way to create arrays on the stack or heap
    /// provides compile and runntime bounds checking
    /// provides compile and runntime index access
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="i"></typeparam>
    /// <typeparam name="t"></typeparam>
    template<class T, int i, type t>
    class UPRISE_CORE_API Array {
    private:
        /// <summary>
        /// the arry or pointer to array
        /// </summary>
        typename std::conditional<t == stack, T[i], T*>::type data;
        /// <summary>
        /// lengt of array
        /// </summary>
        long long size = i;
    public:
        /// <summary>
        /// the type
        /// stack or heap
        /// </summary>
        const type SoH = t;
        /// <summary>
        /// consturctor that allocates the array on the heap if t==heap
        /// </summary>
        __inline Array() {
            if constexpr (t == heap) {
                data = new T[i];
            }
            else {

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
        /// <summary>
        /// runtime index access with runtime bounds checking
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        __inline const T& operator[](const long long index) {
            if constexpr (index > size || index < 0) {
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
        /// </summary>
        /// <typeparam name="ind"></typeparam>
        /// <returns></returns>
        template<long long ind>
        __inline const T& get() {
            if constexpr (ind > size || ind < 0) {
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
}


#endif // !_ARRAY
