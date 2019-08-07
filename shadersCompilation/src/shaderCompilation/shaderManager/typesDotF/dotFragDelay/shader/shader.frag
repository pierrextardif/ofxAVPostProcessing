#version 150


// ==== custom ==== //
in vec2 vUv;
out vec4 outputColor;
// ==== custom ==== //

uniform float u_time;

uniform sampler2DRect tex0;
uniform sampler2DRect tex1;

uniform float u_feedback;
uniform int u_blendmode;

void main () {
    
    
    vec4 now = texture(tex0, vUv);
    vec4 delay = texture(tex1, vUv);
    
    float alpha = max( now.a, delay.a );
    
    if( u_blendmode==0 ){
        // screen
        vec3 screen = 1.0-((1.0-now.xyz)*(1.0-delay.xyz));
        outputColor = vec4(now.xyz*(1.0-u_feedback) + screen*u_feedback, alpha);
    }else if( u_blendmode==1 ){
        // sum
        vec3 sum = min(now.xyz + delay.xyz*u_feedback, vec3(1.0));
        outputColor = vec4( sum, alpha );
    }else if( u_blendmode==2 ){
        // lerp
        outputColor = vec4(now.xyz*(1.0-u_feedback) + delay.xyz*u_feedback, alpha);
    }else if( u_blendmode==3 ){
        // blend max
        outputColor = vec4( max(now.xyz, delay.xyz*u_feedback), alpha );
    }else{
        // blend min
        outputColor = vec4( min(now.xyz, delay.xyz*u_feedback), alpha );
    }
    }
