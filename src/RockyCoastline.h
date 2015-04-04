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
    
    ofVideoPlayer video;
    
    BrightnessShader bright;
    ofxGlow glow;
    
    RockyCoastline(){
        scale = 0.5;
        x = 1000;
        scalex = -1;
        
        video.loadMovie( "video/rockycoastline.mov" );
        //        video.setAnchorPercent(0.5, 0.5);
        video.setVolume(0);
        //        video.play();
        bright.allocate(width,height);
        //        glow.allocate(width,height);
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
        
        bright.brightness = brightness;
        bright.r = r;
        bright.g = g;
        bright.b = b;
        (bright << video);
        video.update();
        bright.update();
        //      glow.update();
    }
    
    virtual void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotate(rotate);
        ofScale(scale*scalex,scale*scaley);
        ofSetColor(255,255,255,alpha*255);
        //        video.draw(0,0);
        bright.draw();
        //        glow.draw();
        ofPopMatrix();
    }
    
    ofTexture& getTextureReference(){
        return video.getTextureReference();
    }
};

#endif
