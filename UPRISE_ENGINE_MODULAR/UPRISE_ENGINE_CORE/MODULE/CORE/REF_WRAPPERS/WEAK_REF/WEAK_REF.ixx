export module UPRISE_ENGINE_CORE:WEAK_REF;
import :WRAPPER_BASE;
import :CONTROL_BASE;
export namespace UPRISE_ENGINE {
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
        ~WeakRef()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
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
            }
            }
        }
#pragma region SelfType


        WeakRef(const WeakRef<Type, true>& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) :ControlBlock(other.ControlBlock) {

            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("it is not legal to copy a null Ref");
                NullSelf();
                break;
            }
            case 1: {
                CaseMoved("it is not legal to copy construct from a moved from ref");
                NullSelf();
            }
            case 2: {
                if constexpr (WarningLevel >= 3) {
                    CaseDefaultConstructed("while it is legal to copy construct from a default constructed ref this may indicate an error in the program");

                }
                break;
            }

            UE_LIKELY default: {
                ///assume that all other values are valid
                ControlBlock->IncrementWeakRefs();

            }
            }

        }
        WeakRef& operator=(const WeakRef<Type, true>& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
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


            switch (reinterpret_cast<unsigned long long>(other.ControlBlock)) {
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
                this->ControlBlock->IncrementWeakRefs();

                break;

            }
            }
        }
        /// <summary>
        /// move constructor.
        /// no nullcheck is neccesary bc no reff count has to be decremented or incremented
        /// </summary>
        /// <param name="other"></param>
        WeakRef(WeakRef<Type, true>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false)
        {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("Control Block of \"this\" was null (0, nullptr). ");
                NullSelf();
                break;
            }
            case 1: {
                //it is to move into a moved from object
                break;
            }
            case 2: {
                ///iz is perfectly legal to move into a default constructed object
            }
            default: {
                ///assume all other values are valid
                this->ControlBlock->DecrementWeakrefs();
                break;
            }
            }

            switch (reinterpret_cast<unsigned long long>(other.ControlBlock)) {

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
                UE_FALLTHROUGH;
            }
            default: {
                ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<UPRISE_ENGINE::ControlBlock_Base*>(1ULL));
            }
            }
        }
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

            switch (reinterpret_cast<unsigned long long>(other.ControlBlock)) {
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
                UE_FALLTHROUGH;
            }
            UE_LIKELY default: {
                this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));

                ///assume all othher values are valid
            }
            }

        }
#pragma endregion


#pragma region OtherType


        /// <summary>
        /// Copy construct from convertible
        /// that means that OtherType and type are somehow related.
        /// performs one nullcheck if other is valid
        /// </summary>
        /// <typeparam name="OtherType"></typeparam>
        /// <typeparam name=""></typeparam>
        /// <param name="other"></param>
        template<
            typename OtherType,
            typename = std::enable_if<
            std::is_convertible_v<OtherType, Type>>>
            WeakRef(const WeakRef<OtherType, true>& other) : ControlBlock(other.ControlBlock) {

            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" other\" was null while trying to copy(func sig :WeakRef(const WeakRef<Type, true>& other)  )");
                NullSelf();
                break;
            }
            case 1: {
                CaseMoved("trying to copy a moved from ref (func sig : WeakRef(const WeakRef<Type, true>& other) )");
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
                ControlBlock->IncrementWeakRefs();
            }
            }

        }

        template<
            typename OtherType,
            typename = std::enable_if<
            std::is_convertible_v<OtherType, Type>>>
            WeakRef& operator=(const WeakRef<OtherType, true>& other) {
            if (&other = this) UE_UNLIKELY{
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
            }
            }
        }

        template<
            typename OtherType,
            typename = std::enable_if<
            std::is_convertible_v<OtherType, Type>>>
            WeakRef(WeakRef<OtherType, true>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
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
                ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<UPRISE_ENGINE::ControlBlock_Base*>(1ULL));
            }
            }

        }


        template<
            typename OtherType,
            typename = std::enable_if <
            std::is_convertible_v<OtherType, Type>>>
            WeakRef& operator=(WeakRef<OtherType, true>&& other)noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if (this == &other)UE_UNLIKELY{
                CaseSelfAsign("while it is legal to self asign it is very likely an error in the program or at the very least a performance loss");
            }
                switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
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
                UE_FALLTHROUGH;
            }
            default: {
                this->ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                ///assume all othher values are valid
            }
            }
        }

