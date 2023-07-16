#pragma once



#include "ObjectWorld.h"

class Apple : public ObjectWorld<Apple> {
public:
    Apple(const sf::Vector2f &position,const sf::Color &color, float size);
};