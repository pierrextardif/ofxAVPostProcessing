// uniforms
uniform float fringeActive;
uniform float VolumeFringe;


OffsetRGB fringeColors(vec2 vUv, OffsetRGB offsetUV){
    
    vec2 center = vec2(resolution.x/2.0, resolution.y/2.0);
    vec2 rev = (center - vUv) * VolumeFringe;
    
    
//    col.g = texture(tex0, vec2(vUv.x, vUv.y)).g;
//    col.r = rgbFromOffset(tex, vec2(vUv.x, vUv.y, offsetUV) + rev).r;
//    col.b = rgbFromOffset(tex, vec2(vUv.x, vUv.y, offsetUV) - rev).b;
    
    offsetUV.red += rev;
    offsetUV.green += vec2(0);
    offsetUV.blue += -rev;
    
    return offsetUV;
}
