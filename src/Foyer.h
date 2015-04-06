//
//  Foyer.h
//  EGBvisuals
//
//  Created by Mohit Hingorani on 4/5/15.
//
//

#ifndef EGBvisuals_Foyer_h
#define EGBvisuals_Foyer_h

struct Foyer : Scene {
    
    ofImage image;
    
    
    Foyer(){
        image.loadImage("images/foyer.jpg");
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
