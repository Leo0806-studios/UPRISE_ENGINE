#pragma once
#pragma once
#ifndef UE___M128_UTILLS_INTERNAL_
#define UE___M128_UTILLS_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <intrin.h>
#include <bit>
#include "CONCEPTS/SIZE/CONCEPT_SIZE_INTERNAL.h"
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    namespace CORE {
        class  M128_UTILLS {

        public:
            template<CONCEPTS::SizeLeq<sizeof(__m128)> T>
            static __m128 __vectorcall To__m128_U(const T __Val) {
                constexpr size_t __Size = sizeof(T);
                __m128 __Result;
                switch (__Size) {
                case 1: {
                    const unsigned int* const __Ptr =       reinterpret_cast<const unsigned int* const>(&__Val);
                    const char* const _Ptr_to_0 = reinterpret_cast<const char* const>(&__Ptr[0]);
                    const char __val0_real = _Ptr_to_0[0];
                    const unsigned int __val0_int = static_cast<unsigned int>(__val0_real);
                    const float __val0 = std::bit_cast<float>(__val0_int);
                    __Result = _mm_setr_ps(__val0, 0.0F, 0.0F, 0.0F);
                    break;
                }
                case 2: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const char* const _Ptr_to_0 = reinterpret_cast<const char* const>(&__Ptr[0]);
                    const char __val0_real = _Ptr_to_0[0];
                    const char __val0_real1 = _Ptr_to_0[1];
                    const unsigned int __val0_int = static_cast<unsigned int>(__val0_real);
                    __val0_int = __val0_int << 8;
                    __val0_int = __val0_int | static_cast<unsigned int>(__val0_real1);
                    const float __val0 = std::bit_cast<float>(__val0_int);
                    __Result = _mm_setr_ps(__val0, 0.0F, 0.0F, 0.0F);
                    break;
                }
                case 3: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const char* const _Ptr_to_0 = reinterpret_cast<const char* const>(&__Ptr[0]);
                    const char __val0_real = _Ptr_to_0[0];
                    const char __val0_real1 = _Ptr_to_0[1];
                    const char __val0_real2 = _Ptr_to_0[2];
                    const unsigned int __val0_int = static_cast<unsigned int>(__val0_real);
                    __val0_int = __val0_int << 8;
                    __val0_int = __val0_int | static_cast<unsigned int>(__val0_real1);
                    __val0_int = __val0_int << 8;
                    __val0_int = __val0_int | static_cast<unsigned int>(__val0_real2);
                    const float __val0 = std::bit_cast<float>(__val0_int);
                    __Result = _mm_setr_ps(__val0, 0.0F, 0.0F, 0.0F);
                    break;
                }
                case 4: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    __Result = _mm_setr_ps(__val0, 0.0F, 0.0F, 0.0F);
                    break;
                }
                case 5: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const char* const _Ptr_to_1 = reinterpret_cast<const char* const>(&__Ptr[1]);
                    const char __val1_real = _Ptr_to_1[0];
                    const unsigned int __val1_int = static_cast<unsigned int>(__val1_real);
                    const float __val1 = std::bit_cast<float>(__val1_int);
                    __Result = _mm_setr_ps(__val0, __val1, 0.0F, 0.0F);
                    break;
                }
                case 6: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const char* const _Ptr_to_1 = reinterpret_cast<const char* const>(&__Ptr[1]);
                    const char __val1_real = _Ptr_to_1[0];
                    const char __val1_real1 = _Ptr_to_1[1];
                    const unsigned int __val1_int = static_cast<unsigned int>(__val1_real);
                    __val1_int = __val1_int << 8;
                    __val1_int = __val1_int | static_cast<unsigned int>(__val1_real1);
                    const float __val1 = std::bit_cast<float>(__val1_int);
                    __Result = _mm_setr_ps(__val0, __val1, 0.0F, 0.0F);
                    break;
                }
                case 7: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const char* const _Ptr_to_1 = reinterpret_cast<const char* const>(&__Ptr[1]);
                    const char __val1_real = _Ptr_to_1[0];
                    const char __val1_real1 = _Ptr_to_1[1];
                    const char __val1_real2 = _Ptr_to_1[2];
                    const unsigned int __val1_int = static_cast<unsigned int>(__val1_real);
                    __val1_int = __val1_int << 8;
                    __val1_int = __val1_int | static_cast<unsigned int>(__val1_real1);
                    __val1_int = __val1_int << 8;
                    __val1_int = __val1_int | static_cast<unsigned int>(__val1_real2);
                    const float __val1 = std::bit_cast<float>(__val1_int);
                    __Result = _mm_setr_ps(__val0, __val1, 0.0F, 0.0F);
                    break;
                }
                case 8: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    __Result = _mm_setr_ps(__val0, __val1, 0.0F, 0.0F);
                    break;
                }
                case 9: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const char* const _Ptr_to_2 = reinterpret_cast<const char* const>(&__Ptr[2]);
                    const char __val2_real = _Ptr_to_2[0];
                    const unsigned int __val2_int = static_cast<unsigned int>(__val2_real);
                    const float __val2 = std::bit_cast<float>(__val2_int);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, 0.0F);
                    break;

                }
                case 10: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const char* const _Ptr_to_2 = reinterpret_cast<const char* const>(&__Ptr[2]);
                    const char __val2_real = _Ptr_to_2[0];
                    const char __val2_real1 = _Ptr_to_2[1];
                    const unsigned int __val2_int = static_cast<unsigned int>(__val2_real);
                    __val2_int = __val2_int << 8;
                    __val2_int = __val2_int | static_cast<unsigned int>(__val2_real1);
                    const float __val2 = std::bit_cast<float>(__val2_int);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, 0.0F);
                    break;
                }
                case 11: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const char* const _Ptr_to_2 = reinterpret_cast<const char* const>(&__Ptr[2]);
                    const char __val2_real = _Ptr_to_2[0];
                    const char __val2_real1 = _Ptr_to_2[1];
                    const char __val2_real2 = _Ptr_to_2[2];
                    const unsigned int __val2_int = static_cast<unsigned int>(__val2_real);
                    __val2_int = __val2_int << 8;
                    __val2_int = __val2_int | static_cast<unsigned int>(__val2_real1);
                    __val2_int = __val2_int << 8;
                    __val2_int = __val2_int | static_cast<unsigned int>(__val2_real2);
                    const float __val2 = std::bit_cast<float>(__val2_int);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, 0.0F);
                    break;
                }
                case 12: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const float __val2 = std::bit_cast<float>(__Ptr[2]);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, 0.0F);
                    break;
                }
                case 13: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const float __val2 = std::bit_cast<float>(__Ptr[2]);
                    const char* const _Ptr_to_3 = reinterpret_cast<const char* const>(&__Ptr[3]);
                    const char __val3_real = _Ptr_to_3[0];
                    const unsigned int __val3_int = static_cast<unsigned int>(__val3_real);
                    const float __val3 = std::bit_cast<float>(__val3_int);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, __val3);
                    break;
                }
                case 14: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const float __val2 = std::bit_cast<float>(__Ptr[2]);
                    const char* const _Ptr_to_3 = reinterpret_cast<const char* const>(&__Ptr[3]);
                    const char __val3_real = _Ptr_to_3[0];
                    const char __val3_real1 = _Ptr_to_3[1];
                    const unsigned int __val3_int = static_cast<unsigned int>(__val3_real);
                    __val3_int = __val3_int << 8;
                    __val3_int = __val3_int | static_cast<unsigned int>(__val3_real1);
                    const float __val3 = std::bit_cast<float>(__val3_int);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, __val3);
                    break;

                }
                case 15: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);
                    const unsigned int& Arr[3] = __Ptr;
                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const float __val2 = std::bit_cast<float>(__Ptr[2]);
                    const char* const _Ptr_to_3 = reinterpret_cast<const char* const>(&__Ptr[3]);
                    const char __val3_real = _Ptr_to_3[0];
                    const char __val3_real1 = _Ptr_to_3[1];
                    const char __val3_real2 = _Ptr_to_3[2];
                    const unsigned int __val3_int = static_cast<unsigned int>(__val3_real);
                    __val3_int = __val3_int << 8;
                    __val3_int = __val3_int | static_cast<unsigned int>(__val3_real1);
                    __val3_int = __val3_int << 8;
                    __val3_int = __val3_int | static_cast<unsigned int>(__val3_real2);
                    const float __val3 = std::bit_cast<float>(__val3_int);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, __val3);
                    break;
                }
                case 16: {
                    const unsigned int* const __Ptr = reinterpret_cast<const unsigned int* const>(&__Val);

                    const float __val0 = std::bit_cast<float>(__Ptr[0]);
                    const float __val1 = std::bit_cast<float>(__Ptr[1]);
                    const float __val2 = std::bit_cast<float>(__Ptr[2]);
                    const float __val3 = std::bit_cast<float>(__Ptr[3]);
                    __Result = _mm_setr_ps(__val0, __val1, __val2, __val3);

                    break;
                }

                default:
                {
                    __Result = _mm_setzero_ps();
                    break;
                }

                }
                return __Result;

            };
        };
    }
}


#endif