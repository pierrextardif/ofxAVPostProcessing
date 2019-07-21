//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef VerticalNoise_hpp
#define VerticalNoise_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class VerticalNoise {
    
    public :
    
    string name = "verticalNoise";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    VerticalNoise(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    
    void begin(ofTexture tex);
    void end();
};

#endif /* VerticalNoise_hpp */
