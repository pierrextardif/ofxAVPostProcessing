//
//  dotFragMirrorAxisManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragMirrorAxisManager_hpp
#define dotFragMirrorAxisManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class dotFragMirrorAxisManager : managerBase {
    
    public :
    
    string name = "mirrorAxis";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragMirrorAxisManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<bool> horizontal;
    ofParameter<bool> vertical;
    ofParameter<bool> doubleMatHorizontally;
    ofParameter<bool> doubleMatVertically;
};


#endif /* dotFragMirrorAxisManager_hpp */
