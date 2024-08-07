//
// Created by lrfri on 14.05.2024.
//
#include "gameplay.h"
#include "tileson.hpp"
#include "raymath.h"
#include "mainmenu.h"
#include "pausescreen.h"
#include "journal.h"
#include "ingameoptions.h"
#include "maincharacter.h"
#include "maincharactermodus.h"
#include "ENEMIES/Enemy.h"
#include "ENEMIES/Enemy1.h"
#include "ENEMIES/Enemy2.h"
#include "ENEMIES/Enemy3.h"
#include "GAME OBJECTS/gameobjects.h"
#include "GAME OBJECTS/robot.h"

void gameplay::update() {

    themaincharacter->update();
    therobot->update();

    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->update();
    }
    for (int i = 0; i < gameobjects.size(); i++) {
        gameobjects[i]->update();
    }
    /*
    switch (currentmodus) {
        case soulmodus:
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = robotmodus;
            }
            break;
        case robotmodus:
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = soulmodus;
            }
    switch (room) {
        case 1:
            if (themaincharacter->position.y <= (doorfromroom1to2)) {
                room = 2;
                reloadRoom();
                themaincharacter->position.y = startposroom1to2;
            }
            break;
        case 2:
            if (themaincharacter->position.y <= doorfromroom2to3) {
                room = 3;
                reloadRoom();
                themaincharacter->position.y = startposroom2to3;
            }
            if (themaincharacter->position.x >= doorfromroom2to4) {
                room = 4;
                reloadRoom();
                themaincharacter->position.x = startposroom2to4;
            }
            if (themaincharacter->position.y >= (doorfromroom2to1)) {
                room = 1;
                hasbeeninroom1before = true;
                reloadRoom();
                themaincharacter->position.y = startposroom2to1;
            }
            break;
        case 3:
            if (themaincharacter->position.y >= (doorfromroom3to2)) {
                room = 2;
                reloadRoom();
                themaincharacter->position.y = startposroom3to2;
            }
            break;
        case 4:
            if (themaincharacter->position.y <= doorfromroom4to5) {
                room = 5;
                reloadRoom();
                themaincharacter->position.y = startposroom4to5;
            }
            if (themaincharacter->position.x <= (doorfromroom4to2)) {
                room = 2;
                reloadRoom();
                themaincharacter->position.x = startposroom4to2;
            }
            break;
        case 5:
            if (themaincharacter->position.y <= doorfromroom5to6) {
                room = 6;
                reloadRoom();
                themaincharacter->position.y = startposroom5to6;
            }
            if (themaincharacter->position.y >= doorfromroom5to4) {
                room = 4;
                reloadRoom();
                themaincharacter->position.y = startposroom5to4;
            }
            break;
        case 6:
            if (themaincharacter->position.y >= doorfromroom6to5) {
                room = 5;
                reloadRoom();
                themaincharacter->position.y = startposroom6to5;
>>>>>>> Stashed changes
            }
            break;
    }*/

    switch (currentmodus) {
        case soulmodus:
            break;
        case robotmodus:
            themaincharacter->position.x = therobot->position.x;
            themaincharacter->position.y = therobot->position.y;
            break;
    }


    switch (room) {
        case 1:
            if (therobot->position.y <= (doorfromroom1to2)) {
                room = 2;
                reloadRoom();
                therobot->position.y = startposroom1to2;
                robotswitched1to2 = true;
            } else if (themaincharacter->position.y <= (doorfromroom1to2)) {
                room = 2;
                reloadRoom();
                themaincharacter->position.y = startposroom1to2;
                maincharacterswitched1to2=true;
            }
            break;
        case 2:
            if (therobot->position.y <= doorfromroom2to3) {
                room = 3;
                reloadRoom();
                therobot->position.y = startposroom2to3;
                robotswitched2to3 = true;
            } else if (themaincharacter->position.y <= doorfromroom2to3) {
                room = 3;
                reloadRoom();
                themaincharacter->position.y = startposroom2to3;
                maincharacterswitched2to3=true;
            } else if (therobot->position.x >= doorfromroom2to4) {
                room = 4;
                reloadRoom();
                robotswitched2to4 = true;
                therobot->position.x = startposroom2to4;
            } else if (themaincharacter->position.x >= doorfromroom2to4) {
                room = 4;
                reloadRoom();
                themaincharacter->position.x = startposroom2to4;
                maincharacterswitched2to4=true;
            } else if (therobot->position.y >= (doorfromroom2to1)) {
                room = 1;
                hasbeeninroom1before = true;
                reloadRoom();
                robotswitched2to1 = true;
                therobot->position.y = startposroom2to1;
            } else if (themaincharacter->position.y >= (doorfromroom2to1)) {
                room = 1;
                hasbeeninroom1before = true;
                reloadRoom();
                themaincharacter->position.y = startposroom2to1;
                maincharacterswitched2to1=true;
            }
            break;
        case 3:
            if (therobot->position.y >= doorfromroom3to2) {
                room = 2;
                reloadRoom();
                robotswitched3to2 = true;
                therobot->position.y = startposroom3to2;
            } else if (themaincharacter->position.y >= (doorfromroom3to2)) {
                room = 2;
                reloadRoom();
                themaincharacter->position.y = startposroom3to2;
                maincharacterswitched3to2=true;
            }
            break;
        case 4:
            if (therobot->position.y <= doorfromroom4to5) {
                room = 5;
                reloadRoom();
                robotswitched4to5 = true;
                therobot->position.y = startposroom4to5;
            } else if (themaincharacter->position.y <= doorfromroom4to5) {
                room = 5;
                reloadRoom();
                themaincharacter->position.y = startposroom4to5;
                maincharacterswitched4to5=true;
            } else if (therobot->position.x <= (doorfromroom4to2)) {
                room = 2;
                reloadRoom();
                therobot->position.x = startposroom4to2;
                robotswitched4to2 = true;
            } else if (themaincharacter->position.x <= (doorfromroom4to2)) {
                room = 2;
                reloadRoom();
                themaincharacter->position.x = startposroom4to2;
                maincharacterswitched4to2=true;
            }
            break;
        case 5:
            if (therobot->position.y <= doorfromroom5to6) {
                room = 6;
                reloadRoom();
                robotswitched5to6 = true;
                therobot->position.y = startposroom5to6;
            } else if (themaincharacter->position.y <= doorfromroom5to6) {
                    room = 6;
                    reloadRoom();
                    themaincharacter->position.y = startposroom5to6;
                    maincharacterswitched5to6=true;
            } else if (therobot->position.y >= doorfromroom5to4) {
                room = 4;
                reloadRoom();
                robotswitched5to4 = true;
                therobot->position.y = startposroom5to4;
            } else if (themaincharacter->position.y >= doorfromroom5to4) {
                room = 4;
                reloadRoom();
                themaincharacter->position.y = startposroom5to4;
                maincharacterswitched5to4=true;
            }
            break;
        case 6:
            if (therobot->position.y >= doorfromroom6to5) {
                room = 5;
                reloadRoom();
                robotswitched6to5 = true;
                therobot->position.y = startposroom6to5;
            } else if (themaincharacter->position.y >= doorfromroom6to5) {
                room = 5;
                reloadRoom();
                themaincharacter->position.y = startposroom6to5;
                maincharacterswitched6to5=true;
            }
            break;
    }
}

