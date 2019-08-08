//
//  ScanLinesManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 30/07/2019.
//

#include "ScanLinesManager.hpp"


void ScanLinesManager::setup(){
    
    string fullPath = pathToShader + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the " + name + " shader" << endl;
    
    initGui();
    
}

void ScanLinesManager::initGui(){
    
    shaderControl.setName(name);
    shaderControl.add(scanLines.set("scanLines", {2,2,2}, {0,0,0}, {4,4,4}));
}

void ScanLinesManager::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform3f("scanL", scanLines->x, scanLines->y, scanLines->z);

    shader.setUniformTexture("tex0", tex, 0);
    
}

void ScanLinesManager::end(){
    shader.end();
}

