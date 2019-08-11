//
//  ofxAVPostProcessing.cpp
//  ofxAVPostProcessing
//
//  Created by Pierre Tardif on 07/08/2019.
//

#include "ofxAVPostProcessing.hpp"

void ofxAVPostProcessing::setup(int _width, int _height){
    guiPanel.setup();
    
    ofFbo::Settings settings;
    settings.width = _width;
    settings.height = _height;
    fbo.allocate(_width, _height);
    
    
    // ==== shaders ==== //
    sManager.setup(&fbo, settings);
    guiPanel.add(sManager.halftoneManager.shaderControl);
    guiPanel.add(sManager.glitchManager.shaderControl);
    guiPanel.add(sManager.fringeManager.shaderControl);
    guiPanel.add(sManager.invertManager.shaderControl);
    guiPanel.add(sManager.vertNoiseManager.shaderControl);
    guiPanel.add(sManager.noiseManager.shaderControl);
    guiPanel.add(sManager.edgeOnTopManager.shaderControl);
    guiPanel.add(sManager.scanLinesManager.shaderControl);
    //dot frag
    guiPanel.add(sManager.dotFragHSB.shaderControl);
    guiPanel.add(sManager.dotFragMirrorAxis.shaderControl);
    guiPanel.add(sManager.dotFragTurbulence.shaderControl);
    guiPanel.add(sManager.dotFragTwist.shaderControl);
    guiPanel.add(sManager.dotFragMonochrome.shaderControl);
    // others
    guiPanel.add(sManager.holeManager.shaderControl);
    guiPanel.add(sManager.godRaysManager.shaderControl);
    guiPanel.finishSetup();

//    guiPanel.gui.loadFromFile("settings.xml");

    ofAddListener(ofEvents().keyPressed, this, &ofxAVPostProcessing::keyPressed);
}

void ofxAVPostProcessing::update(){
    guiPanel.update();
    
}

void ofxAVPostProcessing::begin(){
    fbo.begin();
    ofClear(0);
}
void ofxAVPostProcessing::end(){
    fbo.end();
    
    sManager.draw(guiPanel.activatedShaders);
    if(guiON)guiPanel.draw();
    
}

void ofxAVPostProcessing::keyPressed(ofKeyEventArgs &keyArgs){
    if(keyArgs.key == 'g')guiON = !guiON;
}
