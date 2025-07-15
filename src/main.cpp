#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <random>
#include "constants.hpp"
#include "random_selector.cpp"
#include "snake.hpp"

int main()
{
    std::shared_ptr<sf::RenderWindow> window{new sf::RenderWindow{sf::VideoMode{sf::Vector2u(constants::screen_size)}, "CMake SFML Project"}};
    window->setFramerateLimit(60);

    // Load the texture
    std::shared_ptr<sf::Texture> texture{new sf::Texture{"../../imgs/tile.png"}};
    texture->setRepeated(true);

    // Create field sprite
    sf::Sprite field{*texture};
    field.setTextureRect(sf::IntRect({0, 0}, sf::Vector2<int>(constants::screen_size)));

    // Create a player
    auto player = Snake(texture);

    // Create field positions
    std::unordered_set<sf::Vector2i, Vector2iHash> field_positions;
    for (int i = 0; i < constants::field_width; ++i) {
        for (int j = 0; j < constants::field_height; ++j) {
            field_positions.insert(static_cast<int>(constants::box_size) * sf::Vector2i{i, j});
        }
    }

    // Create an apple
    sf::Sprite apple{*texture};
    apple.setColor(sf::Color{255, 0, 0});
    apple.setScale(sf::Vector2f{constants::apple_size, constants::apple_size});
    // Place apple randomly on field
    auto offset_pos = static_cast<float>(constants::box_size) * sf::Vector2f{(1 - constants::apple_size), (1 - constants::apple_size)} / 2.f;
    random_selector random_selector;
    sf::Vector2f apple_pos{static_cast<sf::Vector2f>(random_selector(field_positions - player.getSet())) + offset_pos};
    apple.setPosition(apple_pos);

    bool apple_eaten = false;

    sf::Clock clock;

    while (window->isOpen() && player.is_alive)
    {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player.current_direction != constants::down) {
            player.future_direction = constants::up;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player.current_direction != constants::left) {
            player.future_direction = constants::right;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player.current_direction != constants::up) {
            player.future_direction = constants::down;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player.current_direction != constants::right) {
            player.future_direction = constants::left;
        }

        if (clock.getElapsedTime().asMilliseconds() > 200) {
            if (apple_eaten) {
                player.addSegment(player.getHeadPos() + static_cast<sf::Vector2i>(player.future_direction));
                apple_eaten = false;
            } else {
                player.moveSegment(player.getHeadPos() + static_cast<sf::Vector2i>(player.future_direction));
            }

            if (0 > player.getHeadPos().x || player.getHeadPos().x > static_cast<int>(constants::screen_size.x)
                || 0 > player.getHeadPos().y || player.getHeadPos().y > static_cast<int>(constants::screen_size.y)) {
                player.is_alive = false;
            }

            if (player.getHeadPos() == static_cast<sf::Vector2i>(apple.getPosition() - offset_pos)) {
                apple_pos = sf::Vector2f(random_selector(field_positions - player.getSet())) + offset_pos;
                apple.setPosition(apple_pos);
                apple_eaten = true;
            }

            player.current_direction = player.future_direction;

            clock.restart();
        }

        window->clear();
        window->draw(field);
        player.updateSprites(window);
        window->draw(apple);
        window->display();
    }
}
