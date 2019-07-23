//
//  managerBase.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 23/07/2019.
//

#ifndef managerBase_hpp
#define managerBase_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== constants imports ==== //
#include "../../../constants.h"

class managerBase {
    
    public :
    
    string name = "";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    managerBase(){
        
    }
    
};
#endif /* managerBase_hpp */
