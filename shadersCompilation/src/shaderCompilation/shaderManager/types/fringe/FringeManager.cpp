//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "FringeManager.hpp"


void FringeManager::setup(){
    
    string fullPath = pathToShader + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the halftone shader" << endl;
    
    initGui();
    
}

void FringeManager::initGui(){
    
    shaderControl.setName("fringe");
    
    shaderControl.add(Volume.set("Volume", 0.1, 0,1));
    shaderControl.add(ScaleW.set("ScaleW", 0, 0,1024));
    shaderControl.add(ScaleH.set("ScaleH", 1, 0,1024));
}

void FringeManager::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("Volume", Volume);
    shader.setUniform1f("ScaleW", ScaleW);
    shader.setUniform1f("ScaleH", ScaleH);
    shader.setUniformTexture("tex0", tex, 0);
    
}

void FringeManager::end(){
    shader.end();
}

