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
    
    ofImage image;
    ofImage mask;
    ofVideoPlayer video;
    ofxMask maskpass;
    
    CharlesRoom(){
        image.loadImage("images/marble.jpg");
//        video.loadMovie( "video/fullmoon.avi" );
        video.loadMovie( "/Users/fishuyo/Movies/trees/trees.mov" );
        video.play();
        //                maskpass.allocate(width,height);
    }
    virtual void update(){
        image.update();
        video.update();
        //        maskpass.setTexture(mask.getTextureReference(), 0);
        //        maskpass.setTexture(video.getTextureReference(),1);
        //        maskpass.update();
    }
    
    virtual void draw(){
//        ofEnableBlendMode(OF_BLENDMODE_ADD);
//        image.draw(0,0); //0,0,width,height);
        //        maskpass.draw();
        
//        ofSetColor(255,255,255,255);
        video.draw(0,0);
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};


#endif
