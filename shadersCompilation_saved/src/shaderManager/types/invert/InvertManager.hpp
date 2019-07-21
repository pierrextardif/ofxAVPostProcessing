//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef InvertManager_hpp
#define InvertManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class InvertManager {
    
    public :
    
    string name = "invert";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    InvertManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //    
    
    void begin(ofTexture tex);
    void end();
    
    
    ofParameter<float>Volume;
};

#endif /* InvertManager_hpp */