import UE_SERIALISATION;
import std;
namespace UPRISE_ENGINE::SERIALISATION {
 bool MemberInfo::CheckType(std::string type) const
    {
     const SerializedTypeInfo* typeInfoMember = RTTIStorage::TryGetTypeInfo(type);
     return typeInfoMember && (*typeInfoMember == *this->typeInfo);
    }


     bool ConstructorInfo::CheckTypes(std::vector<std::string> params)const
    {
         std::vector<const SerializedTypeInfo*> paramTypeInfos;
         for (const auto& param : params) {
             paramTypeInfos.push_back(RTTIStorage::TryGetTypeInfo(param));
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
            paramTypeInfos.push_back( RTTIStorage::TryGetTypeInfo(param));
        }
        for (size_t i = 0; i < Parameters.size(); ++i) {
            if (!paramTypeInfos[i] || !Parameters[i]) {
                return false;
            }
            if (!(*paramTypeInfos[i]==*Parameters[i])) {
                return false;
            }
        }
        return true;

    }
}