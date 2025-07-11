//
// Created by ivan on 14/06/25.
//

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <SFML/Graphics.hpp>
namespace constants {
    inline float box_size{40.0f};
    inline unsigned int field_width{15u};
    inline unsigned int field_height{15u};
    inline float apple_size{0.5f};

    inline sf::Vector2f screen_size{box_size * static_cast<float>(field_width), box_size * static_cast<float>(field_height)};
    inline sf::Vector2f up{0.f, -box_size};
    inline sf::Vector2f right{box_size, 0.f};
    inline sf::Vector2f down{0.f, box_size};
    inline sf::Vector2f left{-box_size, 0.f};
}

#endif //CONSTANTS_HPP

