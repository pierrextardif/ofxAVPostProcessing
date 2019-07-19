#pragma once

#include "ofMain.h"
#include "ofxTessellationShader.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
    
		void setup();
        void setupGui();
        void loadTextures();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void exit();
//        void guiEvent(ofxUIEventArgs &e);
    
        ofxPanel gui;
    
        ofParameter<float> BG_RED;
        ofParameter<float> BG_GREEN;
        ofParameter<float> BG_BLUE;
        ofParameter<float> SPEED;
    
        ofParameter<int> BLEND_MODE;
        ofParameter<bool>PATCHES;
        ofParameter<bool>FILL;
        ofParameter<bool>WIREFRAME;
        ofParameter<bool>DYNAMIC_LOD;
        ofParameter<int> INNER_TESS;
        ofParameter<int>OUTER_TESS;
    
        ofParameter < float > VE;
    
        void updateValsFromGui();

		
        ofxTessellationShader tessShader;
        ofVboMesh mesh;
        ofVboMesh patchMesh;
        ofEasyCam cam;
    
        vector <ofTexture> heightMaps;
        vector <ofTexture> colourMaps;
    
        int heightIndex;
        int colourIndex;
    
        float offset;
        float speed;
        string blendMode;
        float ve;
    
        ofColor bg;
    
//        ofxUICanvas *gui;
    
        bool bDrawPatches;
        bool bDrawWireframe;
        bool bDrawFill;
        bool bDynamicLOD;
    
        int innerLevel;
        int outerLevel;
    
    
    
};
