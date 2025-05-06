#pragma once
#pragma once
#ifndef SHARED_CONTROL_BLOCK_INTERNAL
#define SHARED_CONTROL_BLOCK_INTERNAL
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "atomic"
#include "REF_WRAPPERS/CONTROLL_BLOCKS/CONTROL_BASE/CONTROL_BASE_INTERNAL.h"
#endif // __INTELLISENSE__


namespace UPRISE_ENGINE {
    template<typename Type, bool Nullcheck>
    class SharedControlBlock :public ControlBlock_Base {
        //template<class Ty, bool NC> class SharedControlBlock;
        /// <summary>
        /// Oject Pointer
        /// possible values
        /// 0 = null
        /// 1=manualy deleted
        /// everything else is a valid object (asummed. if not there is a bug in the program)
        /// </summary>
        Type* Object = nullptr;

        void NullChecked_Destroy()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(this->Object)) {
            case 0: {
                CaseNull("the Object Ptr \"this\" was null (0) while trying to destroy. this is an error in the program");
                break;
            }
            case 1: {
                if constexpr (RuntimeWarnings == true) {
                    CaseDeletedManualy("Object was allready deleted manualy while trying to destroy. this may be an error in the programm. this will only show up with RuntimeWarnings enabled");
                }
                break;
            }
            UE_LIKELY default: {
                if constexpr (std::is_array_v<Type>) {
                    delete[] this->Object;//Linter warning is false positive as this is a smart pointer implementation //-V2511
                    this->Object = nullptr;
                }
                else {
                    delete this->Object;// Linter warning is false positive as this is a smart pointer implementation //-V2511
                    this->Object = nullptr;
                }
                break;
            }

            }
        }

        void* Nullchecked_Get() {
            switch (reinterpret_cast<uintptr_t>(Object)) {
            case 0: {
                CaseNull("Object Wass null while trying to get");
                return nullptr;
                break;
            }
            case 1: {
                CaseDeletedManualy("Object was manualy deleted while trying to get");
                return nullptr;
                break;
            }
            default: {
                return static_cast<void*>(Object);
            }
            }
            return nullptr;
        }

        void NullChecked_DeleteManualy(){
            switch (reinterpret_cast<uintptr_t>(Object)) {
            case 0: {
                CaseNull("the object was null while trying to delete manualy");
                break;
            }
            case 2: {
                CaseDeletedManualy("the object was allready manualy deleted");
                break;
            }
            default: {
                if constexpr (std::is_array_v<Type>) {
                    delete[] Object;//Linter false positive as this is in a smart pointer implementation
                }
                else {
                    delete Object;//Linter false positive as this is a smart pointer implementation
                }
                Object = reinterpret_cast<Type*>(1ULL);
            }
            }
        }




        void NonNullchecked_Destroy() {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(Object) > 1) {
                    if constexpr (std::is_array_v<Type>) {
                        delete[] Object; //linter false positive. this is part of a smar pointer implementaton
                        Object = nullptr;
                    }
                    else {
                        delete Object;//linter false positive. this is part of a smart pointer implementation
                        Object = nullptr;
                    }
                }
                else {
                    CaseInvalid("The Object Pointer Contains an invalid value. This messag will only show up in Debug mode. In release mode it will just crash or leak");
                }
            }
            else {
                if (Object) {
                    if constexpr (std::is_array_v<Type>) {
                        delete[] Object;//linter false positive. this is part of a smart pointer implementation
                        Object == nullptr;
                    }
                    else {
                        delete Object;//linter false positive. this is part of a smart ponter implementation
                        Object = nullptr;
                    }

                }


            }
        }
        void* NonNullchecked_Get() {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(Object) > 1) {
                    return static_cast<void*>(Object);
                }
                else {
                    CaseInvalid("The Object Pointer Contains an invalid value. This messag will only show up in Debug mode. In release mode it will just crash or leak");

                    return nullptr;
                }
            }
            else {
                if (Object) {
                    return static_cast<void*>(Object);
                }
                else {
                    return nullptr;
                }
            }
            return nullptr;
        }
        void NonNullChecked_DeleteManualy() {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(Object) > 1) {
                    if constexpr (std::is_array_v<Type>) {
                        delete[] Object; //linter false positive. this is part of a smar pointer implementaton
                        Object = reinterpret_cast<Type*>(1ULL);
                    }
                    else {
                        delete Object;//linter false positive. this is part of a smart pointer implementation
                        Object = reinterpret_cast<Type*>(1ULL);

                    }
                }
                else {
                    CaseInvalid("The Object Pointer Contains an invalid value. This messag will only show up in Debug mode. In release mode it will just crash or leak");
                }
            }
            else {
                if (Object) {
                    if constexpr (std::is_array_v<Type>) {
                        delete[] Object;//linter false positive. this is part of a smart pointer implementation
                        Object = reinterpret_cast<Type*>(1ULL);

                    }
                    else {
                        delete Object;//linter false positive. this is part of a smart ponter implementation
                        Object = reinterpret_cast<Type*>(1ULL);

                    }

                }


            }
        }







        // Inherited via ControlBlock_Base
        void IncrementRefs() noexcept override
        {
            Refs.fetch_add(1, std::memory_order_relaxed);
        }

        void IncrementWeakRefs() noexcept override
        {
            WeakRefs.fetch_add(1, std::memory_order_relaxed);
        }

        void DecrementRefs() noexcept override
        {
            if (Refs.fetch_sub(1, std::memory_order_acquire) == 1) {
                if (Nullcheck) {
                    NullChecked_Destroy();
                }
                else {
                    NonNullchecked_Destroy();
                }
            }

        }

        void DecrementWeakrefs() noexcept override
        {
            if (WeakRefs.fetch_sub(1, std::memory_order_acquire) == 1) {
                Delete();
            }
        }

        void* get() override
        {
            if constexpr (Nullcheck) {
                return Nullchecked_Get();
            }
            else {
                return NonNullchecked_Get();
            }
        }

        void DeleteManualy() override
        {
            if constexpr (Nullcheck) {
                NullChecked_DeleteManualy();
            }
            else {
                NonNullChecked_DeleteManualy();
            }
        }

        ObjState GetObjectState() override
        {
            switch (reinterpret_cast<uintptr_t>(Object)) {
            case 0: {
                return ObjState::Null;
                break;

            }
            case 1: {
                return ObjState::ManualyDeleted;
                break;
            }
            default: {
                return ObjState::Valid;
                break;
            }
            }
        }

        public:
            SharedControlBlock() = default;
            SharedControlBlock(const SharedControlBlock<Type, true>& other) = delete;
            SharedControlBlock& operator=(const SharedControlBlock<Type, true>& other) = delete;
            SharedControlBlock(SharedControlBlock<Type, true>&& other) = delete;
            SharedControlBlock& operator=(SharedControlBlock<Type, true>&& other) = delete;      
            
            SharedControlBlock(const SharedControlBlock<Type, false>& other) = delete;
            SharedControlBlock& operator=(const SharedControlBlock<Type, false>& other) = delete;
            SharedControlBlock(SharedControlBlock<Type, false>&& other) = delete;
            SharedControlBlock& operator=(SharedControlBlock<Type, false>&& other) = delete;
    };

    //template<typename Type>
    //class SharedControlBlock<Type, true> :public ControlBlock_Base {
    //    template<class Ty, bool NC> class SharedControlBlock;
    //    /// <summary>
    //    /// Oject Pointer
    //    /// possible values
    //    /// 0 = null
    //    /// 1=manualy deleted
    //    /// everything else is a valid object (asummed. if not there is a bug in the program)
    //    /// </summary>
    //    Type* Object = nullptr;
    //    void Destroy()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
    //        switch (reinterpret_cast<uintptr_t>(this->Object)) {
    //        case 0: {
    //            CaseNull("the Object Ptr \"this\" was null (0) while trying to destroy. this is an error in the program");
    //            break;
    //        }
    //        case 1: {
    //            if constexpr (RuntimeWarnings == true) {
    //                CaseDeletedManualy("Object was allready deleted manualy while trying to destroy. this may be an error in the programm. this will only show up with RuntimeWarnings enabled");
    //            }
    //            break;
    //        }
    //        UE_LIKELY default: {
    //            if constexpr (std::is_array_v<Type>) {
    //                delete[] this->Object;//Linter warning is false positive as this is a smart pointer implementation //-V2511
    //                this->Object = nullptr;
    //            }
    //            else {
    //                delete this->Object;// Linter warning is false positive as this is a smart pointer implementation //-V2511
    //                this->Object = nullptr;
    //            }
    //            break;
    //        }
    //        }
    //    }
    //    void IncrementRefs()noexcept override final {
    //        Refs.fetch_add(1, std::memory_order_relaxed);
    //    }
    //    void IncrementWeakRefs()noexcept override final {
    //        WeakRefs.fetch_add(1, std::memory_order_relaxed);
    //    }
    //    void DecrementRefs() noexcept(RW_USE_CPP_EXCEPTIONS_ == false) override final {
    //        if (Refs.fetch_sub(1, std::memory_order_acquire) == 1) {
    //            Destroy();
    //        }
    //    }
    //    void DecrementWeakrefs()noexcept override final {
    //        if (WeakRefs.fetch_sub(1, std::memory_order_acquire) == 1) {
    //            Delete();
    //        }
    //    }
    //    void* get() override//linter false positive as it needs to return a generic poiinter for polymorphic reasons
    //    {
    //        switch (reinterpret_cast<uintptr_t>(Object)) {
    //        case 0: {
    //            CaseNull("Object Wass null while trying to get");
    //            return nullptr;
    //            break;
    //        }
    //        case 1: {
    //            CaseDeletedManualy("Object was manualy deleted while trying to get");
    //            return nullptr;
    //            break;
    //        }
    //        default: {
    //            return static_cast<void*>(Object);
    //        }
    //        }
    //        return nullptr;
    //    }
    //    void DeleteManualy()override final {
    //        switch (reinterpret_cast<uintptr_t>(Object)) {
    //        case 0: {
    //            CaseNull("the object was null while trying to delete manualy");
    //            break;
    //        }
    //        case 2: {
    //            CaseDeletedManualy("the object was allready manualy deleted");
    //            break;
    //        }
    //        default: {
    //            if constexpr (std::is_array_v<Type>) {
    //                delete[] Object;//Linter false positive as this is in a smart pointer implementation
    //            }
    //            else {
    //                delete Object;//Linter false positive as this is a smart pointer implementation
    //            }
    //            Object = reinterpret_cast<Type*>(1ULL);
    //        }
    //        }
    //    }
    //public:
    //    SharedControlBlock() = default;
    //    SharedControlBlock(const SharedControlBlock<Type, true>& other) = delete;
    //    SharedControlBlock& operator=(const SharedControlBlock<Type, true>& other) = delete;
    //    SharedControlBlock(SharedControlBlock<Type, true>&& other) = delete;
    //    SharedControlBlock& operator=(SharedControlBlock<Type, true>&& other) = delete;
    //};
    //template<typename Type>
    //class SharedControlBlock<Type, false> :public ControlBlock_Base {
    //    template<class Ty, bool NC> class SharedControlBlock;
    //    /// <summary>
    //    /// Oject Pointer
    //    /// possible values
    //    /// 0 = null
    //    /// 1=manualy deleted
    //    /// everything else is a valid object (asummed. if not there is a bug in the program)
    //    /// </summary>
    //    Type* Object = nullptr;
    //    void Destroy() {
    //        if constexpr (DebugMode) {
    //            if (reinterpret_cast<uintptr_t>(Object) > 1) {
    //                if constexpr (std::is_array_v<Type>) {
    //                    delete[] Object; //linter false positive. this is part of a smar pointer implementaton
    //                    Object = nullptr;
    //                }
    //                else {
    //                    delete Object;//linter false positive. this is part of a smart pointer implementation
    //                    Object = nullptr;
    //                }
    //            }
    //            else {
    //                CaseInvalid("The Object Pointer Contains an invalid value. This messag will only show up in Debug mode. In release mode it will just crash or leak");
    //            }
    //        }
    //        else {
    //            if (Object) {
    //                if constexpr (std::is_array_v<Type>) {
    //                    delete[] Object;//linter false positive. this is part of a smart pointer implementation
    //                    Object == nullptr;
    //                }
    //                else {
    //                    delete Object;//linter false positive. this is part of a smart ponter implementation
    //                    Object = nullptr;
    //                }
    //            }
    //        }
    //    }
    //    // Inherited via ControlBlock_Base
    //    void IncrementRefs() noexcept override
    //    {
    //        Refs.fetch_add(1, std::memory_order_relaxed);
    //    }
    //    void IncrementWeakRefs() noexcept override
    //    {
    //        WeakRefs.fetch_add(1, std::memory_order_relaxed);
    //    }
    //    void DecrementRefs() noexcept override
    //    {
    //        if (Refs.fetch_sub(1, std::memory_order_acquire) == 1) {
    //            Destroy();
    //        }
    //    }
    //    void DecrementWeakrefs() noexcept override
    //    {
    //        if (WeakRefs.fetch_sub(1, std::memory_order_acquire) == 1) {
    //            Delete();
    //        }
    //    }
    //    void* get() override
    //    {
    //        if constexpr (DebugMode) {
    //            if (reinterpret_cast<uintptr_t>(Object) > 1) {
    //                return static_cast<void*>(Object);
    //            }
    //            else {
    //                CaseInvalid("The Object Pointer Contains an invalid value. This messag will only show up in Debug mode. In release mode it will just crash or leak");
    //                return nullptr;
    //            }
    //        }
    //        else {
    //            if (Object) {
    //                return static_cast<void*>(Object);
    //            }
    //            else {
    //                return nullptr;
    //            }
    //        }
    //        return nullptr;
    //    }
    //    void DeleteManualy() override
    //    {
    //        if constexpr (DebugMode) {
    //            if (reinterpret_cast<uintptr_t>(Object) > 1) {
    //                if constexpr (std::is_array_v<Type>) {
    //                    delete[] Object; //linter false positive. this is part of a smar pointer implementaton
    //                    Object = reinterpret_cast<Type*>(1ULL);
    //                }
    //                else {
    //                    delete Object;//linter false positive. this is part of a smart pointer implementation
    //                    Object = reinterpret_cast<Type*>(1ULL);
    //                }
    //            }
    //            else {
    //                CaseInvalid("The Object Pointer Contains an invalid value. This messag will only show up in Debug mode. In release mode it will just crash or leak");
    //            }
    //        }
    //        else {
    //            if (Object) {
    //                if constexpr (std::is_array_v<Type>) {
    //                    delete[] Object;//linter false positive. this is part of a smart pointer implementation
    //                    Object = reinterpret_cast<Type*>(1ULL);
    //                }
    //                else {
    //                    delete Object;//linter false positive. this is part of a smart ponter implementation
    //                    Object = reinterpret_cast<Type*>(1ULL);
    //                }
    //            }
    //        }
    //    }
    //};
}
#endif