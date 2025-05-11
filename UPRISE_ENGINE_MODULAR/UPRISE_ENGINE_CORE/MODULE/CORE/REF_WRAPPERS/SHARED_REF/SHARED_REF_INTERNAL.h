#pragma once
#ifndef UE_SHARED_REF_INTERNAL_
#define UE_SHARED_REF_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif

#ifdef __INTELLISENSE__
#include "REF_WRAPPERS/CONTROLL_BLOCKS/CONTROL_BASE/CONTROL_BASE_INTERNAL.h"
#include "REF_WRAPPERS/WRAPPER_BASE/WRAPPER_BASE_INTERNAL.h"
//#include "REF_WRAPPERS/CONTROLL_BLOCKS/SHARED_CONTROL_BLOCK/SHARED_CONTROL_BLOCK_INTERNAL.h"
#endif
namespace UPRISE_ENGINE {

    template<typename Type, bool NullChk>
    class SharedRef : public WrapperBase{
        template<typename, bool> friend class SharedRef;
    private:
        void Nullchecked_Destructor()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" this\" was null (0) while trying to destruct");
                break;
            }
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            default: {
                ControlBlock->DecrementWeakrefs();
                ControlBlock->DecrementRefs();
                break;
            }
            }
        }
        void Nullchecked_CopyConstructFromSameType(const SharedRef<Type, true>& other) noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {
            case 0: {
                CaseNull("it is not legal to copy a null Ref");
                NullSelf();
                break;
            }
            case 1: {
                CaseMoved("it is not legal to copy construct from a moved from ref");
                NullSelf();
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to copy construct from a default constructed ref this may indicate an error in the program");

                }
                break;
            }

            UE_LIKELY default: {
                ///assume that all other values are valid
                this->ControlBlock = other.ControlBlock;
                ControlBlock->IncrementWeakRefs();
                ControlBlock->IncrementRefs();
                break;

            }
            }
        }
        void Nullchecked_CopyAssignFromSameType(const SharedRef < Type, true>& other) noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if (this == &other)UE_UNLIKELY{
                 CaseSelfAsign("while it is legal to self asign it is very likely an error in the program or at the very least a performance loss");
            }
                ///check if ControlBlock contains one of the special signal values or not
                switch (reinterpret_cast<uintptr_t>(ControlBlock)) {
                case 0: {
                    CaseNull("controll block of \" this\" was null (0) while trying to move assign from other. (function sig: SharedRef& operator=(SharedRef<Type, true>&& other) ");
                    break;
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
                    DecrementRefs();
                    DecrementWeakRefs();
                    //this->ControlBlock->DecrementWeakrefs();
                    //this->ControlBlock->DecrementRefs();
                    break;
                }
                }


            switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {
            case 0: {
                CaseNull("it is not legal to copy (asign) a null ref");
                break;
            }
            case 1: {
                CaseMoved("it is not legal to copy a moved from ref");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to copy a default constructed ref this may indicate an error in the program");
                    NullSelf();
                }
                break;
            }
            UE_LIKELY default: {
                ///assume all other values are valid

                this->ControlBlock = other.ControlBlock;
                IncrementRefs();
                IncrementWeakRefs();
                //this->ControlBlock->IncrementWeakRefs();
                //this->ControlBlock->IncrementRefs();

                break;

            }
            }
        }
        void Nullchecked_MoveConstructorFromSameType(SharedRef<Type, true>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {

            case 0: {
                CaseNull("it is not legal to move (asign) a null ref ");
                NullSelf();
                break;
            }
            case 1: {
                CaseMoved("it is not legal move a moved out of ref!");
                NullSelf();

                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal move in a default construted object it may indicate a error in the program");

                }

                ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                break;
            }
            default: {
                ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                break;
            }
            }
        }
        void Nullchecked_MoveAssignFromSameType(SharedRef<Type, true>&& other) {
            if (this == &other) UE_UNLIKELY{
               CaseSelfAsign("while it is legal to self asign (or in this case self move asign because there are protections aganínst that) it very likely indicates an error in the program or at the very least a performance loss");
            }
            else {
                ///check if ControlBlock contains one of the special signal values or not
                switch (reinterpret_cast<uintptr_t>(ControlBlock)) {
                case 0: {
                    CaseNull("controll block of \" this\" was null (0) while trying to move assign from other. (function sig: SharedRef& operator=(SharedRef<Type, true>&& other) ");
                    break;
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
                    this->ControlBlock->DecrementRefs();
                    break;


                }
                }

                switch (reinterpret_cast<uintptr_t>(other.ControlBlock)) {
                UE_UNLIKELY case 0: {
                    CaseNull("while it is legal to move asign a null ref it deffinetly is an error in the program");
                    NullSelf();
                    break;
                }
                UE_UNLIKELY case 1: {
                    CaseMoved("it is not legal to move asign a moved from ref");
                    NullSelf();
                    break;
                }
                UE_UNLIKELY case 2: {
                    if constexpr (WarningLevel >= 3) {
                        CaseDefaultConstructed("while it is legal to move asign a default constructed object this may indicate an error in the program");
                    }
                    this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V3546 //-V2571
                    break;
                }
                UE_LIKELY default: {
                    this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V3546 //-V2571
                    break;

                    ///assume all othher values are valid
                }
                }
            }
        }
        template<
            typename OtherType,
            typename = std::enable_if <
            !std::is_same_v<Type, OtherType>>>
            void Nullchecked_CopyConstructorFromOtherType(const SharedRef<OtherType, true>& other) {
            switch (reinterpret_cast<unsigned long long>(other.ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" other\" was null while trying to copy(func sig :SharedRef(const SharedRef<Type, true>& other)  )");
                NullSelf();
                break;
            }
            case 1: {
                CaseMoved("trying to copy a moved from ref (func sig : SharedRef(const SharedRef<Type, true>& other) )");
                NullSelf();
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to copy construct from a default constructed object this may indicate an error in the program");
                }
                break;
            }
            default: {
                ///assume that all other values are valid
                this->ControlBlock = other.ControlBlock;
                IncrementRefs();
                IncrementWeakRefs();
                break;
            }
            }

        }
        template<
            typename OtherType,
            typename = std::enable_if <
            !std::is_same_v<Type, OtherType>>>
            void Nullchecked_CopyAssignFromOtherType(const SharedRef<OtherType, true>& other) {
            if (&other == this) UE_UNLIKELY{
                CaseSelfAsign("while it is legal to self assing it may be an error in the program or at the very least a performance loss");
            }
                switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
                case 0: {
                    CaseNull("controlblaock of self is null! ");
                    break;
                }
                case 1: {
                    // its perfectly legal to assign to a moved from object
                    break;
                }
                case 2: {
                    /// its perfectly legal to assign to a default constructed object
                    break;
                }
                default: {
                    ControlBlock->DecrementWeakrefs();
                    ControlBlock->DecrementRefs();
                    break;
                }
                }
            ControlBlock = other.ControlBlock;

            switch (reinterpret_cast<unsigned long long>(other.ControlBlock)) {
            case 0: {
                CaseNull("controllblock of other is null");
                NullSelf();
                break;
            }
            case 1: {
                CaseMoved("it is not legal to copy (asign) a moved from object!");
                NullSelf();
                break;
            }
            case 2: {
                if constexpr (WarningLevel <= 3) {
                    CaseDefaultConstructed("while it is legal to copy asing a default constructed object tis may indicate a error in the program or at the very least a performance loss");
                }
                break;
            }
            default: {
                ControlBlock->IncrementWeakRefs();
                ControlBlock->IncrementRefs();
                break;
            }
            }
        }
        template<
            typename OtherType,
            typename = std::enable_if <
            !std::is_same_v<Type, OtherType>>>
            void Nullchecked_MoveConstructorFromOtherType(SharedRef<OtherType, true>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<unsigned long long>(other.ControlBlock)) {
            case 0: {
                CaseNull("Control Block of \"other\" was null (0, nullptr). ");
                break;
            }
            case 1: {
                CaseMoved("it is not legal move a moved out of object!");
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal move in a default construted object it may indicate a error in the program");
                }
                break;
            }
            default: {
                ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V2571 //-V566 //-V3546
                break;
            }
            }
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            void Nullchecked_MoveAssignFromOtherType(SharedRef<OtherType, true>&& other) {
            if (this == &other)UE_UNLIKELY{
               CaseSelfAsign("while it is legal to self asign it is very likely an error in the program or at the very least a performance loss");
            }
                switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
                case 0: {
                    CaseNull("controll block of \" this\" was null (0) while trying to move assign from other. (function sig: SharedRef& operator=(SharedRef<Type, true>&& other) ");
                    break;
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
                    this->ControlBlock->DecrementRefs();
                    break;
                }
                }
            switch (reinterpret_cast<unsigned long long>(other.ControlBlock)) {
            case 0: {
                CaseNull("it is not legal to move a null object");
                NullSelf();
                break;
            }
            case 1: {
                CaseMoved("it is not legal to move asign a moved from ref");
                NullSelf();
                break;
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to move asign a default constructed object this may indicate an error in the program");
                }
                this->ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571 //-V3546
                break;
            }
            default: {

                this->ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                ///assume all othher values are valid
                break;
            }
            }
        }


        RefState Nullchecked_GetRefState() {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                return RefState::Null;
                break;
            }
            case 1: {
                return RefState::Moved;
                break;

            }
            case 2: {
                return RefState::DefaultConstructed;
                break;

            }
            default: {
                return RefState::Valid;
                break;

            }
            }
        }
        Type* Nullchecked_Get() {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" this\" was null (0) while trying to get the object");
                NullSelf();
                return nullptr;
                break;

            }
            case 1: {
                CaseMoved("ControlBlock of \" this\" was moved from (1) while trying to get the object");
                NullSelf();
                return nullptr;
                break;

            }
            case 2: {
                CaseDefaultConstructed("it is illegal to deref a never assigned ref");
                NullSelf();
                return nullptr;
                break;

            }
            default: {
                return reinterpret_cast<Type*>(ControlBlock->get());
                break;

            }

            }
        }
        Type* Nullchecked_OpperatorArrow() {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" this\" was null (0) while trying to get the object");
                NullSelf();
                return nullptr;
                break;

            }
            case 1: {
                CaseMoved("ControlBlock of \" this\" was moved from (1) while trying to get the object");
                NullSelf();
                return nullptr;
                break;
            }
            case 2: {
                CaseDefaultConstructed("it is illegal to deref a never assigned ref");
                NullSelf();
                return nullptr;
                break;
            }
            default: {
                return reinterpret_cast<Type*>(WrapperBase::_Get());
                break;
            }
            }
        }
        ObjState Nullchecked_GetObjectState() {
            switch (reinterpret_cast<uintptr_t>(ControlBlock)) {
            case 0: {
                CaseNull("Controlblock of \"this\" was null while trying to get object state");
                return ObjState::Invalid;
                break;
            }
            case 1: {
                CaseMoved("\"this\" was moved from. it is illegal to acces such objects. ( while trying to get object state");
                return ObjState::Invalid;
                break;

            }
            case 2: {
                CaseDefaultConstructed("\"this\" was default constructed. it has no controll block");
                return ObjState::Invalid;
            }
            default: {
                return ControlBlock->GetObjectState();
                break;
            }
            }
        }



        void NonNullchecked_Destructor() {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    ControlBlock->DecrementWeakrefs();
                    ControlBlock->DecrementRefs();
                }
                else {
                    if (reinterpret_cast<uintptr_t>(ControlBlock) == 2) {
                        //nothing to do for default objects 
                    }
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    ControlBlock->DecrementWeakrefs();
                    ControlBlock->DecrementRefs();
                }

            }
        }
        void NonNullchecked_CopyConstructorFromSameType(const SharedRef<Type, false>& other) {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = other.ControlBlock;
                    ControlBlock->IncrementWeakRefs();
                    ControlBlock->IncrementRefs();
                }
                else {
                    if (reinterpret_cast<uintptr_t>(other.ControlBlock) == 2) {
                        ControlBlock = other.ControlBlock;
                    }
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {
                    this->ControlBlock = other.ControlBlock;
                }
            }
        }
        void NonNullchecked_CopyAsignFromSameType(const SharedRef<Type, false>& other) {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }
                else {
                    if (reinterpret_cast<uintptr_t>(ControlBlock) == 2) {
                        //2 is the case for a default constructed object wich is a 
                    }
                    else {
                        CaseInvalid("invalid value for own Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }
            }
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {
                    if (reinterpret_cast<uintptr_t>(other.ControlBlock) == 2) {
                        this->ControlBlock = other.ControlBlock;
                    }
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {
                    /*
                    *
                    */
                }

            }
        }
        void NonNullchecked_MoveConstructFromSameType(SharedRef<Type, false>&& other) {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V2571
                    ControlBlock->IncrementWeakRefs();
                    ControlBlock->IncrementRefs();
                }
                else {
                    if (reinterpret_cast<uintptr_t>(other.ControlBlock) == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V2571
                    }
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");

                    }
                }
            }
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V2571
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V2571


                }
            }
        }
        void NonNullchecked_MoveAssignFromSameType(SharedRef<Type, false>&& other) {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }//ControlBlock>2<=2
                else {
                    if (reinterpret_cast<uintptr_t>(ControlBlock) == 2) {//the empthy version is the wanted one .putting it in the if block might increase performance
                    }
                    else {
                        CaseInvalid("invalid value for own Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }
            }
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V2571
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {
                    if (reinterpret_cast<uintptr_t>(other.ControlBlock) == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V2571
                    }
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL)); //-V566 //-V2571

                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();

                }

            }
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            void NonNullchecked_CopyCostructorFromOtherType(const SharedRef<OtherType, false>& other) {
            if constexpr (DebugMode) {
                if (ControlBlock > 2) {
                    ControlBlock = other.ControlBlock;
                    ControlBlock->IncrementWeakRefs();
                    ControlBlock->IncrementRefs();
                }
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = other.ControlBlock;
                    }
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");

                    }
                }
            }
            else {
                if (ControlBlock > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {
                    this->ControlBlock = other.ControlBlock;
                }
            }
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            void NonNullchecked_CopyAssignFromOtherType(const SharedRef<OtherType, false>& other) {
            if constexpr (DebugMode) {
                if (this->ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }
                else {
                    if (ControlBlock == 2) {}
                    else {
                        CaseInvalid("invalid value for own Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }
                else {}
            }
            if constexpr (DebugMode) {
                if (other.ControlBlock > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {
                    if (other.ControlBlock == 2) {
                        this->ControlBlock = other.ControlBlock;
                    }
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (other.ControlBlock > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }
                else {}
            }
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            void NonNullchecked_MoveConstructorFromOtherType(SharedRef<OtherType, false>&& other) {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                    ControlBlock->IncrementWeakRefs();
                    ControlBlock->IncrementRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                    }//other.ControlBlock==2
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }//other.ControlBlock>2
                else {
                    ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                }//other.ControlBlock<=2
            }//DebugMode==false
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            void NonNullchecked_MoveAssinFromOtherType(SharedRef<OtherType, false>&& other) {
            if constexpr (DebugMode) {
                if (this->ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }//ControlBlock>2<=2
                else {
                    if (ControlBlock == 2) {
                        //do Nothing
                    }//ControlBlock==2
                    else {
                        CaseInvalid("invalid value for own Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//ControlBlock!=2
                }//ControBlock
            }//DebugMode==true
            else {
                if (ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
                    this->ControlBlock->DecrementRefs();
                }//ControlBlock>2
                else {
                    //Do Nothing
                }//ControlBlock<=2
            }//DebugMode==false
            //other Check
            if constexpr (DebugMode) {
                if (other.ControlBlock > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                    }//other.ControlBlock
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (other.ControlBlock > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(1ULL)); //-V566 //-V2571
                    this->ControlBlock->IncrementWeakRefs();
                    this->ControlBlock->IncrementRefs();
                }//other.ControlBlock>2
                else {}
            }
        }

        RefState NonNullchecked_GetRefState() {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                return RefState::Null;
                break;
            }
            case 1: {
                return RefState::Moved;
                break;
            }
            case 2: {
                return RefState::DefaultConstructed;
                break;
            }
            default: {
                return RefState::Valid;
                break;
            }
            }
        }
        Type* NonNullchecked_get() {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    return reinterpret_cast<Type*>(ControlBlock->get());
                }
                else {
                    CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    NullSelf();
                    return nullptr;

                }
            }
            else {
                return reinterpret_cast<Type*>(ControlBlock->get());
            }
        }
        Type* NonNullchecked_OperatorArrow() {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    return reinterpret_cast<Type*>(ControlBlock->get());
                }
                else {
                    CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    NullSelf();
                    return nullptr;
                }
            }
            else {
                return reinterpret_cast<Type*>(ControlBlock->get());
            }

        }
        ObjState NonNullchecked_GetObjectState() {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(ControlBlock) > 2) {
                    return ControlBlock->GetObjectState();
                }
                else {
                    CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    return ObjState::Invalid;
                }
            }
            else {
                return ControlBlock->GetObjectState();
            }

        }



        bool Generic_isValid() {
            return reinterpret_cast<uintptr_t>(ControlBlock) > static_cast<uintptr_t>(2);
        }
    public:

        SharedRef()noexcept = default;
        SharedRef(const SharedRef& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_CopyConstructFromSameType(other);
            }
            else {
                NonNullchecked_CopyConstructorFromSameType(other);
            }
        }
        SharedRef& operator=(const SharedRef& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_CopyAssignFromSameType(other);
            }
            else {
                NonNullchecked_CopyAsignFromSameType(other);
            }
            return *this;
        }
        SharedRef(SharedRef&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_MoveConstructorFromSameType(std::move(other));
            }
            else {
                NonNullchecked_MoveConstructFromSameType(std::move(other));
            }
        }
        SharedRef& operator=(SharedRef&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_MoveAssignFromSameType(std::move(other));
            }
            else {
                NonNullchecked_MoveAssignFromSameType(std::move(other));
            }
            return *this;
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            SharedRef(const SharedRef<OtherType, NullChk>& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_CopyConstructorFromOtherType(other);
            }
            else {
                NonNullchecked_CopyCostructorFromOtherType(other);
            }
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            SharedRef& operator=(const SharedRef<OtherType, NullChk>& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_CopyAssignFromOtherType(other);
            }
            else {
                NonNullchecked_CopyAssignFromOtherType(other);
            }
            return *this;
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            SharedRef(SharedRef<OtherType, NullChk>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_MoveConstructorFromOtherType(std::move(other));
            }
            else {
                NonNullchecked_MoveConstructorFromOtherType(std::move(other));
            }
        }
        template<
            typename OtherType,
            typename = std::enable_if<
            !std::is_same_v<Type, OtherType>>>
            SharedRef& operator=(SharedRef<OtherType, NullChk>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (NullChk) {
                Nullchecked_MoveAssignFromOtherType(std::move(other));
            }
            else {
                NonNullchecked_MoveAssinFromOtherType(std::move(other));
            }
            return *this;
        }
        RefState GetRefState() {
            if constexpr (NullChk) {
                return Nullchecked_GetRefState();
            }
            else {
                return NonNullchecked_GetRefState();
            }
        }
        Type* Get() {
            if constexpr (NullChk) {
                return Nullchecked_Get();
            }
            else {
                return NonNullchecked_get();
            }
        }
        Type* operator->() {
            if constexpr (NullChk) {
                return Nullchecked_OpperatorArrow();
            }
            else {
                return NonNullchecked_OperatorArrow();
            }
        }
        ObjState GetObjectState() {
            if constexpr (NullChk) {
                return Nullchecked_GetObjectState();
            }
            else {
                return NonNullchecked_GetObjectState();
            }
        }
        bool IsValid() {
            return Generic_isValid();
        }










        template< typename... Args>
        static SharedRef<Type,NullChk> Create(Args&&... args) {
            SharedControlBlock<Type,NullChk>* controlBlock = new SharedControlBlock<Type, NullChk>();
            controlBlock->CreatObject_Internal<Type>(std::forward<Args>(args)...);//= new Type(std::forward<Args>(args)...);
            SharedRef<Type,NullChk> ownedRef;
            ownedRef.ControlBlock = controlBlock;
            return ownedRef;
        }//Create

    };


    //TODO implement
   // template<typename Type,bool NullCheck> using SharedRef = SharedRef_<Type,NullCheck>
}
#endif