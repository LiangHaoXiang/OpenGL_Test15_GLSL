#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;


layout (std140) uniform Matrices
{
                        // 基准对齐量       // 对齐偏移量
    mat4 projection;    //  16                  0
    mat4 view;          //  16                  16
};

out vec2 TexCoords;

uniform mat4 model;

void main()
{
    TexCoords = aTexCoords;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
