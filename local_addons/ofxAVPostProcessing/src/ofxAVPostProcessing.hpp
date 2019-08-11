	//
//  ofxAVPostProcessing.hpp
//  ofxAVPostProcessing
//
//  Created by Pierre Tardif on 07/08/2019.
//

#ifndef ofxAVPostProcessing_hpp
#define ofxAVPostProcessing_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofEvents.h"


// ==== custom ==== //
#include "gui/GuiApp.h"
#include "shaderManager/shaderManager.hpp"

class ofxAVPostProcessing{
    public :
    ofxAVPostProcessing(){
        
    }
    
    GuiApp guiPanel;
    bool guiON = true;
    
    
    ShaderManager sManager;
    
    ofFbo fbo;
    
    void setup(int _width, int _height);
    void update();
    void draw();
    
    void keyPressed(ofKeyEventArgs &keyArgs);
    
    void begin();
    void end();
};

#endif /* ofxAVPostProcessing_hpp */
