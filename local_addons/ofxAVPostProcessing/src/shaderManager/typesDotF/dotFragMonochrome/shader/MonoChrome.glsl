
uniform float monochromeActive;
uniform float u_low;
uniform float u_high;

vec4 monochrome(vec4 color) {
    float luminance = color.r*0.299 + color.g*0.587 + color.b*0.114;
    
    float range = u_high - u_low;
    float remapped = luminance - u_low;
    remapped = max( 0.0, remapped );
    remapped = min( remapped, range );
    remapped = remapped / range;
    
    return vec4( vec3(remapped), color.a );
}
