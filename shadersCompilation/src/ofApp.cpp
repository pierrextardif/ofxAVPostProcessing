
#include "ofApp.h"

void ofApp::setup(){
    
    ofSetVerticalSync(true);
    cam.setDistance(500);
    
//    ofHideCursor();
    
//    vbo = setupSphere(400, 10);
    
    vbo = setupPlane(40, 6);
    
    
    shaderComp.setup(WIDTH, HEIGHT);
};

void ofApp::update(){
    shaderComp.update();
};

void ofApp::draw(){
    
    float timer = ofGetElapsedTimef() * 0.1;
    
    
    shaderComp.begin();
    ofClear(0);
    
    ofEnableDepthTest();
        cam.begin();
    
            ofBackground(0);
    
            ofRotateX(ofGetElapsedTimef() * 12.0);
            ofRotateZ(ofGetElapsedTimef() * 5.0);
            vbo.draw();
//    myPlayer.draw(0,0);
    
        cam.end();
    ofDisableDepthTest();
    
    shaderComp.end();
    
    
//    sManager.draw(gui.activatedShaders);
//    if(guiON)gui.draw();
};

void ofApp::keyPressed(int key){
//    if(key == 'g'){
//        guiON = !guiON;
//    }
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


ofVboMesh ofApp::setupPlane(int sizePlane, int amount){
    ofVboMesh v;
    v.setMode(OF_PRIMITIVE_TRIANGLES);
    
    for(int i =-amount; i < amount; i++){
        for(int j = -amount; j < amount; j++){
            
            float xPos = i * sizePlane;
            float yPos = j * sizePlane;
            float zPos = 0;
            addOnPlane(&v, {xPos, zPos, yPos}, {(float)i,(float)j}, amount);
            
            xPos = (i+1) * sizePlane;
            yPos = j * sizePlane;
            zPos = 0;
            addOnPlane(&v, {xPos, zPos, yPos}, {(float)(i+1),(float)j}, amount);
            
            xPos = (i+1) * sizePlane;
            yPos = (j+1) * sizePlane;
            zPos = 0;
            addOnPlane(&v, {xPos, zPos, yPos}, {(float)(i+1),(float)(j+1)}, amount);
            
            
            
            xPos = (i) * sizePlane;
            yPos = j * sizePlane;
            zPos = 0;
            addOnPlane(&v, {xPos, zPos, yPos}, {(float)i,(float)j}, amount);
            
            xPos = i * sizePlane;
            yPos = (j+1) * sizePlane;
            zPos = 0;
            addOnPlane(&v, {xPos, zPos, yPos}, {(float)i,(float)(j+1)}, amount);
            
            xPos = (i+1) * sizePlane;
            yPos = (j+1) * sizePlane;
            zPos = 0;
            addOnPlane(&v, {xPos, zPos, yPos}, {(float)(i+1),(float)(j+1)}, amount);
        }
    }
    return v;
}

void ofApp::addOnPlane(ofVboMesh* vbo, ofVec3f pos,ofVec2f texC, int amount){
    
    ofVec2f texCoord = {ofMap(texC.x, 0, amount, 0, WIDTH), ofMap(texC.y, 0, amount, 0, HEIGHT)};
    
    vbo->addVertex(pos);
    vbo->addTexCoord({texCoord.x, texCoord.y});
    ofColor col = ofColor((int)ofRandom(255), (int)ofRandom(255) ,(int)ofRandom(255));
    
    vbo->addNormal({0,0,0});
    vbo->addColor(col);
    
    
}
