
//
//  DockAcension.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_DockAcension2_h
#define EGBvisuals_DockAcension2_h

#include "GodRay.h"

struct DockAcension2 : Scene {
    
    ofImage image, light;
    ofVideoPlayer video;
    GodRayShader god;
    
    DockAcension *dock;
    
    DockAcension2( DockAcension *dock_){
        dock = dock_ ;
//        video.loadMovie( "video/moonloop.mov" );
//        image.loadImage("images/castle3.png");
        light.loadImage("images/castlelight.png");
        video.setVolume(0);
        god.allocate(width,height);
    }
    
    virtual void activate(){
        GodRayShader::x = 660.2;
        GodRayShader::y = 256.16;
        GodRayShader::exposure = .13;
        GodRayShader::decay = 0.98;
        GodRayShader::density = .19;
        GodRayShader::weight = 0.39;
//        video.firstFrame();
//        video.play();
        active = true;
    }
    virtual void deactivate(){
//        video.stop();
        active = false;
    }
    virtual void update(){
        dock->alpha = alpha;
        dock->update();
        god << light;
//        video.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
//        video.draw(0,0);
//        image.draw(0,0);
        dock->draw();
        god.draw();
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};

#endif
