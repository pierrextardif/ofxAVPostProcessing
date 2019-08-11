
uniform float dotFragHSBActive;
uniform float u_hue;
uniform float u_saturation;
uniform float u_brightness;
uniform float u_contrast;

#define TWO_PI 6.28318530718

vec3 applyHue(vec3 aColor, float aHue)
{
    float angle = aHue * TWO_PI;
    vec3 k = vec3(0.57735, 0.57735, 0.57735);
    float cosAngle = cos(angle);
    //Rodrigues' rotation formula
    return aColor * cosAngle + cross(k, aColor) * sin(angle) + k * dot(k, aColor) * (1.0 - cosAngle);
}

vec3 hsbColors(vec3 source, float iTime){
    
    vec3 color = applyHue( source.rgb, u_hue * iTime );
    
    color = ((color - 0.5) * u_contrast) + 0.5;
//
    color = color + u_brightness;

    vec3 intensity = vec3( dot( color, vec3(0.299,0.587,0.114)) );
    color = mix( intensity, color, u_saturation );
    
    return color;
    
}
