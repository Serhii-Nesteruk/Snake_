#include "SnakeControl.h"

#include <iostream>

SnakeControl::SnakeControl(sf::RenderWindow& window, Snake& snake, Apple& apple) {
    this->window = &window;
    this->snake = &snake;
    this->apple = &apple;
}

SnakeControl::~SnakeControl() {
    delete window;
    delete snake;
    delete apple;
}

void SnakeControl::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
        snake->changeDirection(Direction::UP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
        snake->changeDirection(Direction::DOWN);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        snake->changeDirection(Direction::LEFT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        snake->changeDirection(Direction::RIGHT);
}

void SnakeControl::update(float deltaTime) {
    snake->move(150.f);

    checkApple();
}

void SnakeControl::draw() {
    snake->draw(*window);
    apple->draw(*window);
}

void SnakeControl::checkApple() {
    if (snake->getBounds().intersects(apple->getBounds())) {
        snake->addBlock();
        apple->setPosition(sf::Vector2f(rand() % 1200, rand() % 600));//TODO: magic number //TODO: don`t work
    }
}


