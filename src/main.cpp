#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.hpp"
#include "doubly_linked_list.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode{sf::Vector2u(constants::screen_size)}, "CMake SFML Project");
    window.setFramerateLimit(60);

    sf::Texture texture("../../imgs/tile.png");
    texture.setRepeated(true);
    sf::Sprite sprite(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, constants::screen_size));

    auto player = new DoublyLinkedList();
    auto player_init_pos = sf::Vector2f{constants::screen_size.x / 2.f, constants::screen_size.y / 2.f};
    player->insertAtBeginning(0, player_init_pos);
    sf::Sprite playerSprite{texture};
    playerSprite.setColor(sf::Color{0, 0, 255, 128});
    playerSprite.setPosition(player->getHead().position);

    sf::Sprite apple{texture};
    apple.setColor(sf::Color{255, 0, 0});
    apple.setScale(sf::Vector2f{0.8f, 0.8f});
    apple.setPosition(sf::Vector2f{0, 0});

    sf::Vector2f direction{constants::up};
    sf::Clock clock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && direction != constants::down) {
            direction = constants::up;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && direction != constants::left) {
            direction = constants::right;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && direction != constants::up) {
            direction = constants::down;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && direction != constants::right) {
            direction = constants::left;
        }

        if (clock.getElapsedTime().asMilliseconds() > 300) {
            playerSprite.move(direction);
            clock.restart();
        }

        window.clear();
        window.draw(sprite);
        window.draw(playerSprite);
        window.draw(apple);
        window.display();
    }
}
