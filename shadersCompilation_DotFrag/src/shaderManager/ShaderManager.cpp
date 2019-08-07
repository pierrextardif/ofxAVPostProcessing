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
    
//    dotFragDelay.fDelay1.allocate(settings);
//    dotFragDelay.fDelay2.allocate(settings);
    
//    for( int i = 0; i < dotFragDelay.fbos.size(); i++){
//        dotFragDelay.fbos[i].allocate( settings );
//        dotFragDelay.fbos[i].begin();
//        ofClear(0, 0, 0, 0);
//        dotFragDelay.fbos[i].end();
//    }
}



void ShaderManager::draw(vector <bool> activeShaders){
    
    srcPtr = sourceBuf;
    dstPtr = sourceBuf;
    
    for( int i = 0; i < activeShaders.size(); i++){
        if(activeShaders[i]){
            dstPtr->begin();
            tableShaderCorrespondanceBegin(i);
            srcPtr->draw(0,0);
            tableShaderCorrespondanceEnd(i);
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
            dotFragTurbulence.begin(srcPtr->getTextureReference());
            break;
        case 11:
            dotFragTwist.begin(srcPtr->getTextureReference());
            break;
        case 12:
            dotFragMonochrome.begin(srcPtr->getTextureReference());
            break;
//        case 13:
//            dotFragDelay.begin(srcPtr->getTextureReference());
//            break;
            
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
            dotFragTurbulence.end();
            break;
        case 11:
            dotFragTwist.end();
            break;
        case 12:
            dotFragMonochrome.end();
            break;
//        case 13:
//            dotFragDelay.end();
//            break;
            
    }
}

