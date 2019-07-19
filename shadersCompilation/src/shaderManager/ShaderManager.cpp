//
//  ShaderManager.cpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#include "ShaderManager.hpp"

void ShaderManager::setup(ofFbo* f, ofFbo::Settings settings){
    
//    int indexShader = 0;
//    while(indexShader < name.size()){
//        if(name[indexShader] == "halftone"){
//            cout << "loading halftone " << endl;
//
//            HalftoneManager halftoneS;
//            halftoneShaders.push_back(halftoneS);
//
//        }
//        if(name[indexShader] == "glitch"){
//            cout << "loading glitch " << endl;
//
//            GlitchManager glitchS;
//            glitchShaders.push_back(glitchS);
//
//        }
//        if(name[indexShader] == "fringe"){
//            cout << "loading fringe " << endl;
//
//            FringeManager fringeS;
//            fringeShaders.push_back(fringeS);
//
//        }
//        if(name[indexShader] == "invert"){
//            cout << "loading invert " << endl;
//
//            InvertManager invertS;
//            invertShaders.push_back(invertS);
//
//        }
//        indexShader ++;
//    }
    
    // ==== buffer shaders ==== //
    sourceBuf = f;
    buffer[0].allocate(settings);
    buffer[1].allocate(settings);
    
}



void ShaderManager::draw(vector <bool> activeShaders){
    
    buffer[0].begin();
    ofClear(0);
    sourceBuf->draw(0,0);
    buffer[0].end();
    
    srcPtr = &buffer[0];
    dstPtr = &buffer[1];
    
    int indexShaderActivation = 0;
    
    if(activeShaders[0]){
        dstPtr->begin();
        halftoneShader.begin();
        srcPtr->draw(0,0);
        halftoneShader.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[1]){
        dstPtr->begin();
        glitchShader.begin();
        srcPtr->draw(0,0);
        glitchShader.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[2]){
        dstPtr->begin();
        fringeShader.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        fringeShader.end();
        dstPtr->end();

        swap(srcPtr, dstPtr);
    }
    if(activeShaders[3]){
        dstPtr->begin();
        invertShader.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        invertShader.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[4]){
        dstPtr->begin();
        vertNoiseShader.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        vertNoiseShader.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[5]){
        dstPtr->begin();
        noiseShader.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        noiseShader.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[6]){
        dstPtr->begin();
        edgeOnTopShader.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        edgeOnTopShader.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    
    srcPtr->draw(0,0);
    
    
    
    //    sourceBuf->begin();
    //    ofClear(0);
    //
    //    srcPtr->draw(0,0);
    //
    //    sourceBuf->end();
    
    
}
