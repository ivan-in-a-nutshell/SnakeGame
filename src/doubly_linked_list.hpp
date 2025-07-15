//
// Created by ivan on 15/06/25.
//

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <stdexcept>


#include "node.hpp"

template <typename T>
class DoublyLinkedList {
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

public:
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtBeginning(const T &data) {
        std::shared_ptr<Node<T>> new_node{new Node{data}};

        if (this->head == nullptr) {
            this->head = new_node;
            this->tail = this->head;
            return;
        }

        new_node->next = this->head;
        this->head->prev = new_node;
        this->head = new_node;
    }

    void insertAtEnd(const T &data) {
        std::shared_ptr<Node<T>> new_node{new Node(data)};

        if (this->head == nullptr) {
            this->head = new_node;
            return;
        }

        if (this->tail == this->head) {
            this->head->next = new_node;
            new_node->prev = this->head;
            this->tail = new_node;
            return;
        }

        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
    }

    void moveEndToFront(const T &new_data) {
        auto end = this->tail;
        if (end == nullptr) {
            return;
        }

        if (end == this->head) {
            end->data = new_data;
            return;
        }

        this->tail = end->prev;
        this->tail->next = nullptr;
        end->prev = nullptr;
        end->next = this->head;
        this->head->prev = end;
        this->head = end;
        this->head->data = new_data;
    }

    const Node<T>& getHead() {
        if (this->head != nullptr) {
            return *head;
        }
        throw std::out_of_range("DoublyLinkedList::getHead()");
    }

    const Node<T>& getTail() {
        if (this->tail != nullptr) {
            return *tail;
        }
        throw std::out_of_range("DoublyLinkedList::getTail()");
    }
};



#endif //DOUBLY_LINKED_LIST_HPP
