#pragma once
#ifndef UE_OWNED_REF_INTERNAL
#define UE_OWNED_REF_INTERNAL
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif


#ifdef __INTELLISENSE__
#include"REF_WRAPPERS/CONTROLL_BLOCKS/CONTROL_BASE/CONTROL_BASE_INTERNAL.h"
#include"REF_WRAPPERS/WRAPPER_BASE/WRAPPER_BASE_INTERNAL.h"
#include "REF_WRAPPERS/WEAK_REF/WEAK_REF_INTERNAL.h"
#include "REF_WRAPPERS/CONTROLL_BLOCKS/OWNED_CONTROLBLOCK/OWNED_CONTROLBLOCK_INTERNAL.h"
#include <functional>
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    template <typename Type>
    class OwnedRef :public WrapperBase {
        template<class T> friend class OwnedRef;
    public:

        OwnedRef()noexcept {};
        /// <summary>
        /// Detructor for OwnedRef
        /// throws if RW_USE_CPP_EXCEPTIONS_ == true
        /// </summary>
        ~OwnedRef()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(this->ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of\"this\" was null (0) while trying to Destroy OwnedRef. thisis an error in the Program");
                break;
            }
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            UE_LIKELY default: {
                DecrementWeakRefs();

                DecrementRefs();
                break;
            }
            }
        }//~OwnedRef()
        OwnedRef(const OwnedRef<Type>& other) = delete;
        OwnedRef& operator=(const OwnedRef<Type>& other) = delete;
        OwnedRef(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            //NullCheck<true, true, true>(
            //    [](ControlBlock_Base* self, ControlBlock_Base* other) {
            //    reinterpret_cast<OwnedControlBlock*>(self)->DecrementRefs();
            //    reinterpret_cast<OwnedControlBlock*>(other)->IncrementRefs();
            //    },
            //    other.ControlBlock, this->ControlBlock,
            //    " ", 
            //    " ",
            //    " ");
            switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \"other\" was null (0) while trying to move OwnedRef. this is an error in the Program");
                break;
            }
            case 1: {
                CaseMoved("ControlBlock of \"other\" was moved (1) while trying to move OwnedRef. this is an error in the Program");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("ControlBlock of \"other\" was default constructed (2) while trying to move OwnedRef. this might be an error in the program");
                }
                break;
            }
            default: {
                this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                break;
            }
            }




        }//OwnedRef(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false)
        OwnedRef& operator=(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(this->ControlBlock)) {
            case 0: {
                CaseNull("COntrolBlock of \"this\" was null (0). this is an error in the program");
                break;
            }
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            default: {
                DecrementWeakRefs();
                DecrementRefs();
                break;

            }
            }
            switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {
            case 0: {
                CaseNull(" \"other\" was null (0). this is an error in the program");
                break;
            }
            case 1: {
                CaseMoved(" \"other\" was moved (1) from. this is an error in the program");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed(" \"other\" was default constructed (2). this might be an error in the program");
                }
                break;
            }
            default: {
                this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                break;
            }
            }
            return *this;
        }//OwnedRef& operator=(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_==false)
        template <
            typename OtherType,
            typename = std::enable_if<!std::is_same_v<Type,OtherType>>>
        OwnedRef(OwnedRef<OtherType>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {

            switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {
            case 0: {
                CaseNull(" \"other\" was null (0) while trying to move OwnedRef. this is an error in the Program");
                break;
            }
            case 1: {
                CaseMoved(" \"other\" was moved (1) while trying to move OwnedRef. this is an error in the Program");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed(" \"other\" was default constructed (2) while trying to move OwnedRef. this might be an error in the program");
                }
                break;
            }
            default: {
                this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                break;
            }
            }
        }//OwnedRef(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false)
        template <
            typename OtherType,
            typename = std::enable_if<!std::is_same_v<Type, OtherType>>>
        OwnedRef& operator=(OwnedRef<OtherType>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(this->ControlBlock)) {
            case 0: {
                CaseNull(" \"this\" was null (0). this is an error in the program");
                break;
            }
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            default: {
                DecrementWeakRefs();
                DecrementRefs();
                break;
            }
            }
            switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {
            case 0: {
                CaseNull(" \"other\" was null (0). this is an error in the program");
                break;
            }
            case 1: {
                CaseMoved(" \"other\" was moved (1) from. this is an error in the program");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed(" \"other\" was default constructed (2). this might be an error in the program");
                }
                break;
            }
            default: {
                this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                break;
            }
            }
        }//OwnedRef& operator=(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_==false)

        Type* get() noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(this->ControlBlock)) {
            case 0: {
                CaseNull(" \"this\" was null (0). this is an error in the program");
                return nullptr;
                break;
            }
            case 1: {
                CaseMoved(" \"this\" was moved (1) from. this is an error in the program");
                return nullptr;
                break;
            }
            case 2: {

                CaseDefaultConstructed(" \"this\" was default constructed (2). this is an error in the programm");

                return nullptr;
                break;
            }
            UE_LIKELY  default: {
                return static_cast<Type*>(static_cast<UPRISE_ENGINE::OwnedControlBlock<Type>>(this->ControlBlock)->get());
                break;
            }
            }
        }//get()
        Type* operator->() {
            switch (reinterpret_cast<uintptr_t>(this->ControlBlock)) {
            case 0: {
                CaseNull(" \"this\" was null (0). this is an error in the program");
                return nullptr;
                break;
            }
            case 1: {
                CaseMoved(" \"this\" was moved (1) from. this is an error in the program");
                return nullptr;
                break;
            }
            case 2: {

                CaseDefaultConstructed(" \"this\" was default constructed (2). this is an error in the programm");

                return nullptr;
                break;
            }
            UE_LIKELY  default: {
                return static_cast<Type*>(_Get());
                break;
            }
            }
        }
        WeakRef<Type, true> GetWeakRef() {
            UE_THROW_NOT_IMPLEMENTED;
            return WeakRef<Type, true>();
        }
        template< typename... Args>
        static OwnedRef<Type> Create(Args&&... args) {
            OwnedControlBlock<Type>* controlBlock = new OwnedControlBlock<Type>();
            controlBlock->Object = new Type{ std::forward<Args>(args)... };
            OwnedRef<Type> ownedRef;
            ownedRef.ControlBlock = controlBlock; 
            return ownedRef;
        }//Create
    };
    typedef OwnedRef<int> UE_DEBUG_INTOWNEDREF;
}

#endif