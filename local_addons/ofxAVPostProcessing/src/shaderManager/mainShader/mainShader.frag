#version 330
precision highp float;

uniform sampler2DRect tex0;
uniform float iTime;
uniform vec2 resolution;

struct OffsetRGB {
    vec2 red;
    vec2 green;
    vec2 blue;
    
};


vec4 rgbFromOffset(sampler2DRect tex, vec2 uV, OffsetRGB offset){
    float r = texture(tex, uV+offset.red).r;
    float g = texture(tex, uV+offset.green).g;
    float b = texture(tex, uV+offset.blue).b;
    float a = texture(tex, uV).a;
    
    return vec4(r,g,b,a);
}


// ==== imports glsl from types ==== //

//customs
#pragma include "../types/halftone/shader/halftone.glsl"
#pragma include "../types/glitch/shader/glitch.glsl"
#pragma include "../types/fringe/shader/fringe.glsl"
#pragma include "../types/invert/shader/invert.glsl"
#pragma include "../types/verticalNoise/shader/verticalNoise.glsl"
#pragma include "../types/noise/shader/noise.glsl"
#pragma include "../types/edgeOnTop/shader/edgeOnTop.glsl"
#pragma include "../types/scanLines/shader/scanLines.glsl"

//dotFrag
#pragma include "../typesDotF/dotFragHSB/shader/hsb.glsl"
#pragma include "../typesDotF/dotFragMirrorAxis/shader/mirrorAxis.glsl"
#pragma include "../typesDotF/dotFragTurbulence/shader/turbulence.glsl"
#pragma include "../typesDotF/dotFragTwist/shader/twist.glsl"
#pragma include "../typesDotF/dotFragMonoChrome/shader/monochrome.glsl"

//others
#pragma include "../others/Hole/shader/hole.glsl"
#pragma include "../others/GodRays/shader/godRays.glsl"


// ==== imports glsl from types ==== //

in vec2 vUv;
out vec4 outputColor;


void main () {
    
    
    // uv texture coordinates changes
    vec2 uV = vUv;
    if(mirrorAxisActive == 1)       uV = mirrorAxis(uV);
    if(verticalNoiseActive == 1)    uV = verticalNoiseColors(uV, iTime);
    if(turbulenceActive == 1)       uV = turbulence(uV, iTime);
    if(twistActive == 1)            uV = twist(uV, iTime);
    
    vec3 newColors;
    
    OffsetRGB offsetUV;
    offsetUV.red    = vec2(0);
    offsetUV.green  = vec2(0);
    offsetUV.blue   = vec2(0);
    
    
    if(fringeActive == 1)offsetUV = fringeColors(uV, offsetUV);
    vec4 colors = rgbFromOffset(tex0,uV, offsetUV);
    
    
    if(halftoneActive == 1)colors.rgb = halftoneColors(uV, tex0, colors, offsetUV);
    if(glitchActive == 1){
        for( int i = 0; i < iterationsGlitch; i++){
            vec4 newC = glitchColors( uV, tex0, offsetUV, i);
            colors.rgba = mix(newC, colors, colors - newC);
            
        }
    }
    
    
    if(edgeOnTopActive == 1)        colors.rgb += edgeOnTopColors(uV, tex0, offsetUV);
    if(monochromeActive == 1)       colors = monochrome(colors);
    if(godRaysActive == 1)          colors = godRaysColors(uV, tex0, colors, offsetUV);
    if(scanLinesActive == 1)        colors.rgb += scanLinesColors(uV, tex0, colors, offsetUV);
    if(dotFragHSBActive == 1)       colors.rgb = hsbColors(colors.rgb, iTime);
    if(noiseActive == 1)            colors.rgb += noiseColors(uV, iTime);
    if(invertActive == 1)           colors = invertColors(uV, colors);
    if(holeActive == 1)             colors.rgb *= hole(uV, colors.rgb);
    
    outputColor = colors;
}
