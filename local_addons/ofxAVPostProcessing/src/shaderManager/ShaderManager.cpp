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
    
#ifdef LOCALADDON
    string fullPath = "../../../local_addons/ofxAVPostProcessing/src/shaderManager/mainShader/";
#else
    string fullPath = "../../../../../addons/ofxAVPostProcessing/src/shaderManager/mainShader/";
#endif

    filesystem::path path = filesystem::path(fullPath);
    mainShader.load(path/"mainShader.vert", path/"mainShader.frag");

    if(!mainShader.isLoaded())cout << "issue loading the main shader" << endl;
    
    resolution = {(float)settings.width, (float)settings.height};
}



void ShaderManager::draw(vector <ofParameter<bool>> activeShaders){
    
    srcPtr = sourceBuf;
    
    mainShader.begin();
    
    halftoneManager.addUniforms(        &mainShader, activeShaders[0]);
    glitchManager.addUniforms(          &mainShader, activeShaders[1]);
    fringeManager.addUniforms(          &mainShader, activeShaders[2]);
    invertManager.addUniforms(          &mainShader, activeShaders[3]);
    vertNoiseManager.addUniforms(       &mainShader, activeShaders[4]);
    noiseManager.addUniforms(           &mainShader, activeShaders[5]);
    edgeOnTopManager.addUniforms(       &mainShader, activeShaders[6]);
    scanLinesManager.addUniforms(       &mainShader, activeShaders[7]);
    dotFragHSB.addUniforms(             &mainShader, activeShaders[8]);
    dotFragMirrorAxis.addUniforms(      &mainShader, activeShaders[9]);
    dotFragTurbulence.addUniforms(      &mainShader, activeShaders[10]);
    dotFragTwist.addUniforms(           &mainShader, activeShaders[11]);
    dotFragMonochrome.addUniforms(      &mainShader, activeShaders[12]);
    holeManager.addUniforms(            &mainShader, activeShaders[13]);
    godRaysManager.addUniforms(         &mainShader, activeShaders[14]);
    
    mainShader.setUniformTexture("tex0", srcPtr->getTextureReference(), 0);
    mainShader.setUniform1f("iTime", ofGetElapsedTimef());
    mainShader.setUniform2f("resolution", resolution);
    srcPtr->draw(0,0);
    srcPtr->draw(0,0);
    mainShader.end();
    
}
