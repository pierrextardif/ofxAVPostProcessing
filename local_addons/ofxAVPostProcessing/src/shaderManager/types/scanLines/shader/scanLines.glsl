// uniforms
uniform  float scanLinesActive;
uniform float time;
uniform vec3 scanL;


float random (in vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))*43758.5453123);
}

float noiseScanLines (in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);

    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));
    vec2 u = f * f * (3.0 - 2.0 * f);
    return mix(a, b, u.x) +
    (c - a)* u.y * (1.0 - u.x) +
    (d - b) * u.x * u.y;
}

vec3 scanLinesColors(vec2 vUv, sampler2DRect tex0, vec4 colors, OffsetRGB offsetRGB) {

    vec4 colorRGBA = rgbFromOffset(tex0, vUv, offsetRGB).rgba;

    float offset = 0;
    if(colorRGBA.a == 1.0){

        vec2 newSt = vec2(vUv.x + noiseScanLines(vec2(0.1, 0.1) ), vUv.y);
        float colorR = sin(time) * 0.5 + + 0.3 + 0.2 * texture(tex0,newSt).r;

        float scanVol = vUv.y * 800 * scanL.x;
        float scanLines = sin(scanVol)*0.04 * scanL.y;

        offset = -scanLines * scanL.z;
    }
    return vec3(offset);
}



