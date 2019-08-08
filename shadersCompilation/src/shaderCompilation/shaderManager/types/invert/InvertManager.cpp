//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "InvertManager.hpp"


void InvertManager::setup(){
    
    string fullPath = pathToShader + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the invert shader" << endl;
    
    shaderControl.setName("invert");
    
}

void InvertManager::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("Volume", 1.0);
    shader.setUniformTexture("tex0", tex, 0);
    
}

void InvertManager::end(){
    shader.end();
}

