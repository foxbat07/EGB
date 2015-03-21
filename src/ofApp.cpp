#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAlphaBlending();
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    int projectorWidth = 1280, projectorHeight = 800;
    
    // setup secondary window for projection, primary for gui
    projector.setup("Projector", 0, 0, projectorWidth, projectorHeight, false);
    
  
    // setup blend shader
    blendfx = new BlendShader();
    blendfx->allocate(projectorWidth, projectorHeight);
    
    
    // load sandbox shader
    sandbox = new ofxFXObject();
    loadSandboxShader("test.frag");
    
    scene = new SceneTest();
    scene1 = new Scene1();
    
    black = new Black();

    throneRoom = new ThroneRoom();
    charlesRoom = new CharlesRoom();
    
//    scenes.push_back(throneRoom);
    
    //
    // Init GUI
    //
    gui1 = new ofxUISuperCanvas("PANEL 1: Switch Videos");
    gui1->setPosition(0, 0);
    gui1->setHeight(600);
    gui1->setName("Switch");
    gui1->addLabel("Toggle Videos");
    gui1->addSpacer();
    gui1->addSlider("blendfx.blend", 0.0f, 1.0f, &blendfx->blend);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    scene->update();
//    scene1->update();
    throneRoom->update();
    charlesRoom->update();
//    blendfx->setTexture(black->getTextureReference(), 0);
//    blendfx->setTexture(throneRoom->getTextureReference(), 1);
//    blendfx->update();
    
    
//    video.update();
    
//    sandbox.begin();
//    ofClear(255, 255);
//    sandbox.draw();
//    ofSetColor(0,255);
//    ofCircle(mouseX, mouseY, 5);
//    sandbox.end();
    
//    glow.setRadius(sin(beat)*15);
//    glow << video.getTextureReference();
//    glow.update();
    
//    sandbox.update();
//    beat += (1.0/ofGetFrameRate())*2;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    video.draw(0,0);
    projector.begin();
    ofClear(0);
//    ofScale(0.1,0.1);
//    blendfx->draw();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(255,255,255,blendfx->blend*255);
//    throneRoom->draw();
    ofSetColor(255,255,255,(1.0-blendfx->blend)*255);
    charlesRoom->draw();
//    glow.draw();
//    sandbox.draw();
    projector.end();
//    ofSetColor(255,255,255);
    
//    sandbox.draw();
    
}

void ofApp::loadSandboxShader(const char* path){
    
    sandbox->allocate(projectorWidth, projectorHeight);
    sandbox->setPasses(1);
   
//    sandbox.load(std::string(path));
    ofBuffer buffer = ofBufferFromFile(path);
    sandbox->setCode(buffer.getText());
//    sandbox.setTexture(video.getTextureReference());
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == ' '){
//        if(!video.isPlaying()) video.play();
//        else video.stop();
    } else if( key == 'r'){
        loadSandboxShader("test.frag");
    }
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
