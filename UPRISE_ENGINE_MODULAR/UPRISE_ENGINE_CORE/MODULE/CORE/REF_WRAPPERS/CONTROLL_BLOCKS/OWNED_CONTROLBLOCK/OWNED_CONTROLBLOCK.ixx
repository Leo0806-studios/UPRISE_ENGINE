// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module UPRISE_ENGINE_CORE:OWNED_CONTROLBLOCK;
import :CONTROL_BASE;
import <atomic>;
export namespace UPRISE_ENGINE {
    /// <summary>
    /// Derived controlBlock for use in owned ref
    /// </summary>
    /// <typeparam name="Type"></typeparam>
    template<typename Type>
    class OwnedControlBlock:public ControlBlock_Base {
        /// <summary>
        /// Oject Pointer
        /// possible values
        /// 0 = null
        /// 1=manualy deleted
        /// everything else is a valid object (asummed if not there is a bug in the program)
        /// </summary>
        Type* Object = nullptr;
        void Destroy()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
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
            if (Refs.fetch_sub(1, std::memory_order_acquire) == 1)
            {
                Destroy();
            }

        }
        void DecrementWeakrefs() noexcept override
        {
            if (WeakRefs.fetch_sub(1, std::memory_order_acquire)==1) {
                Delete();
            }
        }
        void* get() override//linter false positive as it needs to return a generic poiinter for polymorphic reasons
        {
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
        void DeleteManualy() override
        {
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
                Object = reinterpret_cast<Type*>(1ULL);//Linter False positive. this is an intentional setting to set the pointer to a signal value
            }
            }
        }
    };
}