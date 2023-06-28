#include "Object.h"

Object::Object(const sf::Vector2f &position, const sf::Color &color, float size)
    : position(position), color(color), size(size) {
    shapeSettings();
}

Object::Object(const Object& other) 
    : position(other.position), color(other.color), size(other.size) {
    shapeSettings();
}

Object::Object(const sf::Vector2f& position, const Object& other) : Object(other) {
    this->setPosition(position);
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Object::getBounds() {
    return this->shape.getGlobalBounds();
}

sf::Vector2f Object::getPosition() const {
    return this->position;
}

void Object::setPosition(const sf::Vector2f& position) {
    this->position = position;
}

sf::Color Object::getColor() const {
    return this->color;
}

void Object::setColor(sf::Color color) {
    this->color = color;
}

float Object::getSize() const {
    return this->size;
}

void Object::setSize(float size) {
    this->size = size;
}

void Object::shapeSettings() {
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(position);
    shape.setFillColor(color);
}
