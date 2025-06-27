//
// Created by ivan on 15/06/25.
//

#ifndef NODE_HPP
#define NODE_HPP

#include <SFML/Graphics.hpp>

struct Node {
    int place;
    sf::Vector2f position;
    Node *next;
    Node *prev;
    Node(int place, const sf::Vector2f &position);
};



#endif //NODE_HPP
