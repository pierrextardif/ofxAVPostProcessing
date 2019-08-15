// uniforms
uniform float glitchActive;
uniform float amount;
uniform float angle;
uniform float seed;
uniform float seed_x;
uniform float seed_y;
uniform float distortion_x;
uniform float distortion_y;
uniform int iterationsGlitch;


vec4 glitchColors(vec2 vUv, sampler2DRect tex, OffsetRGB offsetUV, float indexSeed){
    
    float xs = floor(vUv.x / 0.5);
    float ys = floor(vUv.y / 0.5);
    vec4 normal = rgbFromOffset(tex, vUv*seed*seed, offsetUV);
    if(vUv.y<distortion_x && vUv.y>distortion_x*seed) {
        if(seed_x>0.){
            vUv.y = 1. - (vUv.y + distortion_y);
        }else {
            vUv.y = distortion_y;
        }
    }
    if(vUv.x<distortion_y && vUv.x>distortion_y*seed) {
        if(seed_y>0.){
            vUv.x=distortion_x;
        }else {
            vUv.x = 1. - (vUv.x + distortion_x);
        }
    }
    vUv.x+=normal.x*seed_x*((seed + indexSeed)/5.);
    vUv.y+=normal.y*seed_y*((seed + indexSeed)/5.);
    //base from RGB shift shader
    vec2 offset = amount*vec2( cos(angle), sin(angle));
    vec4 cr = rgbFromOffset(tex, vUv + offset, offsetUV);
    vec4 cga = rgbFromOffset(tex, vUv, offsetUV);
    vec4 cb = rgbFromOffset(tex, vUv - offset, offsetUV);
    return vec4(cr.r, cga.g, cb.b, cga.a);
    
//    OffsetRGB glitchOffset;
//    glitchOffset.red = offset;
//    glitchOffset.green = vec2(0);
//    glitchOffset.blue = -offset;
//
//    return glitchOffset;
}
