//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef NoiseManager_hpp
#define NoiseManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class NoiseManager : managerBase {
    
    public :
    
    string name = "noise";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    NoiseManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<float>Volume;
};

#endif /* NoiseManager_hpp */
