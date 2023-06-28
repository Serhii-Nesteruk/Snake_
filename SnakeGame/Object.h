#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
    Object(const sf::Vector2f &position, sf::Color color, float size);
    Object(const Object& other);
    Object(const sf::Vector2f &position, const Object& other);
    ~Object() = default;

    void draw(sf::RenderWindow& window);

    sf::FloatRect getBounds();

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f &position);

    sf::Color getColor() const;
    void setColor(sf::Color color);

    float getSize() const;
    void setSize(float size);
private:
    void shapeSettings();
protected:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Color color;
    float size;
};