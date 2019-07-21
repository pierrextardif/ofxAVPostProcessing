#include "ofMain.h"
#include "ofApp.h"

#include "constants.h"


//========================================================================
int main( ){

    
    ofGLWindowSettings settings;
    settings.setGLVersion(VERSION,SUB);
    settings.setSize(WIDTH, HEIGHT);
    ofCreateWindow(settings);
	ofRunApp( new ofApp());

}
