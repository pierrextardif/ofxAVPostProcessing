
uniform float mirrorAxisActive;
uniform float u_vertical;
uniform float u_horizontal;

uniform float doubleMatHorizontally;
uniform float doubleMatVertically;

vec2 mirrorAxis(vec2 vUv, sampler2DRect tex0) {
    
    vec2 st = vUv;
    
    float invx = step( resolution.x / 2, st.x) * u_horizontal;
    st.x = mix( st.x, resolution.x - st.x, invx );
    
    float invy = step( resolution.y / 2, st.y) * u_vertical;
    st.y = mix( st.y, resolution.y - st.y, invy );

    
    if(texture(tex0, st).a == 0){
        st.x = (resolution.x - st.x) * doubleMatHorizontally + st.x * (1 - doubleMatHorizontally);
        st.y = (resolution.y - st.y) * doubleMatVertically   + st.y * (1 - doubleMatVertically);
    }
    
    return st;
}
