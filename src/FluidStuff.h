//
//  FluidStuff.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/10/15.
//
//


#ifndef EGBvisuals_FluidStuff_h
#define EGBvisuals_FluidStuff_h

#include "ofxFluid.h"
#include "ofxFlowTools.h"

#include "ofxUI.h"

struct FluidStuff {
    
    ofxFluid fluid;
    flowTools::ftFluidSimulation ftFluid;
    ofVec2f gravity;
    
    float mouseSensitivity =10;
    float mouseRadius = 3;
    
    ofxUICanvas *gui2;

    
    void setup(int w, int h){
        
        fluid.allocate(w, h, 0.30);
        fluid.dissipation = 0.99;
        fluid.velocityDissipation = 0.99;

        gui2 = new ofxUISuperCanvas("PANEL 2: Fluid");
        gui2->setPosition(200, 0);
        gui2->setHeight(600);
        gui2->setName("Fluid");
        gui2->addLabel("Permanent Forces");
        gui2->addSpacer();
        gui2->addSlider("fluid.dissipation", 0.0f, 1.0f, &fluid.dissipation);
        gui2->addSlider("fluid.velocityDissipation", 0.0f, 1.0f, &fluid.velocityDissipation);
        
        gui2->addSlider("gravity X", -2, 2, &gravity.x);
        gui2->addSlider("gravity Y", -2, 2, &gravity.y);
        
        gui2->addLabel("Temporal Forces");
        gui2->addSpacer();
        gui2->addSlider("mouseSensitivity", 0, 100, &mouseSensitivity);
        gui2->addSlider("mouseRadius", 0, 10, &mouseRadius);
        
        gui2->setWidgetColor(OFX_UI_WIDGET_COLOR_FILL, ofColor(64,128,192,200));
        gui2->setWidgetColor(OFX_UI_WIDGET_COLOR_FILL_HIGHLIGHT, ofColor(0,128,128, 200));
    }
};

#endif
