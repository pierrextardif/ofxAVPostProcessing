#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOscParameterSync.h"

#include "../constants.h"

class GuiApp {
    public:
        void setup();
        void add(ofParameterGroup shaderControl);
        void finishSetup();

        void update();
        void draw();
    
    
    
        vector < ofParameter< bool > > activatedShaders;
    
    
        ofxPanel gui;
    
        ofxOscParameterSync sync;
    
    ofxOscReceiver receiverTest;
    float testShader;
};

