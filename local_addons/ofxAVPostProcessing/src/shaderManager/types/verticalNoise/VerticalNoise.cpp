//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "VerticalNoise.hpp"


void VerticalNoise::setup(){
    
    initGui();
    
}

void VerticalNoise::initGui(){
    
    shaderControl.setName("vertical Noise");
}

void VerticalNoise::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
}
