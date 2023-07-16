#include "SnakeBlock.h"

SnakeBlock::SnakeBlock(const sf::Vector2f &position,const sf::Color &color, float size)
    : ObjectWorld(position, color, size) {
}

SnakeBlock::SnakeBlock(const sf::Vector2f& position, const SnakeBlock& other) 
    : ObjectWorld(position, other) {
}