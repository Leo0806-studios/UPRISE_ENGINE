export module UPRISE_ENGINE_ECS:HEIGHTMAP;
import REF_WRAPPER; //-V2575 //-V3549
import std; //-V2575 //-V3549
export namespace UPRISE_ENGINE {
    /// <summary>
/// storage class for terain heightmap
/// </summary>
    class HeightMap {
    private:
        /// <summary>
        /// data storage
        /// </summary>
        std::vector<std::vector<float>> Data;
    public:
        /// <summary>
        /// default constructor
        /// </summary>
        HeightMap() = default;
        ~HeightMap() = default;
        /// <summary>
        /// get heigfht at x,y
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        UPRISE_ECS_API float GetHeight(Index x, Index y);
        /// <summary>
        /// set heigth at x,y
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="height"></param>
        /// <returns></returns>
        UPRISE_ECS_API float SetHeight(Index x, Index y, float height);

    };
}