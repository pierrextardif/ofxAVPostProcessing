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
    buffer[0].allocate(settings);
    buffer[1].allocate(settings);
    
    // ==== shaders names ==== //
    names = {
        "halftoneShader",
        "glitchShader",
        "fringeShader",
        "invertShader",
        "vertNoiseShader",
        "noiseShader",
        "edgeOnTopShader",
        "scanLinesShader",
        "dotFragHSB",
        "dotFragMirrorAxis",
        "dotFragTurbulence",
        "dotFragTwist",
        "dotFragMonochrome"
        
    };
    
}



void ShaderManager::draw(vector <bool> activeShaders){
    
    buffer[0].begin();
//    srcPtr->begin();
    ofClear(0);
    sourceBuf->draw(0,0);
//    srcPtr->end();
    buffer[0].end();
    
    srcPtr = &buffer[0];
    dstPtr = &buffer[1];
//    dstPtr = srcPtr;
    
    for( int i = 0; i < activeShaders.size(); i++){
        if(activeShaders[i]){
            dstPtr->begin();
            tableShaderCorrespondanceBegin(i);
            //        halftoneShader.begin();
            srcPtr->draw(0,0);
            tableShaderCorrespondanceEnd(i);
            //        halftoneShader.end();
            dstPtr->end();
            
            swap(srcPtr, dstPtr);
        }
    }
    
    srcPtr->draw(0,0);
    
    
}

void ShaderManager::tableShaderCorrespondanceBegin(int indexShader){
    switch(indexShader){
        case 0:
            halftoneShader.begin();

            break;
        case 1:
            glitchShader.begin();
            break;
        case 2:
            fringeShader.begin(srcPtr->getTextureReference());
            break;
        case 3:
            invertShader.begin(srcPtr->getTextureReference());
            break;
        case 4:
            vertNoiseShader.begin(srcPtr->getTextureReference());
            break;
        case 5:
            noiseShader.begin(srcPtr->getTextureReference());
            break;
        case 6:
            edgeOnTopShader.begin(srcPtr->getTextureReference());
            break;
        case 7:
            scanLinesShader.begin(srcPtr->getTextureReference());
            break;
        case 8:
            dotFragHSB.begin(srcPtr->getTextureReference());
            break;
        case 9:
            dotFragMirrorAxis.begin(srcPtr->getTextureReference());
            break;
        case 10:
            dotFragTwist.begin(srcPtr->getTextureReference());
            break;
        case 11:
            dotFragMonochrome.begin(srcPtr->getTextureReference());
            break;
            
    }
}



void ShaderManager::tableShaderCorrespondanceEnd(int indexShader){
    switch(indexShader){
        case 0:
            halftoneShader.end();
            
            break;
        case 1:
            glitchShader.end();
            break;
        case 2:
            fringeShader.end();
            break;
        case 3:
            invertShader.end();
            break;
        case 4:
            vertNoiseShader.end();
            break;
        case 5:
            noiseShader.end();
            break;
        case 6:
            edgeOnTopShader.end();
            break;
        case 7:
            scanLinesShader.end();
            break;
        case 8:
            dotFragHSB.end();
            break;
        case 9:
            dotFragMirrorAxis.end();
            break;
        case 10:
            dotFragTwist.end();
            break;
        case 11:
            dotFragMonochrome.end();
            break;
            
    }
}

