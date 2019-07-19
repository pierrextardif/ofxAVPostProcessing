#pragma once

#include "ofMain.h"

#include "gui/GuiApp.h"
#include "shaderManager/shaderManager.hpp"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
    
    
    ofEasyCam  cam;
    
    GuiApp gui;
    bool guiON = true;
    
    ofVboMesh vbo;
    ofVboMesh setupSphere(int radius, int amount);
    
    ShaderManager sManager;
    
    ofFbo fbo;
    
    void calculateOnePos(ofVboMesh* vbo, float amount, float radius,float propI, float i, float j);
    void addToVbo(ofVboMesh* vbo, ofVec3f v, ofVec2f texCoord, ofColor col);
};
