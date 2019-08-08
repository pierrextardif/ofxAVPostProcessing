#version 330
precision highp float;


// ==== imports glsl from types ==== //
#pragma include "../types/invert/shader/invert.glsl"
#pragma include "../types/glitch/shader/glitch.glsl"



// ==== imports glsl from types ==== //



uniform sampler2DRect tex0;


in vec2 vUv;
out vec4 outputColor;


void main () {
    vec4 colors = vec4(texture(tex0, vec2(vUv.x,vUv.y)).rgb, 1.0);
    
    if(glitchActive == 1)colors = glitchColors(vUv, amount, angle, seed, seed_x, seed_y, distortion_x, distortion_y, tex0);
    
    if(invertActive == 1)colors = invertColors(vUv, colors, 1.0);
    
    outputColor = colors;
}
