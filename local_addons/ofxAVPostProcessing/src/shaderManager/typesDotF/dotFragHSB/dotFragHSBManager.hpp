//
//  dotFragHSBManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragHSBManager_hpp
#define dotFragHSBManager_hpp

// ==== constants imports ==== //
#include "../../../constants.h"

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class dotFragHSBManager : managerBase{
    
    public :
    
    string name = "dotFragHSB";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragHSBManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<float>hue;
    ofParameter<float>brightness;
    ofParameter<float>saturation;
    ofParameter<float>contrast;
};



#endif /* dotFragHSBManager_hpp */
