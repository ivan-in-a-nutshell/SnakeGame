#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <random>

#include "apple.hpp"
#include "constants.hpp"
#include "field.hpp"
#include "random_selector.cpp"
#include "snake.hpp"

int main()
{
    std::shared_ptr<sf::RenderWindow> window{new sf::RenderWindow{sf::VideoMode{sf::Vector2u(constants::screen_size)}, "CMake SFML Project"}};
    window->setFramerateLimit(60);

    sf::Texture texture{"../../imgs/tile.png"};
    texture.setRepeated(true);
    sf::Texture apple_texture{"../../imgs/apple.png"};

    auto player = Snake(texture);
    auto field = Field(texture);
    auto apple = Apple(apple_texture);

    bool apple_eaten = false;

    sf::Clock clock;
    while (window->isOpen() && player.is_alive)
    {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }

        // TODO: Should be handled by some kind of class (GameController or InputHandler)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player.current_direction != constants::down) {
            player.future_direction = constants::up;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player.current_direction != constants::left) {
            player.future_direction = constants::right;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player.current_direction != constants::up) {
            player.future_direction = constants::down;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player.current_direction != constants::right) {
            player.future_direction = constants::left;
        }

        // TODO: also GameController
        if (clock.getElapsedTime().asMilliseconds() > 200) {

            if (apple_eaten) {
                player.addSegment(player.getHeadPos() + player.future_direction);
                apple_eaten = false;
            } else {
                player.moveSegment(player.getHeadPos() + player.future_direction);
            }

            if (0 > player.getHeadPos().x || player.getHeadPos().x >= static_cast<int>(constants::screen_size.x)
                || 0 > player.getHeadPos().y || player.getHeadPos().y >= static_cast<int>(constants::screen_size.y)) {
                player.is_alive = false;
            }

            if (player.getHeadPos() == apple.getPosition()) {
                apple.updatePosition(field.getFieldPositions() - player.getSet());
                apple_eaten = true;
            }

            player.current_direction = player.future_direction;

            clock.restart();
        }

        window->clear();
        window->draw(field.getSprite());
        player.updateSprites(window);
        window->draw(apple.getSprite());
        window->display();
    }
}
