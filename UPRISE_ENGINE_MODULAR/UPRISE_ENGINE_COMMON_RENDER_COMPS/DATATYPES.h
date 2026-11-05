#pragma once
#include <vector>
#include <VECTOR3.h>
#include <VECTOR2.h>
namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {
    class ShaderProgram;
    namespace DATATYPES {
    class Vertex {
    public:
        UPRISE_ENGINE::DATATYPES::Vector3 position;
        UPRISE_ENGINE::DATATYPES::Vector3 normal;
        UPRISE_ENGINE::DATATYPES::Vector2 uv;
    };
    class Mesh {
        std::vector<Vertex> vertices;
};
    class Model {
        std::vector<Mesh> meshes;
    };
}
}