//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef FringeManager_hpp
#define FringeManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class FringeManager : managerBase {
    
    public :
    
    string name = "fringe";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    FringeManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();    
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<float>Volume;
    ofParameter<float>ScaleW;
    ofParameter<float>ScaleH;
};

#endif /* FringeManager_hpp */
