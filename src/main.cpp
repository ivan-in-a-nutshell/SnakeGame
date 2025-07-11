#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <random>
#include "constants.hpp"
#include "doubly_linked_list.hpp"
#include "random_selector.cpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode{sf::Vector2u(constants::screen_size)}, "CMake SFML Project");
    window.setFramerateLimit(60);

    // Load the texture
    sf::Texture texture("../../imgs/tile.png");
    texture.setRepeated(true);

    // Create field sprite
    sf::Sprite field(texture);
    field.setTextureRect(sf::IntRect({0, 0}, sf::Vector2<int>(constants::screen_size)));

    // Create a player
    auto player = new DoublyLinkedList();
    auto player_init_pos = constants::box_size * sf::Vector2f{static_cast<float>(static_cast<int>(constants::field_width / 2)), static_cast<float>(static_cast<int>(constants::field_height / 2))};
    player->insertAtBeginning(0, player_init_pos);
    std::vector<sf::Sprite> player_sprites;
    player_sprites.emplace_back(texture);
    player_sprites[0].setColor(sf::Color{0, 128, 255, 128});

    // Create field positions
    std::unordered_set<sf::Vector2i, Vector2iHash> field_positions;
    for (int i = 0; i < constants::field_width; ++i) {
        for (int j = 0; j < constants::field_height; ++j) {
            field_positions.insert(static_cast<int>(constants::box_size) * sf::Vector2i{i, j});
        }
    }

    // Create an apple
    sf::Sprite apple{texture};
    apple.setColor(sf::Color{255, 0, 0});
    apple.setScale(sf::Vector2f{constants::apple_size, constants::apple_size});
    // Place apple randomly on field
    auto offset_pos = constants::box_size * sf::Vector2f{(1 - constants::apple_size), (1 - constants::apple_size)} / 2.f;
    random_selector random_selector;
    sf::Vector2f apple_pos{static_cast<sf::Vector2f>(random_selector(field_positions - player->set)) + offset_pos};
    apple.setPosition(apple_pos);

    bool apple_eaten = false;
    bool game_playing = true;

    sf::Vector2f direction{constants::up};
    sf::Vector2f player_direction{constants::up};
    sf::Clock clock;

    while (window.isOpen() && game_playing)
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player_direction != constants::down) {
            direction = constants::up;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player_direction != constants::left) {
            direction = constants::right;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player_direction != constants::up) {
            direction = constants::down;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player_direction != constants::right) {
            direction = constants::left;
        }

        if (clock.getElapsedTime().asMilliseconds() > 200) {
            if (apple_eaten) {
                game_playing = player->insertAtBeginning(0, player->getHead().position + direction);
                player_sprites.emplace_back(texture);
                player_sprites.back().setColor(sf::Color{0, 128, 255});
                apple_eaten = false;
            } else {
                game_playing = player->moveEndToFront(player->getHead().position + direction);
            }

            if (0.f > player->getHead().position.x || player->getHead().position.x > constants::screen_size.x
                || 0.f > player->getHead().position.y || player-> getHead().position.y > constants::screen_size.y) {
                game_playing = false;
            }

            if (static_cast<sf::Vector2i>(player->getHead().position) == static_cast<sf::Vector2i>(apple.getPosition() - offset_pos)) {
                apple_pos = sf::Vector2f(random_selector(field_positions - player->set)) + offset_pos;
                apple.setPosition(apple_pos);
                apple_eaten = true;
            }

            player_direction = direction;

            clock.restart();
        }

        window.clear();
        window.draw(field);

        int i = 0;
        Node *current = &player->getHead();
        while (current != nullptr) {
            player_sprites[i].setPosition(current->position);
            window.draw(player_sprites[i]);
            current = current->next;
            ++i;
        }
        delete current;

        window.draw(apple);

        window.display();
    }
}
