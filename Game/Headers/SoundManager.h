#pragma once

#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <filesystem>

//template <class T>
//concept isInt = std::is_integral_v<T>;

template <class T>
concept isFloatingPoint = std::is_floating_point_v<T>;

enum SoundType {
    BACKGROUND_MUSIC1,
    EAT_APPLE
};

class SoundManager final {
private:
    using path = std::filesystem::path;
public:

    SoundManager() = default;
    ~SoundManager() = default;

    void loadSound(const path &pathToFile);
    void playAll();
    void stopAll();

    std::size_t getSoundIndex(const SoundType &soundType);
    void playSound(const SoundType &soundType);
    void stopSound(const SoundType &soundType);

    template <isFloatingPoint T>
    inline void setVolume(T volume) {
        for (auto &sound: sounds)
            sound.setVolume(volume);
    }
    //template <isInt T>
    //inline void playSound(T soundIndex) {
    //    sounds.at(soundIndex).play();
    //}
    //
    //template <isInt T>
    //inline void stopSound(T soundIndex) {
    //    sounds.at(soundIndex).stop();
    //}
private:
    void checkSoundType(const SoundType &soundType);
private:
    std::vector<sf::Sound> sounds{};
};