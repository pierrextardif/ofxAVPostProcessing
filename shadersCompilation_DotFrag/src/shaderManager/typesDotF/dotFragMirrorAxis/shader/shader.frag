#version 150

in vec2 vUv;
out vec4 outputColor;

uniform sampler2DRect tex0;

uniform float u_vertical;
uniform float u_horizontal;


void main () {
    
    vec2 st = vUv;
    vec2 texFlipCoords = st;
    
//    float invx = step( 0.5, st.x) * u_horizontal;
//    texFlipCoords.x = mix( st.x, 0.5 - st.x, 0.5 );
    
    
    texFlipCoords.x = vUv.x;
    if(vUv.x > 0.5)texFlipCoords.x = (vUv.x - 0.5);
    
//    float invy = step( 0.5, st.y) * u_vertical;
//    texFlipCoords.y = mix( st.y, 0.5 - st.y, 0.5 );
    
    vec4 source = texture( tex0, texFlipCoords );
    outputColor = source;
    
}
