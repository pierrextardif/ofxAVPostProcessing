#version 150

uniform float Volume;
uniform float Phase;
uniform float ScaleW;
uniform float ScaleH;

uniform sampler2DRect tex0;

in vec2 vUv;
out vec4 outputColor;

void main(void){
    vec2 st = vUv;
    vec4 col;
    vec3 maximum = vec3(0.0,0.0,0.0);
    vec3 minimum = vec3(1.0,1.0,1.0);
    
    int i = 0;
    int j = 0;
    for (i; i < 3;i++){
        for (j; j < 3;j++){
            vec4 c = texture(tex0, vec2(st.x + float(i) - 1.0,
                                              st.y + float(j) - 1.0));
            
            maximum.r = max(maximum.r, c.r);
            minimum.r = min(minimum.r, c.r);
            maximum.g = max(maximum.g, c.g);
            minimum.g = min(minimum.g, c.g);
            maximum.b = max(maximum.b, c.b);
            minimum.b = min(minimum.b, c.b);
            
        }
    }
    
    col = texture(tex0, vec2(st.x, st.y));
    
    vec3 br = vec3(pow(maximum.r - minimum.r,2.0),
                   pow(maximum.g - minimum.g,2.0),
                   pow(maximum.b - minimum.b,2.0));
    
    outputColor = vec4(br,1.0) + col;
}
