
uniform float brightness;
uniform float contrast;
uniform float saturation;
uniform float alpha;
uniform float red;
uniform float green;
uniform float blue;
uniform float shadowIntensity;

void RGBColors(void)
{
    // Extract colors from baseMap
    vec4 baseColor = texture2DRect( baseMap, gl_TexCoord[0].st );
    
    vec3 baseColor3 = baseColor.rgb;
    
    
    // Brightness, contrast and saturation
    const float AvgLumR = 0.5;
    const float AvgLumG = 0.5;
    const float AvgLumB = 0.5;
    const vec3 LumCoeff = vec3(0.2125, 0.7154, 0.0721);
    vec3 AvgLumin = vec3(AvgLumR, AvgLumG, AvgLumB);
    vec3 brtColor = baseColor3 * brightness;
    vec3 intensity = vec3(dot(brtColor, LumCoeff));
    vec3 satColor = mix(intensity, brtColor, saturation);
    vec3 conColor = mix(AvgLumin, satColor, contrast);
    
    baseColor.rgb = conColor;
    
    
    
    
    // colour, alpha, lighting
    //vec3 normal         = normalize( v_normal );
    vec3 colourVec      = vec3(red, green, blue);
    baseColor.rgb       *= colourVec;
    //float ndotl         = max(dot(normal, v_light_dir), shadowIntensity);
    //baseColor.rgb       *= ndotl;
    //baseColor.a         = alpha;
    
    
    vec4 result = clamp(baseColor, 0.0, 1.0);
    
    //result.r += v_colour.r;
    //result.g = 1.0;
    //result += v_colour;
    //result.a = v_colour.a;
    
    gl_FragColor        =    result;
    
}
