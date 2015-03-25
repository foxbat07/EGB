//
//  Black.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_Black_h
#define EGBvisuals_Black_h

#include "Scene.h"

struct Black : Scene {
    
    Black(){}
    virtual void update(){}
    
    virtual void draw(){
        ofSetColor(0,0,0,alpha*255);
        ofRectangle(0,0,width,height);
    }
};


#endif
