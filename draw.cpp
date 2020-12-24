#include "game.hpp"

#include <iostream>

void Game::draw(sf::Font& font_debug) {

    window.clear();

    //window.draw(player.getSprite());
    window.draw(player.getRectangle());

    for (int i = 0; i < number_of_platforms; i++) {
        window.draw(platforms[i].getRectangle());
    }

    window.draw(hud_debug);

    window.display();

}
