//
// Created by ivan on 7/16/25.
//

#include "field.hpp"

#include "constants.hpp"


Field::Field(const sf::Texture &texture) : sprite {texture } {
    this->sprite.setTextureRect(sf::IntRect{{0, 0}, sf::Vector2i{static_cast<int>(constants::screen_size.x), static_cast<int>(constants::screen_size.y)}});

    for (int i = 0; i < constants::field_width; ++i) {
        for (int j = 0; j < constants::field_height; ++j) {
            this->field_positions.insert(constants::box_size * sf::Vector2i{i, j});
        }
    }
}

const std::unordered_set<sf::Vector2i, Vector2iHash> &Field::getFieldPositions() const {
    return this->field_positions;
}

const sf::Sprite &Field::getSprite() const {
    return this->sprite;
}