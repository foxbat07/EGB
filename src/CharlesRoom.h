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

#include "ofxMask.h"

struct CharlesRoom : Scene {
    
    ofImage wall, window;
    ofImage mask;
    ofVideoPlayer video;
    ofxMask maskpass;
    
    CharlesRoom(){
        video.loadMovie( "video/moon.mp4" );
        video.setVolume(0);
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
//        window.update();
        video.update();
        //        maskpass.setTexture(mask.getTextureReference(), 0);
        //        maskpass.setTexture(video.getTextureReference(),1);
        //        maskpass.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
//        window.draw(x,y);
//        maskpass.draw();
        
        
        ofSetColor(255,255,255,alpha*255);
        video.draw(0,0);
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return window.getTextureReference();
    }
};


#endif
