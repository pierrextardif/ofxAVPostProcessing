//
//  GlitchManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 19/03/2019.
//

#ifndef GlitchManager_hpp
#define GlitchManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class GlitchManager : managerBase{
    
    public :
    
    string name = "glitch";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    GlitchManager(){
        
        setup();
    }
    
    void setup();
    // ==== control ==== //
    void initGui();

    
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<float>amount;
    ofParameter<float>angle;
    ofParameter<float>seed;
    ofParameter<float>seed_x;
    ofParameter<float>seed_y;
    ofParameter<float>distortion_x;
    ofParameter<float>distortion_y;
    ofParameter<float>col_s;
    
    ofParameter < int > iterationsGlitch;
    
    
};

#endif /* GlitchManager_hpp */
