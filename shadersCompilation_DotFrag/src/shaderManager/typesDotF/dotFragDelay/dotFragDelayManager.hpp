//
//  dotFragDelayManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragDelayManager_hpp
#define dotFragDelayManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class dotFragDelayManager {
    
    public :
    
    string name = "dotFragDelay";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragDelayManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void begin(ofTexture tex);
    void end();
    
    // fbo
    int amountDelays;
    int indexBuffer;
    vector < ofFbo > fbos;
    
    
    
    ofParameter<int>   delays;
    ofParameter<float> feedback;
    ofParameter<int>   blendmode;
};


#endif /* dotFragDelayManager_hpp */
