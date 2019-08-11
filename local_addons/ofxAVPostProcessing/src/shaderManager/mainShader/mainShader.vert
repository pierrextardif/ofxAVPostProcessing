#version 330

uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

out vec2 vUv;

void main()
{
    vUv = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
    
}
