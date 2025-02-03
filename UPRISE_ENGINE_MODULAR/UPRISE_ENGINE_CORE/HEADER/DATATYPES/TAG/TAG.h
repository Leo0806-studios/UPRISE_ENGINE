// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_TAG_
#define UE_TAG_
import std; //-V2575 //-V3549
namespace UPRISE_ENGINE {
    /// <summary>
/// class that represents the tag of a gameobject
/// </summary>
    class UPRISE_CORE_API Tag {
    private:
        /// <summary>
        /// id of the tag
        /// </summary>
        int id;
        /// <summary>
        /// name of the tag
        /// </summary>
        std::string name;
    public:
#pragma region constructor
        /// <summary>
        /// default constructor
        /// </summary>
        Tag() = default;
        /// <summary>
        /// constructor that takes in the id and name of the tag
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        Tag(int id, std::string name) :id(id), name(name) {};
#pragma endregion
        /// <summary>
        /// getter that returns a non const reference to the name of the tag
        /// </summary>
        /// <returns></returns>
        __inline std::string& Name() { return name; }
        /// <summary>
        /// returns the id of the tag
        /// </summary>
        /// <returns></returns>
        __inline int ID() { return id; }
    };
}

#endif // !1
