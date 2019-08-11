//
//  dotFragTwistManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragTwistManager_hpp
#define dotFragTwistManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class dotFragTwistManager : managerBase {
    
    public :
    
    string name = "twist";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragTwistManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<float> amount;
    ofParameter<float> variation;
};


#endif /* dotFragTwistManager_hpp */