scene *gameplay::evaluateSceneChange() {
    if (IsKeyPressed(KEY_M)) {
        return new mainmenu();
    } else if (IsKeyPressed(KEY_P)) {
        return new pausescreen();
    } else if (IsKeyPressed(KEY_J)) {
        return new journal();
    } else if (IsKeyPressed(KEY_O)) {
        return new ingameoptions();
    }
    return this;
}

void gameplay::draw() {
    ClearBackground(GRAY);

    //draws the map
    int tilesetCols = 1;
    int tileSize = 32;

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int data = tiles[y * mapWidth + x];
            if (data < 0) continue;
            Rectangle src = {(float) (data % tilesetCols * tileSize), (float) (data / tilesetCols * tileSize),
                             (float) (tileSize), (float) (tileSize)};
            Rectangle dest = {(float) (x * tileSize), (float) (y * tileSize), (float) (tileSize), (float) (tileSize)};
//hier kann man "static_cast<float>" durch (float) ersetzen -> ist C, aber geht hier auch
            DrawTexturePro(tilesetgrass, src, dest, {}, 0, WHITE);
        }

        for (Enemy *enemy: enemies) {
            enemy->draw();
        }

    }

    themaincharacter->draw();
    therobot->draw();
/*
        if(room==1){
            do{
                therobot->draw();
            }while(!maincharacterswitched1to2||!robotswitched1to2);
            if(robotswitched2to1){
                therobot->draw();
            }
        }
        if(room==2) {
            if (robotswitched1to2 || robotswitched3to2 || robotswitched4to2) {
                therobot->draw();
            }
        }
        if(room==3) {
            if (robotswitched2to3) {
                therobot->draw();
            }
        }
        if(room==4) {
            if (robotswitched2to4 || robotswitched5to4) {
                therobot->draw();
            }
        }
        if(room==5) {
            if (robotswitched4to5 || robotswitched6to5) {
                therobot->draw();
            }
        }
        if(room==6) {
            if (robotswitched5to6) {
                therobot->draw();
            }
        }
*/
    //if(room==1 && !hasbeeninroom1before){enemies->draw();} //drawt die Enemies nur in Level 1 und nur, wenn man zum ersten Mal im Raum ist
    //if(room==1){enemy1->draw();} //drawt die Enemies nur in Level 1, aber die laufen da weiter, wo sie zuletzt waren (spawnen nicht immer am Start-Ort)
