//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "VerticalNoise.hpp"


void VerticalNoise::setup(){
    
//    string fullPath = pathToShader + name + "/shader";
//    filesystem::path path = filesystem::path(fullPath);
//    shader.load(path/"shader.vert", path/"shader.frag");
//    
//    if(!shader.isLoaded())cout << "issue loading the vertical Noise shader" << endl;
    
    initGui();
    
}

void VerticalNoise::initGui(){
    
    shaderControl.setName("vertical Noise");
}

void VerticalNoise::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
}
