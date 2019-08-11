//
//  GlitchManager.cpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 19/03/2019.
//

#include "GlitchManager.hpp"

void GlitchManager::setup(){
    
    initGui();
}

void GlitchManager::initGui(){
    
    shaderControl.setName("glitch");
    
    shaderControl.add(amount.set("amount", 0, 0, 10));
    shaderControl.add(angle.set("angle", 1, 0,100));
    shaderControl.add(seed.set("seed", 1, 0,3));
    shaderControl.add(seed_x.set("seed_x", 100, 0,100));
    shaderControl.add(seed_y.set("seed_y", 100, 0,100));
    shaderControl.add(distortion_x.set("distortion_x", 1, 0,1));
    shaderControl.add(distortion_y.set("distortion_y", 1, 0,1));
    shaderControl.add(iterationsGlitch.set("iterationsGlitch", 1,1, 6));
//    shaderControl.add(col_s.set("col_s", 1, 0,512));
}

void GlitchManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("amount", amount);
        shader->setUniform1f("angle", angle);
        shader->setUniform1f("seed", seed);
        shader->setUniform1f("seed_x", seed_x);
        shader->setUniform1f("seed_y", seed_y);
        shader->setUniform1f("distortion_x", distortion_x);
        shader->setUniform1f("distortion_y", distortion_y);
        shader->setUniform1i("iterationsGlitch", iterationsGlitch);
    }
}
