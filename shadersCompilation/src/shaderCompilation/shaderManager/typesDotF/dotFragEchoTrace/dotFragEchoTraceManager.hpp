//
//  dotFragEchoTraceManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragEchoTraceManager_hpp
#define dotFragEchoTraceManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class dotFragEchoTraceManager {
    
    public :
    
    string name = "dotFragEchoTrace";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragEchoTraceManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void begin(ofTexture tex);
    void end();
    
    
    
    ofParameter<float> gain;
    ofParameter<float> threshold;
    ofParameter<bool> invert;
    ofParameter<bool> hardCutoff;
};


#endif /* dotFragEchoTraceManager_hpp */
