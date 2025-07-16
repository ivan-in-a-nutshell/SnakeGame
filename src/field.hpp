//
// Created by ivan on 7/16/25.
//

#ifndef FIELD_HPP
#define FIELD_HPP

#include <unordered_set>

#include "SFML/Graphics/Sprite.hpp"
#include "utilities.hpp"


class Field {
    sf::Sprite sprite;
    std::unordered_set<sf::Vector2i, Vector2iHash> field_positions;

public:
    explicit Field(const sf::Texture &texture);

    const std::unordered_set<sf::Vector2i, Vector2iHash> &getFieldPositions() const;
    const sf::Sprite &getSprite() const;
};



#endif //FIELD_HPP
