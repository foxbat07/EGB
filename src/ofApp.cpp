#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAlphaBlending();
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    projector.setup("Projector", 0, 0, projectorWidth, projectorHeight, false);
    
    fluid.allocate(projectorWidth, projectorHeight, 0.30);
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;

    
    gui1 = new ofxUISuperCanvas("PANEL 1: Switch Videos");
    gui1->setPosition(0, 0);
    gui1->setHeight(600);
    gui1->setName("Switch");
    gui1->addLabel("Toggle Videos");
    gui1->addSpacer();
    


    
    
    
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
    
    
    
    
    video.loadMovie( "kolor-fighter-aircraft-4k.mp4" ); //Load the video file    
    video.play(); //Start the video to play
    videoWidth =  video.getWidth();
    videoHeight = video.getHeight();
    //videoPixels 	= new unsigned char[videoWidth*videoHeight *3];
    //videoTexture.allocate(videoWidth,videoHeight, GL_RGB);

    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
