//
//  Scene14aPalace.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_Scene14aPalace_h
#define EGBvisuals_Scene14aPalace_h


//14a (64) is a street just outside the palace walls.  Siddington will stand at a podium with a small EGB flag on it.  I like your idea of an EGB flag for an image here.

struct Palace : Scene {
    
    ofImage image;
    
    
    Palace(){
        image.loadImage("images/highClareCastle.jpg");
        scale = 1.2;
    }
    virtual void update(){
        image.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
        image.draw(0,0);
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};

#endif
