
uniform float fringeActive;
uniform float VolumeFringe;
uniform float ScaleW;
uniform float ScaleH;


vec3 fringeColors(vec2 vUv, sampler2DRect tex, vec4 col){
    
    vec2 center = vec2(ScaleW/2.0, ScaleH/2.0);
    vec2 rev = (center - vUv) * VolumeFringe;
    
    
//    col.g = texture(tex0, vec2(vUv.x, vUv.y)).g;
    col.r = texture(tex, vec2(vUv.x, vUv.y) + rev).r;
    col.b = texture(tex, vec2(vUv.x, vUv.y) - rev).b;
    
    return col.rgb;
    
}
