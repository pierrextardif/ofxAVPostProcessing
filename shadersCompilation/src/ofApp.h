#pragma once

#include "ofMain.h"
//#include "shaderCompilation/shaderCompilation.hpp"
// custom post Processing shaders
#include "ofxAVPostProcessing.hpp"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
    
    
    ofEasyCam  cam;
    
    
    ofVboMesh vbo;
    
    ofVideoPlayer myPlayer;

    //plane
    ofVboMesh setupPlane(int sizePlane, int amount);
    void addOnPlane(ofVboMesh* vbo, ofVec3f pos,ofVec2f texC, int amount);
    //sphere
    ofVboMesh setupSphere(int radius, int amount);
    void calculateOnePos(ofVboMesh* vbo, float amount, float radius,float propI, float i, float j);
    void addToVbo(ofVboMesh* vbo, ofVec3f v, ofVec2f texCoord, ofColor col);
    
    
    // custom shader
    ofxAVPostProcessing shaderComp;
    
};
