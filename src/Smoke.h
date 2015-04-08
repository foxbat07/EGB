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
    ofImage image;
    BrightnessShader bright;
    ofxGlow glow;
    float smokeAlpha = 0;
    float imageAlpha = 1;
    bool smokeGo = false;
    float smokex=0,smokey=0;
    
    Smoke(){
        video.loadMovie( "video/smoke/smoke3.mp4" );
        //        video.setAnchorPercent(0.5, 0.5);
        video.setVolume(0);
        video.setLoopState(OF_LOOP_NONE);
        //        video.play();
        bright.allocate(width,height);
        //        glow.allocate(width,height);
        image.loadImage("images/village3.jpg");
    }
    virtual void activate(){
        //video.firstFrame();
        active = true;
    }
    virtual void deactivate(){
        smokeAlpha = 0;
        video.stop();
        active = false;
    }
    virtual void update(){
        if(smokeGo){
//            smokeAlpha = 1.0;
            video.firstFrame();
            video.play();
            smokeGo = false;
        }
        float pos = video.getPosition();
        if(pos < 0.15){
            smokeAlpha = ((pos) / 0.15);
        }
        if(pos > 0.75){
            smokeAlpha = 1.0 - ((pos - 0.75) / 0.25);
        }
        
        bright.brightness = brightness;
        bright.r = r;
        bright.g = g;
        bright.b = b;
        (bright << video);
        video.update();
        bright.update();
        image.update();
        //      glow.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale*scalex,scale*scaley);
        ofSetColor(255,255,255,smokeAlpha * alpha *255);
        //        video.draw(0,0);
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        
        ofPushMatrix();
        ofTranslate(smokex,smokey);
        bright.draw();
        ofPopMatrix();
        
        
        ofSetColor(255,255,255,imageAlpha * alpha *255);

//        bright << image;
//        bright.update();
        image.draw(0,0);
//        bright.draw();

        //        glow.draw();
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return video.getTextureReference();
    }
};

#endif
