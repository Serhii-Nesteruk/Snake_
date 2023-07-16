#pragma once

#include <memory>

#include "Direction.h"
#include "Snake.h"
#include "Apple.h"
#include "SoundManager.h"

class SnakeControl {
public:
    SnakeControl(sf::RenderWindow& window, Snake& snake, Apple& apple,
                 SoundManager &soundManager);
    ~SnakeControl() = default;
    void handleInput();

    void update(float deltaTime);
    void checkWall();
    void draw();

    inline float getSnakeSpeed() const {
        return this->snakeSpeed;
    }
    inline void setSnakeSpeed(float speed) {
        this->snakeSpeed = speed;
    }
    inline float getLeftSideCoordinate() const {
        return this->leftSideCoordinate;
    }
    inline void setLeftSideCoordinate(float coordinate) {
        this->leftSideCoordinate = coordinate;
    }
    inline float getRightSideCoordinate() const {
        return this->rightSideCoordinate;
    }
    inline void setRightSideCoordinate(float coordinate) {
        this->rightSideCoordinate = coordinate;
    }
    inline float getUpSideCoordinate() const {
        return this->upSideCoordinate;
    }
    inline void setUpSizeCoordiante(float coordinate) {
        this->rightSideCoordinate = coordinate;
    }
    inline float getDownSideCoordinate() const {
        return this->downSideCoordinate;
    }
    inline void setDownSideCoordinate(float coordinate) {
        this->downSideCoordinate = coordinate;
    }
private:
    void checkApple();
private:
    sf::RenderWindow& window;
    Snake& snake;
    Apple& apple;

    float snakeSpeed = 75.f;
    float leftSideCoordinate = 0.f;
    float rightSideCoordinate = 600.f;
    float upSideCoordinate = 0.f;
    float downSideCoordinate = 600.f;

    SoundManager& soundManager;
};