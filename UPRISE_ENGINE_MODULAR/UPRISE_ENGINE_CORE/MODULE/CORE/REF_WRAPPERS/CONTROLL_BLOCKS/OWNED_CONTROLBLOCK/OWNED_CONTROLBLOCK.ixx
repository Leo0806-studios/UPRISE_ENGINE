export module UPRISE_ENGINE_CORE:OWNED_CONTROLBLOCK;
import :CONTROL_BASE;
export namespace UPRISE_ENGINE {
    template<typename Type>
    class OwnedControlBlock:public ControlBlock_Base {
        /// <summary>
        /// Oject Pointer
        /// possible values
        /// 0 = null
        /// 1= moved from
        /// 2=manualy deleted
        /// <=3 = valid
        /// </summary>
        Type* Object = nullptr;
        void Destroy()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<uintptr_t>(this->Object)) {
            case 0: {
                CaseNull("ControlBlock of \"this\" was null (0) while trying to destroy");
                break;
            }
            case 1: {
                CaseMoved("ControlBlock of \"this\" was moved (1) while trying to destroy");
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

                Delete();
            }

        }
        void DecrementWeakrefs() noexcept override
        {
        }
        void* get() override
        {
            return nullptr;
        }
        void DeleteManualy() override
        {
        }
    };
}