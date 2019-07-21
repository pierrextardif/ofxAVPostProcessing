//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef EdgeOnTopManager_hpp
#define EdgeOnTopManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class EdgeOnTopManager {
    
    public :
    
    string name = "edgeOnTop";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    EdgeOnTopManager(){
        
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

#endif /* EdgeOnTopManager_hpp */
