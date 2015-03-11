//
//  Scene.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/8/15.
//
//

#ifndef EGBvisuals_Scene_h
#define EGBvisuals_Scene_h


#include "ofMain.h"


struct Scene {
    
    // shared class variables for projection size
    static int width;
    static int height;
    
    
    
    Scene(){}
    virtual void update(){}
    virtual void draw(){}
    virtual ofTexture& getTextureReference() = 0;
    ~Scene(){}
    
    float time;
    
};

#endif