/*<<<<<<< Updated upstream
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->draw();
    }
=======
    /*for (int i = 0; i < enemies.size(); i++){
        enemies[i]->draw();}*/


    for (int i = 0; i < gameobjects.size(); i++) {
        gameobjects[i]->draw();
    }

    DrawText("Press O to go to options.", 10, 400, 10, WHITE);
    DrawText("Press P to pause the game.", 10, 420, 10, WHITE);
    DrawText("Press M to go back to the main menu.", 10, 440, 10, WHITE);
    DrawText("Press J to open the journal.", 10, 460, 10, WHITE);


    DrawTexture(heart, 10, 20, WHITE);
    DrawTexture(heart, 50, 20, WHITE);
    DrawTexture(heart, 90, 20, WHITE);


    if (IsKeyDown(KEY_H)) {
        this->drawDebug();
    }
}


void gameplay::drawDebug() {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32.0, y * 32.0) == 1) {
                DrawRectangleLines(x * 32, y * 32, 32, 32, RED);
            }
        }
    }
}

//gets the data from the map needed to draw it
gameplay::gameplay() {
    tson::Tileson tileson;
    themaincharacter = new maincharacter(this);
    therobot = new robot(this);
    //gameobjects.push_back(new robot(this));
    /*robot *therobot = new robot(this);
    therobot->position = {11 * 32, 5 * 32};
    gameobjects.push_back(therobot);*/



    //gameobjects.push_back(new robot(this, {11 * 32, 5 * 32}));


    reloadRoom();
}

