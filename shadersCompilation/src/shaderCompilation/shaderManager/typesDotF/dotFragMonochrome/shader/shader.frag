#version 150

in vec2 vUv;
out vec4 outputColor;

uniform sampler2DRect tex0;

uniform float u_low;
uniform float u_high;

void main (void) {
    vec2 st = vUv;
    
    vec4 source = texture( tex0, st );
    float luminance = source.r*0.299 + source.g*0.587 + source.b*0.114;
    
    float range = u_high - u_low;
    float remapped = luminance - u_low;
    remapped = max( 0.0, remapped );
    remapped = min( remapped, range );
    remapped = remapped / range;
    
    outputColor = vec4( vec3(remapped), source.a );
}
