//
//  shaderCompilation.cpp
//  shadersCompilation
//
//  Created by Pierre Tardif on 07/08/2019.
//

#include "shaderCompilation.hpp"

void shaderCompilation::setup(int _width, int _height){
    gui.setup();
    
    ofFbo::Settings settings;
    settings.width = _width;
    settings.height = _height;
    fbo.allocate(_width, _height);
    
    
    // ==== shaders ==== //
    sManager.setup(&fbo, settings);
    gui.add(sManager.halftoneShader.shaderControl);
    gui.add(sManager.glitchShader.shaderControl);
    gui.add(sManager.fringeShader.shaderControl);
    gui.add(sManager.invertShader.shaderControl);
    gui.add(sManager.vertNoiseShader.shaderControl);
    gui.add(sManager.noiseShader.shaderControl);
    gui.add(sManager.edgeOnTopShader.shaderControl);
    gui.add(sManager.scanLinesShader.shaderControl);
    //dot frag
    gui.add(sManager.dotFragHSB.shaderControl);
    gui.add(sManager.dotFragMirrorAxis.shaderControl);
    gui.add(sManager.dotFragTurbulence.shaderControl);
    gui.add(sManager.dotFragTwist.shaderControl);
    gui.add(sManager.dotFragMonochrome.shaderControl);
    gui.finishSetup();
    
    gui.gui.loadFromFile("settings.xml");
}

void shaderCompilation::update(){
    gui.update();
    
}

void shaderCompilation::begin(){
    fbo.begin();
    ofClear(0);
}
void shaderCompilation::end(){
    fbo.end();
    
    sManager.draw(gui.activatedShaders);
    if(guiON)gui.draw();
    
}
