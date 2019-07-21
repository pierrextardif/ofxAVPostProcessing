#version 150

in vec2 vUv;
out vec4 outputColor;

uniform sampler2DRect tex0;

uniform float u_vertical;
uniform float u_horizontal;

uniform vec2 u_resolution;

void main () {
    
    vec2 st = vUv;
    
    float invx = step( u_resolution.x, st.x) * u_horizontal;
    st.x = mix( st.x, u_resolution.x * 2 - st.x, invx );
    
    float invy = step( u_resolution.y, st.y) * u_vertical;
    st.y = mix( st.y, u_resolution.y * 2 - st.y, invy );
    
    outputColor = texture( tex0, st );
    
}
