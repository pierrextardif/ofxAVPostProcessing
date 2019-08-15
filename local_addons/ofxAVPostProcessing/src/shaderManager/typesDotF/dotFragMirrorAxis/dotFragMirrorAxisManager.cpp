//
//  dotFragMirrorAxisManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragMirrorAxisManager.hpp"


void dotFragMirrorAxisManager::setup(){
    
    initGui();
}

void dotFragMirrorAxisManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(horizontal.set("horizontal", false));
    shaderControl.add(vertical.set("vertical", false));
    shaderControl.add(doubleMatHorizontally.set("doubleMatHorizontally", false));
    shaderControl.add(doubleMatVertically.set("doubleMatVertically", false));
                      
    
}

void dotFragMirrorAxisManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("u_horizontal", (horizontal)?   1.0f : 0.0f );
        shader->setUniform1f("u_vertical",   (vertical)?     1.0f : 0.0f );
        
        shader->setUniform1f("doubleMatHorizontally",     (doubleMatHorizontally)?  1.0f : 0.0f );
        shader->setUniform1f("doubleMatVertically",       (doubleMatVertically)?  1.0f : 0.0f );
    }
}
