#version 150

uniform float Volume;
uniform sampler2DRect tex0;

in vec2 vUv;

out vec4 outputColor;


void main(void){
    vec2 st = vUv;
    vec3 col;
    
    col = texture(tex0, vec2(st.x,st.y)).rgb;
    
    col.r += ((1.0 - col.r) - col.r) * Volume;
    col.g += ((1.0 - col.g) - col.g) * Volume;
    col.b += ((1.0 - col.b) - col.b) * Volume;
    
    outputColor = vec4(col,1.0);
    
}
