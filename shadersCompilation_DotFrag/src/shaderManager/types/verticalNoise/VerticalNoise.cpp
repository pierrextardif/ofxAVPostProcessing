//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "VerticalNoise.hpp"


void VerticalNoise::setup(){
    
    string fullPath = "../../src/shaderManager/types/" + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the vertical Noise shader" << endl;
    
    initGui();
    
}

void VerticalNoise::initGui(){
    
    shaderControl.setName("vertical Noise");
}

void VerticalNoise::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("Phase", ofGetElapsedTimef());

    shader.setUniformTexture("tex0", tex, 0);
    
}

void VerticalNoise::end(){
    shader.end();
}

