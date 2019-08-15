//
//  RGBShader.hpp
//  rayMarching_withPostProcessing
//
//  Created by Pierre Tardif on 12/08/2019.
//

#ifndef RGBShader_hpp
#define RGBShader_hpp

#include <stdio.h>

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class RGBShader : managerBase {
    
    public :
    
    string name = "RGB";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    RGBShader(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    ofParameter<float> brightness;
    ofParameter<float> contrast;
    ofParameter<float> saturation;
    ofParameter<float> alpha;
    ofParameter<float> red;
    ofParameter<float> green;
    ofParameter<float> blue;
    ofParameter<float> shadowIntensity;
    
};
#endif /* RGBShader_hpp */
