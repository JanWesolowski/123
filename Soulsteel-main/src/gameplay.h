//
// Created by lrfri on 14.05.2024.
//

#ifndef RAYLIBSTARTER_GAMEPLAY_H
#define RAYLIBSTARTER_GAMEPLAY_H

#include <vector>
#include "raylib.h"
#include "globalstates.h"
#include "languagesettings.h"
#include "controlsettings.h"
#include "soundsettings.h"
#include "difficultysettings.h"
#include "assestmanagergraphics.h"

    class gameplay {
    public:
        void update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes, difficultylevel &difficultylevel);

        void draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes,difficultylevel &difficultylevel);

        //loads the necessary textures
        Texture2D heart = assestmanagergraphics::getTexture("assets/graphics/heart_smaller.png");
        //Texture2D modeRobo = LoadTexture("assets/graphics/robot_anuki_3.png");
        //Texture2D modeSoul = LoadTexture("assets/graphics/soul_destiny_3.png");

        //loads the textures on the map (Kachelsatz)
        Texture2D tilesetgrass = assestmanagergraphics::getTexture("assets/graphics/grasses.png");


        //attributes necessary for using the map
        std::vector<int> tiles;
        int rows;
        int cols;
        gameplay();
    };




#endif //RAYLIBSTARTER_GAMEPLAY_H
