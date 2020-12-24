#include "game.hpp"

#include <iostream>
#include <memory>
#include <math.h>

Game::Game() {

    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(
        //sf::VideoMode::getFullscreenModes()[0],
        sf::VideoMode(resolution.x, resolution.y),
        "Platformer?",
        sf::Style::Default
        //sf::Style::Fullscreen
    );

    //window.setFramerateLimit(FPS);

    sf::Font font_debug;

    sf::Text hud_debug;

    sf::Vector2f debug_platformPOS[2] = {
        sf::Vector2f(300, 851),
        sf::Vector2f(200, 901)
    };
    sf::Vector2f debug_platformSIZE[2] = {
        sf::Vector2f(500, 50),
        sf::Vector2f(1000, 50)
    };
    sf::Color debug_platformCOLOR[2] = {
        sf::Color::White,
        sf::Color::Yellow
    };

    number_of_platforms = 2;
    platforms = std::make_unique<Platform[]>(number_of_platforms);
    for (int i = 0; i < number_of_platforms; i++) {
        platforms[i].setPosition(debug_platformPOS[i].x, debug_platformPOS[i].y);
        platforms[i].setSize(debug_platformSIZE[i].x, debug_platformSIZE[i].y);
        platforms[i].setColor(debug_platformCOLOR[i]);
    }

}

void Game::start() {

    sf::Clock clock;

    if (!font_debug.loadFromFile("resources/fonts/Hack-Regular.ttf")) {
        std::cout << "failed to load font" << std::endl;
    }
    hud_debug.setFont(font_debug);
    hud_debug.setCharacterSize(75);
    hud_debug.setFillColor(sf::Color::Green);
    hud_debug.setString("position: (0, 0)     velocity: (0, 0)");

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        input(dtAsSeconds);
        update(dtAsSeconds);
        draw(font_debug);

    }

}

void Game::checkPlayerCollisions() {

    //std::cout << "checkPlayerCollisions()" << std::endl;

    sf::Vector2f collision = sf::Vector2f (0, 0);

    sf::FloatRect playerxy = player.getPosition();     

    //std::cout << "player -- " << "L: " << playerxy.left << " T: " << playerxy.top << " W: " << playerxy.width << " H: " << playerxy.height << std::endl;   

    for (int i = 0; i < number_of_platforms; i++) {

        sf::FloatRect platformxy = platforms[i].getPosition();
        //std::cout << "platform -- " << "L: " << platformxy.left << " T: " << platformxy.top << " W: " << platformxy.width << " H: " << platformxy.height << std::endl;

        // top: (L, T) <--> (L + W, T)
        // left: (L, T) <--> (L, T + H)
        // right: (L + W, T) <--> (L + W, T + H)
        // bottom: (L, T + H) <--> (L + W, T + H)

        sf::Vector2f platform_upper_left(platformxy.left, platformxy.top);
        sf::Vector2f platform_upper_right(platformxy.left + platformxy.width, platformxy.top);
        sf::Vector2f platform_lower_left(platformxy.left, platformxy.top + platformxy.height);
        sf::Vector2f platform_lower_right(platformxy.left + platformxy.width, platformxy.top + platformxy.height);

        sf::Vector2f player_upper_left(playerxy.left, playerxy.top);
        sf::Vector2f player_upper_right(playerxy.left + playerxy.width, playerxy.top);
        sf::Vector2f player_lower_left(playerxy.left, playerxy.top + playerxy.height);
        sf::Vector2f player_lower_right(playerxy.left + playerxy.width, playerxy.top + playerxy.height);

        // hitting top of platform
        if ( floor(player_lower_left.y) == platform_upper_left.y ) {

            if ( player_lower_right.x >= platform_upper_left.x && player_lower_left.x <= platform_upper_right.x ) {
                //std::cout << "on top of platform" << std::endl;
                collision.y = 1;
            }

        }

        // hitting underside of platform

        // hitting right side of platform

        if ( floor(player_lower_left.y) > platform_upper_right.y || floor(player_upper_left.y) < platform_lower_right.y ) {

            if ( player_lower_left.x == platform_upper_right.x ) {
                //std::cout << "right side of platform" << std::endl;
                collision.x = -1;
            }

        }

        //hitting left side of platform

        if ( player_lower_right.y > floor(platform_upper_left.y) || player_upper_right.y < floor(platform_lower_left.y) ) {

            if ( player_lower_right.x == floor(platform_upper_left.x) ) {
                //std::cout << "left side of platform" << std::endl;
                collision.x = 1;
            }

        }


        if (collision.x != 0 || collision.y != 0) {
            /*
            std::cout << "player" << std::endl;
            std::cout << "( " << player_upper_left.x << ", " << player_upper_left.y << " )" << " -- " << "( " << player_upper_right.x << ", " << player_upper_right.y << " )" << std::endl;
            std::cout << "( " << player_lower_left.x << ", " << player_lower_left.y << " )" << " -- " << "( " << player_lower_right.x << ", " << player_lower_right.y << " )" << std::endl;

            std::cout << "platform" << std::endl;
            std::cout << "( " << platform_upper_left.x << ", " << platform_upper_left.y << " )" << " -- " << "( " << platform_upper_right.x << ", " << platform_upper_right.y << " )" << std::endl;
            std::cout << "( " << platform_lower_left.x << ", " << platform_lower_left.y << " )" << " -- " << "( " << platform_lower_right.x << ", " << platform_lower_right.y << " )" << std::endl;
            */
        }

    }

    player.setCollisions(collision.x, collision.y);

}
