#pragma once

#include <SFML/Graphics.hpp>

template <class T>
class ObjectWorld {
public:
    ObjectWorld(const sf::Vector2f &position,const sf::Color &color, float size);
    ObjectWorld(const ObjectWorld& other);
    ObjectWorld(const sf::Vector2f &position, const ObjectWorld& other);
    ~ObjectWorld() = default;

    void draw(sf::RenderWindow& window);

    sf::FloatRect getBounds();

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f &position);

    sf::Color getColor() const;
    void setColor(sf::Color color);

    float getSize() const;
    void setSize(float size);
    void setRandomPosition(const sf::Vector2u &windowSize);
private:
    void shapeSettings();
protected:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Color color;
    float size;
};

template <class T>
ObjectWorld<T>::ObjectWorld(const sf::Vector2f& position, const sf::Color& color, float size)
    : position(position), color(color), size(size) {
    shapeSettings();
}

template <class T>
ObjectWorld<T>::ObjectWorld(const ObjectWorld& other)
    : position(other.position), color(other.color), size(other.size) {
    shapeSettings();
}

template <class T>
ObjectWorld<T>::ObjectWorld(const sf::Vector2f& position, const ObjectWorld& other) : ObjectWorld(other) {
    this->setPosition(position);
}

template <class T>
void ObjectWorld<T>::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

template <class T>
sf::FloatRect ObjectWorld<T>::getBounds() {
    return this->shape.getGlobalBounds();
}

template <class T>
sf::Vector2f ObjectWorld<T>::getPosition() const {
    return this->position;
}

template <class T>
void ObjectWorld<T>::setPosition(const sf::Vector2f& position) {
    this->position = position;
    shape.setPosition(position);
}

template <class T>
sf::Color ObjectWorld<T>::getColor() const {
    return this->color;
}

template <class T>
void ObjectWorld<T>::setColor(sf::Color color) {
    this->color = color;
}

template <class T>
float ObjectWorld<T>::getSize() const {
    return this->size;
}

template <class T>
void ObjectWorld<T>::setSize(float size) {
    this->size = size;
}

template <class T>
void ObjectWorld<T>::setRandomPosition(const sf::Vector2u& windowSize) {
    sf::Vector2f randPosition;
    randPosition.x = rand() % windowSize.x;
    randPosition.y = rand() % windowSize.y;

    setPosition(randPosition);
}

template <class T>
void ObjectWorld<T>::shapeSettings() {
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(position);
    shape.setFillColor(color);
}