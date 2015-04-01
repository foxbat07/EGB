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
};

#endif
