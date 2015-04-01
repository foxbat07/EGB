#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAlphaBlending();
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    int projectorWidth = 1024, projectorHeight = 768;
    
    // setup secondary window for projection, primary for gui
    projector.setup("Projector", 0, 0, projectorWidth, projectorHeight, false);
    
  
    // setup blend shader
    blendfx = new BlendShader();
    blendfx->allocate(projectorWidth, projectorHeight);
    
    
    // load sandbox shader
    sandbox = new ofxFXObject();
    loadSandboxShader("test.frag");
    
    sceneGraph = new SceneGraph();
    
//    scene = new SceneTest();
//    scene1 = new Scene1();
    
//    black = new Black();

//    throneRoom = new ThroneRoom();
//    charlesRoom = new CharlesRoom();
    
//    scenes.push_back(throneRoom);
    
    //
    // Init GUI
    //
    gui1 = new ofxUISuperCanvas("PANEL 1: Switch Videos");
    gui1->setPosition(0, 0);
    gui1->setHeight(800);
    gui1->setName("Switch");
    gui1->addLabel("Toggle Videos");
    gui1->addSpacer();
    gui1->addSlider("transition", 0.0f, 1.0f, &sceneGraph->transition);
    gui1->addSlider("transition length", 0.1f, 10.0f, &sceneGraph->transitionLength);
    gui1->addSpacer();
    gui1->addRadio("RADIO VERTICAL", sceneGraph->names, OFX_UI_ORIENTATION_VERTICAL);
    
    gui1->addSpacer();
    gui1->addSlider("x", -1000.0f, 1000.0f, &sceneGraph->x);
    gui1->addSlider("y", -1000.0f, 1000.0f, &sceneGraph->y);
    gui1->addSlider("scale", 0.0f, 2.0f, &sceneGraph->scale);
    gui1->addSlider("rotate", -90.0f, 90.0f, &sceneGraph->rotate);
   
    gui1->addSpacer();

    gui1->addSlider("brightness", 0.0f, 3.0f, &sceneGraph->brightness);
    gui1->addSlider("red", 0.0f, 3.0f, &sceneGraph->r);
    gui1->addSlider("green", 0.0f, 3.0f, &sceneGraph->g);
    gui1->addSlider("blue", 0.0f, 3.0f, &sceneGraph->b);
    
    ofAddListener(gui1->newGUIEvent,this,&ofApp::guiEvent);
    
    receiver.setup(8000);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    scene->update();
//    scene1->update();
//    throneRoom->update();
//    charlesRoom->update();
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
    
    while(receiver.hasWaitingMessages()) {
        ofxOscMessage message;
        receiver.getNextMessage(&message);
        
        auto addr = message.getAddress();
        cout << "OSCl: " << addr << endl;
        
        if(addr == "/1/toggle1") {
            sceneGraph->prev();
            ((ofxUIRadio *) gui1->getWidget("RADIO VERTICAL"))->activateToggle(sceneGraph->names[sceneGraph->currentScene]);
        } else if(addr == "/1/toggle2") {
            sceneGraph->next();
            ((ofxUIRadio *) gui1->getWidget("RADIO VERTICAL"))->activateToggle(sceneGraph->names[sceneGraph->currentScene]);
        } else if(addr == "/3/xy1"){
            float x = message.getArgAsFloat(0);
            float y = message.getArgAsFloat(1);
            sceneGraph->x = x * 2000 - 1000;
            sceneGraph->y = y * 2000 - 1000;
        } else if( addr == "/3/xy2"){
            float x = message.getArgAsFloat(0);
            float y = message.getArgAsFloat(1);
            sceneGraph->scale = y * 2;
            
        } else if( addr == "/1/rotary1"){
            float x = message.getArgAsFloat(0);
            sceneGraph->r = x * 3;
        } else if( addr == "/1/rotary2"){
            float x = message.getArgAsFloat(0);
            sceneGraph->g = x * 3;
        } else if( addr == "/1/rotary3"){
            float x = message.getArgAsFloat(0);
            sceneGraph->b = x * 3;
        } else if( addr == "/1/rotary4"){
            float x = message.getArgAsFloat(0);
            sceneGraph->brightness = x * 3;
        }
    }
    
    sceneGraph->update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    projector.begin();
    ofClear(0);
//    blendfx->draw();
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
//    ofSetColor(255,255,255,blendfx->blend*255);
//    throneRoom->draw();
//    ofSetColor(255,255,255,(1.0-blendfx->blend)*255);
//    charlesRoom->draw();
//    glow.draw();
//    sandbox.draw();
    sceneGraph->draw();
    projector.end();
    
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
void ofApp::guiEvent(ofxUIEventArgs &e){
    string name = e.getName();
    int kind = e.getKind();
//    cout << "got event from: " << name << endl;
    
    if(name == "RADIO VERTICAL"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        sceneGraph->setScene(radio->getValue());
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == ' '){
//        if(!video.isPlaying()) video.play();
//        else video.stop();
    } else if( key == 'r'){
        loadSandboxShader("test.frag");
    } else if( key == OF_KEY_LEFT){
        sceneGraph->prev();
        ((ofxUIRadio *) gui1->getWidget("RADIO VERTICAL"))->activateToggle(sceneGraph->names[sceneGraph->currentScene]);
    } else if ( key == OF_KEY_RIGHT){
        sceneGraph->next();
        ((ofxUIRadio *) gui1->getWidget("RADIO VERTICAL"))->activateToggle(sceneGraph->names[sceneGraph->currentScene]);
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
