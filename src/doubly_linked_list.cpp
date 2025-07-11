//
// Created by ivan on 15/06/25.
//

#include "doubly_linked_list.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

bool DoublyLinkedList::insertAtBeginning(const int place, const sf::Vector2f &position) {
    auto newNode = new Node(place, position);

    if (this->set.count(static_cast<sf::Vector2i>(position)) > 0) {
        return false;
    }
    this->set.insert(static_cast<sf::Vector2i>(position));

    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = this->head;
        return true;
    }

    newNode->next = this->head;
    this->head->prev = newNode;
    this->head = newNode;
    return true;
}

void DoublyLinkedList::insertAtEnd(int place, const sf::Vector2f &position) {
    auto newNode = new Node(place, position);
    this->set.insert(static_cast<sf::Vector2i>(position));

    if (this->head == nullptr) {
        this->head = newNode;
        return;
    }

    if (this->tail == this->head) {
        this->head->next = newNode;
        newNode->prev = this->head;
        this->tail = newNode;
        return;
    }

    this->tail->next = newNode;
    newNode->prev = this->tail;
    this->tail = newNode;
}

void DoublyLinkedList::printListForward() {
    auto temp = this->head;
    while (temp != nullptr) {
        std::cout << temp->place << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

DoublyLinkedList::~DoublyLinkedList() {
    auto current = this->head;
    while (current != nullptr) {
        auto nextNode{current->next};
        delete current;
        current = nextNode;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

bool DoublyLinkedList::moveEndToFront(const sf::Vector2f &new_position) {
    auto end = this->tail;
    if (end == nullptr) {
        return true;
    }

    if (this->set.count(static_cast<sf::Vector2i>(new_position)) > 0) {
        return false;
    }

    this->set.erase(static_cast<sf::Vector2i>(end->position));
    if (end == this->head) {
        end->position = new_position;
        this->set.insert(static_cast<sf::Vector2i>(end->position));
        return true;
    }

    this->tail = end->prev;
    this->tail->next = nullptr;
    end->prev = nullptr;
    end->next = this->head;
    this->head->prev = end;
    this->head = end;
    this->head->position = new_position;
    this->set.insert(static_cast<sf::Vector2i>(end->position));
    return true;
}

Node& DoublyLinkedList::getHead() {
    if (this->head != nullptr) {
        return *head;
    }
    throw std::out_of_range("DoublyLinkedList::getHead()");
}