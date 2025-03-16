#pragma once
#ifndef UE_SMALL_STRING
#define UE_SMALL_STRING
#ifndef CORE_MODULE_BUILD
import std;

#endif // !CORE_MODULE_BUILD
#include "cstring"
namespace UPRISE_ENGINE {
    class SmallString {

    private:
        unsigned int Length;
        unsigned int Capacity;
        union {
        public:
            char* Data;
            char DataSSO[sizeof(char*)];
        };
    public:
        SmallString()noexcept :Length(0), Capacity(0), Data(nullptr) {}
        __inline SmallString(const char* chars) : Data(nullptr)
        {
            rsize_t length = strlen(chars);
            if (length >= static_cast<size_t>(std::numeric_limits<unsigned int>::max()))UE_UNLIKELY{
                std::string errorout = "string too long!! max allowed size for SmallString is: ";
            errorout += std::to_string(static_cast<size_t>(std::numeric_limits<unsigned int>::max()));
            errorout += " but got: ";
            errorout += std::to_string(length);
                throw std::runtime_error(errorout);
            }
            Length = static_cast<unsigned int>(length);
            Capacity = static_cast<unsigned int>(length);
            if (length <= sizeof(const char*)) {
                memcpy(&DataSSO, chars, length);
            }

        }
        SmallString(const SmallString& other) {

            if (other.Length <= sizeof(const char*)) {
                this->Length = other.Length;
                this->Capacity = other.Length;
                memcpy(&this->DataSSO, &other.DataSSO, other.Length);
            }
            else {
                this->Length = other.Length;
                this->Capacity = other.Length;
                Data = new char[Length];
                memcpy(&this->Data, &other.Data, other.Length);
            }
        }

        SmallString(SmallString&& other) {
            if (this->Capacity > sizeof(const char*)) {
                delete[] Data;
                this->Length = other.Length;
                this->Capacity = other.Capacity;
                this->Data = other.Data;
                other.Capacity = 0;
                other.Length = 0;
                other.Data = nullptr;
            }
            else {
                this->Length = other.Length;
                this->Capacity = other.Capacity;
                memcpy(&this->DataSSO, &other.DataSSO, other.Length);
                other.Length = 0;
                other.Capacity = 0;
                other.DataSSO[0] = '\0';

            }
        }

        ~SmallString() {
            if (Capacity > sizeof(const char*)) {
                delete[] Data;
            }
        }
        SmallString& operator=(const SmallString& other) {
            if (this == &other) UE_UNLIKELY{
                return *this;
            }
                if (other.Length <= sizeof(const char*)) {
                    this->Length = other.Length;
                    this->Capacity = other.Length;
                    memcpy(&this->DataSSO, &other.DataSSO, other.Length);
                }
                else {
                    this->Length = other.Length;
                    this->Capacity = other.Length;
                    Data = new char[Length];
                    memcpy(&this->Data, &other.Data, other.Length);
                }
            return *this;
        }
        SmallString& operator=(SmallString&& other) {
            if (this == &other) UE_UNLIKELY{
                return *this;

            }
            if (this->Capacity > sizeof(const char*)) {
                delete[] Data;
                this->Length = other.Length;
                this->Capacity = other.Capacity;
                this->Data = other.Data;
                other.Capacity = 0;
                other.Length = 0;
                other.Data = nullptr;
            }
            else {
                this->Length = other.Length;
                this->Capacity = other.Capacity;
                memcpy(&this->DataSSO, &other.DataSSO, other.Length);
                other.Length = 0;
                other.Capacity = 0;
                other.DataSSO[0] = '\0';

            }
        }
    };
}

#endif
