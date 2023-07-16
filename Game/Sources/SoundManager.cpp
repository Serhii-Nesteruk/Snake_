#include "SoundManager.h"

void SoundManager::loadSound(const path &pathToFile) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(pathToFile.string()))
        throw std::runtime_error("Failed loading from file " + pathToFile.string());

    sf::Sound sound;
    sound.setBuffer(buffer);
    sounds.emplace_back(sound);
}

void SoundManager::playAll() {
    if (sounds.empty())
        throw std::runtime_error("Empty sound list");

    for (auto &sound: sounds)
        sound.play();
}

void SoundManager::stopAll() {
    if (sounds.empty())
        throw std::runtime_error("Empty sound list");

    for (auto &sound: sounds)
        sound.stop();
}

std::size_t SoundManager::getSoundIndex(const SoundType &soundType) {
    if (soundType == SoundType::BACKGROUND_MUSIC1)
        return 0;
    if (soundType == SoundType::EAT_APPLE)
        return 1;
}

void SoundManager::playSound(const SoundType &soundType) {
    std::size_t soundIndex = getSoundIndex(soundType);
    if (soundIndex < sounds.size())
        sounds.at(soundIndex).play();
}

void SoundManager::stopSound(const SoundType &soundType) {//TODO: magic number
    std::size_t soundIndex = getSoundIndex(soundType);
    if (sounds.size() >= soundIndex - 1)
        sounds.at(soundIndex).stop();
}