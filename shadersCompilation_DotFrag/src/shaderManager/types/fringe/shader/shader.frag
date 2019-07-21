#version 150

uniform float Volume;
uniform sampler2DRect tex0;
uniform float ScaleW;
uniform float ScaleH;

in vec2 vUv;

out vec4 outputColor;

void main(void){
    vec2 center = vec2(ScaleW/2.0, ScaleH/2.0);
    vec2 st = vUv;
    vec2 rev = (center - st) * Volume;
    
    vec3 col;
    vec3 col_fringe;
    
    col = texture(tex0, vec2(st.x,st.y)).rgb;
    col_fringe.r = texture(tex0, vec2(st.x,st.y) + rev).r;
    col_fringe.b = texture(tex0, vec2(st.x,st.y) - rev).b;
    col_fringe.g = 0.0;
    
    col.r = col_fringe.r;
    col.b = col_fringe.b;
    
    outputColor = vec4(col,1.0);
    
}
