#include <SFML/Graphics.hpp>
#include <string>
#include "MapMetaLoader.h"

int main()
{

    sf::Image i;
    sf::Texture t;
    sf::Sprite s;

    i.loadFromFile("map0.png");
    t.loadFromImage(i);
    s.setTexture(t);
    std::vector<Country> countries;
    MapMetaLoader::load("map0_meta.xml", countries);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(s);

        // end the current frame
        window.display();
    }

    return 0;
}


