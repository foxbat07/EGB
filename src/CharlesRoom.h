//
//  CharlesRoom.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_CharlesRoom_h
#define EGBvisuals_CharlesRoom_h

#include "Scene.h"

#include "BrightnessShader.h"

#include "ofxGlow.h"
#include "ofxBokeh.h"
#include "ofxBloom.h"

struct CharlesRoom : Scene {
    
    ofImage image, wall;
    ofVideoPlayer video;
    ofxGlow glow;
//    ofxBloom glow;
    
    CharlesRoom(){
        scale=0.5;
        image.loadImage("images/charlesroom.png");
        wall.loadImage("images/charlesroomwall.png");
        glow.allocate(width,height);
    }
    
    virtual void update(){
        bright.brightness = brightness;
        bright.r = r;
        bright.g = g;
        bright.b = b;
        
        glow.setRadius(sin( ofGetElapsedTimef() )*70);
        glow << (bright << image);
        bright.update();
        image.update();
        glow.update();
        wall.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
//        image.draw(0,0);
//        bright.draw();
        
        glow.draw();

//        wall.draw(0,0);
        ofPopMatrix();
    }
    
};


#endif
