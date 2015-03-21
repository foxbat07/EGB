//
//  ThroneRoom.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_ThroneRoom_h
#define EGBvisuals_ThroneRoom_h


#include "Scene.h"

#include "ofxMask.h"

struct ThroneRoom : Scene {
    
    ofImage image;
//    ofImage mask;
//    ofVideoPlayer video;
//    ofxMask maskpass;
    
    ThroneRoom(){
        image.loadImage("images/marble.jpg");
//                video.loadMovie( "/Users/fishuyo/Movies/trees/trees.mov" );
//                video.play();
//                maskpass.allocate(width,height);
    }
    virtual void update(){
        image.update();
        //        video.update();
        //        maskpass.setTexture(mask.getTextureReference(), 0);
        //        maskpass.setTexture(video.getTextureReference(),1);
        //        maskpass.update();
    }
    
    virtual void draw(){
        image.draw(0,0); //0,0,width,height);
        //        maskpass.draw();
        //        video.draw(0,0);
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};


#endif
