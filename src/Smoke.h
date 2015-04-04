//
//  Smoke.h
//  EGBvisuals
//
//  Created by Tim Wood on 4/3/15.
//
//

#ifndef EGBvisuals_Smoke_h
#define EGBvisuals_Smoke_h

#include "Scene.h"

#include "BrightnessShader.h"
#include "ofxGlow.h"
#include "ofxBloom.h"
#include "ofxBlur.h"

struct Smoke : Scene {
    
    ofVideoPlayer video;
    
    BrightnessShader bright;
    ofxGlow glow;
    
    Smoke(){
        video.loadMovie( "video/smoke/smoke3.mp4" );
        //        video.setAnchorPercent(0.5, 0.5);
        video.setVolume(0);
        video.setLoopState(OF_LOOP_NONE);
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
        
        float pos = video.getPosition();
        if(pos > 0.75){
            alpha = 1.0 - ((pos - 0.75) / 0.25);
        }
        
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
