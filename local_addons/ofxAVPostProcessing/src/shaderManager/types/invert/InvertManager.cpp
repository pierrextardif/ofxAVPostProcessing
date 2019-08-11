//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "InvertManager.hpp"


void InvertManager::setup(){
    
    initGui();
}

void InvertManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(Volume.set("Volume", 1, 0,1));
}

void InvertManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("VolumeInvert", Volume);
    }
    
}
