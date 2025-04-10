#pragma once
#ifndef UE_WEAK_REF__
#define UE_WEAK_REF__

#ifndef CORE_MODULE_BUILD
import std;
#endif // !CORE_MODULE_BUILD
#include "CORE/REF_WRAPPERS/CONTROLL_BLOCKS/CONTROL_BASE/CONTROL_BASE.h"
#include "CORE/REF_WRAPPERS/WRAPPER_BASE/WRAPPER_BASE.h"
namespace UPRISE_ENGINE {
    /// <summary>
    /// WeakRef to a Owned or shared Ref
    /// will not keep the object referdd to alive but will keep the controll block alive
    /// </summary>
    /// <typeparam name="Type"></typeparam>
    /// <typeparam name="DoNullCheck"></typeparam>
    template<typename Type, bool DoNullCheck>
    class WeakRef :public UPRISE_ENGINE::WrapperBase {


    };
    template<typename Type>
    class WeakRef<Type, true> :WrapperBase {
        template<typename T, bool NC> friend class WeakRef;
        friend class WeakRef<Type, true>;
        friend class CreateRefs;
        //#ifdef __INTELLISENSE__
           // public:
        //#else
    private:
        //#endif


    public:

        WeakRef()noexcept = default;
#pragma region SelfType


        WeakRef(const WeakRef<Type, true>& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) :ControlBlock(other.ControlBlock) {

            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" other\" was null while trying to copy(func sig :WeakRef(const WeakRef<Type, true>& other)noexcept  )");
                break;
            }
            case 1: {
                CaseMoved("trying to copy a moved from object (func sig : WeakRef(const WeakRef<Type, true>& other)noexcept )");
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to copy construct from a default constructed object this may indicate an error in the program");
                }
            }
           UE_LIKELY default: {
                ///assume that all other values are valid
                ControlBlock->IncrementWeakRefs();

            }
            }

        }
        WeakRef& operator=(const WeakRef<Type, true>& other) {
            if (this == &other)UE_UNLIKELY{
                CaseSelfAsign("while it is legal to self asign it is very likely an error in the program or at the very least a performance loss");
            }
                ///check if ControlBlock contains one of the special signal values or not
                switch (ControlBlock) {
                case 0: {
                    CaseNull("controll block of \" this\" was null (0) while trying to move assign from other. (function sig: WeakRef& operator=(WeakRef<Type, true>&& other) ");
                }
                case 1: {
                    ///perfectly legal to asign to moved from object
                    break;
                }
                case 2: {
                    ///perfectly legal to asign to default initialized object
                    break;
                }
                default: {
                    ///assume all other values are valid
                    this->ControlBlock->DecrementWeakrefs();
                    break;
                }
                }


            this->ControlBlock = other.ControlBlock;
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("while it is legal copying a null object it deffinetly is an error in the program");
                break;
            }
            case 1: {
                CaseMoved("it is not legal to copy a moved from object");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to copy a default constructed object this may indicate an error in the program");
                }
                break;
            }
              UE_LIKELY default: {
                ///assume all other values are valid


            }
            }
        }
        /// <summary>
        /// move constructor.
        /// no nullcheck is neccesary bc no reff count has to be decremented or incremented
        /// </summary>
        /// <param name="other"></param>
        WeakRef(WeakRef<Type, true>&& other)noexcept :ControlBlock(std::exchange(other.ControlBlock, reinterpret_cast<UPRISE_ENGINE::ControlBlock_Base*>(1ULL))) {}
        WeakRef& operator=(WeakRef<Type, true>&& other) {
            if (this == &other) UE_UNLIKELY{
                CaseSelfAsign("while it is legal to self asign (or in this case self move asign because there are protections aganínst that) it very likely indicates an error in the program or at the very least a performance loss");
                return *this;
            }
                ///check if ControlBlock contains one of the special signal values or not
                switch (ControlBlock) {
                case 0: {
                    CaseNull("controll block of \" this\" was null (0) while trying to move assign from other. (function sig: WeakRef& operator=(WeakRef<Type, true>&& other) ");
                }
                case 1: {
                    ///perfectly legal to move asign to moved from object
                    break;
                }
                case 2: {
                    ///perfectly legal to move asign to default initialized object
                    break;
                }

                default: {
                    ///assume all other values are valid
                    this->ControlBlock->DecrementWeakrefs();
                    break;


                }
                }

            this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) { 
            case 0: {
                CaseNull("while it is legal to move asign a null object it deffinetly is an error in the program");
                break;
            }
            case 1: {
                CaseMoved("it is not legal to move asign a moved from object");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to move asign a default constructed object this may indicate an error in the program");
                }
                break;
            }
            default: {
                ///assume all othher values are valid
            }
            }

        }
#pragma endregion

        template<
            typename OtherType,
            typename = std::enable_if<
            std::is_convertible_v<OtherType, Type>>>
            WeakRef(const WeakRef<OtherType, true>& other) : ControlBlock(other.ControlBlock) {

            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" other\" was null while trying to copy(func sig :WeakRef(const WeakRef<Type, true>& other)  )");
                break;
            }
            case 1: {
                CaseMoved("trying to copy a moved from object (func sig : WeakRef(const WeakRef<Type, true>& other) )");
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to copy construct from a default constructed object this may indicate an error in the program");
                }
            }
            default: {
                ///assume that all other values are valid
                ControlBlock->IncrementWeakRefs();
            }
            }

        }

        template<
            typename OtherType,
            typename = std::enable_if<
            std::is_convertible_v<OtherType, Type>>>
            WeakRef(WeakRef<OtherType, true>&& other)noexcept :ControlBlock(std::exchange(other.ControlBlock, nullptr)) {}


    };
    template<typename Type>
    class WeakRef<Type, false> :WrapperBase {
        template<typename T, bool NC> friend class WeakRef;
        friend class CreateRefs;

        ControlBlock_Base* ControlBlock = nullptr;
    public:

        WeakRef()noexcept = default;


    };
    typedef WeakRef<int, true> __DebugWeakRefIntTrue;
}
#endif