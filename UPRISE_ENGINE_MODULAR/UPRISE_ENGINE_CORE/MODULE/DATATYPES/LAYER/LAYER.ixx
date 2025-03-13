export module UPRISE_ENGINE_CORE:LAYER;
import  std;
export namespace UPRISE_ENGINE {
    //cant prvent padding. 
    //disabeling warning for this class
#pragma warning(push)
#pragma warning(disable: 4820)
#pragma warning (push)
#pragma warning(disable: 4514)
    /// <summary>
/// layer for GameObjects
/// </summary>
    class  Layer {
    private:
        /// <summary>
/// layer id
/// </summary>
        int id = -1;
        /// <summary>
/// layer name
/// </summary>
        std::string name{};


    public:
#pragma region constructor
        /// <summary>
        /// default cosntructor
        /// </summary>
        UPRISE_CORE_API Layer() = default;

        /// <summary>
        /// constructor that accsepts an id and name
        /// </summary>
        /// <param name="id"></param>
        /// <param name="name"></param>
        UPRISE_CORE_API Layer(int id, std::string name) :id(id), name(name) {};
#pragma endregion
        /// <summary>
        /// getter for the name of the layer
        /// returns the name of the layer as a non const reference
        /// </summary>
        /// <returns></returns>
        __inline UPRISE_CORE_API  std::string& Name() { return name; }

        /// <summary>
        /// getter for the id of the layer
        /// returns the id of the layer
        /// <summary>
        __inline UPRISE_CORE_API int ID() const { return id; }
        __inline UPRISE_CORE_API int SetID(int i) { id = i; return id; }
    };
}
#pragma warning(pop)
#pragma warning(pop)