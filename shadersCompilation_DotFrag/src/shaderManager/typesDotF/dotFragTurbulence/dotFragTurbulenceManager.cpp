//
//  dotFragTurbulenceManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragTurbulenceManager.hpp"


void dotFragTurbulenceManager::setup(){
    
    string fullPath = "../../src/shaderManager/typesDotF/" + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the " + name + " shader" << endl;
    
    shaderControl.setName(name);
    
    initGui();
}

void dotFragTurbulenceManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(x.set("x", 0, 0, 1));
    shaderControl.add(y.set("y", 0, 0, 1));
    
}

void dotFragTurbulenceManager::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("u_amount_x", x);
    shader.setUniform1f("u_amount_y", y);
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniformTexture("tex0", tex, 0);
    shader.setUniform2f("u_resolution", {WIDTH, HEIGHT});
}

void dotFragTurbulenceManager::end(){
    shader.end();
}

