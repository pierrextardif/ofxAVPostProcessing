//
//  dotFragMonochromeManager.hpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#ifndef dotFragMonochromeManager_hpp
#define dotFragMonochromeManager_hpp

// ==== include the baseManager ==== //
#include "../../managerBase/managerBase.hpp"

class dotFragMonochromeManager : managerBase {
    
    public :
    
    string name = "monochrome";
    ofShader shader;
    
    ofParameterGroup shaderControl;
    
    dotFragMonochromeManager(){
        
        setup();
    };
    
    void setup();
    // ==== control ==== //
    void initGui();
    
    void addUniforms(ofShader* shader, bool active);
    
    ofParameter<float> low;
    ofParameter<float> high;
};


#endif /* dotFragMonochromeManager_hpp */
