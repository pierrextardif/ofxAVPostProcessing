#version 150

in vec2 vUv;
out vec4 outputColor;

//uniform int byp;//should we apply the glitch ?

uniform sampler2DRect tDiffuse;
uniform sampler2DRect tDisp;

uniform float amount;
uniform float angle;
uniform float seed;
uniform float seed_x;
uniform float seed_y;
uniform float distortion_x;
uniform float distortion_y;


float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
//    if(byp<1) {
        vec2 p = vUv;
        float xs = floor(gl_FragCoord.x / 0.5);
        float ys = floor(gl_FragCoord.y / 0.5);
        //based on staffantans glitch shader for unity https://github.com/staffantan/unityglitch
        vec4 normal = texture(tDisp, p*seed*seed);
        if(p.y<distortion_x && p.y>distortion_x*seed) {
            if(seed_x>0.){
                p.y = 1. - (p.y + distortion_y);
            }else {
                p.y = distortion_y;
            }
        }
        if(p.x<distortion_y && p.x>distortion_y*seed) {
            if(seed_y>0.){
                p.x=distortion_x;
            }else {
                p.x = 1. - (p.x + distortion_x);
            }
        }
        p.x+=normal.x*seed_x*(seed/5.);
        p.y+=normal.y*seed_y*(seed/5.);
        //base from RGB shift shader
        vec2 offset = amount * vec2( cos(angle), sin(angle));
        vec4 cr = texture(tDiffuse, p + offset);
        vec4 cga = texture(tDiffuse, p);
        vec4 cb = texture(tDiffuse, p - offset);
        outputColor = vec4(cr.r, cga.g, cb.b, cga.a);
        //add noise
        vec4 snow = 200.*amount*vec4(rand(vec2(xs * seed,ys * seed*50.))*0.2);
        outputColor = outputColor+ snow;
//    }else {
//        outputColor=texture2D (tDiffuse, vUv);
//    }
}
