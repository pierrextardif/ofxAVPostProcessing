//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "NoiseManager.hpp"


void NoiseManager::setup(){
    
    initGui();
    
}

void NoiseManager::initGui(){
    
    shaderControl.setName("noise");
    
    shaderControl.add(Volume.set("Volume", 0.1, 0,1));
}

void NoiseManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("VolumeNoise", Volume);
    }
    
    
}
