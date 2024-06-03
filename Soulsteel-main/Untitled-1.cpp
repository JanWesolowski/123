/*
// AudioPlayer.h
#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include "raylib.h"
#include <string>

class AudioPlayer {
public:
    AudioPlayer();
    ~AudioPlayer();

    bool loadFromFile(const std::string& filename);
    void play();
    void pause();
    void stop();
    bool isPlaying();

private:
    Sound sound;
    bool isSoundLoaded;
};

#endif // AUDIO_PLAYER_H
//*********************************
// AudioPlayer.cpp
#include "AudioPlayer.h"
#include <iostream>

AudioPlayer::AudioPlayer() : isSoundLoaded(false) {
    InitAudioDevice(); // Inicjalizacja urządzenia audio
}

AudioPlayer::~AudioPlayer() {
    if (isSoundLoaded) {
        UnloadSound(sound); // Zwolnienie zasobów dźwiękowych
    }
    CloseAudioDevice(); // Zamknięcie urządzenia audio
}

bool AudioPlayer::loadFromFile(const std::string& filename) {
    sound = LoadSound(filename.c_str());
    if (sound.frameCount > 0) {
        isSoundLoaded = true;
        return true;
    } else {
        std::cerr << "Failed to load audio file: " << filename << std::endl;
        return false;
    }
}

void AudioPlayer::play() {
    if (isSoundLoaded) {
        PlaySound(sound);
    }
}

void AudioPlayer::pause() {
    if (isSoundLoaded) {
        PauseSound(sound);
    }
}

void AudioPlayer::stop() {
    if (isSoundLoaded) {
        StopSound(sound);
    }
}

bool AudioPlayer::isPlaying() {
    return isSoundLoaded && IsSoundPlaying(sound);
}
//********************************
// main.cpp
#include <iostream>
#include "AudioPlayer.h"

int main() {
    // Tworzenie instancji klasy AudioPlayer
    AudioPlayer player;

    // Ładowanie pliku dźwiękowego
    if (!player.loadFromFile("path/to/your/soundfile.wav")) {
        std::cerr << "Error loading sound file." << std::endl;
        return -1;
    }

    // Odtwarzanie dźwięku
    player.play();

    // Poczekaj, aż dźwięk się zakończy
    while (player.isPlaying()) {
        // Możemy dodać opóźnienie, aby nie zajmować zbyt wiele CPU
        Sleep(100);
    }

    return 0;
}
*\