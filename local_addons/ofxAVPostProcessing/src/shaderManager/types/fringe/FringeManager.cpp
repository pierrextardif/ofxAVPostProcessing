//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "FringeManager.hpp"


void FringeManager::setup(){
    
//    string fullPath = pathToShader + name + "/shader";
//    filesystem::path path = filesystem::path(fullPath);
//    shader.load(path/"shader.vert", path/"shader.frag");
//    
//    if(!shader.isLoaded())cout << "issue loading the halftone shader" << endl;
    
    initGui();
    
}

void FringeManager::initGui(){
    
    shaderControl.setName("fringe");
    
    shaderControl.add(Volume.set("Volume", 0.04, 0,1));
}

void FringeManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("VolumeFringe", Volume);
        
    }
}
