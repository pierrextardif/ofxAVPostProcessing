//
//  HoleManager.hpp
//  rayMarching_2
//
//  Created by Pierre Tardif on 08/08/2019.
//

#ifndef HoleManager_hpp
#define HoleManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class HoleManager : managerBase {
    
    public :
    
    string name = "hole";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    HoleManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    ofParameter<float> holeSize;
    ofParameter<ofVec3f> maskCol;
    ofParameter<float> spacingDots;
    ofParameter<float> antialiasRange;
    
};
#endif /* HoleManager_hpp */
