#pragma once

#include "ObjectWorld.h"

class SnakeBlock : public ObjectWorld<SnakeBlock> {
public:
    SnakeBlock(const sf::Vector2f &position,const sf::Color &color, float size);
    SnakeBlock(const sf::Vector2f &position, const SnakeBlock &other);
};

