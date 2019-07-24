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
    srcPtr->allocate(settings);
    
    // ==== shaders names ==== //
    names = {
        "halftoneShader",
        "glitchShader",
        "fringeShader",
        "invertShader",
        "vertNoiseShader",
        "noiseShader",
        "edgeOnTopShader",
        "dotFragHSB",
        "dotFragMirrorAxis",
        "dotFragTurbulence",
        "dotFragTwist",
        "dotFragMonochrome"
        
    };
    
//    for( int i = 0; i < names.size(); i++){
//
//        HalftoneManager                 halftoneShader;
//        shadersManagerVector.push_back(halftoneShader);
//        GlitchManager                   glitchShader;
//        shadersManagerVector.push_back(glitchShader);
//        FringeManager                   fringeShader;
//        shadersManagerVector.push_back(fringeShader);
//        InvertManager                   invertShader;
//        shadersManagerVector.push_back(invertShader);
//        VerticalNoise                   vertNoiseShader;
//        shadersManagerVector.push_back(vertNoiseShader);
//        NoiseManager                    noiseShader;
//        shadersManagerVector.push_back(noiseShader);
//        EdgeOnTopManager                edgeOnTopShader;
//        shadersManagerVector.push_back(edgeOnTopShader);
//        dotFragHSBManager               dotFragHSB;
//        shadersManagerVector.push_back(dotFragHSB);
//        dotFragMirrorAxisManager        dotFragMirrorAxis;
//        shadersManagerVector.push_back(dotFragMirrorAxis);
//        dotFragTurbulenceManager        dotFragTurbulence;
//        shadersManagerVector.push_back(dotFragTurbulence);
//        dotFragTwistManager             dotFragTwist;
//        shadersManagerVector.push_back(dotFragTwist);
//        dotFragMonochromeManager        dotFragMonochrome;
//        shadersManagerVector.push_back(dotFragMonochrome);
////        string nameManager = names[i] +
////        shadersManagerVector.push_back(nameManager);
//    }
}



void ShaderManager::draw(vector <bool> activeShaders){
    
//    buffer[0].begin();
    srcPtr->begin();
    ofClear(0);
    sourceBuf->draw(0,0);
    srcPtr->end();
//    buffer[0].end();
    
//    srcPtr = &buffer[0];
//    dstPtr = &buffer[1];
    dstPtr = srcPtr;
    
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
    if(activeShaders[7]){
        dstPtr->begin();
        dotFragHSB.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        dotFragHSB.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[8]){
        dstPtr->begin();
        dotFragMirrorAxis.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        dotFragMirrorAxis.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[9]){
        dstPtr->begin();
        dotFragTurbulence.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        dotFragTurbulence.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
    if(activeShaders[10]){
        dstPtr->begin();
        dotFragTwist.begin(srcPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        dotFragTwist.end();
        dstPtr->end();
        
        swap(srcPtr, dstPtr);
    }
//    if(activeShaders[11]){
//        dstPtr->begin();
//        dotFragEchoTrace.begin(dstPtr->getTextureReference());
//        
//        srcPtr->draw(0,0);
//        dotFragEchoTrace.end();
//        dstPtr->end();
//        
//        swap(srcPtr, dstPtr);
//    }
    if(activeShaders[11]){
        dstPtr->begin();
        dotFragMonochrome.begin(dstPtr->getTextureReference());
        
        srcPtr->draw(0,0);
        dotFragMonochrome.end();
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
