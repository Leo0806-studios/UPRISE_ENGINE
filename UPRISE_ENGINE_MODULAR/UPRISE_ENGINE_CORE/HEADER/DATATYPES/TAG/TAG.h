// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_TAG_
#define UE_TAG_
import std; //-V2575 //-V3549
namespace UPRISE_ENGINE {
#pragma warning(disable:4820)
#pragma warning(disable: 4514)

    /// <summary>
/// class that represents the tag of a gameobject
/// </summary>
    class  Tag {
    private:
/// <summary>
/// name of the tag
/// </summary>
        std::string name;
        /// <summary>
        /// id of the tag
        /// </summary>
        int id;

    public:
#pragma region constructor
        /// <summary>
        /// default constructor
        /// </summary>
        UPRISE_CORE_API Tag() = default;
        /// <summary>
        /// constructor that takes in the id and name of the tag
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        UPRISE_CORE_API  Tag(int id, std::string name) : name(name), id(id) {};
#pragma endregion
        /// <summary>
        /// getter that returns a non const reference to the name of the tag
        /// </summary>
        /// <returns></returns>
        UPRISE_CORE_API __inline std::string& Name() { return name; }
        /// <summary>
        /// returns the id of the tag
        /// </summary>
        /// <returns></returns>
        UPRISE_CORE_API __inline int ID() const { return id; }
    };
#pragma warning(default:4820)
#pragma warning(default: 4514)
}

#endif // !1
