{
    "name": "TestFShader",
    "configType": "FragmentShader",
    "modelPath": "NULL",
    "texturePaths": [
        "NULL"
    ],
    "data": {
        "LayoutVars": {
            "test": {
                "location": "1",
                "type": "vec3"
            }
        },
        "Uniforms": {
            "sampler2D": [
                "texture1",
                "texture2"
            ]
        },
        "shaderCode": [
            "#version 330 core",
            "out vec4 FragColor;",
            "in vec2 TexCoord;",
            "uniform sampler2D texture1;",
            "uniform sampler2D texture2;",
            "void main()",
            "{",
            "FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);",
            "}"
        ]
    }
}