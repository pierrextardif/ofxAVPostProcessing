//
//  ShaderManager.cpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "ShaderManager.hpp"

void ShaderManager::setup(ofFbo* f, ofFbo::Settings settings){
    
    // ==== buffer shaders ==== //
    sourceBuf = f;
    
    // ==== main shader Load ==== //
    mainShader.load("../../src/shaderCompilation/shaderManager/mainShader/mainShader.vert",
                    "../../src/shaderCompilation/shaderManager/mainShader/mainShader.frag");
    
    ofVec2f widthHeight = {(float)settings.width, (float)settings.height};
    
    fringeManager.uniformsWidthHeight = widthHeight;
}



void ShaderManager::draw(vector <ofParameter<bool>> activeShaders){
    
    srcPtr = sourceBuf;
    
    mainShader.begin();
    
    halftoneManager.addUniforms(    &mainShader, activeShaders[0]);
    glitchManager.addUniforms(      &mainShader, activeShaders[1]);
    fringeManager.addUniforms(      &mainShader, activeShaders[2]);
    invertManager.addUniforms(      &mainShader, activeShaders[3]);
    vertNoiseManager.addUniforms(   &mainShader, activeShaders[4]);
    noiseManager.addUniforms(       &mainShader, activeShaders[5]);
    edgeOnTopManager.addUniforms(   &mainShader, activeShaders[6]);
    scanLinesManager.addUniforms(   &mainShader, activeShaders[7]);
    
    mainShader.setUniformTexture("tex0", srcPtr->getTextureReference(), 0);
    mainShader.setUniform1f("iTime", ofGetElapsedTimef());
    srcPtr->draw(0,0);
    mainShader.end();
    
}
