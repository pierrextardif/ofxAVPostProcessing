// invert colors
uniform float invertActive;

vec4 invertColors(vec2 st, vec4 col, float Volume){
    
    col.r += ((1.0 - col.r) - col.r) * Volume;
    col.g += ((1.0 - col.g) - col.g) * Volume;
    col.b += ((1.0 - col.b) - col.b) * Volume;
    
    return col;
    
}
