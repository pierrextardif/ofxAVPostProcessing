//
//  dotFragMirrorAxisManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragMirrorAxisManager_hpp
#define dotFragMirrorAxisManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class dotFragMirrorAxisManager : managerBase {
    
    public :
    
    string name = "dotFragMirrorAxis";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragMirrorAxisManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void begin(ofTexture tex);
    void end();
    
    
    ofParameter<bool> horizontal;
    ofParameter<bool> vertical;
};


#endif /* dotFragMirrorAxisManager_hpp */
