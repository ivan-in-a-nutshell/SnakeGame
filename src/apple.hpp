//
// Created by ivan on 7/16/25.
//

#ifndef APPLE_HPP
#define APPLE_HPP
#include <memory>
#include <unordered_set>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "utilities.hpp"


class Apple {
    sf::Sprite sprite;
    sf::Vector2i position;

public:
    explicit Apple(const sf::Texture &texture);
    void updatePosition(const std::unordered_set<sf::Vector2i, Vector2iHash> &positions);
    const sf::Vector2i &getPosition() const;
    const sf::Sprite &getSprite() const;
};



#endif //APPLE_HPP
