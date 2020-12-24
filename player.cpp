#include "player.hpp"

#include "eigen/Dense"
#include "tweeny/tweeny.h"

#include <iostream>

Player::Player() {

    maxPosition.x = sf::VideoMode::getDesktopMode().width;
    maxPosition.y = sf::VideoMode::getDesktopMode().height;
    
    position.x() = 300;
    position.y() = 800;

    velocity.x() = 0;
    velocity.y() = 0;

    acceleration.x() = 0.5;
    acceleration.y() = 0;

    collision.x = 0;
    collision.y = 0;

    jumpVelocity = 500;
    gravity = 2;//0.5;
    acceleration_value = 2;//0.5;
    friction = -2; //-0.12;

    //texture.loadFromFile("");
    //sprite.setTexture(texture);

    rectangle.setSize(sf::Vector2f(50, 50));
    rectangle.setFillColor(sf::Color::Red);

}

sf::Sprite Player::getSprite() {
    return sprite;
}

sf::RectangleShape Player::getRectangle() {
    return rectangle;
}

void Player::accelerateLeft() {
    acceleration.x() = -acceleration_value;
}

void Player::accelerateRight() {
    acceleration.x() = acceleration_value;
}

sf::Vector2f Player::getCollisions() {
    return collision;
}

void Player::setCollisions(int x, int y) {
    collision.x = x;
    collision.y = y;
}

void Player::jump() {
    if (collision.y == 1) {
        collision.y = 0;
        velocity.y() = -jumpVelocity;
    }
}

Eigen::Vector2f Player::getPositionVector() {
    return position;
}

sf::FloatRect Player::getPosition() {
    return rectangle.getGlobalBounds();
}

Eigen::Vector2f Player::getVelocity() {
    return velocity;
}

Eigen::Vector2f Player::getAcceleration() {
    return acceleration;
}

void Player::update(float elapsedTime) {

    //std::cout << "player::update()" << std::endl;

    acceleration.x() = 0;
    acceleration.y() = gravity;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        accelerateLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        accelerateRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        jump();
    }

    if ( (acceleration.x() < 1 && acceleration.x() >= 0 ) || (acceleration.x() > -1 && acceleration.x() <= 0) ) {
        acceleration.x() = 0;
    }
    if ( (acceleration.y() < 1 && acceleration.y() >= 0 ) || (acceleration.y() > -1 && acceleration.y() <= 0) ) {
        acceleration.y() = 0;
    }
    if ( (velocity.x() < 1 && velocity.x() >= 0) || (velocity.x() > -1 && velocity.x() <= 0) ) {
        velocity.x() = 0;
    }
    if ( (velocity.y() < 1 && velocity.y() >= 0) || (velocity.y() > -1 && velocity.y() <= 0) ) {
        velocity.y() = 0;
    }
    
    // no collision OR (collision left and acceleration right) OR (collision right and acceleration left)
    if (collision.x == 0 || (collision.x == -1 && acceleration.x() > 0) /* || (collision.x == 1 && acceleration.x() < 0) */ ) {

        // apply friction to x axis only
        acceleration.x() += (velocity.x() * friction) * elapsedTime;
        // equations of motion
        velocity.x() += acceleration.x();
        position.x() += (velocity.x() + (0.5 * acceleration.x())) * elapsedTime;

    } else {

        acceleration.x() = acceleration_value;
        velocity.x() = 0;

    }

    // no collision OR (collision down and acceleration up)
    if (collision.y == 0 || (collision.y == 1 && acceleration.y() < 0) ) {
        velocity.y() += acceleration.y();
        position.y() += (velocity.y() + (0.5 * acceleration.y())) * elapsedTime;

    } else {
        acceleration.y() = acceleration_value;
        velocity.y() = 0;

    }

    //wrap around screen on x axis
    if (position.x() > maxPosition.x) {
        position.x() = 0;
    }
    if (position.x() < 0) {
        position.x() = maxPosition.x;
    }

    //wrap around screen on y axis
    if (position.y() > maxPosition.y) {
        position.y() = 0;
    }
    if (position.y() < 0) {
        position.y() = maxPosition.y;
    }
        
    //sprite.setPosition(position);
    rectangle.setPosition(sf::Vector2f(position.x(), position.y()));

}
