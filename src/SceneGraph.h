//
//  AllSets.h
//  EGBvisuals
//
//  Created by Tim Wood on 3/17/15.
//
//

#ifndef EGBvisuals_AllSets_h
#define EGBvisuals_AllSets_h

#include "Black.h"
#include "ThroneRoom.h"
#include "CharlesRoom.h"
#include "Courtyard.h"
#include "VillageSquare.h"
#include "RockyCoastline.h"
#include "BraveCave.h"
#include "DockAcension.h"
#include "Palace.h"
#include "Jungle.h"
#include "CassowaryNest.h"
#include "BeachSunset.h"
#include "JungleEdge.h"
#include "JungleHalt.h"

#include <vector>
#include <map>

struct SceneGraph {
    
    std::set< Scene* > scenes;  // unique set of all scenes
    std::vector< Scene* > order;   // scene order for play
    std::vector< std::string > names;   // scene names
    int currentScene = 0;
    int prevScene = 0;
    float currentTime = 0;
    float transition = 0;
    float transitionLength = 1;
    bool isTransitioning = false;
    
    
    float x = 0, y = 0;
    float scale = 1, scalex=1, scaley=1, rotate = 0;
    
    float brightness = 1, r=1, g=1, b=1;

    
    SceneGraph(){
        Scene *black = new Black();
        Scene *throne = new ThroneRoom();
        Scene *village = new VillageSquare();
        Scene *cave = new BraveCave();
        Scene *jungle = new Jungle();
        
        addScene("black", black);
        addScene("throne", throne);
        addScene("charles", new CharlesRoom());
        addScene("courtyard", new Courtyard());
        addScene("village", village);
        addScene("throne2", throne);
        addScene("coastline", new RockyCoastline());
        addScene("throne3", throne);
        addScene("village2", village);
        addScene("brave", cave);
        addScene("dock", new DockAcension());
        addScene("brave2", cave);
        addScene("outer palace", new Palace());
        addScene("brave3", cave);
        addScene("jungle", jungle);
        addScene("jungleHalt", new JungleHalt());
        addScene("nest", new CassowaryNest());
        addScene("jungleEdge", new JungleEdge());
        addScene("throne4", throne);
        addScene("beachsunset", new BeachSunset());
        
    };
    
    void loadSceneConfig(){
        Scene *s = order[currentScene];
        loadSceneConfig( names[currentScene], s);
    }
    void loadSceneConfig(std::string name, Scene *s){
        ofFile file(name + ".txt", ofFile::ReadOnly);
        if( file.isFile()){
//            ofBuffer buf = file.readToBuffer();
//            float scl = std::atof(buf.getNextLine().c_str());
            float scl,sx,sy,xx,yy,rr,gg,bb,rot,bri;
            file >> xx >> yy >> scl >> sx >> sy >> rot >> rr >> gg >> bb >> bri;
            s->scale = scale = scl;
            s->scalex = scalex = sx;
            s->scaley = scaley = sy;
            s->x = x = xx;
            s->y = y = yy;
            s->r = r = rr;
            s->g = g = gg;
            s->b = b = bb;
            s->brightness = brightness = bri;
            s->rotate = rotate = rot;
        }
    };
    
    void saveSceneConfig(){
        Scene *s = order[currentScene];
        saveSceneConfig( names[currentScene], s);
    }
    void saveSceneConfig(std::string name, Scene *s){
        ofFile file(name + ".txt", ofFile::WriteOnly);
        file << s->x << " " << s->y << " ";
        file << s->scale << " " << s->scalex << " " << s->scaley << " ";
        file << s->rotate << " ";
        file << s->r << " " << s->g << " " << s->b << " " << s->brightness;
    };
    
    void addScene(std::string name, Scene *s){
        scenes.insert(s);
        order.push_back(s);
        names.push_back(name);
        loadSceneConfig(name,s);
    };
    
    void setScene(int idx){
        if(isTransitioning) return;
        isTransitioning = true;
        prevScene = currentScene;
        currentScene = idx;
        Scene* nextScene = order[currentScene];
        nextScene->alpha = 0;
        nextScene->activate();
        x = nextScene->x;
        y = nextScene->y;
        scale = nextScene->scale;
        rotate = nextScene->rotate;
        scalex = nextScene->scalex;
        scaley = nextScene->scaley;
        r = nextScene->r;
        g = nextScene->g;
        b = nextScene->b;
        brightness = nextScene->brightness;
        currentTime = 0;
    }
    void next(){
        int scene = (currentScene + 1) % order.size();
        setScene(scene);
    };
    void prev(){
        int scene = (currentScene - 1);
        if( scene < 0) scene = order.size()-1;
        setScene(scene);
    };
    
    void update(){
        if( isTransitioning){
            currentTime += ofGetLastFrameTime();
            transition = currentTime / transitionLength;
        }
        if(transition >= 1){
            transition = 1;
            isTransitioning = false;
            if(order[prevScene] != order[currentScene]) order[prevScene]->deactivate();
        }
//        std::cout << "transition: " << transition << std::endl;
        order[prevScene]->alpha = 1.0 - transition;
        order[currentScene]->alpha = transition;
        
        Scene *s = order[currentScene];
        s->x = x;
        s->y = y;
        s->scale = scale;
        s->scalex = scalex;
        s->scaley = scaley;
        s->rotate = rotate;
        
        s->brightness = brightness;
        s->r = r;
        s->g = g;
        s->b = b;
        
        for( auto s : scenes){
            if( s->active ) s->update();
        }
        
    };
    void draw(){
        for( auto s : scenes){
            if( s->active ) s->draw();
        }
    };
    
};


#endif
