#pragma once
#ifndef _STRING_
#define _STRING_
#ifndef CORE_MODULE_BUILD
import std;

#endif // !CORE_MODULE_BUILD
namespace UPRISE_ENGINE {
    /// <summary>
    /// class is packed.
    /// dont take adress of data ptr as the ptr might not be allignt.
    /// the aligment of the string is alignof(SizeType)
    /// </summary>
    /// <typeparam name="SizeType"></typeparam>
    /// <typeparam name="SSO_Capacity"></typeparam>
    template<std::unsigned_integral SizeType, SizeType SSO_Capacity>

    class String {
    private:
        template <std::unsigned_integral T, T s>
        friend class String;
         

        union STRING_IMPLEMANTATION {
#pragma pack(push)

#pragma pack(1)

            struct Impl
            {

                char* Data;
                SizeType Capacity;

            } _Impl;
            struct ImplSSO
            {
                char Data[SSO_Capacity];
            }_ImplSSO;
#pragma pack(pop)

        }_Implementation;

        
        SizeType Length;
        bool _fitsSSO(const SizeType __input)const noexcept {
            return __input <= SSO_Capacity;
        }
      inline constexpr  bool _fitsSSOSelf()const noexcept {
            return Length <= SSO_Capacity;
        }
        /// <summary>
        /// small wrapper for strlen
        /// returns strlen+1
        /// main reason is to only have one warning in the static analyzer
        /// </summary>
        /// <param name="in"></param>
        /// <returns></returns>
        inline size_t External_length(const char* const in) const  noexcept {
            return   std::strlen(in);
        }
        /// <summary>
        /// only works when in non sso mode
        /// this->_Implementation._Impl.Data has to be realloced beforhand to fit other
        /// calls strcat so not very efficient
        /// </summary>
        /// <param name="other"></param>
        inline void concatSelfOther(const char* other) {
            std::strcat(this->_Implementation._Impl.Data, other);
        }
        /// <summary>
        /// concats this and other.
        /// no need to call realloc as this is handelt internaly.
        /// you need to pass in the length of the string +1 as paramater.
        /// the index of the \0 in this will be replaced by other[0]
        /// </summary>
        /// <param name="other"></param>
        /// <param name="otherLength"></param>
        inline void concatSelfOther(const char* other, size_t otherLength) {
            const bool concatfitsSSO = this->Length + otherLength - 1 <= SSO_Capacity;
            const bool SelfSSO = this->_fitsSSOSelf();
            //TODO: finish implementing
            UE_THROW_NOT_IMPLEMENTED;

        }
    public:
        /// <summary>
        /// Default constructor
        /// String strats in SSO (Small String Optimisation) Mode ( no heap allocation)
        /// </summary>
        String()noexcept :_Implementation{ {0} }, Length(0) {}
        /// <summary>
        /// constructs a string from the data a null terminated const char pointer points to.
        /// throws a  std:.runtime_error if strlen(String)+1  is larger than the max value of SizeType (std::numeric_limits |SizeType| ::max())
        /// if the string is to large for the SSO buffer it will call new (might also throw)
        /// </summary>
        /// <param name="String">const char input from either a litteral or a pointer</param>
        String(const char* const String) {
            const auto EX_Length = External_length(String);
            if (EX_Length > std::numeric_limits<SizeType>::max()) UE_UNLIKELY{
                throw std::runtime_error("String too Long when trying to convert from const char*!");
            };
            const bool isSSO = _fitsSSO(static_cast<SizeType>(EX_Length));

            if (isSSO) {
                Length = static_cast<SizeType>(EX_Length);
                memcpy(&this->_Implementation._ImplSSO.Data, String, EX_Length);
            }
            else {
                Length = static_cast<SizeType>(EX_Length);
                this->_Implementation._Impl.Data = new char[EX_Length];
                memcpy(this->_Implementation._Impl.Data, String, EX_Length);
                this->_Implementation._Impl.Capacity = static_cast<SizeType>(EX_Length);
            }
        }
        /// <summary>
        /// constructs a string from a std::string.
        /// throws a std::runtime_error if other.length() is larger than the max value of SizeType (std::numeric_limits |SizeType| ::max())
        /// if the string is to large for the SSO buffer it will call new (might also throw)
        /// </summary>
        /// <param name="other"></param>
        String(const std::string& other) {
            const size_t ExLength = other.length() + 1;
            const bool isSSO = _fitsSSO(ExLength);
            const char* otherData = other.data();
            if (ExLength > std::numeric_limits<SizeType>::max())UE_UNLIKELY{
                throw std::runtime_error("String too long when trying to convert from std::string!");
            };
            if (isSSO) {
                Length = ExLength;
                memcpy(&this->_Implementation._ImplSSO.Data, otherData, ExLength);
            }
            else {
                Length = ExLength;
                this->_Implementation._Impl.Data = new char[ExLength];
                memcpy(this->_Implementation._Impl.Data, otherData, ExLength);
                this->_Implementation._Impl.Capacity = ExLength;
            }
        }

