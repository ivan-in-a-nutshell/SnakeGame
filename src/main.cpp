#include <SFML/Graphics.hpp>
#include "constants.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode{sf::Vector2u(constants::screen_size)}, "CMake SFML Project");
    window.setFramerateLimit(60);

    sf::Texture texture("../../imgs/tile.png");
    texture.setRepeated(true);
    sf::Sprite sprite(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, constants::screen_size));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
