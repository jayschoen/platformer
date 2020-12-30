# an attempt at making a platformer game in c++

## to compile:

```clang++ -stdlib=libc++ -std=c++17 main.cpp player.cpp platform.cpp draw.cpp game.cpp input.cpp update.cpp -I/usr/local/include -I./eigen -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system  -o output```

requires [SFML](https://www.sfml-dev.org/) to be installed

## to run:

./output
