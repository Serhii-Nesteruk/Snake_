#include "SnakeControl.h"

#include <iostream>

SnakeControl::SnakeControl(sf::RenderWindow& window, Snake& snake, Apple& apple,
                           SoundManager &soundManager)
    : window(window), snake(snake), apple(apple), soundManager(soundManager) {
}

void SnakeControl::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
        snake.changeDirection(Direction::UP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
        snake.changeDirection(Direction::DOWN);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        snake.changeDirection(Direction::LEFT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        snake.changeDirection(Direction::RIGHT);
}

void SnakeControl::update(float deltaTime) {
    float distanceMovement = snakeSpeed * deltaTime;
    snake.move(distanceMovement);
    checkApple();
}

void SnakeControl::checkWall() {
    sf::Vector2f snakePosition = snake.getBounds().getPosition();
    if (snakePosition.x <= leftSideCoordinate)
        snake.setPosition(sf::Vector2f(rightSideCoordinate, snakePosition.y));
    if (snakePosition.x >= rightSideCoordinate)
        snake.setPosition(sf::Vector2f(leftSideCoordinate, snakePosition.y));
    if (snakePosition.y <= upSideCoordinate)
        snake.setPosition(sf::Vector2f(snakePosition.x, downSideCoordinate));
    if (snakePosition.y >= downSideCoordinate)
        snake.setPosition(sf::Vector2f(snakePosition.x, upSideCoordinate));
}

void SnakeControl::draw() {
    snake.draw(window);
    apple.draw(window);
}

void SnakeControl::checkApple() {
    if (snake.getBounds().intersects(apple.getBounds())) {
        snake.enlargeSnake();
        apple.setRandomPosition(window.getSize());
    }
}