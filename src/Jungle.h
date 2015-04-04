
//
//  Scene14dJungleCassowaryShadow.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_Scene14dJungleCassowaryShadow_h
#define EGBvisuals_Scene14dJungleCassowaryShadow_h

#include "Scene.h"

#include "BrightnessShader.h"
#include "ofxGlow.h"
#include "ofxBloom.h"
#include "ofxBlur.h"

struct Jungle : Scene {
    
    ofVideoPlayer video;
    
    BrightnessShader bright;
    ofxGlow glow;
    
    Jungle(){
        video.loadMovie( "video/jungle.mp4" );
        //        video.setAnchorPercent(0.5, 0.5);
        video.setVolume(0);
        video.play();
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