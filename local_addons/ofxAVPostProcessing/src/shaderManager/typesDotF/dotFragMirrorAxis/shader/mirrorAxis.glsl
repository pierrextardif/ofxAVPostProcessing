
uniform float mirrorAxisActive;
uniform float u_vertical;
uniform float u_horizontal;

vec2 mirrorAxis(vec2 vUv) {
    
    vec2 st = vUv;
    
    float invx = step( resolution.x / 2, st.x) * u_horizontal;
    st.x = mix( st.x, resolution.x - st.x, invx );
    
    float invy = step( resolution.y / 2, st.y) * u_vertical;
    st.y = mix( st.y, resolution.y - st.y, invy );
    
    return st;
    
}