        /// <summary>
        /// constructs a string from a different templated string.
        /// performs many(possible costly) checks to make sure the strings can be safely converted
        /// will throw a std::runtime_error otherwise (other.Length > std::numeric_limits |SizeType|::max())
        /// if the string is to large for the SSO buffer it will call new (might also throw)
        /// </summary>
        /// <typeparam name=""></typeparam>
        /// <typeparam name="OtherSizeType">the sizetype of the string you have as an iput parameter</typeparam>
        /// <typeparam name="otherSSO_Capacity">the sso capacity of the string you have as input</typeparam>
        /// <param name="other">the input string</param>
        template
            <std::unsigned_integral OtherSizeType,
            OtherSizeType otherSSO_Capacity,
            typename = std::enable_if<!std::is_same_v<SizeType, OtherSizeType>>>
            String(const String<OtherSizeType, otherSSO_Capacity>& other) {

            if (other.Length > std::numeric_limits<SizeType>::max())UE_UNLIKELY{
                throw std::runtime_error("string is too long while creating from oher string of different size");
            
            };
            const bool otherisSSO = other._fitsSSO(other.Length);
            const bool fitsSSO = _fitsSSO(other.Length);
            const char* ptrToData = [&]() {
                if (otherisSSO) {
                    return other._Implementation._ImplSSO.Data;
                }
                else {
                    return const_cast<const char*>(other._Implementation._Impl.Data);
                }
                }();
            
            if (fitsSSO) {
                this->Length = other.Length;
                memcpy(&this->_Implementation._ImplSSO.Data, ptrToData, other.Length);
            }
            else {
                this->Length = other.Length;
                this->_Implementation._Impl.Data = new char[other.Length];
                memcpy(this->_Implementation._Impl.Data, ptrToData, other.Length);
                this->_Implementation._Impl.Capacity = other.Length;
            }
        }

        /// <summary>
        /// copy constructor that constructs a string from a string of the same type. performs WAY less checks than when constructing from a different string. strongly reccomended to mostly use this
        /// can throw because it calls new if other.lengt is to large for the sso buffer
        /// </summary>
        /// <param name="other"></param>
        String(const String<SizeType, SSO_Capacity>& other) {
            const SizeType EXLength = other.Length;
            if (_fitsSSO(EXLength)) {
                this->_Implementation._ImplSSO = other._Implementation._ImplSSO;
                this->Length = EXLength;
            }
            else {
                this->Length = other.Length;
                this->_Implementation._Impl.Data = new char[EXLength];
                memcpy(this->_Implementation._Impl.Data, other._Implementation._Impl.Data, EXLength);
                this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
            }

        }

