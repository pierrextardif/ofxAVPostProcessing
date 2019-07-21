//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef FringeManager_hpp
#define FringeManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class FringeManager {
    
    public :
    
    string name = "fringe";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    FringeManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    
    void begin(ofTexture tex);
    void end();
    
    
    ofParameter<float>Volume;
    ofParameter<float>ScaleW;
    ofParameter<float>ScaleH;
};

#endif /* FringeManager_hpp */
