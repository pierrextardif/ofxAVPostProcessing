//
//  dotFragTurbulenceManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragTurbulenceManager.hpp"


void dotFragTurbulenceManager::setup(){
    
    initGui();
}

void dotFragTurbulenceManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(x.set("x", 0, 0, 1));
    shaderControl.add(y.set("y", 0, 0, 1));
    
}

void dotFragTurbulenceManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        
        shader->setUniform1f("u_amount_x", x);
        shader->setUniform1f("u_amount_y", y);
        shader->setUniform2f("u_resolution", {WIDTH, HEIGHT});
    }
}
