//
//  dotFragEchoTraceManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragEchoTraceManager.hpp"

void dotFragEchoTraceManager::setup(){
    
    string fullPath = "../../src/shaderManager/typesDotF/" + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the " + name + " shader" << endl;
    
    shaderControl.setName(name);
    
    initGui();
}

void dotFragEchoTraceManager::initGui(){
    shaderControl.setName(name);

    shaderControl.add(gain.set("gain", 0.7, 0, 2.0));
    shaderControl.add(threshold.set("threshold", 0.55, 0, 1.0));
    shaderControl.add(invert.set("invert", false));
    shaderControl.add(hardCutoff.set("hardCutoff", false));
}

void dotFragEchoTraceManager::begin(ofTexture tex){

    shader.begin();
    shader.setUniform1f("u_gain", gain);
    shader.setUniform1f("u_threshold", threshold);
    shader.setUniform1f("u_invert", invert?1:0);
    shader.setUniform1f("u_hardcutoff", hardCutoff?1:0);
    shader.setUniformTexture("tex1", tex, 1);
//    shader.setUniformTexture("tex1", tex1, 0);
    shader.setUniform2f("u_resolution", {WIDTH, HEIGHT});
}

void dotFragEchoTraceManager::end(){
    shader.end();
}
