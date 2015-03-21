#pragma once

#include "ofMain.h"

#include "ofxSecondWindow.h"
#include "ofxUI.h"

#include "FluidStuff.h"

#include "ofxFXObject.h"
#include "BlendShader.h"

#include "SceneGraph.h"
//#include "Scene.h"
#include "Scene1.h"
#include "SceneTest.h"

#include <vector>


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
    
    void loadSandboxShader(const char *path);
    
    
    ofxSecondWindow projector;
    int projectorWidth, projectorHeight;

    ofxFXObject *sandbox;
    BlendShader *blendfx;
    
//    std::vector<Scene *> scenes;
    
    Scene *scene;
    Scene *scene1;
    
    Black *black;
    ThroneRoom *throneRoom;
    CharlesRoom *charlesRoom;
    
    ofxUICanvas *gui1,*gui2,*gui3;
    
};
