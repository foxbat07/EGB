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

#include "BrightnessShader.h"
#include "ofxGlow.h"
#include "ofxBloom.h"
#include "ofxBlur.h"

struct BraveCave : Scene {
    
    ofVideoPlayer video;
    
    BrightnessShader bright;
    ofxGlow glow;

    BraveCave(){
        video.loadMovie( "video/bravecave.mov" );
//        video.setAnchorPercent(0.5, 0.5);
        video.setVolume(0);
//        video.play();
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
