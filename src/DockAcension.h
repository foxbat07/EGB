
//
//  DockAcension.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_DockAcension_h
#define EGBvisuals_DockAcension_h

#include "GodRay.h"

struct DockAcension : Scene {
    
    ofImage image, light;
    ofVideoPlayer video;
    GodRayShader god;
    
    bool ascend = false;
    bool ascending = false;
    
    float startTime = 0;
    float t = 0;
    
    DockAcension(){
        
        auto gui2 = new ofxUISuperCanvas("PANEL 3: God");
        gui2->setPosition(420,0);
        gui2->setHeight(800);
        gui2->setName("Transform");
        gui2->addLabel("pos color");
        gui2->addSpacer();
        gui2->addSlider("x", 0.0f, 2000.0f, &GodRayShader::x);
        gui2->addSlider("y", 0.0f, 2000.0f, &GodRayShader::y);
        gui2->addSlider("exposure", 0.0f, 1, &GodRayShader::exposure);
        gui2->addSlider("decay", -1.0f, 2, &GodRayShader::decay);
        gui2->addSlider("density", 0.0f, 1, &GodRayShader::density);
        gui2->addSlider("weight", 0.0f, 10, &GodRayShader::weight);
        gui2->addToggle("ascend", &ascend);
        
        video.loadMovie( "video/moonloop.mov" );
        image.loadImage("images/castle3.png");
        light.loadImage("images/castlelight.png");
        video.setVolume(0);
        god.allocate(width,height);
    }
    
    virtual void activate(){
        GodRayShader::x = 660.2;
        GodRayShader::y = 256.16;
        GodRayShader::exposure = 0;
//        GodRayShader::exposure = .13;
        GodRayShader::decay = 0.98;
        GodRayShader::density = .19;
        GodRayShader::weight = 0.39;
        video.firstFrame();
        video.play();
        active = true;
    }
    virtual void deactivate(){
        video.stop();
        active = false;
    }
    virtual void update(){
        god << light;
        video.update();
        if(ascend){
            ascend = false;
            ascending = true;
            startTime = ofGetElapsedTimef();
            GodRayShader::exposure = .13;
        }
        if(ascending){
            t = ofGetElapsedTimef() - startTime;
            
            if(t < 0.2){

            } else if(t < 0.5){
                float d = ((t - 0.2) / 0.3)* .81 + .19;
                GodRayShader::density = d;
            } else if(t < 0.7){
                
            } else if(t < 0.75){
                float d = (1-((t - 0.7) / 0.05))*.11 + .19;
                GodRayShader::density = d;
            }
        }
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
        video.draw(0,0);
        image.draw(0,0);

        if(ascending){
            god.draw();
        }
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};

#endif
