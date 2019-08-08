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

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class EdgeOnTopManager : managerBase {
    
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
    
    
    void addUniforms(ofShader* shader, bool active);    
    
    ofParameter<float>Volume;
    ofParameter<float>ScaleW;
    ofParameter<float>ScaleH;
};

#endif /* EdgeOnTopManager_hpp */
