//
// Created by ivan on 14/06/25.
//

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <SFML/Graphics.hpp>
namespace constants {
    inline int box_size{40};
    inline int field_width{15};
    inline int field_height{15};
    inline sf::Vector2f screen_size{static_cast<float>(box_size * field_width),
                                    static_cast<float>(box_size *field_height)};

    inline sf::Vector2i player_start_pos{box_size * sf::Vector2i{field_width / 2, field_height / 2}};
    inline sf::Vector2i up{0, -box_size};
    inline sf::Vector2i right{box_size, 0};
    inline sf::Vector2i down{0, box_size};
    inline sf::Vector2i left{-box_size, 0};

    inline sf::Color player_color{0, 128, 255};
}

#endif //CONSTANTS_HPP

