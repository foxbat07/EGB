//
//  GodRay.h
//  EGBvisuals
//
//  Created by Tim Wood on 4/5/15.
//
//

#ifndef EGBvisuals_GodRay_h
#define EGBvisuals_GodRay_h


#define STRINGIFY(A) #A

#include "ofMain.h"
#include "ofxFXObject.h"

class GodRayShader : public ofxFXObject {
public:

    static float exposure, decay, density, weight;
    static float x, y;
    
    GodRayShader(){
        
        passes = 1;
        internalFormat = GL_RGBA;
        
        fragmentShader = STRINGIFY(
                                   uniform sampler2DRect tex0;
                                
                                   uniform float exposure;
                                   uniform float decay;
                                   uniform float density;
                                   uniform float weight;
                                   uniform vec2 lightPositionOnScreen;

                                   const int NUM_SAMPLES = 100 ;
                                   
                                   void main()
                                   {
                                       vec2 deltaTextCoord = vec2( gl_TexCoord[0].st - lightPositionOnScreen.xy );
                                       vec2 textCoo = gl_TexCoord[0].st;
                                       deltaTextCoord *= 1.0 /  float(NUM_SAMPLES) * density;
                                       float illuminationDecay = 1.0;
                                       
                                       
                                       for(int i=0; i < NUM_SAMPLES ; i++)
                                       {
                                           textCoo -= deltaTextCoord;
                                           vec4 sample = texture2DRect(tex0, textCoo );
                                           
                                           sample *= illuminationDecay * weight;
                                           
                                           gl_FragColor += sample;
                                           
                                           illuminationDecay *= decay;
                                       }
                                       gl_FragColor *= exposure;
                                   }
                                   );
    }
    
protected:
    
    void injectUniforms() {
        shader.setUniform1f("exposure", exposure);
        shader.setUniform1f("decay", decay);
        shader.setUniform1f("density", density);
        shader.setUniform1f("weight", weight);
        shader.setUniform2f("lightPositionOnScreen", x, y);
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
