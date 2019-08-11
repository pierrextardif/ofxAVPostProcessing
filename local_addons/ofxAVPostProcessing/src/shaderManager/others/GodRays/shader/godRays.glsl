

uniform float godRaysActive;

uniform float lightDirDOTviewDir;
uniform vec2 lightPositionOnScreen;
uniform float samplesRay;


// 2x1 hash. Used to jitter the samples.
float hash( vec2 p ){ return fract(sin(dot(p, vec2(41, 289)))*45758.5453); }

vec2 lOff(){
    
    vec2 u = sin(vec2(resolution.x * 3/2, 0) - iTime * 8);
    mat2 a = mat2(u, -u.y, u.x);
    
    vec3 l = normalize(vec3(resolution.y * 3/2, resolution.x, -resolution.y / 2));
    l.xz = a * l.xz;
    l.xy = a * l.xy;
    
    return l.xy;
    
}





vec4 godRaysColors(vec2 vUv, sampler2DRect tex0, vec4 colors, OffsetRGB offsetUV){

    vec4 origColor = colors;
    vec4 raysColor = origColor;
    
    
    if (lightDirDOTviewDir>0.0){
        float exposure    = 0.1/float(samplesRay);
        float decay        = 1.0 ;
        float density    = 0.5;
        float weight    = 6.0;
        float illuminationDecay = 1.0;
        
        
//        lightPositionOnScreen = vec2(resolution.x/2, resolution.y / 2);
        
        vec2 deltaTextCoord = vec2( vUv - lightPositionOnScreen);
        vec2 textCoo = vUv;
        deltaTextCoord *= 1.0 / float(samplesRay) * density;
        
        
        
        for(int i=0; i < samplesRay ; i++)
        {
            textCoo -= deltaTextCoord;
            vec4 tsample = rgbFromOffset(tex0, textCoo, offsetUV);
            tsample *= illuminationDecay * weight;
            raysColor += tsample;
            illuminationDecay *= decay;
        }
        raysColor *= exposure * lightDirDOTviewDir;
        float p = 0.3 *raysColor.g + 0.59*raysColor.r + 0.11*raysColor.b;
        return origColor + p;
    } else {
        return origColor;
    }
}
