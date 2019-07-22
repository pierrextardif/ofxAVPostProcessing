//
//  dotFragMonochromeManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragMonochromeManager_hpp
#define dotFragMonochromeManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class dotFragMonochromeManager {
    
    public :
    
    string name = "dotFragMonochrome";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragMonochromeManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void begin(ofTexture tex);
    void end();
    
    ofParameter<float> low;
    ofParameter<float> high;
};


#endif /* dotFragMonochromeManager_hpp */
