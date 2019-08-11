//
//  GodRays.cpp
//  rayMarching_2
//
//  Created by Pierre Tardif on 09/08/2019.
//

#include "GodRays.hpp"


void GodRays::setup(){
    
    initGui();
    
    positionLight = {0,0};
}

void GodRays::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(lightDirDOTviewDir.set("lightDirDOTviewDir", 0.7, 0,2));
    shaderControl.add(lightMoveSpeed.set("lightMoveSpeed", {0.3,0.5}, {0,0}, {3,3}));
    shaderControl.add(samples.set("samples",  32, 0,50));
}

void GodRays::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    if(active){
        updatePositionLight();
        
        shader->setUniform1f("lightDirDOTviewDir", lightDirDOTviewDir);
        shader->setUniform2f("lightPositionOnScreen", positionLight);
        shader->setUniform1f("samplesRay", samples );
    }
    
}
void GodRays::updatePositionLight(){
    
    positionLight.x = WIDTH *  ofNoise(ofGetElapsedTimef() * lightMoveSpeed->x);
    positionLight.y = HEIGHT * ofNoise(ofGetElapsedTimef() * lightMoveSpeed->y);
}
