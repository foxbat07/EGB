
//
//  VillageSquare.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_VillageSquare_h
#define EGBvisuals_VillageSquare_h

struct VillageSquare : Scene {
    
    ofImage image;
    
    
    VillageSquare(){
        image.loadImage("images/village3v.jpg");
        scale = 1;
    }
    virtual void update(){
        bright.brightness = brightness;
        bright.r = r;
        bright.g = g;
        bright.b = b;
        
        (bright << image);
        bright.update();
        image.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
//        image.draw(0,0);
        bright.draw();
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};

#endif
