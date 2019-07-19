#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    setupGui();
    
    loadTextures();

    tessShader.load("../../src/shaders/terrain_vert.glsl","../../src/shaders/terrain_frag.glsl","../../src/shaders/terrain_tcs.glsl","../../src/shaders/terrain_tes.glsl", "../../src/shaders/terrain_geom.glsl");

    mesh.setMode(OF_PRIMITIVE_PATCHES);
    patchMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

    float width = 1024;
    int tiles = 4;

    for(int y = 0; y < tiles; y++){

        for (int x = 0; x < tiles; x++){

            mesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles), 0, -width/2.0 + y*(width/tiles))); // A
            mesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles)+(width/tiles), 0, -width/2.0 + y*(width/tiles))); // B
            mesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles), 0, -width/2.0 + y*(width/tiles)+(width/tiles))); // C
            mesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles)+(width/tiles), 0, -width/2.0 + y*(width/tiles))); //B
            mesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles), 0, -width/2.0 + y*(width/tiles)+(width/tiles))); //C
            mesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles)+(width/tiles), 0, -width/2.0 + y*(width/tiles)+(width/tiles))); //D

            patchMesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles), 0, -width/2.0 + y*(width/tiles))); // A
            patchMesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles)+(width/tiles), 0, -width/2.0 + y*(width/tiles))); // B
            patchMesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles), 0, -width/2.0 + y*(width/tiles)+(width/tiles))); // C
            patchMesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles)+(width/tiles), 0, -width/2.0 + y*(width/tiles))); //B
            patchMesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles), 0, -width/2.0 + y*(width/tiles)+(width/tiles))); //C
            patchMesh.addVertex(ofVec3f(-width/2.0 + x*(width/tiles)+(width/tiles), 0, -width/2.0 + y*(width/tiles)+(width/tiles))); //D

        }

    }

    cam.enableMouseInput();
    cam.setDistance(1000);

    offset = 0.0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateValsFromGui();
    
    if(speed == 0){
        
        offset = 0;
        
    }else{

        offset += speed;
    
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    glm::vec3 eyePosition = {cam.getPosition().x, cam.getPosition().y, cam.getPosition().z};
    
    ofBackground(bg);
    
    ofEnableDepthTest();


    if(blendMode == "ADD")
        ofEnableBlendMode(OF_BLENDMODE_ADD);
    else if(blendMode == "MULTIPLY")
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    else
        ofDisableBlendMode();

    cam.begin();

    tessShader.begin();

    tessShader.setUniform1i("wireframe", bDrawWireframe);
    tessShader.setUniform1i("dynamic", bDynamicLOD);
    tessShader.setUniform1f("alpha", 0.2);
    tessShader.setUniform1f("offset", offset);
    tessShader.setUniformTexture("heightmap", heightMaps[heightIndex], 1);
    tessShader.setUniformTexture("colourmap", colourMaps[colourIndex], 2);
    tessShader.setUniform1i("innerLevel", innerLevel);
    tessShader.setUniform1i("outerLevel", outerLevel);
    tessShader.setUniform3f("eye_position", eyePosition);
    tessShader.setUniform1f("ve", ve);

    if(bDrawFill) mesh.draw(OF_MESH_FILL);

    tessShader.end();


    if(bDrawPatches){

        ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        patchMesh.draw(OF_MESH_WIREFRAME);

    }

    cam.end();
    ofDisableDepthTest();
    
    
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::exit()
{
//    gui->saveSettings("settings.xml");
//    delete gui;
}

//--------------------------------------------------------------
void ofApp::updateValsFromGui()
{
    bg.r = BG_RED;
    bg.g = BG_GREEN;
    bg.b = BG_BLUE;
    speed = SPEED;
    
    if(BLEND_MODE == 0){
        blendMode = "ADD";
    }else if(BLEND_MODE == 1){
        blendMode = "MULTIPLY";
    }else if(BLEND_MODE == 2){
        blendMode = "yoyoyo";
    }
    bDrawPatches = PATCHES;
    bDrawFill = FILL;
    
    bDrawWireframe = WIREFRAME;
    innerLevel = INNER_TESS;
    outerLevel = OUTER_TESS;
    bDynamicLOD = DYNAMIC_LOD;
    ve = VE;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'g':
//            gui->toggleVisible();
            break;
        case '.':
            heightIndex++;
            heightIndex %= heightMaps.size();
            break;
        case ',':
            heightIndex--;
            heightIndex %= heightMaps.size();
            break;
        case '=':
            colourIndex++;
            colourIndex %= colourMaps.size();
            break;
        case '-':
            colourIndex--;
            colourIndex %= colourMaps.size();
            break;
        default:
            break;
    }

}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::loadTextures(){
    
    heightMaps.push_back(ofTexture());
    heightMaps.back().setTextureWrap(GL_REPEAT, GL_REPEAT);
    ofLoadImage(heightMaps[heightMaps.size()-1],"rough_height.png");
    
    heightMaps.push_back(ofTexture());
    heightMaps.back().setTextureWrap(GL_REPEAT, GL_REPEAT);
    ofLoadImage(heightMaps[heightMaps.size()-1],"repeatable.png");
    
    colourMaps.push_back(ofTexture());
    colourMaps.back().setTextureWrap(GL_REPEAT, GL_REPEAT);
    ofLoadImage(colourMaps[colourMaps.size()-1],"rough_rgb.png");
    
    colourMaps.push_back(ofTexture());
    colourMaps.back().setTextureWrap(GL_REPEAT, GL_REPEAT);
    ofLoadImage(colourMaps[colourMaps.size()-1],"rough_height.png");
    
    colourMaps.push_back(ofTexture());
    colourMaps.back().setTextureWrap(GL_REPEAT, GL_REPEAT);
    ofLoadImage(colourMaps[colourMaps.size()-1],"white.jpg");
    
    
    heightIndex = 0;
    colourIndex = 0;

    
}
//--------------------------------------------------------------
void ofApp::setupGui(){
    
    gui.setName("Background");
    gui.setup();

    gui.add(BG_RED.set("GB_RED", 0, 0, 100));
    gui.add(BG_GREEN.set("GB_GREEN", 0, 0, 100));
    gui.add(BG_BLUE.set("GB_BLUE", 0, 0, 100));
    gui.add(SPEED.set("SPEED", 1, 0, 1));
    
    vector<string> modes;
    modes.push_back("ADD");
    modes.push_back("MULTIPLY");
    modes.push_back("NONE");
    
    
    gui.add(BLEND_MODE.set("BLEND_MODE", 1, 0, 2));
    gui.add(PATCHES.set("PATCHES", false));
    gui.add(FILL.set("FILL", false));
    gui.add(WIREFRAME.set("WIREFRAME", false));
    
    gui.add(DYNAMIC_LOD.set("DYNAMIC_LOD", false));
    gui.add(INNER_TESS.set("INNER_TESS", 0, 32, 4));
    gui.add(OUTER_TESS.set("OUTER_TESS", 0, 32, 4));
    
    gui.add(VE.set("VE", 0, 0, 200));
}
