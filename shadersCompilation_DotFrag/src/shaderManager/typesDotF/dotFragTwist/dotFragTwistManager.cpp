//
//  dotFragTwistManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragTwistManager.hpp"

void dotFragTwistManager::setup(){
    
    string fullPath = "../../src/shaderManager/typesDotF/" + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the " + name + " shader" << endl;
    
    shaderControl.setName(name);
    
    initGui();
    
}

void dotFragTwistManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(amount.set("amount", 0.5, 0, 1.0));
    shaderControl.add(variation.set("variation", 0.5, 0, 1.0));
}

void dotFragTwistManager::begin(ofTexture tex){
    float rand = ofRandom( 1.005f-variation );
    shader.begin();
    shader.setUniform1f        ("rand",        rand);
    shader.setUniform1f        ("val1",        ofRandom(amount));
    shader.setUniform1f        ("val2",        ofRandom(amount));
    shader.setUniform1f        ("val3",        ofRandom(amount));
    shader.setUniform1f        ("val4",        ofRandom(amount));
    shader.setUniform1f        ("multx",       1.0f/(1.5325*rand*rand) );
    shader.setUniform1f        ("multy",       1.0f/(2.5157*rand*rand) );
    
    shader.setUniformTexture("tex0", tex, 0);
    shader.setUniform2f("u_resolution", {WIDTH, HEIGHT});
}

void dotFragTwistManager::end(){
    shader.end();
}
