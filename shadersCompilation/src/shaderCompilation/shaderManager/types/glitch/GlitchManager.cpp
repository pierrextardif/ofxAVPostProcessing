//
//  GlitchManager.cpp
//  ShaderCompilation
//
//  Created by Pierre Tardif on 19/03/2019.
//

#include "GlitchManager.hpp"

void GlitchManager::setup(){
    
//    string fullPath = pathToShader + name + "/shader";
//    filesystem::path path = filesystem::path(fullPath);
//    shader.load(path/"shader.vert", path/"shader.frag");
//
//    if(!shader.isLoaded())cout << "issue loading the halftone shader" << endl;
//
    initGui();
    
    initTextures();
    
}

void GlitchManager::initGui(){
    
    shaderControl.setName("glitch");
    
    shaderControl.add(amount.set("amount", 0, 0,0.1));
    shaderControl.add(angle.set("angle", 1, 0,100));
    shaderControl.add(seed.set("seed", 1, 0,5));
    shaderControl.add(seed_x.set("seed_x", 100, 0,100));
    shaderControl.add(seed_y.set("seed_y", 100, 0,100));
    shaderControl.add(distortion_x.set("distortion_x", 1, 0,1));
    shaderControl.add(distortion_y.set("distortion_y", 1, 0,1));
//    shaderControl.add(col_s.set("col_s", 1, 0,512));
}

void GlitchManager::addUniforms(ofShader* shader, bool active){
    
    shader->setUniform1f(name+"Active", active?1:0);
    
    if(active){
        shader->setUniformTexture("tDiffuse", image1.getTexture(),0);
        shader->setUniform1f("amount", amount);
        shader->setUniform1f("angle", angle);
        shader->setUniform1f("seed", seed);
        shader->setUniform1f("seed_x", seed_x);
        shader->setUniform1f("seed_y", seed_y);
        shader->setUniform1f("distortion_x", distortion_x);
        shader->setUniform1f("distortion_y", distortion_y);
    }
}


ofImage GlitchManager::generateHeightTexture(int size){
    unsigned char* pixels;
    ofImage image;
    
    int dataSize = size * size;
    pixels = new unsigned char[dataSize];
    
    for( int i = 0; i < size * size; i++){
        float xPos = ofRandom(1);
        pixels[i] = xPos;
        
    }
    
    image.setFromPixels(pixels, size, size, OF_IMAGE_GRAYSCALE);
    return image;
}


void GlitchManager::initTextures(){
    
    string fullPath = pathToShader + name + "/texture";
    filesystem::path path = filesystem::path(fullPath);
    image1.load(path/"yellowWater.jpg");
    // 1024 is the size of the image1
//    image2 = generateHeightTexture(1024);
}
