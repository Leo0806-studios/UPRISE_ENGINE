// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module UPRISE_ENGINE_CORE:OWNED_REF;
import :WEAK_REF;
import :WRAPPER_BASE;
import :CONTROL_BASE;
import :OWNED_CONTROLBLOCK;
import <functional>;
export namespace UPRISE_ENGINE {
    template <typename Type>
    class OwnedRef :public WrapperBase {

    public:

        OwnedRef()noexcept = default;
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
                ControlBlock->DecrementWeakrefs();

                reinterpret_cast<OwnedControlBlock<Type>*>(ControlBlock)->DecrementRefs();
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
                this->ControlBlock =  std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(2ULL));
                break;
            }
            }


            
            
        }//OwnedRef(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false)

        OwnedRef& operator=(OwnedRef<Type>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_==false) {
            switch (reinterpret_cast<uintptr_t>(this->ControlBlock)) {
            case 0: {
                CaseNull("COntrolBlock of \"this\" was null (0). this is an error in the program");
                break;
            }
            case 1:{
                break;
            }
            case 2: {
                break;
            }
            default: {
                this->ControlBlock->DecrementWeakrefs();
                this->ControlBlock->DecrementRefs();
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
            case 2:{
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed(" \"other\" was default constructed (2). this might be an error in the program");
                }
                break;
            }
            default: {
                this->ControlBlock = std::exchange(other.ControlBlock, IntegerTypeToPointer<ControlBlock_Base>(2ULL));
                break;
            }
            }
            return *this;
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
    };
    typedef OwnedRef<int> UE_DEBUG_INTOWNEDREF;
}