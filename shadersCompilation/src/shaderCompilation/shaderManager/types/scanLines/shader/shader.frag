#version 150

in vec2 vUv;
out vec4 outColor;

// ==== custom ==== //
uniform sampler2DRect tex0;

uniform float time;
uniform vec3 scanL;
// ==== custom ==== //


float random (in vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))*43758.5453123);
}

float noise (in vec2 st) {
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

void main() {

    vec2 st = vUv.xy;

    vec4 colorRGBA = texture(tex0, st).rgba;

    if(colorRGBA.a == 1.0){

        vec2 newSt = vec2(st.x + noise(vec2(0.1, 0.1) ), st.y);
        float colorR = sin(time) * 0.5 + + 0.3 + 0.2 * texture(tex0,newSt).r;

        float scanVol = st.y * 800 * scanL.x;
        float scanLines = sin(scanVol)*0.04 * scanL.y;

        colorRGBA.r -= scanLines * scanL.z;
        colorRGBA.g -= scanLines * scanL.z;
        colorRGBA.b -= scanLines * scanL.z;
    }
    outColor = colorRGBA;
}



