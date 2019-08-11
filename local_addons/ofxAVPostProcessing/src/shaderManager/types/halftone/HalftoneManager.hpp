//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef HalftoneManager_hpp
#define HalftoneManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class HalftoneManager : managerBase {
    
    public :
    
    string name = "halftone";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    HalftoneManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    
    void addUniforms(ofShader* shader, bool active);
    
    ofParameter<float>radius;
    ofParameter<float>rotateR;
    ofParameter<float>rotateG;
    ofParameter<float>rotateB;
    ofParameter<float>scatter;
    ofParameter<float>width;
    ofParameter<float>height;
    ofParameter<int>shape;
    ofParameter<float>disableFloat;
    ofParameter<float>blending;
    ofParameter<int>blendingMode;
    ofParameter<float>greyscaleFloat;
    
};

#endif /* HalftoneManager_hpp */
