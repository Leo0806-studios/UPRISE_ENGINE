export module UPRISE_ENGINE_CORE:TAG;
import std;
export namespace UPRISE_ENGINE {
#pragma warning(push)
#pragma warning(disable:4820)
#pragma warning(push)
#pragma warning(disable: 4514)

    /// <summary>
/// class that represents the tag of a gameobject
/// </summary>
    class  Tag {
    private:
        /// <summary>
        /// name of the tag
        /// </summary>
        std::string name{ "" };
        /// <summary>
        /// id of the tag
        /// </summary>
        int Id{ 0 };

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
        UPRISE_CORE_API  Tag(int id, std::string name) : name(name), Id(id) {};
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
        UPRISE_CORE_API __inline int ID() const { return Id; }
        UPRISE_CORE_API __inline void SetID(int id) { this->Id = id; }
    };
#pragma warning(pop)
#pragma warning(pop)

}