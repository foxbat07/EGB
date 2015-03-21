//
//  Scene1.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/8/15.
//
//

#ifndef EGBvisuals_SceneTest_h
#define EGBvisuals_SceneTest_h

#include "Scene.h"

#include "ofxMask.h"

struct SceneTest : Scene {
    
    ofImage image, mask;
    ofVideoPlayer video;
    
    ofxMask maskpass;
    
    SceneTest(){
        mask.loadImage("/Users/fishuyo/Desktop/dawg.jpg");
        video.loadMovie( "/Users/fishuyo/Movies/trees/trees.mov" );
        video.play();
        maskpass.allocate(width,height);
    }
    void update(){
        video.update();
        maskpass.setTexture(mask.getTextureReference(), 0);
        maskpass.setTexture(video.getTextureReference(),1);
        maskpass.update();
    }
    
    void draw(){
        maskpass.draw(0,0,width,height);
//        video.draw(0,0);
    }
    
    ofTexture& getTextureReference(){
        return maskpass.getTextureReference();
    }
    
};


#endif
