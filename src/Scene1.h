//
//  Header.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/9/15.
//
//

#ifndef EGBvisuals_Scene1_h
#define EGBvisuals_Scene1_h

#include "Scene.h"

#include "ofxMask.h"

struct Scene1 : Scene {
    
    ofImage image, mask;
    ofVideoPlayer video;
    
//    ofxMask maskpass;
    
    Scene1(){
        image.loadImage("/Users/fishuyo/Desktop/throneroomc.jpg");
//        video.loadMovie( "/Users/fishuyo/Movies/trees/trees.mov" );
//        video.play();
//        maskpass.allocate(width,height);
    }
    virtual void update(){
        image.update();
//        video.update();
//        maskpass.setTexture(mask.getTextureReference(), 0);
//        maskpass.setTexture(video.getTextureReference(),1);
//        maskpass.update();
    }
    
    virtual void draw(){
        image.draw(0,0,width,height);
//        maskpass.draw();
        //        video.draw(0,0);
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};


#endif
