#version 150

in vec2 vUv;
out vec4 outputColor;


uniform vec2 u_resolution;
uniform float u_time;

uniform sampler2DRect tex0;
uniform sampler2DRect tex1;

uniform float u_gain;
uniform float u_threshold;
uniform float u_invert;
uniform float u_hardcutoff;

void main () {
    vec2 st = vUv;
//    gl_FragCoord.xy/u_resolution;
    
    vec4 freshPixel = texture( tex0, st );
    vec4 stalePixel = texture( tex1, st );
    float brightLevel = 0.299*freshPixel.r +  0.587*freshPixel.g + 0.114*freshPixel.b;
    
    // invert
    brightLevel = mix( brightLevel, 1.0 - brightLevel, u_invert );
    
    brightLevel = brightLevel * u_gain;
    
    // hard cutof
    brightLevel = mix( brightLevel, step( u_threshold, brightLevel ), u_hardcutoff );
    
    outputColor = mix( freshPixel, stalePixel, brightLevel);
    
}
