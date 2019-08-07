#version 150

in vec2 vUv;
out vec4 outputColor;

uniform vec2 u_resolution;
uniform float u_time;
uniform sampler2DRect tex0;

uniform float u_amount_x;
uniform float u_amount_y;

float rand(vec2 st, float t){
    return fract(sin(dot(st.xy + fract(t*0.0013) ,vec2(12.9898,78.233))) * 43758.5453);
}

void main(){
    vec2 st = vUv;
    vec2 dt;
    
    float amtx = u_amount_x * u_amount_x * 0.2;
    float amty = u_amount_y * u_amount_y * 0.2;
    
    dt.x = st.x + (rand(st, u_time)*u_resolution.x * 2 - u_resolution.x) * amtx;
    dt.y = st.y + (rand(st, u_time)*u_resolution.y * 2 - u_resolution.y) * amty;
    
    vec4 source = texture( tex0, dt );
    
    outputColor = source;
}
