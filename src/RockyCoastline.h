//
//  RockyCoastline.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_RockyCoastline_h
#define EGBvisuals_RockyCoastline_h

struct RockyCoastline : Scene {
    
    ofImage image;
    
    
    RockyCoastline(){
        image.loadImage("images/marble.jpg");
        scale = 0.5;
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
