#include "Snake.h"

Snake::Snake(const sf::Vector2f &position, sf::Color color, float size)
    : direction(Direction::RIGHT) {
    SnakeBlock headBlock(position, color, size);
    blocks.push_back(headBlock);
}

void Snake::move(float distance) {
    sf::Vector2f currentPosition = blocks.front().getPosition();
    sf::Vector2f newPosition = calculateNewPosition(currentPosition, distance);

    //SnakeBlock newBlock(newPosition, blocks.front().getColor(), blocks.front().getSize());
    SnakeBlock newBlock(newPosition, blocks.front());
    blocks.insert(blocks.begin(), newBlock);

    blocks.pop_back();
}

void Snake::changeDirection(Direction newDirection) {
    //if (isOppositeDirection(newDirection, direction)) {
    //    return;
    //}
    this->direction = newDirection;
}

void Snake::draw(sf::RenderWindow& window) {
    for (auto& block : blocks) {
        block.draw(window);
    }
}

sf::FloatRect Snake::getBounds() {
    return blocks.front().getBounds();
}

void Snake::addBlock() {
   sf::Vector2f currentPosition = blocks.front().getPosition();
   float distance = blocks.front().getSize();
   sf::Vector2f newPosition = calculateNewPosition(currentPosition, distance);

    //SnakeBlock newBlock(newPosition, blocks.front().getColor(), blocks.front().getSize());
    SnakeBlock newBlock(newPosition, blocks.back());
    blocks.emplace_back(newBlock);
}

sf::Vector2f Snake::calculateNewPosition(sf::Vector2f position, float distance) {
    switch (direction) {
    case Direction::UP:
        return sf::Vector2f(position.x, position.y - distance);
    case Direction::DOWN:
        return sf::Vector2f(position.x, position.y + distance);
    case Direction::LEFT:
        return sf::Vector2f(position.x - distance, position.y);
    case Direction::RIGHT:
        return sf::Vector2f(position.x + distance, position.y);
    }
}

bool Snake::isOppositeDirection(Direction newDirection, Direction currentDirection) {
    return (newDirection == Direction::UP && currentDirection == Direction::DOWN) ||
        (newDirection == Direction::DOWN && currentDirection == Direction::UP) ||
        (newDirection == Direction::LEFT && currentDirection == Direction::RIGHT) ||
        (newDirection == Direction::RIGHT && currentDirection == Direction::LEFT);
}
