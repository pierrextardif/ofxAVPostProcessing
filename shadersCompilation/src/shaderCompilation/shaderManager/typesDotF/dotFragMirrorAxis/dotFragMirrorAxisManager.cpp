//
//  dotFragMirrorAxisManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragMirrorAxisManager.hpp"


void dotFragMirrorAxisManager::setup(){
    
    string fullPath = "../../src/shaderManager/typesDotF/" + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the " + name + " shader" << endl;
    
    shaderControl.setName(name);
    
    initGui();
}

void dotFragMirrorAxisManager::initGui(){
    
    shaderControl.setName(name);
    
    shaderControl.add(horizontal.set("horizontal", false));
    shaderControl.add(vertical.set("vertical", false));
                      
    
}

void dotFragMirrorAxisManager::begin(ofTexture tex){
    
    shader.begin();
    shader.setUniform1f("u_horizontal", (horizontal)?   1.0f : 0.0f );
    shader.setUniform1f("u_vertical",   (vertical)?     1.0f : 0.0f );
    shader.setUniformTexture("tex0", tex, 0);
    shader.setUniform2f("u_resolution", {WIDTH / 2, HEIGHT / 2});
}

void dotFragMirrorAxisManager::end(){
    shader.end();
}
