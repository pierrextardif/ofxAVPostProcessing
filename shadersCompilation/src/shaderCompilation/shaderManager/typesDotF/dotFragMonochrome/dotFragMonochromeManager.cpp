//
//  dotFragMonochromeManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragMonochromeManager.hpp"


void dotFragMonochromeManager::setup(){
    
    string fullPath = pathToDotShader + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the " + name + " shader" << endl;
    
    shaderControl.setName(name);
    
    initGui();
    
}

void dotFragMonochromeManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(low.set("low", 0, 0,1));
    shaderControl.add(high.set("high", 1, 0,1));
}

void dotFragMonochromeManager::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("u_low", low);
    shader.setUniform1f("u_high", high);
    shader.setUniformTexture("tex0", tex, 0);
    
}

void dotFragMonochromeManager::end(){
    shader.end();
}
