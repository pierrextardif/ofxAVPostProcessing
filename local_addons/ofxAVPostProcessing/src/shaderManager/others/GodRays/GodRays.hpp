//
//  GodRays.hpp
//  rayMarching_2
//
//  Created by Pierre Tardif on 09/08/2019.
//

#ifndef GodRays_hpp
#define GodRays_hpp

#include <stdio.h>

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class GodRays : managerBase {
    
    public :
    
    string name = "godRays";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    GodRays(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    ofVec2f positionLight;
    void updatePositionLight();
    
    void addUniforms(ofShader* shader, bool active);
    
    ofParameter<float> lightDirDOTviewDir;
    ofParameter<ofVec2f> lightMoveSpeed;
    ofParameter<float> samples;
    
};

#endif /* GodRays_hpp */
