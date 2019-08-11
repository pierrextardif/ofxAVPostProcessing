
uniform float holeActive;
uniform float holeSize;
uniform vec3 maskCol;
uniform float spacingDots;
uniform float antialiasRange;


float map(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp)
{
    if (abs(inputMin - inputMax) < 0.000000001){
        return outputMin;
    } else {
        float outVal = ((value - inputMin) / (inputMax - inputMin) * (outputMax - outputMin) + outputMin);
        
        if(clamp){
            if(outputMax < outputMin){
                if( outVal < outputMax )outVal = outputMax;
                else if( outVal > outputMin )outVal = outputMin;
            }else{
                if( outVal > outputMax )outVal = outputMax;
                else if( outVal < outputMin )outVal = outputMin;
            }
        }
        return outVal;
    }
}

vec3 hole(vec2 vUv, vec3 color)
{
    vec2 centre = vec2(resolution.x / 2, resolution.y / 2);
    
    vec3 result = vec3(0);
    
    float ratio = resolution.x / resolution.y;
    
    float distToCentre = distance(centre, vUv + spacingDots * vec2(cos(iTime + vUv.x), sin(iTime + vUv.y)));
    
    if (distToCentre <= 0.5 * holeSize)
    {
        result = vec3(1);
    }
    else if (distToCentre > 0.5 * holeSize && distToCentre < 0.5 * (holeSize * (1.0 + antialiasRange)))
    {
        float aaBegin= 0.5 * (holeSize * (1.0 + antialiasRange));
        float aaEnd = 0.5 * holeSize;
        float red = map(distToCentre, aaBegin, aaEnd, maskCol.r, 1, true);
        float green = map(distToCentre, aaBegin, aaEnd, maskCol.g, 1, true);
        float blue = map(distToCentre, aaBegin, aaEnd, maskCol.b, 1, true);
        result = vec3(red, green, blue);
    }
    else
    {
        result = maskCol;
    }
    
    return result;
}






//void main(void)
//{
//    vec2 pos = gl_TexCoord[0].st;
//    vec4 src = texture2D(tex0, pos);
//    vec2 centre = vec2(0.5, 0.5);
//    
//    float ratio = resolution.x / resolution.y;
//    
//    pos.x = map(pos.x, 0.0, 1.0, -((ratio - 1.0) * 0.5), 1.0 + ((ratio - 1.0) * 0.5), true);
//    
//    float distToCentre = distance(centre, pos);
//    
//    if (distToCentre <= 0.5 * holeSize)
//    {
//        src = src;
//    }
//    else if (distToCentre > 0.5 * holeSize && distToCentre < 0.5 * (holeSize * (1.0 + antialiasRange)))
//    {
//        float aaBegin= 0.5 * (holeSize * (1.0 + antialiasRange));
//        float aaEnd = 0.5 * holeSize;
//        src.a = map(distToCentre, aaBegin, aaEnd, 0.0, 1.0, true);
//    }
//    else
//    {
//        src.a = 0.0;
//    }
//    
//    gl_FragColor = src;
//}
