
//
//  Scene14dJungleCassowaryShadow.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_Scene14dJungleCassowaryShadow_h
#define EGBvisuals_Scene14dJungleCassowaryShadow_h



//moving plant textures blending together Cassowary shadow Scene 14d (86) starts the Jungle.  Ilike the jungle images mixed with shadows of the Cassowary.  Video needs to stop quickly after Lue’s line “That blue tree” (87) when the Casswary attacks Strong off stage.

struct Jungle : Scene {
    
    ofImage image;
    
    
    Jungle(){
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
