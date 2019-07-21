//
//  dotFragTwistManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragTwistManager_hpp
#define dotFragTwistManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class dotFragTwistManager {
    
    public :
    
    string name = "dotFragTwist";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragTwistManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void begin(ofTexture tex);
    void end();
    
    
    
    ofParameter<float> amount;
    ofParameter<float> variation;
};


#endif /* dotFragTwistManager_hpp */
