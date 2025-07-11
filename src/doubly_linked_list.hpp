//
// Created by ivan on 15/06/25.
//

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <unordered_set>
#include "node.hpp"
#include "utilities.hpp"


class DoublyLinkedList {
    Node *head;
    Node *tail;

    public:
    std::unordered_set<sf::Vector2i, Vector2iHash> set;
    DoublyLinkedList();
    bool insertAtBeginning(int place, const sf::Vector2f &position);
    void insertAtEnd(int place, const sf::Vector2f &position);
    void printListForward();
    ~DoublyLinkedList();
    bool moveEndToFront(const sf::Vector2f &new_position);
    Node& getHead();
};



#endif //DOUBLY_LINKED_LIST_HPP
