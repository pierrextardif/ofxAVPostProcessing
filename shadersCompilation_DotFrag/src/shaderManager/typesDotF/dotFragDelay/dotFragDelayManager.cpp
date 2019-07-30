//
//  dotFragDelayManager.cpp
//  shadersCompilation_DotFrag
//
//  Created by Pierre Tardif on 20/07/2019.
//

#include "dotFragDelayManager.hpp"




void dotFragDelayManager::setup(){
    
    string fullPath = "../../src/shaderManager/typesDotF/" + name + "/shader";
    filesystem::path path = filesystem::path(fullPath);
    shader.load(path/"shader.vert", path/"shader.frag");
    
    if(!shader.isLoaded())cout << "issue loading the " + name + " shader" << endl;
    
    shaderControl.setName("dotFragHSB");
    
    indexBuffer = 0;
    amountDelays = 5;
    fbos.resize(amountDelays);
    
    initGui();
    
    
 }

void dotFragDelayManager::initGui(){
    
    shaderControl.setName(name);
    shaderControl.add(delays.set("delays", 0, 0, amountDelays-1));
    shaderControl.add(feedback.set("feedback", 0, 0,1));
    shaderControl.add(blendmode.set("blendmode", 0, 0,4));

    
}

void dotFragDelayManager::begin(ofTexture tex){
    
    indexBuffer++;
    if(indexBuffer >= fbos.size())indexBuffer = 0;

    int bufferDelayIndex = delays - indexBuffer;
    if(bufferDelayIndex < 0)bufferDelayIndex += fbos.size();
    
    
    
    fbos[indexBuffer].begin();
    ofClear(0,0,0,0);
    shader.begin();
    shader.setUniform1f("u_feedback", feedback);
    shader.setUniform1f("u_blendmode", blendmode);
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniformTexture("tex0", tex, 0);
    
    shader.setUniformTexture("tex1", fbos[bufferDelayIndex].getTexture(), fbos[bufferDelayIndex].getTexture().getTextureData().textureID);
    
}

void dotFragDelayManager::end(){
    shader.end();
    fbos[indexBuffer].end();
    
    int now = indexBuffer-1;
    if(now<0) now+=fbos.size();
    fbos[now].draw(0,0);
}
