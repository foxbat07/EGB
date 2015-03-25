
//
//  DockAcension.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_DockAcension_h
#define EGBvisuals_DockAcension_h

struct DockAcension : Scene {
    
    ofImage image;
    ofVideoPlayer video;
    
    DockAcension(){
        video.loadMovie( "video/moon.mp4" );
        video.setVolume(0);
    }
    
    virtual void activate(){
        video.firstFrame();
        video.play();
        active = true;
    }
    virtual void deactivate(){
        video.stop();
        active = false;
    }
    virtual void update(){
        video.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale,scale);
        ofSetColor(255,255,255,alpha*255);
        video.draw(0,0);
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return image.getTextureReference();
    }
};

#endif
