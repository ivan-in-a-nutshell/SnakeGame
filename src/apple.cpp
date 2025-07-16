//
// Created by ivan on 7/16/25.
//

#include "apple.hpp"
#include "constants.hpp"
#include "random_selector.cpp"

Apple::Apple(const sf::Texture &texture) : sprite(texture) {}

void Apple::updatePosition(const std::unordered_set<sf::Vector2i, Vector2iHash> &positions) {
    random_selector random_selector;
    const sf::Vector2i new_position{random_selector(positions)};

    this->sprite.setPosition(static_cast<sf::Vector2f>(new_position));
    this->position = new_position;
}

const sf::Vector2i &Apple::getPosition() const {
    return this->position;
}

const sf::Sprite &Apple::getSprite() const {
    return this->sprite;
}
