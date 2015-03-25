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
    
    Scene() : active(false) {}
    virtual void update(){}
    virtual void draw(){}
    virtual void activate(){ active = true; }
    virtual void deactivate(){ active = false; }
    virtual ofTexture& getTextureReference(){ ofTexture t; return t; } // hack
    ~Scene(){}
    
    bool active;
    float alpha;
    float time;
    
    float x=0, y=0;
    float scale=1, rotate=0;
    
};

#endif
