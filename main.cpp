#include "game.hpp"

//clang++ -stdlib=libc++ -std=c++17 main.cpp player.cpp platform.cpp draw.cpp game.cpp input.cpp update.cpp -I/usr/local/include -I./eigen -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system  -o output

int main() {

    Game game;

    game.start();

    return 0;

}
