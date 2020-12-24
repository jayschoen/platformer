#include <SFML/Graphics.hpp>

#include "eigen/Dense"

#include <functional>

class Player {

    private:

        Eigen::Vector2f position;

        sf::Vector2f maxPosition;

        Eigen::Vector2f velocity;
        Eigen::Vector2f acceleration;

        sf::Vector2f collision;

        sf::Texture texture;
        sf::Sprite sprite;

        sf::RectangleShape rectangle;

        bool jumping;
        float jumpVelocity;
        float gravity;
        float acceleration_value;
        float friction;

    public:

        Player();

        sf::Sprite getSprite();
        sf::RectangleShape getRectangle();

        void accelerateLeft();
        void accelerateRight();

        Eigen::Vector2f getPositionVector();

        sf::FloatRect getPosition();

        Eigen::Vector2f getVelocity();

        Eigen::Vector2f getAcceleration();

        sf::Vector2f getCollisions();
        void setCollisions(int x, int y);

        void jump();

        void update(float elapsedTime);

};
