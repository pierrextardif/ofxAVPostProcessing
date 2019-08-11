//
//  HalftoneManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef InvertManager_hpp
#define InvertManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class InvertManager : managerBase {
    
    public :
    
    string name = "invert";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    InvertManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    
    ofParameter<float>Volume;
};

#endif /* InvertManager_hpp */
