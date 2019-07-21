#include "GuiApp.h"

//#include "../constants.h"
void GuiApp::setup(){
    gui.setup("control section");
    
}

void GuiApp::add(ofParameterGroup shaderControl){
    gui.add(shaderControl);
    
    const string shaderActivatorName = "activator_"+shaderControl.getEscapedName();
    
    ofParameter< bool > shaderActivator;
    activatedShaders.push_back(shaderActivator);
    gui.add(activatedShaders[activatedShaders.size() - 1].set(shaderActivatorName, false));
}

void GuiApp::finishSetup(){
    
    ofBackground(0);
    ofSetVerticalSync(false);
    gui.minimizeAll();
    gui.setPosition({WIDTH / 10, 40});
    
    sync.setup((ofParameterGroup&)gui.getParameter(),OSCRECEIVINGPORTVISUALS,"localhost",OSCRECEIVINGPORTML);
}

void GuiApp::update(){
    
    sync.update();
    
//    radiusCONTROL

}

void GuiApp::draw(){
	gui.draw();
}