        /// <summary>
        /// coppy assigment opperator for strings of same type
        /// will return instantly if self asigning
        /// will call new if other.length is larger than the sso buffer (possibly thows)
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        String& operator=(const String<SizeType, SSO_Capacity>& other) {
            if (this == &other) UE_UNLIKELY{
                return*this;
            }
            const SizeType EXLength = other.Length;
            if (_fitsSSO(EXLength)) {
                this->_Implementation._ImplSSO = other._Implementation._ImplSSO;
                this->Length = EXLength;
            }
            else {
                this->Length = other.Length;
                this->_Implementation._Impl.Data = new char[EXLength];
                memcpy(this->_Implementation._Impl.Data, other._Implementation._Impl.Data, EXLength);
                this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
            }
            return *this;
        }

        /// <summary>
        /// copy assigment operator for strings of other type
        /// performs many(possible costly) checks to make sure the strings can be safely converted
        /// will throw a std::runtime_error otherwise (other.Length > std::numeric_limits |SizeType|::max())
        /// if the string is to large for the SSO buffer it will call new (might also throw)
        /// </summary>
        /// <typeparam name=""></typeparam>
        /// <typeparam name="OtherSizeType"></typeparam>
        /// <typeparam name="otherSSO_Capacity"></typeparam>
        /// <param name="other"></param>
        /// <returns></returns>
        template
            <std::unsigned_integral OtherSizeType,
            OtherSizeType otherSSO_Capacity,
            typename = std::enable_if<!std::is_same_v<SizeType, OtherSizeType>>>
            String& operator=(const String<OtherSizeType, otherSSO_Capacity>& other) {
            if (other.Length > std::numeric_limits<SizeType>::max())UE_UNLIKELY{
             throw std::runtime_error("string is too long while creating from oher string of different size");
            };
            const bool otherisSSO = other._fitsSSO(other.Length);
            const bool fitsSSO = _fitsSSO(other.Length);
            const char* ptrToData = [&]() {
                if (otherisSSO) {
                    return other._Implementation._ImplSSO.Data;
                }
                else {
                    return const_cast<const char*>(other._Implementation._Impl.Data);
                }
                }();
            if (fitsSSO) {
                this->Length = other.Length;
                memcpy(&this->_Implementation._ImplSSO.Data, ptrToData, other.Length);
            }
            else {
                this->Length = other.Length;
                this->_Implementation._Impl.Data = new char[other.Length];
                memcpy(this->_Implementation._Impl.Data, ptrToData, other.Length);
                this->_Implementation._Impl.Capacity = other.Length;
            }
            return *this;
        }

