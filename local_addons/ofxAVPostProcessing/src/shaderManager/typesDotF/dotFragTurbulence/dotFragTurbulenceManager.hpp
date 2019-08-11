//
//  dotFragTurbulenceManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragTurbulenceManager_hpp
#define dotFragTurbulenceManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class dotFragTurbulenceManager : managerBase{
    
    public :
    
    string name = "turbulence";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragTurbulenceManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<float>x;
    ofParameter<float>y;
};

#endif /* dotFragTurbulenceManager_hpp */
