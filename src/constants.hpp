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
    inline float apple_size{0.5f};
    inline sf::Vector2f screen_size{static_cast<float>(box_size * field_width),
                                    static_cast<float>(box_size *field_height)};

    inline sf::Vector2i player_start_pos{static_cast<int>(box_size) * sf::Vector2i{static_cast<int>(field_width / 2), static_cast<int>(field_height / 2)}};
    inline sf::Vector2f up{0.f, static_cast<float>(-box_size)};
    inline sf::Vector2f right{static_cast<float>(box_size), 0.f};
    inline sf::Vector2f down{0.f, static_cast<float>(box_size)};
    inline sf::Vector2f left{static_cast<float>(-box_size), 0.f};

    inline sf::Color player_color{0, 128, 255};

}

#endif //CONSTANTS_HPP

