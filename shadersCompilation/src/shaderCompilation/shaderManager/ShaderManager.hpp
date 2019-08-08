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
#include "types/scanLines/scanLinesManager.hpp"

// ==== ShaderHandlers ofxDotFrag ==== //
#include "typesDotF/dotFragHSB/dotFragHSBManager.hpp"
#include "typesDotF/dotFragMirrorAxis/dotFragMirrorAxisManager.hpp"
#include "typesDotF/dotFragTurbulence/dotFragTurbulenceManager.hpp"
#include "typesDotF/dotFragTwist/dotFragTwistManager.hpp"
#include "typesDotF/dotFragMonochrome/dotFragMonochromeManager.hpp"


class ShaderManager{
  
    public :
    ShaderManager(){
        
    }
    
    // ==== shader Managers ==== //
    HalftoneManager                 halftoneManager;
    GlitchManager                   glitchManager;
    FringeManager                   fringeManager;
    InvertManager                   invertManager;
    VerticalNoise                   vertNoiseManager;
    NoiseManager                    noiseManager;
    EdgeOnTopManager                edgeOnTopManager;
    ScanLinesManager                scanLinesManager;
    
//    dotFragHSBManager               dotFragHSB;
//    dotFragMirrorAxisManager        dotFragMirrorAxis;
//    dotFragTurbulenceManager        dotFragTurbulence;
//    dotFragTwistManager             dotFragTwist;
//    dotFragMonochromeManager        dotFragMonochrome;
    
    
    void setup(ofFbo* f, ofFbo::Settings settings);
    void draw(vector <ofParameter<bool>> activeShaders);
    
    // pointer to the fbo used to Draw things
    ofFbo *sourceBuf;
    
    // points to swapping fbos for multi shader effects
    ofFbo *srcPtr;
    ofFbo *dstPtr;
    
    
    ofShader mainShader;
};

#endif /* ShaderManager_hpp */
