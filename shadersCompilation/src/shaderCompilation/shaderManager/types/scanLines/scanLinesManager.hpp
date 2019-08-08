//
//  ScanLinesManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 30/07/2019.
//

#ifndef ScanLinesManager_hpp
#define ScanLinesManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class ScanLinesManager : managerBase {
    
    public :
    
    string name = "ScanLines";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    ScanLinesManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    ofParameter < ofVec3f > scanLines;
    
    
    
    
    
    void addUniforms(ofShader* shader, bool active);
};

#endif /* ScanLinesManager_hpp */
