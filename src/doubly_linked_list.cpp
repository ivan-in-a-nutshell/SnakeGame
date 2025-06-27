//
// Created by ivan on 15/06/25.
//

#include "doubly_linked_list.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void DoublyLinkedList::insertAtBeginning(int place, const sf::Vector2f &position) {
    auto newNode = new Node(place, position);

    if (this->head == nullptr) {
        this->head = newNode;
        return;
    }

    newNode->next = this->head;
    this->head->prev = newNode;
    this->head = newNode;
}

void DoublyLinkedList::insertAtEnd(int place, const sf::Vector2f &position) {
    auto newNode = new Node(place, position);

    if (this->head == nullptr) {
        this->head = newNode;
        return;
    }

    if (this->tail == nullptr) {
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

void DoublyLinkedList::moveEndToFront() {
    auto end = this->tail;
    if (end == nullptr || end->prev == nullptr) {
        return; // List is empty or has only one element
    }
    this->tail = end->prev;
    this->tail->next = nullptr;
    end->prev = nullptr;
    end->next = this->head;
    this->head->prev = end;
    this->head = end;
}

Node& DoublyLinkedList::getHead() {
    if (this->head != nullptr) {
        return *head;
    }
    throw std::out_of_range("DoublyLinkedList::getHead()");
}
