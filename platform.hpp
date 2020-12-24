#include <SFML/Graphics.hpp>

#include "eigen/Dense"

class Platform {

    private:

        Eigen::Vector2f position;

        sf::RectangleShape platform;

    public:

        Platform();

        void setPosition(float x, float y);
        void setSize(float w, float h);
        void setColor(sf::Color);

        sf::RectangleShape getRectangle();

        sf::FloatRect getPosition();

};
