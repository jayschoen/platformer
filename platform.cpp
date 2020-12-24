#include "platform.hpp"

#include "eigen/Dense"

#include <iostream>

Platform::Platform() {

    position.x() = 0;
    position.y() = 0;

    platform.setPosition(sf::Vector2f(position.x(), position.y()));

    platform.setSize(sf::Vector2f(0, 0));

    platform.setFillColor(sf::Color::White);

}

void Platform::setPosition(float x, float y) {

    position.x() = x;
    position.y() = y;

    platform.setPosition(sf::Vector2f(x, y));

}

void Platform::setSize(float w, float h) {

    platform.setSize(sf::Vector2f(w, h));

}

void Platform::setColor(sf::Color color) {

    platform.setFillColor(color);

}

sf::RectangleShape Platform::getRectangle() {
    return platform;
}

sf::FloatRect Platform::getPosition() {
    return platform.getGlobalBounds();
}
