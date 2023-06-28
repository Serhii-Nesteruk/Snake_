#pragma once

#include "SnakeBlock.h"
#include "Direction.h"
#include <vector>

class Snake {
public:
    Snake(const sf::Vector2f &position, sf::Color color, float size);
    Snake() = default;

    void move(float distance);
    void changeDirection(Direction newDirection);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds();
    void addBlock();
private:
    sf::Vector2f calculateNewPosition(sf::Vector2f position, float distance);
    bool isOppositeDirection(Direction newDirection, Direction currentDirection);

private:
    std::vector<SnakeBlock> blocks;
    Direction direction;
};