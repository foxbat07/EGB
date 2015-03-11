//
//  Blend.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/9/15.
//
//

#ifndef EGBvisuals_Blend_h
#define EGBvisuals_Blend_h

#define STRINGIFY(A) #A

#include "ofMain.h"
#include "ofxFXObject.h"

class BlendShader : public ofxFXObject {
public:
    float blend = 0.5;
    
    BlendShader(){
        passes = 1;
        internalFormat = GL_RGBA;
        
        fragmentShader = STRINGIFY(
                                   uniform sampler2DRect tex0;
                                   uniform sampler2DRect tex1;

                                   uniform float blend;
                                   
                                   void main(void){
                                       vec2 st = gl_TexCoord[0].st;
                                       vec4 pix0 = texture2DRect(tex0, st) * blend;
                                       vec4 pix1 = texture2DRect(tex1, st) * (1.0 - blend);
                                       
                                       gl_FragColor = pix0 + pix1;
                                   }
                                   );
    }
    
protected:
    
    void injectUniforms() {
        shader.setUniform1f("blend", blend);
    }
};

#endif
