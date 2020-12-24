#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{

RenderWindow window(VideoMode(800,600),"TEXT");

/****************************************************/

//Declare a Font object
Font font;

//Load and check the availability of the font file
if(!font.loadFromFile("resources/fonts/Hack-Regular.ttf"))
{
    cout << "can't load font" << endl;
}

//Declare a Text object
Text text("Score = 0",font);

//Set character size
text.setCharacterSize(100);

//Set fill color
text.setFillColor(Color::White);

/****************************************************/


while(window.isOpen())
{
    Event event;
    while(window.pollEvent(event))
    {
         if(event.type == Event::Closed){window.close();}
    }

    //Clear the window
    window.clear();
    //Draw the text
    window.draw(text);
    //Display the text to the window
    window.display();
}

return 0;
}