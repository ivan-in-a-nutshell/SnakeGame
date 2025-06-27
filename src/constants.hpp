//
// Created by ivan on 14/06/25.
//

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <SFML/Graphics.hpp>
namespace constants {
    inline int box_size{40u};
    inline int field_width{20u};
    inline int field_height{20u};
    inline sf::Vector2i screen_size{box_size * field_width, box_size * field_height};
    inline sf::Vector2f up{0.f, static_cast<float>(-box_size)};
    inline sf::Vector2f right{static_cast<float>(box_size), 0.f};
    inline sf::Vector2f down{0.f, static_cast<float>(box_size)};
    inline sf::Vector2f left{static_cast<float>(-box_size), 0.f};
}

#endif //CONSTANTS_HPP

