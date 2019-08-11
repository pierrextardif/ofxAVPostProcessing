
uniform float turbulenceActive;

uniform float u_amount_x;
uniform float u_amount_y;

float rand(vec2 st, float t){
    return fract(sin(dot(st.xy + fract(t*0.0013) ,vec2(12.9898,78.233))) * 43758.5453);
}

vec2 turbulence(vec2 vUv, float iTime){
    vec2 st = vUv;
    vec2 dt;
    
    float amtx = u_amount_x * u_amount_x * 0.2;
    float amty = u_amount_y * u_amount_y * 0.2;
    
    dt.x = st.x + (rand(st, iTime)*resolution.x * 2 - resolution.x) * amtx;
    dt.y = st.y + (rand(st, iTime)*resolution.y * 2 - resolution.y) * amty;
    
    return dt;
}
