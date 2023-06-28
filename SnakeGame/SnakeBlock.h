#pragma once

#include "Object.h"

class SnakeBlock : public Object {
public:
    SnakeBlock(const sf::Vector2f &position, sf::Color color, float size);
    SnakeBlock(const sf::Vector2f &position, const SnakeBlock &other);
};

