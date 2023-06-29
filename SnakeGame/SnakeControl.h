#pragma once

#include <memory>

#include "Direction.h"
#include "Snake.h"
#include "Apple.h"

class SnakeControl {
public:
    SnakeControl(sf::RenderWindow& window, Snake& snake, Apple& apple);
    ~SnakeControl() = default;
    void handleInput();

    void update(float deltaTime);
    void checkWall();
    void draw();
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
};