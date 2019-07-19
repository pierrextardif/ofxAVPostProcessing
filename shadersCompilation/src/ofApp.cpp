
#include "ofApp.h"

void ofApp::setup(){
    
    ofSetVerticalSync(true);
    cam.setDistance(500);
    
    vbo = setupSphere(400, 10);
    
    gui.setup();
    
    ofFbo::Settings settings;
    settings.width = WIDTH;
    settings.height = HEIGHT;
    
    // ==== shaders ==== //
    
    vector < string > shaders = {"halftone", "glitch", "fringe", "invert", "verticalNoise"};
    fbo.allocate(WIDTH, HEIGHT);
    sManager.setup(&fbo, settings);
    gui.add(sManager.halftoneShader.shaderControl);
    gui.add(sManager.glitchShader.shaderControl);
    gui.add(sManager.fringeShader.shaderControl);
    gui.add(sManager.invertShader.shaderControl);
    gui.add(sManager.vertNoiseShader.shaderControl);
    gui.add(sManager.noiseShader.shaderControl);
    gui.add(sManager.edgeOnTopShader.shaderControl);
    gui.finishSetup();
};

void ofApp::update(){
    gui.update();
};

void ofApp::draw(){
    
    float timer = ofGetElapsedTimef() * 0.1;
    
    
    fbo.begin();
    ofClear(0);
    
    ofEnableDepthTest();
        cam.begin();
    
            ofBackground(0);
    
            ofRotateX(ofGetElapsedTimef() * 12.0);
            ofRotateZ(ofGetElapsedTimef() * 5.0);
            vbo.draw();
    
        cam.end();
    ofDisableDepthTest();
    
    fbo.end();
    
    
    ofBackground(ofColor::pink);
    sManager.draw({gui.activatedShaders[0], gui.activatedShaders[1], gui.activatedShaders[2], gui.activatedShaders[3], gui.activatedShaders[4], gui.activatedShaders[5], gui.activatedShaders[6]});
    

    
    if(guiON)gui.draw();
};

void ofApp::keyPressed(int key){
    if(key == 'g'){
        guiON = !guiON;
    }
};

ofVboMesh ofApp::setupSphere(int radius, int amount){
    ofVboMesh v;
    v.setMode(OF_PRIMITIVE_TRIANGLES);
    for( int i = 0; i < amount; i ++){
            float propI = (float)(i) / (float)(amount) * 2 * M_PI;
            
            for(int j =0; j < amount; j ++){
                
                calculateOnePos(&v, (float)amount, (float)radius, propI, (float)i, (float)j);
                propI = (float)(i+1) / (float)(amount) * 2 * M_PI;
                calculateOnePos(&v, (float)amount, (float)radius, propI, (float)(i+1), (float)j);
                calculateOnePos(&v, (float)amount, (float)radius, propI, (float)(i+1), (float)(j+1));
                propI = (float)(i) / (float)(amount) * 2 * M_PI;
                
                
                calculateOnePos(&v, (float)amount, (float)radius, propI, (float)i, (float)j);
                calculateOnePos(&v, (float)amount, (float)radius, propI, (float)i, (float)(j+1));
                propI = (float)(i+1) / (float)(amount) * 2 * M_PI;
                calculateOnePos(&v, (float)amount, (float)radius, propI, (float)(i+1), (float)(j+1));
                propI = (float)(i) / (float)(amount) * 2 * M_PI;
                
        }
    }
    return v;
}

void ofApp::calculateOnePos(ofVboMesh* vbo, float amount, float radius, float propI, float i, float j){
    
    // i, j
    float propJ = (float)(j) / (float)(amount) * 2 * M_PI;
    float x = radius * cos(propJ) * cos(propI);
    float y = radius * sin(propJ) * cos(propI);
    float z = radius * sin(propI); 
    
    
    
    float uTex = ofMap(i, 0, amount, 0, 2944);
    float vTex = ofMap(j, 0, amount, 0, 1562);
    
    
    ofColor col = ofColor((int)ofRandom(255), (int)ofRandom(255) ,(int)ofRandom(255));
    addToVbo(vbo, {x,y,z}, {uTex, vTex}, col);
}

void ofApp::addToVbo(ofVboMesh* vbo, ofVec3f pos, ofVec2f texCoord, ofColor col){
    
    vbo->addVertex(pos);
    vbo->addTexCoord({texCoord.x,texCoord.y});
    vbo->addNormal({0,0,0});
    vbo->addColor(col);

}

