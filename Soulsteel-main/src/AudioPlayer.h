/*#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include "raylib.h"
#include <string>
#include <vector>

class SoundManager {
public:

    SoundManager();
    ~SoundManager();

    bool loadSounds(const std::vector<std::string>& filenames);
    void playSound(int index);
    void stopSound(int index);


    bool loadMusics(const std::vector<std::string>& filenames);

    int getNumLoadedSounds() const;

private:
    std::vector<Sound> loadedSounds;
};

#endif // AUDIO_PLAYER_H
*/
#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "raylib.h"
#include <string>
#include <vector>

class SoundManager {
public:
    SoundManager();
    ~SoundManager();

    bool loadSounds(const std::vector<std::string>& filenames);
    void playSound(int index);
    void stopSound(int index);
    int getNumLoadedSounds() const;

    bool loadBackgroundMusic(const std::string& filename);
    void playBackgroundMusic();
    void updateBackgroundMusic();
    void stopBackgroundMusic();

private:
    std::vector<Sound> loadedSounds;
    Music backgroundMusic;
    bool isBackgroundMusicLoaded;
};

#endif // SOUNDMANAGER_H
