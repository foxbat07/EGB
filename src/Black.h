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

#include "ofxMask.h"

struct Black : Scene {
    
    ofImage image;
    ofTexture texture;
    //    ofImage mask;
    //    ofVideoPlayer video;
    //    ofxMask maskpass;
    
    Black(){
//        texture.allocate(10,10,GL_LUMINANCE);
        image.loadImage("images/black.jpg");
//        image.getTextureReference().setTextureWrap(GL_REPEAT, GL_REPEAT);
//        image.loadImage("images/marble.jpg");
        //                video.loadMovie( "/Users/fishuyo/Movies/trees/trees.mov" );
        //                video.play();
        //                maskpass.allocate(width,height);
    }
    virtual void update(){
//        image.update();
        //        video.update();
        //        maskpass.setTexture(mask.getTextureReference(), 0);
        //        maskpass.setTexture(video.getTextureReference(),1);
        //        maskpass.update();
    }
    
    virtual void draw(){
//        image.draw(0,0,width,height);
        //        maskpass.draw();
        //        video.draw(0,0);
    }
    
    ofTexture& getTextureReference(){
//        return texture;
        return image.getTextureReference();
    }
};


#endif
