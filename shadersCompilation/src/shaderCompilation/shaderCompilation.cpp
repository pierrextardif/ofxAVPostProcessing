//
//  shaderCompilation.cpp
//  shadersCompilation
//
//  Created by Pierre Tardif on 07/08/2019.
//

#include "shaderCompilation.hpp"

void shaderCompilation::setup(int _width, int _height){
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
//    //dot frag
//    gui.add(sManager.dotFragHSB.shaderControl);
//    gui.add(sManager.dotFragMirrorAxis.shaderControl);
//    gui.add(sManager.dotFragTurbulence.shaderControl);
//    gui.add(sManager.dotFragTwist.shaderControl);
//    gui.add(sManager.dotFragMonochrome.shaderControl);
    guiPanel.finishSetup();
    
//    guiPanel.gui.loadFromFile("settings.xml");
    
    ofAddListener(ofEvents().keyPressed, this, &shaderCompilation::keyPressed);
}

void shaderCompilation::update(){
    guiPanel.update();
    
}

void shaderCompilation::begin(){
    fbo.begin();
    ofClear(0);
}
void shaderCompilation::end(){
    fbo.end();
    
    sManager.draw(guiPanel.activatedShaders);
    if(guiON)guiPanel.draw();
    
}

void shaderCompilation::keyPressed(ofKeyEventArgs &keyArgs){
    if(keyArgs.key == 'g')guiON = !guiON;
}
