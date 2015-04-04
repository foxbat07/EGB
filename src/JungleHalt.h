//
//  JungleHalt.h
//  EGBvisuals
//
//  Created by Tim Wood on 4/3/15.
//
//

#ifndef EGBvisuals_JungleHalt_h
#define EGBvisuals_JungleHalt_h

struct JungleHalt : Scene {
    
    ofImage image;
    
    
    JungleHAlt(){
        image.loadImage("images/jungle2.jpg");
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
