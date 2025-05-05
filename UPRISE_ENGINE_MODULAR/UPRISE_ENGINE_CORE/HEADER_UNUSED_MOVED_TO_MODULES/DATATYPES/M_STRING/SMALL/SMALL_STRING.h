#pragma once
#ifndef UE_SMALL_STRING
#define UE_SMALL_STRING
#ifndef CORE_MODULE_BUILD
import std;

#endif // !CORE_MODULE_BUILD
#include "cstring"
#include <intrin.h>


namespace UPRISE_ENGINE {
    namespace DO_NOT_USE_MANUALY___INTERNALS {
#pragma pack(push)
#pragma pack(4)
        union SmallString_Internals {
#pragma pack(4)

            struct
            {
                char* Data;
                unsigned int Capacity;
            } _impl;
#pragma pack(4)

            struct {
                char DataSSo[sizeof(_impl)];
            }_implSSO;
        };
#pragma pack(pop)

    }

    class UE_SIMD_ALIGN__M128 SmallString {

    private:
        DO_NOT_USE_MANUALY___INTERNALS::SmallString_Internals _internals;
        unsigned int Length;///includes null terminator in length
        __inline constexpr bool _fitsInSSO(const char*) = delete;
        __inline constexpr bool _fitsInSSO(unsigned int _input) const noexcept {
            return _input <= sizeof(this->_internals._implSSO.DataSSo);

        }
    public:
        SmallString()noexcept :_internals{ {0} } {}
        SmallString(const char* _string) {
            const size_t lengthOfInput = strlen(_string) + 1;
            const bool fitsinMaxSize = lengthOfInput <= std::numeric_limits<unsigned int>::max();
            if (!fitsinMaxSize)UE_UNLIKELY{
                throw std::runtime_error("String too long");
            }
                if (_fitsInSSO(static_cast<unsigned int>(lengthOfInput))) {

                    memcpy(&this->_internals._implSSO.DataSSo, _string, lengthOfInput);
                    this->Length = (lengthOfInput);
                }
                else {

                    this->_internals._impl.Data = new char[lengthOfInput];
                    memcpy(this->_internals._impl.Data, _string, lengthOfInput);
                    this->_internals._impl.Capacity = lengthOfInput;
                    Length = lengthOfInput;

                }


        }
        SmallString(const SmallString& other)noexcept {
            if (_fitsInSSO(other.Length)) {
                this->Length = other.Length;
                this->_internals._implSSO = other._internals._implSSO;
            }
            else {
                this->Length = other.Length;
                this->_internals._impl.Data = new char[Length];
                this->_internals._impl.Capacity = Length;
                memcpy(this->_internals._impl.Data, other._internals._impl.Data, Length);
            }
        }
        SmallString(SmallString&& other) {
            if (_fitsInSSO(other.Length)) {
                this->Length = other.Length;
                this->_internals._implSSO = other._internals._implSSO;
                other.Length = 0;
                other._internals._implSSO.DataSSo[0] = '\0';
            }
            else {
                this->Length = other.Length;
                this->_internals._impl = other._internals._impl;
                _mm_store_ps(std::bit_cast<float*>(&other), _mm_setzero_ps());
            }
        }
        SmallString(const std::string& other) {
            const size_t ohterlengt = other.length() + 1;
            const bool Fits = ohterlengt <= std::numeric_limits<unsigned int>::max();
            if (!Fits)UE_UNLIKELY{
                throw std::runtime_error("String too long");
            };
            if (_fitsInSSO(static_cast<unsigned int>(ohterlengt))) {
                this->Length = ohterlengt;
                memcpy(&this->_internals._implSSO.DataSSo, other.data(), ohterlengt);
            }
            else {
                Length = ohterlengt;
                this->_internals._impl.Data = new char[ohterlengt];
                memcpy(this->_internals._impl.Data, other.data(), ohterlengt);

            }

        }


    };
}



#endif