void gameplay::reloadRoom() {
    tson::Tileson tileson;
    tiles.clear();
    enemies.clear();

    switch (room) {
        case 1: {
            auto map = tileson.parse("assets/graphics/tilesets/room1test_greyboxing1.tmj");
            if (map->getStatus() != tson::ParseStatus::OK) {
                std::cout << map->getStatusMessage();
            }
            auto layer = map->getLayer("Kachelebene 1");

            for (int y = 0; y < layer->getSize().y; y++) {
                for (int x = 0; x < layer->getSize().x; x++) {
                    tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
                    tiles.back()--;
                }
            }
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }

            break;
        case 2: {
            auto map = tileson.parse("assets/graphics/tilesets/room2test_greyboxing1.tmj");
            if (map->getStatus() != tson::ParseStatus::OK) {
                std::cout << map->getStatusMessage();
            }
            auto layer = map->getLayer("Kachelebene 1");

            for (int y = 0; y < layer->getSize().y; y++) {
                for (int x = 0; x < layer->getSize().x; x++) {
                    tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
                    tiles.back()--;
                }
            }
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;


            //custom enemies
            if (std::find(enemyID.begin(), enemyID.end(), 201) == enemyID.end())  {


                Enemy1 *enemy1 = new Enemy1(this);
                enemy1->controltype = Path;
                enemy1->id = 201;
                enemy1->stopleft = 5 * 32; //creates new stop points for Enemy1 instance enemy1
                enemy1->stopdown = 4 * 32;
                enemy1->stopright = 6 * 32;
                enemy1->stopup = 3 * 32;
                enemy1->calculatePathAsRectangle();
                enemies.push_back(enemy1);

                if (enemy1->health == 0) {
                    //std::vector<int> enemyID = {enemy1->id};
                    enemyID.push_back(enemy1->id);
                }
            }
            //if statement (is id 201 dead?) Vector um enemy id zu speichern

            Enemy2 *enemy2 = new Enemy2(this);
            enemy2->controltype = Random;
            enemy2->id = 202;
            enemies.push_back(enemy2);

            if (enemy2->health == 0) {
                std::vector<int> enemyID = {enemy2->id};
            }

            Enemy3 *enemy3 = new Enemy3(this);
            enemy3->controltype = Path;
            float polygons = 180;
            for (int i = 0; i < polygons; i++){
                float angle = (float)i * PI * 2 / polygons;
                enemy3->path.push_back({cos(angle)* 64 + 12 * 32, sin(angle)* 64 + 7 * 32 });
            }
            enemies.push_back(enemy3);






            //creates enemies for room 2
            /*enemies.push_back((new Enemy1(this)));
                    //creates enemies with diffrent stop points


            enemies.push_back((new Enemy2(this)));
            enemies.push_back((new Enemy3(this)));



            gameplay scene; //implements gameplay instance

            Enemy1 enemy1(&scene); //creates Enemy1 instance
            enemy1.controltype = Path; // sets control type

            Enemy2 enemy2(&scene);
            enemy2.controltype = Random;

            Enemy3 enemy3(&scene);
            enemy3.controltype = Path;*/



        }
            break;

        case 3: {
            auto map = tileson.parse("assets/graphics/tilesets/room3test_greyboxing1.tmj");
            if (map->getStatus() != tson::ParseStatus::OK) {
                std::cout << map->getStatusMessage();
            }
            auto layer = map->getLayer("Kachelebene 1");

            for (int y = 0; y < layer->getSize().y; y++) {
                for (int x = 0; x < layer->getSize().x; x++) {
                    tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
                    tiles.back()--;
                }
            }
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
        case 4: {
            auto map = tileson.parse("assets/graphics/tilesets/room4test.tmj");
            if (map->getStatus() != tson::ParseStatus::OK) {
                std::cout << map->getStatusMessage();
            }
            auto layer = map->getLayer("Kachelebene 1");

            for (int y = 0; y < layer->getSize().y; y++) {
                for (int x = 0; x < layer->getSize().x; x++) {
                    tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
                    tiles.back()--;
                }
            }
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
        case 5: {
            auto map = tileson.parse("assets/graphics/tilesets/room5test_greyboxing1.tmj");
            if (map->getStatus() != tson::ParseStatus::OK) {
                std::cout << map->getStatusMessage();
            }
            auto layer = map->getLayer("Kachelebene 1");

            for (int y = 0; y < layer->getSize().y; y++) {
                for (int x = 0; x < layer->getSize().x; x++) {
                    tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
                    tiles.back()--;
                }
            }
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
        case 6: {
            auto map = tileson.parse("assets/graphics/tilesets/room5test.tmj");
            if (map->getStatus() != tson::ParseStatus::OK) {
                std::cout << map->getStatusMessage();
            }
            auto layer = map->getLayer("Kachelebene 1");

            for (int y = 0; y < layer->getSize().y; y++) {
                for (int x = 0; x < layer->getSize().x; x++) {
                    tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
                    tiles.back()--;
                }
            }
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
    }
}

int gameplay::getTileAt(float x, float y) {
    //catch out of bounds
    if (x < 0 || y < 0 || x >= mapWidth * 32 || y >= mapHeight * 32) {
        return 0;
    }
    int tileX = x / 32;
    int tileY = y / 32;
    return tiles[tileY * mapWidth + tileX];
}

bool gameplay::touchesWall(Vector2 pos, float size) {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if ((getTileAt(x * 32, y * 32) == 1)) {
                if (CheckCollisionCircleRec(pos, size,
                                            Rectangle{(float) x * 32, (float) y * 32, (float) 32, (float) 32})) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool gameplay::touchesNextDoor(Vector2 pos, float size) {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) == 3) {
                if (CheckCollisionCircleRec(pos, size,
                                            Rectangle{(float) x * 32, (float) y * 32, (float) 32, (float) 32})) {
                    return true;
                }
            }
        }
    }
    return false;
}

Rectangle gameplay::getTouchedWall(Vector2 position, float radius) {
    //check all walls
    //on contact, note distance to wall
    //return wall with shortest distance
    float shortestDistance = 1000000;
    Rectangle closestWall{};
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) == 1) {
                Rectangle wall{static_cast<float>(x * 32), static_cast<float>(y * 32), 32, 32};
                Vector2 wallTouchPoint = Vector2Clamp(position, Vector2{wall.x, wall.y},
                                                      Vector2{wall.x + wall.width, wall.y + wall.height});
                float distance = Vector2Distance(position, wallTouchPoint);
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    closestWall = wall;
                }
            }
        }
    }
    return closestWall;
}

bool gameplay::touchesBars(Vector2 pos, float size) {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if ((getTileAt(x * 32, y * 32) == 10)) {
                if (CheckCollisionCircleRec(pos, size,
                                            Rectangle{(float) x * 32, (float) y * 32, (float) 32, (float) 32})) {
                    return true;
                }
            }
        }
    }
    return false;
}

Rectangle gameplay::getTouchedBars(Vector2 position, float radius) {
    //check all walls
    //on contact, note distance to wall
    //return wall with shortest distance
    float shortestDistance = 1000000;
    Rectangle closestBar{};
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) == 10) {
                Rectangle bars{static_cast<float>(x * 32), static_cast<float>(y * 32), 32, 32};
                Vector2 wallTouchPoint = Vector2Clamp(position, Vector2{bars.x, bars.y},
                                                      Vector2{bars.x + bars.width, bars.y + bars.height});
                float distance = Vector2Distance(position, wallTouchPoint);
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    closestBar = bars;
                }
            }
        }
    }
    return closestBar;

}

void gameplay::clearEnemies() {
    for (Enemy *enemy: enemies) {
        delete enemy;
    }
    enemies.clear();
}


