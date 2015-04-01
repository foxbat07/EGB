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
#include "Scene14aPalace.h"
#include "Scene14dJungleCassowaryShadow.h"
#include "CassowaryNest.h"
#include "BeachSunset.h"
#include "JungleEdge.h"

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
    float scale = 1, rotate = 0;
    
    float brightness = 1, r=1, g=1, b=1;

    
    SceneGraph(){
        Scene *black = new Black();
        Scene *throne = new ThroneRoom();
        Scene *village = new VillageSquare();
        Scene *cave = new BraveCave();
        
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
    };
    
    void addScene(std::string name, Scene *s){
        scenes.insert(s);
        order.push_back(s);
        names.push_back(name);
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
