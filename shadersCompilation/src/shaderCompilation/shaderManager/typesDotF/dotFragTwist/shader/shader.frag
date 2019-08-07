#version 150


in  vec2 vUv;
out vec4 outputColor;

uniform float u_time;
uniform sampler2DRect tex0;

uniform vec2 u_resolution;

uniform float rand;
uniform float val1,val2,val3,val4;
uniform float multx, multy;

void main ()
{
    
    vec2 st = vUv;
    
    vec2 dt;
    float addvar = rand*val2;
    dt.x = st.x + sin( st.y / u_resolution.y * multx + addvar + u_time*3.0)*val3 * u_resolution.x;
    dt.y = st.y + cos( st.x / u_resolution.x * multy + addvar + u_time*2.4)*val3 * u_resolution.y;
    
    vec4 source = texture( tex0, dt );
    
    outputColor = source;
}
