//
//  ShaderManager.hpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 18/03/2019.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== ShaderHandlers types ==== //
#include "types/halftone/HalftoneManager.hpp"
#include "types/glitch/GlitchManager.hpp"
#include "types/fringe/FringeManager.hpp"
#include "types/invert/InvertManager.hpp"
#include "types/verticalNoise/VerticalNoise.hpp"
#include "types/noise/NoiseManager.hpp"
#include "types/edgeOnTop/EdgeOnTopManager.hpp"


class ShaderManager{
  
    public :
    ShaderManager(){
        
    }
    
    
    int amntShaders;
    
    HalftoneManager         halftoneShader;
    GlitchManager           glitchShader;
    FringeManager           fringeShader;
    InvertManager           invertShader;
    VerticalNoise           vertNoiseShader;
    NoiseManager            noiseShader;
    EdgeOnTopManager         edgeOnTopShader;
    
    void setup(ofFbo* f, ofFbo::Settings settings);
    void draw(vector < bool > activeShaders);
    
    ofFbo *sourceBuf;
    ofFbo buffer[2];
    
    ofFbo *srcPtr;
    ofFbo *dstPtr;
    
};

#endif /* ShaderManager_hpp */
