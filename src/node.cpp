//
// Created by ivan on 15/06/25.
//

#include "node.hpp"

Node::Node(const int place, const sf::Vector2f &position) {
    this->place = place;
    this->position = position;
    this->next = nullptr;
    this->prev = nullptr;
}