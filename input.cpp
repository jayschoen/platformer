#include "game.hpp"

#include <iostream>

void Game::input(float dtAsSeconds) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }

/*     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.accelerateLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.accelerateRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        std::cout << "jumping" << std::endl;
        player.jump();
    } */
}
