//
// Created by ivan on 15/06/25.
//

#ifndef NODE_HPP
#define NODE_HPP

#include <memory>


template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

    explicit Node(const T &data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};



#endif //NODE_HPP
