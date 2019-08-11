// uniforms
uniform float edgeOnTopActive;

vec3 edgeOnTopColors(vec2 vUv, sampler2DRect tex, OffsetRGB offsetUV){
    vec2 st = vUv;
    vec4 col;
    vec3 maximum = vec3(0.0,0.0,0.0);
    vec3 minimum = vec3(1.0,1.0,1.0);
    
    int i = 0;
    int j = 0;
    for (i; i < 3;i++){
        for (j; j < 3;j++){
            vec4 c = rgbFromOffset(tex, vec2(vUv.x + float(i) - 1.0,
                                              vUv.y + float(j) - 1.0), offsetUV);
            
            maximum.r = max(maximum.r, c.r);
            minimum.r = min(minimum.r, c.r);
            maximum.g = max(maximum.g, c.g);
            minimum.g = min(minimum.g, c.g);
            maximum.b = max(maximum.b, c.b);
            minimum.b = min(minimum.b, c.b);
            
        }
    }
    
    return vec3(pow(maximum.r - minimum.r,2.0),
                   pow(maximum.g - minimum.g,2.0),
                   pow(maximum.b - minimum.b,2.0));
}
