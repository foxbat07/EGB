//
//  cassowarydance.h
//  EGBvisuals
//
//  Created by Mohit Hingorani on 4/7/15.
//
//

#ifndef EGBvisuals_cassowarydance_h
#define EGBvisuals_cassowarydance_h

#include "Scene.h"

#include "BrightnessShader.h"
#include "ofxGlow.h"
#include "ofxBloom.h"
#include "ofxBlur.h"

struct Cassowarydance : Scene {
    
    ofVideoPlayer video;
    
    BrightnessShader bright;
    ofxGlow glow;
    
    Cassowarydance(){
        video.loadMovie( "video/chicken.mov" );
        //        video.setAnchorPercent(0.5, 0.5);
        video.setVolume(0);
        video.setSpeed(0.5);
        video.setLoopState(OF_LOOP_PALINDROME);
        
       // video.setPosition(0.5);
        video.play();
        bright.allocate(width,height);
        //        glow.allocate(width,height);
    }
    virtual void activate(){
        video.firstFrame();
        video.play();
        active = true;
    }
    virtual void deactivate(){
        video.stop();
        active = false;
    }
    virtual void update(){
        
//        if( video.getPosition()<0.5)
//            video.setPosition(0.5);
        
        bright.brightness = brightness;
        bright.r = r;
        bright.g = g;
        bright.b = b;
        (bright << video);
        video.update();
        bright.update();
        //      glow.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale*scalex,scale*scaley);
        ofSetColor(255,255,255,alpha*255);
        //        video.draw(0,0);
        bright.draw();
        //        glow.draw();
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return video.getTextureReference();
    }
};


#endif
