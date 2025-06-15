//
// Created by ivan on 14/06/25.
//

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <cstdint>
#include <SFML/Graphics.hpp>
namespace constants {
    inline std::uint16_t box_size = 40u;
    inline std::uint16_t field_width = 20u;
    inline std::uint16_t field_height = 20u;
    inline sf::Vector2i screen_size{box_size * field_width, box_size * field_height};
}

#endif //CONSTANTS_HPP

