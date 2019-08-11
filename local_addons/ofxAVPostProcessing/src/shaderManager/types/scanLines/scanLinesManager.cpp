//
//  ScanLinesManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 30/07/2019.
//

#include "ScanLinesManager.hpp"


void ScanLinesManager::setup(){
    
    initGui();
    
}

void ScanLinesManager::initGui(){
    
    shaderControl.setName(name);
    shaderControl.add(scanLines.set("scanLines", {2,2,2}, {0,0,0}, {4,4,4}));
}

void ScanLinesManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("time", ofGetElapsedTimef());
        shader->setUniform3f("scanL", scanLines->x, scanLines->y, scanLines->z);
    }

}
