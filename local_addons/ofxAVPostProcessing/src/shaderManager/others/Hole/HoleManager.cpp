//
//  HoleManager.cpp
//  rayMarching_2
//
//  Created by Pierre Tardif on 08/08/2019.
//

#include "HoleManager.hpp"


void HoleManager::setup(){
    
    initGui();
    
}

void HoleManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(holeSize.set("holeSize", 204, 1,2000));
    shaderControl.add(maskCol.set("maskCol", {0,0,1}, {0,0,0}, {1,1,1}));
    shaderControl.add(spacingDots.set("spacingDots", 2,0,50));
    shaderControl.add(antialiasRange.set("antialiasRange", 1.6, 0,20));
}

void HoleManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    if(active){
        
        shader->setUniform1f("holeSize", holeSize);
        shader->setUniform3f("maskCol", maskCol->x, maskCol->y, maskCol->z);
        shader->setUniform1f("spacingDots", spacingDots);
        shader->setUniform1f("antialiasRange", antialiasRange);
    }
    
}
