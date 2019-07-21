//
//  dotFragTurbulenceManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragTurbulenceManager_hpp
#define dotFragTurbulenceManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class dotFragTurbulenceManager {
    
    public :
    
    string name = "dotFragTurbulence";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragTurbulenceManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void begin(ofTexture tex);
    void end();
    
    
    ofParameter<float>x;
    ofParameter<float>y;
};

#endif /* dotFragTurbulenceManager_hpp */
