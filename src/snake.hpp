//
// Created by ivan on 7/12/25.
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <unordered_set>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "doubly_linked_list.hpp"
#include "utilities.hpp"

class Snake {
    std::unordered_set<sf::Vector2i, Vector2iHash> set;
    DoublyLinkedList<sf::Vector2i> body;
    sf::Texture texture;
    std::vector<sf::Sprite> sprites;

    void addTexture();
    bool isOkToMove(const sf::Vector2i &next_position);

public:
    sf::Vector2i current_direction;
    sf::Vector2i future_direction;
    bool is_alive;

    explicit Snake(const sf::Texture &texture);

    const std::unordered_set<sf::Vector2i, Vector2iHash> &getSet();
    const sf::Vector2i &getHeadPos();
    void addSegment(const sf::Vector2i &position);
    void moveSegment(const sf::Vector2i &position);
    void updateSprites(const std::shared_ptr<sf::RenderWindow> &window);
};



#endif //SNAKE_HPP
