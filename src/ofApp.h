#pragma once

#include "ofMain.h"
#include "ofxFluid.h"
#include "ofxSecondWindow.h"
#include "ofxUI.h"
#include "ofxFlowTools.h"

using namespace flowTools;




class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofxFluid fluid;
    ofxSecondWindow projector;
    ftFluidSimulation	ftFluid;
    ofxUICanvas                 *gui1,*gui2,*gui3;
    int     projectorWidth =1280,projectorHeight= 800;
    ofVec2f gravity;
    ofVideoPlayer video;
    float videoWidth =1920, videoHeight = 1080;
    unsigned char * 	videoPixels;
    ofTexture			videoTexture;

    float mouseSensitivity =10;
    float mouseRadius = 3;
    

		
};
