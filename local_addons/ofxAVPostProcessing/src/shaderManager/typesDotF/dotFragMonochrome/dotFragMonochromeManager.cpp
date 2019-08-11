//
//  dotFragMonochromeManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragMonochromeManager.hpp"


void dotFragMonochromeManager::setup(){
    
    initGui();
    
}

void dotFragMonochromeManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(low.set("low", 0, 0,1));
    shaderControl.add(high.set("high", 1, 0,1));
}

void dotFragMonochromeManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("u_low", low);
        shader->setUniform1f("u_high", high);
    }
    
}
