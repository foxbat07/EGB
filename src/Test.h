//
//  Test.h
//  EGBvisuals
//
//  Created by Tim Wood on 4/5/15.
//
//

#ifndef EGBvisuals_Test_h
#define EGBvisuals_Test_h

#include "ofMain.h"
#include "GodRay.h"
#include "ofxUI.h"


struct Test : Scene {
    
    ofImage image;
    GodRayShader god;


    Test(){
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
        

        image.loadImage("images/castlelight.png");
        
        scale = 1;
        god.allocate(width,height);
    }
    virtual void update(){
        bright.brightness = brightness;
        bright.r = r;
        bright.g = g;
        bright.b = b;
        
//        god.begin();
//        ofClear(255, 255);
//        god.draw();
//        ofSetColor(0,255);
//        ofCircle(ofGetMouseX(), ofGetMouseY(), 5);
//        god.end();
        
        (god << image);
        god.update();
        image.update();
    }

    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
//                image.draw(0,0);
        god.draw();
        ofPopMatrix();
    }


};

#endif
