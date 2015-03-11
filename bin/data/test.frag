#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect tex0;

vec4 dead = vec4(1.0,1.0,1.0,1.0);
vec4 alive = vec4(0.0,0.0,0.0,1.0);

void main(void) {
    vec2  st = gl_TexCoord[0].st;
    int sum = 0;
    vec4 y = texture2DRect(tex0, st);

    if (texture2DRect(tex0, st + vec2(-1.0, -1.0)) == alive) ++sum;
    if (texture2DRect(tex0, st + vec2(0.0, -1.0)) == alive) ++sum;
    if (texture2DRect(tex0, st + vec2(1.0, -1.0)) == alive) ++sum;

    if (texture2DRect(tex0, st + vec2(-1.0, 0.0)) == alive) ++sum;
    if (texture2DRect(tex0, st + vec2(1.0, 0.0)) == alive) ++sum;

    if (texture2DRect(tex0, st + vec2(-1.0, 1.0)) == alive) ++sum;
    if (texture2DRect(tex0, st + vec2(0.0, 1.0)) == alive) ++sum;
    if (texture2DRect(tex0, st + vec2(1.0, 1.0)) == alive) ++sum;

    if (sum < 2) gl_FragColor = dead;
    else if (sum > 3) gl_FragColor = dead;
    else if (sum == 3) gl_FragColor = alive;
    else gl_FragColor = y;
    
    gl_FragColor = y; //vec4(1,0,0,1);
}