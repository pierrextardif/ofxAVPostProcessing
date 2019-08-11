// uniforms
uniform float invertActive;
uniform float VolumeInvert;

vec4 invertColors(vec2 st, vec4 col){
    
    col.r += ((1.0 - col.r) - col.r) * VolumeInvert;
    col.g += ((1.0 - col.g) - col.g) * VolumeInvert;
    col.b += ((1.0 - col.b) - col.b) * VolumeInvert;
    
    return col;
    
}
