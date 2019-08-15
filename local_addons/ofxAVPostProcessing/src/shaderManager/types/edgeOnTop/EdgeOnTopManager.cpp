//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "EdgeOnTopManager.hpp"


void EdgeOnTopManager::setup(){
    
//    string fullPath = pathToShader + name + "/shader";
//    filesystem::path path = filesystem::path(fullPath);
//    shader.load(path/"shader.vert", path/"shader.frag");
//    
//    if(!shader.isLoaded())cout << "issue loading the halftone shader" << endl;
    
    initGui();
    
}

void EdgeOnTopManager::initGui(){
    
    shaderControl.setName("edgeOnTop");
    
    shaderControl.add(Volume.set("Volume", 0.1, 0,1));
//    shaderControl.add(color.set("color", {0,0,0}, {0,0,0}, {1,1,1}));
}

void EdgeOnTopManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
//    if(active){
//        shader->setUniform3f("colorEdges", color->x, color->y, color->z);
//    }
    
}
