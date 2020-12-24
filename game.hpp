#include "player.hpp"
#include "platform.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

class Game {

    private:

        sf::RenderWindow window;
        sf::Vector2f resolution;

        //const float FPS = 60.0f; //The desired FPS. (The number of updates each second).

        sf::Font font_debug;
        sf::Text hud_debug;

        Player player;

        int number_of_platforms;
        std::unique_ptr<Platform[]> platforms;

        void input(float dtAsSeconds);
        void update(float dtAsSeconds);
        void draw(sf::Font&);

        void checkPlayerCollisions();

    public:

        Game();

        void start();

};
