#pragma once

#include <memory>

#include "Direction.h"
#include "Snake.h"
#include "Apple.h"

class SnakeControl {
public:
    SnakeControl(sf::RenderWindow& window, Snake& snake, Apple& apple);
    ~SnakeControl();
    void handleInput();

    void update(float deltaTime);

    void draw();
private:
    void checkApple();
private:
    sf::RenderWindow* window = nullptr;//TODO: make the unique_ptr
    Snake* snake = nullptr;//TODO: make the unique_ptr
    Apple* apple = nullptr;//TODO: make the unique_ptr
    //std::unique_ptr<sf::RenderWindow> window;
    //std::unique_ptr<Snake> snake;
    //std::unique_ptr<Apple> apple;
};