#pragma endregion



        bool isValid()const noexcept {
            return ControlBlock > 2;
        }
        RefState GetRefState()const noexcept {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                return RefState::Null;
            }
            case 1: {
                return RefState::Moved;
            }
            case 2: {
                return RefState::DefaultConstructed;
            }
            default: {
                return RefState::Valid;
            }
            }
        }

        Type* get()const noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" this\" was null (0) while trying to get the object");
                NullSelf();
                return nullptr;
            }
            case 1: {
                CaseMoved("ControlBlock of \" this\" was moved from (1) while trying to get the object");
                NullSelf();
                return nullptr;
            }
            case 2: {
                CaseDefaultConstructed("it is illegal to deref a never assigned ref");
                NullSelf();
                return nullptr;
            }
            default: {
                return reinterpret_cast<Type*>(ControlBlock->get());
            }

            }
        }
        Type* operator->()const noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                CaseNull("ControlBlock of \" this\" was null (0) while trying to get the object");
                NullSelf();
                return nullptr;
            }
            case 1: {
                CaseMoved("ControlBlock of \" this\" was moved from (1) while trying to get the object");
                NullSelf();
                return nullptr;
            }
            case 2: {
                CaseDefaultConstructed("it is illegal to deref a never assigned ref");
                NullSelf();
                return nullptr;
            }
            default: {
                return reinterpret_cast<Type*>(ControlBlock->get());
            }
            }
        }
    };//WeakRef<Type, true> class

    template<typename Type>
    class WeakRef<Type, false> :WrapperBase {
        template<typename T, bool NC> friend class WeakRef;
        friend class CreateRefs;

    public:

        WeakRef()noexcept = default;
        ~WeakRef()noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (DebugMode) {
                if (ControlBlock > 2) {
                    ControlBlock->DecrementWeakrefs();
                }
                else {
                    if (ControlBlock == 2) {
                        //nothing to do for default objects (that have never been used 
                    }
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }
                }
            }
            else {
                if (ControlBlock > 2) {
                    ControlBlock->DecrementWeakrefs();
                }
                else {
                    //dont do anything
                }
            }
        }//~WeakRef()


        WeakRef(const WeakRef<Type, false>& other) {

            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = other.ControlBlock;
                    ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = other.ControlBlock;
                    }//other.ControlBlock==2
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");

                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    this->ControlBlock = other.ControlBlock;
                }//other.ControlBlock<=2
            }//DebugMode==false
        }

        WeakRef& operator=(const WeakRef<Type, false>& other) {
            if constexpr (DebugMode) {
                if (this->ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
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
                }//ControlBlock>2
                else {
                    //Do Nothing
                }//ControlBlock<=2
            }//DebugMode==false

            //other Check
            if constexpr (DebugMode) {
                if (other.ControlBlock > 2) {

                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        this->ControlBlock = other.ControlBlock;
                    }//other.ControlBlock
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (other.ControlBlock > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();

                }//other.ControlBlock>2
                else {

                    //do Nothing
                }//other.ControlBlock<=2

            }//DebugMode==false;
        }//WeakRef& operator=(const WeakRef<Type,false>& other)

        WeakRef(WeakRef<Type, false>&& other) {

            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    }//other.ControlBlock==2
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");

                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));


                }//other.ControlBlock<=2
            }//DebugMode==false

        }//WeakRef(WeakRef<Type,false>&& other)

        WeakRef& operator=(WeakRef<Type, false>&& other) {
            if constexpr (DebugMode) {
                if (this->ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
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
                }//ControlBlock>2
                else {
                    //Do Nothing
                }//ControlBlock<=2
            }//DebugMode==false

            //other Check
            if constexpr (DebugMode) {
                if (other.ControlBlock > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));

                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));

                    }//other.ControlBlock
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (other.ControlBlock > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));

                    this->ControlBlock->IncrementWeakRefs();

                }//other.ControlBlock>2
                else {

                    //do Nothing
                }//other.ControlBlock<=2

            }//DebugMode==false;
        }

        template<
            typename OtherType,
            typename = std::enable_if<
            std::is_convertible_v<OtherType, Type>>>
            WeakRef(const WeakRef<OtherType, false>& other) {
            if constexpr (DebugMode) {
                if (ControlBlock > 2) {
                    ControlBlock = other.ControlBlock;
                    ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = other.ControlBlock;
                    }//other.ControlBlock==2
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");

                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (ControlBlock > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    this->ControlBlock = other.ControlBlock;
                }//other.ControlBlock<=2

            }//DebugMode==false
        }//WeakRef(const WeakRef<OtherType,false>& other)

        template<
            typename OtherType,
            typename = std::enable_if<
            std::is_convertible_v<OtherType, Type>>>
            WeakRef& operator=(const WeakRef<OtherType, false>& other) {
            if constexpr (DebugMode) {
                if (this->ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
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
                }//ControlBlock>2
                else {}
            }//DebugMode==false
            //other Check
            if constexpr (DebugMode) {
                if (other.ControlBlock > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        this->ControlBlock = other.ControlBlock;
                    }//other.ControlBlock
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (other.ControlBlock > 2) {
                    this->ControlBlock = other.ControlBlock;
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {}
            }//DebugMode==false;
        }//WeakRef& operator=(const WeakRef<OtherType,false>& other)
        template<
            typename OtherType,
            typename = std::enable_if <
            std::is_convertible_v<OtherType, Type>>>
            WeakRef(WeakRef<OtherType, false>&& other) {
            if constexpr (DebugMode) {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    }//other.ControlBlock==2
                    else {
                        CaseInvalid("invalid value for Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (reinterpret_cast<uintptr_t>(other.ControlBlock) > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                }//other.ControlBlock<=2
            }//DebugMode==false
        }//WeakRef(WeakRef<Type,false>&& other)
        template<
            typename OtherType,
            typename = std::enable_if <
            std::is_convertible_v<OtherType, Type>>>
            WeakRef& operator=(WeakRef<OtherType, false>&& other) {
            if constexpr (DebugMode) {
                if (this->ControlBlock > 2) {
                    this->ControlBlock->DecrementWeakrefs();
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
                }//ControlBlock>2
                else {
                    //Do Nothing
                }//ControlBlock<=2
            }//DebugMode==false
            //other Check
            if constexpr (DebugMode) {
                if (other.ControlBlock > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {
                    if (other.ControlBlock == 2) {
                        ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    }//other.ControlBlock
                    else {
                        CaseInvalid("invalid value for other Controlblock. this will only show up in debug mode. in release mode it will just crash or leak");
                    }//other.ControlBlock!=2
                }//other.ControlBlock<=2
            }//DebugMode==true
            else {
                if (other.ControlBlock > 2) {
                    ControlBlock = std::exchange(other.ControlBlock, reinterpret_cast<ControlBlock_Base*>(1ULL));
                    this->ControlBlock->IncrementWeakRefs();
                }//other.ControlBlock>2
                else {}
            }//DebugMode==false;
        }
        bool isValid()const noexcept {
            return ControlBlock > 2;
        }
        RefState GetRefState()const noexcept {
            switch (reinterpret_cast<unsigned long long>(ControlBlock)) {
            case 0: {
                return RefState::Null;
            }
            case 1: {
                return RefState::Moved;
            }
            case 2: {
                return RefState::DefaultConstructed;
            }
            default: {
                return RefState::Valid;
            }
            }
        }
        Type* get()const noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (DebugMode) {
                if (ControlBlock > 2) {
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
        Type* operator->()const noexcept(RW_USE_CPP_EXCEPTIONS_ == false) {
            if constexpr (DebugMode) {
                if (ControlBlock > 2) {
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
    };
    typedef WeakRef<int, true> __DebugWeakRefIntTrue;
}