//
//  BeachSunset.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_BeachSunset_h
#define EGBvisuals_BeachSunset_h


#include "Scene.h"

#include "BrightnessShader.h"
#include "ofxMask.h"

struct BeachSunset : Scene {
    
    ofImage image;
    ofVideoPlayer video;
    
    BrightnessShader bright;
    ofxMask maskpass;
    
    BeachSunset(){
        scale = 1;
        //        image.loadImage("images/marblerod.jpg");
        video.loadMovie( "video/beachsunset.MOV" );
        //        video.setAnchorPercent(0.5, 0.5);
        video.setVolume(0);
        //        video.play();
        bright.allocate(width,height);
        maskpass.allocate(width,height);
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
        //        image.update();
        bright.update();
        video.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
        //        video.draw(0,0);
        bright.draw();
        ofPopMatrix();
    }
    
    //    ofTexture& getTextureReference(){
    //        return image.getTextureReference();
    //    }
};


#endif
