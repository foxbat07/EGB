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

#include <vector>
#include <map>

struct SceneGraph {
    
    std::map< const char*, Scene* > scenes;  // contains all scenes keyed to name
    std::vector< Scene* > order;              // scene order
    
    int currentScene = 0;
    
    SceneGraph();
    void load();
    void next();
    void prev();
    
    void update();
    void draw();
};


#endif
