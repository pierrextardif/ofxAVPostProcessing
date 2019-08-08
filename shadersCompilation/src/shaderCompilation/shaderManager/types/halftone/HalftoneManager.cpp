//
//  HaltoneManager.cpp
//  shaderControlCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "HalftoneManager.hpp"


void HalftoneManager::setup(){
    
    string fullPath = pathToShader + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the halftone shader" << endl;
    
    initGui();
    
}

void HalftoneManager::initGui(){
    
    shaderControl.setName("halftone");
    
    shaderControl.add(radius.set("radius", 1, 1,25));
    shaderControl.add(rotateR.set("rotateR", 0, 0,M_PI));
    shaderControl.add(rotateG.set("rotateG", 1, 0,M_PI));
    shaderControl.add(rotateB.set("rotateB", 1, 0,M_PI));
    shaderControl.add(scatter.set("scatter", 1, 0,1));
    shaderControl.add(shape.set("shape", 1, 1,4));
    shaderControl.add(blending.set("blending", 1, 0,1));
    shaderControl.add(blendingMode.set("blendingMode", 1, 1,5));
}

void HalftoneManager::begin(){
    
    shader.begin();
    shader.setUniform1f("radius", radius);
    shader.setUniform1f("rotateR", rotateR);
    shader.setUniform1f("rotateG", rotateG);
    shader.setUniform1f("rotateB", rotateB);
    shader.setUniform1f("scatter", scatter);
    shader.setUniform1f("width", WIDTH);
    shader.setUniform1f("height", HEIGHT);
    shader.setUniform1i("shape", shape);
    shader.setUniform1f("blending", blending);
    shader.setUniform1i("blendingMode", blendingMode);
    
}

void HalftoneManager::end(){
    shader.end();
}

