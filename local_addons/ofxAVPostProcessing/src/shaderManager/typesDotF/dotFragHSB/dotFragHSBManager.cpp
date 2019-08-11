//
//  dotFragHSBManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragHSBManager.hpp"


void dotFragHSBManager::setup(){
    
//    string fullPath = pathToDotShader + name + "/shader";
//    filesystem::path path = filesystem::path(fullPath);
//    shader.load(path/"shader.vert", path/"shader.frag");
//    
//    if(!shader.isLoaded())cout << "issue loading the dotFragHSB shader" << endl;
//    
//    shaderControl.setName("dotFragHSB");
    
    initGui();
    
}

void dotFragHSBManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(hue.set("hue", 0, 0,1));
    shaderControl.add(brightness.set("brightness", 0, -1, 1));
    shaderControl.add(saturation.set("saturation", 1, 0, 2));
    shaderControl.add(contrast.set("contrast", 1, 0, 2));
}

void dotFragHSBManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniform1f("u_hue", hue);
        shader->setUniform1f("u_brightness", brightness);
        shader->setUniform1f("u_saturation", saturation);
        shader->setUniform1f("u_contrast", contrast);
//        shader.setUniform1f("sine", ofGetElapsedTimef());
    }
    
}
