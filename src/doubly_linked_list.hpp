//
// Created by ivan on 15/06/25.
//

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "node.hpp"


class DoublyLinkedList {
    Node *head;
    Node *tail;

    public:
    DoublyLinkedList();
    void insertAtBeginning(int place, const sf::Vector2f &position);
    void insertAtEnd(int place, const sf::Vector2f &position);
    void printListForward();
    ~DoublyLinkedList();
    void moveEndToFront();
    Node& getHead();
};



#endif //DOUBLY_LINKED_LIST_HPP
