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

#include "BrightnessShader.h"

struct Scene {
    
    // shared class variables for projection size
    static int width;
    static int height;
    
    Scene() : active(false) { } //bright.allocate(width,height); }
    virtual void update(){}
    virtual void draw(){}
    virtual void activate(){ active = true; }
    virtual void deactivate(){ active = false; }
    virtual ofTexture& getTextureReference(){ ofTexture t; return t; } // hack
    ~Scene(){}
    
    static BrightnessShader bright;
    
    bool active;
    float alpha, brightness=1, r=1, g=1, b=1;
    float time;
    
    float x=0, y=0;
    float scale=1, scalex=1, scaley=1, rotate=0;
    
};

#endif
