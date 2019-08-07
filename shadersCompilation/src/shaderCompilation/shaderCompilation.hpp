//
//  shaderCompilation.hpp
//  shadersCompilation
//
//  Created by Pierre Tardif on 07/08/2019.
//

#ifndef shaderCompilation_hpp
#define shaderCompilation_hpp

#include <stdio.h>
#include "ofMain.h"

// ==== custom ==== //
#include "gui/GuiApp.h"
#include "shaderManager/shaderManager.hpp"

class shaderCompilation{
    public :
    shaderCompilation(){
        
    }
    
    GuiApp gui;
    bool guiON = true;
    
    
    ShaderManager sManager;
    
    ofFbo fbo;
    
    void setup(int _width, int _height);
    void update();
    void draw();
    
    void begin();
    void end();
};

#endif /* shaderCompilation_hpp */
