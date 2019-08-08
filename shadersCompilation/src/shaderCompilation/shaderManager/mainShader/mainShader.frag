#version 330
precision highp float;


// ==== imports glsl from types ==== //
#pragma include "../types/halftone/shader/halftone.glsl"
#pragma include "../types/glitch/shader/glitch.glsl"
#pragma include "../types/fringe/shader/fringe.glsl"
#pragma include "../types/invert/shader/invert.glsl"
#pragma include "../types/verticalNoise/shader/verticalNoise.glsl"
#pragma include "../types/noise/shader/noise.glsl"
#pragma include "../types/edgeOnTop/shader/edgeOnTop.glsl"
#pragma include "../types/scanLines/shader/scanLines.glsl"




// ==== imports glsl from types ==== //



uniform sampler2DRect tex0;
uniform float iTime;


in vec2 vUv;
out vec4 outputColor;


void main () {
    vec4 colors = vec4(texture(tex0, vec2(vUv.x,vUv.y)).rgb, 1.0);
    vec3 newColors;
    
    if(halftoneActive == 1){
        newColors.rgb = halftoneColors(vUv, tex0, colors);
        colors.rgb = mix(newColors, colors.rgb, colors.rgb - newColors);
    }
    if(glitchActive == 1){
        vec4 newC = glitchColors(vUv, amount, angle, seed, seed_x, seed_y, distortion_x, distortion_y, tex0);
        colors.rgba = mix(newC, colors, colors - newC);
    }
    
    if(fringeActive == 1){
        newColors = fringeColors(vUv, tex0, colors);
        colors.rgb = mix(newColors, colors.rgb, colors.rgb - newColors);
    }
    
    if(verticalNoiseActive == 1){
        colors.rgb += verticalNoiseColors(vUv, tex0, iTime);
//        colors.rgb = mix(newColors, colors.rgb, colors.rgb - newColors);
    }
    if(scanLinesActive == 1){
        newColors = scanLinesColors(vUv, tex0, colors);
        colors.rgb = mix(newColors, colors.rgb, colors.rgb - newColors);
        
    }
    
    if(edgeOnTopActive == 1)    colors.rgb += edgeOnTopColors(vUv, tex0);
    if(noiseActive == 1)        colors.rgb += noiseColors(vUv, tex0, iTime);
    if(invertActive == 1)       colors = invertColors(vUv, colors);
    
    outputColor = colors;
}