        /// <summary>
        /// move constructor for string of same type.
        /// moving from string in sso mode can have more overhead than from non sso mode strings as in sso mode the buffer has to be copied ( move from sso string == copy sso String)
        /// 
        /// </summary>
        /// <param name="other"></param>
        String(String<SizeType, SSO_Capacity>&& other) {
            const bool OtherSSSO = other._fitsSSOSelf();
            const bool SelfSSO = this->_fitsSSOSelf();
            this->Length = other.Length;
            other.Length = 0;
            const char* const OtherData = [&]() ->const char* const {
                if (OtherSSSO) {
                    return const_cast<const char* const>(other._Implementation._ImplSSO.Data);
                }
                else {
                    return other._Implementation._Impl.Data;
                }
                }();
            if (!SelfSSO) {
                delete[] this->_Implementation._Impl.Data;
            }
            if (OtherSSSO) {
                this->_Implementation._ImplSSO = other._Implementation._ImplSSO;
                other._Implementation._ImplSSO.Data[0] = '\0';
                other.Length = 0;
            }
            else {
                this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                this->_Implementation._Impl.Capacity = other.Length;
                other._Implementation._Impl.Data = nullptr;
                other._Implementation._Impl.Capacity = 0;
                other.Length = 0;

            }

        }
        /// <summary>
        /// Move cosntrucor from other type string
        /// performs many(possible costly) checks to make sure the strings can be safely converted
        /// will throw a std::runtime_error otherwise (other.Length > std::numeric_limits |SizeType|::max())
        /// moving from string in sso mode can have more overhead than from non sso mode strings as in sso mode the buffer has to be copied ( move from sso string == copy sso String)
        /// uses if constexpr to make it more efficient (sadly less readable)
        /// </summary>
        /// <typeparam name=""></typeparam>
        /// <typeparam name="OtherSizeType"></typeparam>
        /// <typeparam name="otherSSO_Capacity"></typeparam>
        /// <param name="other"></param>
        template
            <std::unsigned_integral OtherSizeType,
            OtherSizeType otherSSO_Capacity,
            typename = std::enable_if<!std::is_same_v<SizeType, OtherSizeType>>>
            String(String<OtherSizeType, otherSSO_Capacity>&& other) {
            const bool OtherSSO = other._fitsSSOSelf();
            const bool SelfSSO = this->_fitsSSOSelf();
            const char* const OtherData = [&]() ->const char* const {
                if (OtherSSO) {
                    return const_cast<const char* const>(other._Implementation._ImplSSO.Data);
                }
                else {
                    return other._Implementation._Impl.Data;
                }
                }();
            if (!SelfSSO) {
                delete[] this->_Implementation._Impl.Data;
            }
            //move if other max value is less thant this max value
            if constexpr (std::numeric_limits<OtherSizeType>::max() <= std::numeric_limits<SizeType>::max()) {
                //move if other sso fits in own sso
                if constexpr (otherSSO_Capacity <= SSO_Capacity) {
                    this->Length = other.Length;
                    //move if other is sso
                    if (OtherSSO) {
                        //memset(&this->_Implementation._ImplSSO.Data, 0, SSO_Capacity); security improvement at the cost of speed. zero out own sso buffer before writing in smaller buffer to prevent data leaks
                        for (Index i = 0; i <= otherSSO_Capacity; i++) {
                            this->_Implementation._ImplSSO.Data[i] = other._Implementation._ImplSSO.Data[i];
                        }
                        other.Length = 0;
                        other._Implementation._ImplSSO.Data[0] = '\0';
                    }
                    //move if other isnt sso
                    else {
                        // move if fits in sso
                        if (other.Length <= SSO_Capacity) {
                            memcpy(other._Implementation._Impl.Data, &this->_Implementation._ImplSSO.Data, other.Length);
                            delete[]other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                            other._Implementation._Impl.Data = nullptr;
                        }
                        //move if doesnt fit in sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }

                    }

                }
                // move if other sso fitnst in own sso
                else {
                    this->Length = other.Length;
                    const bool OtherFitsinOwnSSO = _fitsSSO(OtherSSO);
                    //move if other is sso
                    if (OtherSSO) {
                        //move if other fits in own sso
                        if (OtherFitsinOwnSSO) {

                            memcpy(this->_Implementation._ImplSSO.Data, other._Implementation._Impl.Data, other.Length);
                            delete[] other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }
                        //move if other doesnt fit in own sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;


                        }
                    }
                    //move if other isnt sso
                    else {
                        this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                        this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                        other._Implementation._Impl.Data = nullptr;
                        other._Implementation._Impl.Capacity = 0;
                        other.Length = 0;
                    }

                }
            }
            //move if other max value is more thant this max value
            else {
                if (static_cast<size_t>(other.Length) > static_cast<size_t>(std::numeric_limits<SizeType>::max())) {
                    throw std::runtime_error("string is too large while trying to move from string with smaler Sizetype and different  SSO capacity");
                }
                //move if other sso fits in own sso
                if constexpr (otherSSO_Capacity <= SSO_Capacity) {
                    //move if other is sso
                    if (OtherSSO) {
                        //memset(&this->_Implementation._ImplSSO.Data, 0, SSO_Capacity); security improvement at the cost of speed. zero out own sso buffer before writing in smaller buffer to prevent data leaks
                        for (Index i = 0; i <= otherSSO_Capacity; i++) {
                            this->_Implementation._ImplSSO.Data[i] = other._Implementation._ImplSSO.Data[i];
                        }
                        other.Length = 0;
                        other._Implementation._ImplSSO.Data[0] = '\0';
                    }
                    //move if other isnt sso
                    else {
                        // move if fits in sso
                        if (other.Length <= SSO_Capacity) {
                            memcpy(other._Implementation._Impl.Data, &this->_Implementation._ImplSSO.Data, other.Length);
                            delete[]other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                            other._Implementation._Impl.Data = nullptr;
                        }
                        //move if doesnt fit in sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }

                    }

                }
                // move if other sso fitnst in own sso
                else {
                    this->Length = other.Length;
                    const bool OtherFitsinOwnSSO = _fitsSSO(OtherSSO);
                    //move if other is sso
                    if (OtherSSO) {
                        //move if other fits in own sso
                        if (OtherFitsinOwnSSO) {

                            memcpy(this->_Implementation._ImplSSO.Data, other._Implementation._Impl.Data, other.Length);
                            delete[] other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }
                        //move if other doesnt fit in own sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;


                        }
                    }
                    //move if other isnt sso
                    else {
                        this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                        this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                        other._Implementation._Impl.Data = nullptr;
                        other._Implementation._Impl.Capacity = 0;
                        other.Length = 0;
                    }

                }
            }
        }


        /// <summary>
        /// move asigment opperator for string of own type
        /// moving from string in sso mode can have more overhead than from non sso mode strings as in sso mode the buffer has to be copied ( move from sso string == copy sso String)
        /// </summary>
        /// <param name="other"></param>
        String& operator=(String<SizeType, SSO_Capacity>&& other) {

            if (!this->_fitsSSOSelf()) {
                delete[] this->_Implementation._Impl.Data;
            }
            if (other._fitsSSOSelf()) {

                memcpy(&this->_Implementation._ImplSSO.Data, &other._Implementation._ImplSSO.Data, other.Length);
                this->Length = other.Length;
                other.Length = 0;
                other._Implementation._ImplSSO.Data[0] = '\0';
            }
            else {
                this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                other._Implementation._Impl.Data = nullptr;
                this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                other._Implementation._Impl.Capacity = 0;
                this->Length = other.Length;
                other.Length = 0;
            }
            return *this;
        }
        /// <summary>
        /// move asign operator for string of other type
        /// performs many(possible costly) checks to make sure the strings can be safely converted
        /// will throw a std::runtime_error otherwise (other.Length > std::numeric_limits |SizeType|::max())
        /// moving from string in sso mode can have more overhead than from non sso mode strings as in sso mode the buffer has to be copied ( move from sso string == copy sso String)
        /// uses if constexpr to make it more efficient (sadly less readable)
        /// </summary>
        /// <typeparam name=""></typeparam>
        /// <typeparam name="OtherSizeType"></typeparam>
        /// <typeparam name="otherSSO_Capacity"></typeparam>
        /// <param name="other"></param>
        /// <returns></returns>
        template
            <std::unsigned_integral OtherSizeType,
            OtherSizeType otherSSO_Capacity,
            typename = std::enable_if<!std::is_same_v<SizeType, OtherSizeType>>>
            String& operator=(String<OtherSizeType, otherSSO_Capacity>&& other) {
            const bool OtherSSO = other._fitsSSOSelf();
            const bool SelfSSO = this->_fitsSSOSelf();
            const char* const OtherData = [&]() ->const char* const {
                if (OtherSSO) {
                    return const_cast<const char* const>(other._Implementation._ImplSSO.Data);
                }
                else {
                    return other._Implementation._Impl.Data;
                }
                }();
            if (!SelfSSO) {
                delete[] this->_Implementation._Impl.Data;
            }
            //move if other max value is less thant this max value
            if constexpr (std::numeric_limits<OtherSizeType>::max() <= std::numeric_limits<SizeType>::max()) {
                //move if other sso fits in own sso
                if constexpr (otherSSO_Capacity <= SSO_Capacity) {
                    this->Length = other.Length;
                    //move if other is sso
                    if (OtherSSO) {
                        //memset(&this->_Implementation._ImplSSO.Data, 0, SSO_Capacity); security improvement at the cost of speed. zero out own sso buffer before writing in smaller buffer to prevent data leaks
                        for (Index i = 0; i <= otherSSO_Capacity; i++) {
                            this->_Implementation._ImplSSO.Data[i] = other._Implementation._ImplSSO.Data[i];
                        }
                        other.Length = 0;
                        other._Implementation._ImplSSO.Data[0] = '\0';
                    }
                    //move if other isnt sso
                    else {
                        // move if fits in sso
                        if (other.Length <= SSO_Capacity) {
                            memcpy(other._Implementation._Impl.Data, &this->_Implementation._ImplSSO.Data, other.Length);
                            delete[]other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                            other._Implementation._Impl.Data = nullptr;
                        }
                        //move if doesnt fit in sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }

                    }

                }
                // move if other sso fitnst in own sso
                else {
                    this->Length = other.Length;
                    const bool OtherFitsinOwnSSO = _fitsSSO(OtherSSO);
                    //move if other is sso
                    if (OtherSSO) {
                        //move if other fits in own sso
                        if (OtherFitsinOwnSSO) {

                            memcpy(this->_Implementation._ImplSSO.Data, other._Implementation._Impl.Data, other.Length);
                            delete[] other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }
                        //move if other doesnt fit in own sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;


                        }
                    }
                    //move if other isnt sso
                    else {
                        this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                        this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                        other._Implementation._Impl.Data = nullptr;
                        other._Implementation._Impl.Capacity = 0;
                        other.Length = 0;
                    }

                }
            }
            //move if other max value is more thant this max value
            else {
                if (static_cast<size_t>(other.Length) > static_cast<size_t>(std::numeric_limits<SizeType>::max())) {
                    throw std::runtime_error("string is too large while trying to move from string with smaler Sizetype and different  SSO capacity");
                }
                //move if other sso fits in own sso
                if constexpr (otherSSO_Capacity <= SSO_Capacity) {
                    //move if other is sso
                    if (OtherSSO) {
                        //memset(&this->_Implementation._ImplSSO.Data, 0, SSO_Capacity); security improvement at the cost of speed. zero out own sso buffer before writing in smaller buffer to prevent data leaks
                        for (Index i = 0; i <= otherSSO_Capacity; i++) {
                            this->_Implementation._ImplSSO.Data[i] = other._Implementation._ImplSSO.Data[i];
                        }
                        other.Length = 0;
                        other._Implementation._ImplSSO.Data[0] = '\0';
                    }
                    //move if other isnt sso
                    else {
                        // move if fits in sso
                        if (other.Length <= SSO_Capacity) {
                            memcpy(other._Implementation._Impl.Data, &this->_Implementation._ImplSSO.Data, other.Length);
                            delete[]other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                            other._Implementation._Impl.Data = nullptr;
                        }
                        //move if doesnt fit in sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }

                    }

                }
                // move if other sso fitnst in own sso
                else {
                    this->Length = other.Length;
                    const bool OtherFitsinOwnSSO = _fitsSSO(OtherSSO);
                    //move if other is sso
                    if (OtherSSO) {
                        //move if other fits in own sso
                        if (OtherFitsinOwnSSO) {

                            memcpy(this->_Implementation._ImplSSO.Data, other._Implementation._Impl.Data, other.Length);
                            delete[] other._Implementation._Impl.Data;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;
                        }
                        //move if other doesnt fit in own sso
                        else {
                            this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                            this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                            other._Implementation._Impl.Data = nullptr;
                            other._Implementation._Impl.Capacity = 0;
                            other.Length = 0;


                        }
                    }
                    //move if other isnt sso
                    else {
                        this->_Implementation._Impl.Data = other._Implementation._Impl.Data;
                        this->_Implementation._Impl.Capacity = other._Implementation._Impl.Capacity;
                        other._Implementation._Impl.Data = nullptr;
                        other._Implementation._Impl.Capacity = 0;
                        other.Length = 0;
                    }

                }
            }
            return *this;
        }


        const char* Data() const noexcept {
            const bool selfsso = this->_fitsSSOSelf();
            return [&]() ->const char* {
                if (selfsso) {
                    return const_cast<const char*>(this->_Implementation._ImplSSO.Data);
                }
                else {
                    return this->_Implementation._Impl.Data;
                }
                }();
        }
        /// <summary>
        /// length of the string
        /// is of type SizeType
        /// includes the null terminator
        /// </summary>
        /// <returns></returns>
        SizeType length()const noexcept {
            return Length;
        }
        const  char* Begin() {
            if (this->_fitsSSOSelf()) {
                return this->_Implementation._ImplSSO.Data;
            }
            else {
                return this->_Implementation._Impl.Data;
            }
        }
        const char* End() {
            if (this->_fitsSSOSelf()) {
                return this->_Implementation._ImplSSO.Data + this->Length;

            }
            else {
                return this->_Implementation._Impl.Data + this->Length;

            }
        }
        SizeType Capacity() {
            if (this->_fitsSSOSelf()) {
                return SSO_Capacity;
            }
            else
            {
                return this->_Implementation._Impl.Capacity;
            }
        }
        inline bool IsSSO() {
            return this->_fitsSSOSelf();
        }
        /// <summary>
        /// reserves Size amount of bytes for the string
        /// if the string is in sso mode and size is larger than SSO_Capacity it will do a call to new ( can throw)
        /// will return instantly if size less or equal capacity
        /// reserved memory can optinaly be set to zerod out
        /// false by default
        /// </summary>
        /// <param name="Size">the number of bytes to allocate </param>
        /// <param name="Null"> optinal flag to signify zeroing out of the allocated memory</param>
        void Reserve(SizeType Size, bool Null = false) {
            if (this->_fitsSSOSelf()) {
                if (Size <= SSO_Capacity) {
                    return void();
                }
                else {
                    this->_Implementation._Impl.Data = new char[Size];
                    if (Null) {
                        memset(this->_Implementation._Impl.Data, 0, Size);
                    }
                    this->_Implementation._Impl.Capacity = Size;

                }

            }
            else {
                if (Size <= this->_Implementation._Impl.Capacity) {
                    return void();
                }
                else {
                    this->_Implementation._Impl.Data = new char[Size];
                    if (Null) {
                        memset(this->_Implementation._Impl.Data, 0, Size);
                    }
                    this->_Implementation._Impl.Capacity = Size;
                }
            }
        }

        /// <summary>
        /// shrinks the allocated area to fit the length of the string
        /// will do nothing if string is in SSO mode
        /// </summary>
        void ShrinkToFit() {
            if (this->_fitsSSOSelf()) {
                return void();
                
            }
            else {
                realloc(this->_Implementation._Impl.Data, this->Length);
                this->_Implementation._Impl.Capacity = this->Length;
            }

        }

        String& operator=(const char* other) {
            const bool isSSO = _fitsSSOSelf();
            size_t exLength = External_length(other);
            //TODO: finish implementing
            UE_THROW_NOT_IMPLEMENTED;

            if constexpr (std::is_same_v<SizeType, size_t>) {
                const size_t dif = std::numeric_limits<size_t>::max() - this->Length;
                if (dif < exLength) {
                    throw std::runtime_error("string too long while += from const char*. SizeType is size_t or similar (64bits)");
                }
            }
            else {
                if (this->Length + exLength < std::numeric_limits<SizeType>::max()) {
                    throw std::runtime_error("string too long while += from const char*");

                }
            }
            
        }


    };
    typedef String<size_t, sizeof(size_t) * 2> BigString;
    typedef  String<unsigned int, sizeof(size_t) + sizeof(unsigned int)>  SmallString;
    typedef String<unsigned short, sizeof(size_t) + sizeof(unsigned short)> ShortString;
    typedef String <unsigned char, sizeof(size_t) + sizeof(unsigned char)> TinyString;
    typedef BigString UE_String;

}
#endif // !_STRING_
