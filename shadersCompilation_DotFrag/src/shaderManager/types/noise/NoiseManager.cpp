//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "NoiseManager.hpp"


void NoiseManager::setup(){
    
    string fullPath = "../../src/shaderManager/types/" + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the noise shader" << endl;
    
    initGui();
    
}

void NoiseManager::initGui(){
    
    shaderControl.setName("noise");
    
    shaderControl.add(Volume.set("Volume", 0.1, 0,1));
}

void NoiseManager::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("Volume", Volume);
    shader.setUniform1f("Phase", ofGetElapsedTimef());
    
    shader.setUniformTexture("tex0", tex, 0);
    
}

void NoiseManager::end(){
    shader.end();
}

