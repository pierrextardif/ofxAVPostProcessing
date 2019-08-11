
uniform float twistActive;

uniform float randomFloat;
uniform float val1,val2,val3,val4;
uniform float multx, multy;

vec2 twist(vec2 vUv, float iTime)
{
    
    vec2 st = vUv;
    
    vec2 dt;
    float addvar = randomFloat*val2;
    dt.x = st.x + sin( st.y / resolution.y * multx + addvar + iTime*3.0)*val3 * resolution.x;
    dt.y = st.y + cos( st.x / resolution.x * multy + addvar + iTime*2.4)*val3 * resolution.y;
    
    return dt;
}
