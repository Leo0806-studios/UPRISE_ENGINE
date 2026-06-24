import UE_SERIALISATION;
import std;
namespace UPRISE_ENGINE::SERIALISATION {
    bool MemberInfo::CheckType(std::string type) const
    {
        const SerializedTypeInfo* typeInfoMember = RTTIStorage::Get(type);

        return typeInfoMember && (*typeInfoMember == *this->typeInfo);
    }
    bool MemberInfo::CheckClassType(std::string type) const
    {
        const SerializedTypeInfo* typeInfoMember = RTTIStorage::Get(type);

        return typeInfoMember && (*typeInfoMember == *this->classType);
    }

    void MemberInfo::SetRaw(void* obj, void* value, bool assign) const {
        if (reinterpret_cast<std::uintptr_t>(obj) % classType->Alignment()) {
            throw AlignmentException("Object buffer is not properly aligned");
        }
        if (reinterpret_cast<std::uintptr_t>(value) % typeInfo->Alignment()) {
            throw AlignmentException("Value buffer is not properly aligned");
        }
        if (typeInfo->IsTriviallyCopyable()) {
            std::memcpy(reinterpret_cast<uint8_t*>(obj) + offset, value, typeInfo->Size()); //trivially copiable does not differentiate between construction and assignment 
        }
        else if (assign) {
            if (typeInfo->IsCopyAssignable()) {
                auto CopyAsssign = typeInfo->GetFunctionMember(std::format("{}& operator=(const {}&)", typeInfo->Name(), typeInfo->Name()));
                void* params[] = { value };
                CopyAsssign->InvokeRaw(obj, params, obj);
            }
            else {
                throw MemberNotFoundException(std::format("member {} of type {} on type {} is not copy assignable", name, typeInfo->Name(), classType->Name()), MemberType::Member);
            }
        }
        else {
            if (typeInfo->IsCopyConstructible()) {
                auto CopyConstructor = typeInfo->GetConstructor(std::format("Constructor(const {}&)", typeInfo->Name()));
                void* params[] = { value };
                CopyConstructor->InvokeRaw(reinterpret_cast<uint8_t*>(obj) + offset, params);
            }
            else {
                throw MemberNotFoundException(std::format("member {} of type {} on type {} is not copy constructible", name, typeInfo->Name(), classType->Name()), MemberType::Member);
            }
        }
    }

    void MemberInfo::GetRaw(void* obj, void* out, bool assign) const {
        if (reinterpret_cast<uintptr_t>(obj) % classType->Alignment()) {
            throw AlignmentException("Object buffer is not properly aligned");
        }
        if (reinterpret_cast<uintptr_t>(out) % typeInfo->Alignment()) {
            throw AlignmentException("Output buffer is not properly aligned");
        }
        if (typeInfo->IsTriviallyCopyable()) {
            std::memcpy(out, reinterpret_cast<uint8_t*>(obj) + offset, typeInfo->Size()); //trivially copiable does not differentiate between construction and assignment 

        }
        else if (assign) {
            if (typeInfo->IsCopyAssignable()) {
                auto CopyAsssign = typeInfo->GetFunctionMember(std::format("{}& operator=(const {}&)", typeInfo->Name(), typeInfo->Name()));
                void* params[] = { static_cast<void*>(reinterpret_cast<uint8_t*>(obj) + offset) };
                CopyAsssign->InvokeRaw(obj, params, out);
            }
            else {
                throw MemberNotFoundException(std::format("member {} of type {} on type {} is not copy assignable", name, typeInfo->Name(), classType->Name()), MemberType::Member);
            }
        }
        else {
            if (typeInfo->IsCopyConstructible()) {
                auto CopyConstructor = typeInfo->GetConstructor(std::format("Constructor(const {}&)", typeInfo->Name()));
                void* params[] = { static_cast<void*>(reinterpret_cast<uint8_t*>(obj) + offset) };
                CopyConstructor->InvokeRaw(out, params);


            }
            else {
                throw MemberNotFoundException(std::format("member {} of type {} on type {} is not copy constructible", name, typeInfo->Name(), classType->Name()), MemberType::Member);
            }
        }
    }


    bool ConstructorInfo::CheckTypes(std::vector<std::string> params)const
    {
        std::vector<const SerializedTypeInfo*> paramTypeInfos;
        for (const auto& param : params) {
            const auto* const  typeInfo = RTTIStorage::Get(param);
            if (!typeInfo) {
                return false;
            }
            paramTypeInfos.push_back(typeInfo);
        }
        for (size_t i = 0; i < Parameters.size(); ++i) {
            if (!paramTypeInfos[i] || !Parameters[i]) {
                return false;
            }
            if (!(*paramTypeInfos[i] == *Parameters[i])) {
                return false;
            }
        }
        return true;
    }
    bool FunctionMemberInfo::CheckTypes(std::vector<std::string> params)const
    {
        std::vector<const SerializedTypeInfo*> paramTypeInfos;
        for (const auto& param : params) {
            const auto* const  typeInfo = RTTIStorage::Get(param);
            if (!typeInfo) {
                return false;
            }
            paramTypeInfos.push_back(typeInfo);
        }
        for (size_t i = 0; i < Parameters().size(); ++i) {
            if (!paramTypeInfos[i] || !Parameters()[i]) {
                return false;
            }
            if (!(*paramTypeInfos[i] == *Parameters()[i])) {
                return false;
            }
        }
        return true;

    }
    bool FunctionMemberInfo::CheckClassType(std::string params) const
    {
        auto* typeInfoMember = RTTIStorage::Get(params);
        if (!typeInfoMember) {
            return false;
        }
        if (!classType) {
            return false;
        }
        if (*typeInfoMember == *classType) {
            return true;
        }
        return false;
    }
    bool UPRISE_ENGINE::SERIALISATION::DestructorInfo::CheckClassType(std::string params) const
    {
        auto* typeInfoMember = RTTIStorage::Get(params);
        if (!typeInfoMember) {
            return false;
        }
        if (!classType) {
            return false;
        }
        if (*typeInfoMember == *classType) {
            return true;
        }
        return false;
    }
}