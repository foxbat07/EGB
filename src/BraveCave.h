//
//  BraveCave.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_BraveCave_h
#define EGBvisuals_BraveCave_h

#include "Scene.h"

#include "ofxMask.h"

struct BraveCave : Scene {
    
    ofVideoPlayer video;

    BraveCave(){
        video.loadMovie( "video/bravecave.MOV" );
        video.play();
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
        video.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
        video.draw(0,0);
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return video.getTextureReference();
    }
};

#endif
