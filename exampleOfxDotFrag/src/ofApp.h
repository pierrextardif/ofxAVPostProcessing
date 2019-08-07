#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDotFrag.h"

class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
        
        void openCam();
        
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);


        string path;
        int mode;
        float nCursor;
        
        ofImage img;
        ofVideoGrabber vidGrabber;

        ofFbo fbo;
        
        vector<string> arguments;
        
        bool bCamOpen;
        bool bDisplayFps;
        
        bool bDrawGui;
        ofxPanel gui;

        // change the name to test different shaders
    /*
#include "dotfrag/Delay.h"
#include "dotfrag/HSB.h"
#include "dotfrag/Mirror.h"
#include "dotfrag/MirrorAxis.h"
#include "dotfrag/ThreeTones.h"
#include "dotfrag/InvertStrobe.h"
#include "dotfrag/EchoTrace.h"
#include "dotfrag/Turbolence.h"
#include "dotfrag/FXAA.h"
#include "dotfrag/Twist.h"
#include "dotfrag/RadialRemap.h"
#include "dotfrag/Live.h"
#include "dotfrag/Monochrome.h"
     */
        ofx::dotfrag::Live frag;
};
