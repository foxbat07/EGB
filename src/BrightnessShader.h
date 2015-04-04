//
//  BrightnessShader.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/30/15.
//
//

#ifndef EGBvisuals_BrightnessShader_h
#define EGBvisuals_BrightnessShader_h

#define STRINGIFY(A) #A

#include "ofMain.h"
#include "ofxFXObject.h"

class BrightnessShader : public ofxFXObject {
public:
    float brightness = 1.0;
    float r=1, g=1, b=1;
    
    float tx=0, ty=0;
    float scalex=1, scaley=1;
    
    BrightnessShader(){
        passes = 1;
        internalFormat = GL_RGBA;
        
        fragmentShader = STRINGIFY(
                                   uniform sampler2DRect tex0;
                                   
                                   uniform float brightness;
                                   uniform float r;
                                   uniform float g;
                                   uniform float b;
                                   
                                   void main(void){
                                       vec2 st = gl_TexCoord[0].st;
                                       vec4 pix0 = texture2DRect(tex0, st);
                                       pix0.r *= r;
                                       pix0.g *= g;
                                       pix0.b *= b;
                                       gl_FragColor = pix0 * brightness;
                                   }
                                   );
    }
    
protected:
    
    void injectUniforms() {
        shader.setUniform1f("brightness", brightness);
        shader.setUniform1f("r", r);
        shader.setUniform1f("g", g);
        shader.setUniform1f("b", b);
    }
    
//    // A simplified way of filling the textures
//    void setTexture(ofBaseDraws& tex, int _texNum){
//        if ( tex.getWidth() > width || tex.getHeight() > height ) {
//            allocate(tex.getWidth(), tex.getHeight());
//        }
//        
//        if ((_texNum < nTextures) && ( _texNum >= 0)){
//            textures[_texNum].begin();
//            ofPushStyle();
//            {
//                ofClear(0,0);
//                ofSetColor(255);
//                ofDisableAlphaBlending(); // Defer alpha blending until .draw() to keep transparencies clean.
//                tex.draw(width/2,height/2);
//            }
//            ofPopStyle();
//            textures[_texNum].end();
//        }
//    }
    
//    void renderFrame(float _width, float _height){
//        if (_width == -1) _width = width;
//        if (_height == -1) _height = height;
//        
//        // If the shader is not well compiled it will show an image little more gray.
//        //
//        if (bFine)
//            ofSetColor(255,255);
//        else
//            ofSetColor(150,255);
//        
//        ofPushMatrix();
//        ofTranslate(tx,ty);
////        ofRotate(rotate);
//        ofScale(scalex,scaley);
////        ofSetColor(255,255,255,alpha*255);
//
//        
//        glBegin(GL_QUADS);
//        glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
//        glTexCoord2f(_width, 0); glVertex3f(_width, 0, 0);
//        glTexCoord2f(_width, _height); glVertex3f(_width, _height, 0);
//        glTexCoord2f(0,_height);  glVertex3f(0,_height, 0);
//        glEnd();
//        
//        ofPopMatrix();
//        
//    }

};

#endif
