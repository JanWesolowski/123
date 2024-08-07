﻿#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "raylib.h"

#include "config.h"
#include "stdlib.h"
#include "mainmenu.h"
#include "globalstates.h"
#include "languagesettings.h"
#include "optionen.h"
#include "gameplay.h"
#include "pausescreen.h"
#include "journal.h"
#include "controlsettings.h"
#include "soundsettings.h"
#include "maincharacter.h"
#include "maincharactermodus.h"
#include "difficultysettings.h"
#include "ingameoptions.h"
#include "assestmanagergraphics.h"
#include "AudioPlayer.h"



int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, "Soul Steel");
    SetTargetFPS(60);
    InitAudioDevice();

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here

    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);
    float renderScale{}; //those two are relevant to drawing and code-cleanliness
    Rectangle renderRec{};

    //set enums to the state they have when starting the game

    languagestates language =german;

    globalstates state = menu;

    soundstates sound =stumm;

    controlmodes control =tastaturmode;

    maincharactermodus modus =soul;

    difficultylevel difficultylevel =guided;



    //create objects of the classes
    mainmenu mainmenu;
    optionen optionen;
    gameplay gameplay;
    pausescreen pausescreen;
    journal journal;
    maincharacter maincharacter;
    class ingameoptions ingameoptions1;
    SoundManager soundManager;

    std::vector<std::string> filenames = {
            "assets/audio/sfx/filenames.wav"
    };
    if (!soundManager.loadSounds(filenames))
    {
        printf("nie zaladowano plikow");
        return 1;
    }

    if (!soundManager.loadBackgroundMusic("assets/audio/sfx/filename.mp3")) {
        printf("Nie udało się załadować muzyki tła.\n");
        CloseWindow();
        return 1;
    }

    soundManager.playBackgroundMusic();





    //SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
    //ToggleFullscreen();
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_F)) { //Fullscreen logic.
            if (IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(Game::ScreenWidth, Game::ScreenHeight);
            } else {
                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
                ToggleFullscreen();
            }
        }
        //checks which screen is shown and calls the methods needed there
        switch (state) {
            case menu:
                mainmenu.update(state, language, sound, control);
                break;
            case hauptoptionen:
                optionen.update(state, language, sound,control, difficultylevel);
                break;
            case ingameoptions:
                ingameoptions1.update(state, language, sound,control, difficultylevel);
                break;
            case gameplayscreen:
                gameplay.update(state, language,sound,control, difficultylevel);
                maincharacter.update(language, modus, difficultylevel);
                break;
            case pausieren:
                pausescreen.update(state, language, sound,control);
                break;
            case hauptjournal:
                journal.update(state, language, sound,control, difficultylevel);
                break;
            default:
                break;
        }

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instead
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(BLACK);

            //checks which screen is shown and calls the methods needed there
            switch (state) {
                case menu:
                    mainmenu.draw(language,sound,control);
                    break;
                case hauptoptionen:
                    optionen.draw(language,sound,control, difficultylevel);
                    break;
                case ingameoptions:
                    ingameoptions1.draw(language, sound,control, difficultylevel);
                    break;
                case gameplayscreen:
                    gameplay.draw(language,sound,control, difficultylevel);
                    maincharacter.draw(language, modus, difficultylevel);
                    break;
                case pausieren:
                    pausescreen.draw(language,sound,control);
                    break;
                case hauptjournal:
                    journal.draw(language,sound,control, difficultylevel);
                    break;
                default:
                    break;
            }
        }
        EndTextureMode();
        //The following lines put the canvas in the middle of the window and have the negative as black
        ClearBackground(BLACK);
        renderScale = std::min(GetScreenHeight() /
                               (float) canvas.texture.height, //Calculates how big or small the canvas has to be rendered.
                               GetScreenWidth() / (float) canvas.texture.width);
        renderRec.width = canvas.texture.width * renderScale;
        renderRec.height = canvas.texture.height * renderScale;
        renderRec.x = (GetScreenWidth() - renderRec.width) / 2.0f;
        renderRec.y = (GetScreenHeight() - renderRec.height) / 2.0f;
        DrawTexturePro(canvas.texture, Rectangle{0, 0, (float) canvas.texture.width, (float) -canvas.texture.height},
                       renderRec,
                       {}, 0, WHITE);
        EndDrawing();

        //Audio section
        soundManager.updateBackgroundMusic();
        if (IsKeyDown(KEY_SPACE)) {
            soundManager.playSound(0);

        }

    } // Main game loop end

    // De-initialization here

    // Close window and OpenGL context
    CloseWindow();

    CloseAudioDevice();

    return EXIT_SUCCESS;
}


