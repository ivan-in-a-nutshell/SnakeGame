//
// Created by ivan on 7/12/25.
//

#include "snake.hpp"
#include "constants.hpp"

Snake::Snake(const sf::Texture &texture){
    this->body = DoublyLinkedList<sf::Vector2i>();
    this->set = std::unordered_set<sf::Vector2i, Vector2iHash>();
    this->current_direction = constants::up;
    this->future_direction = constants::up;
    this->texture = texture;
    this->is_alive = true;

    this->body.insertAtBeginning(constants::player_start_pos);
    this->set.insert(constants::player_start_pos);
    this->addTexture();
}

void Snake::addTexture() {
    this->sprites.emplace_back(this->texture);
    this->sprites.back().setColor(constants::player_color);
}

const std::unordered_set<sf::Vector2i, Vector2iHash> &Snake::getSet() {
    return this->set;
}

void Snake::addSegment(const sf::Vector2i &position) {
    this->is_alive = this->isOkToMove(position);
    this->body.insertAtBeginning(position);
    this->set.insert(position);
    this->addTexture();
}

void Snake::moveSegment(const sf::Vector2i &position) {
    this->set.erase(this->body.getTail().data);
    this->is_alive = this->isOkToMove(position);
    this->body.moveEndToFront(position);
    this->set.insert(position);
}


const sf::Vector2i &Snake::getHeadPos() {
    return this->body.getHead().data;
}

void Snake::updateSprites(const std::shared_ptr<sf::RenderWindow> &window) {
    auto current_node{std::make_shared<Node<sf::Vector2i>>(this->body.getHead())};
    for (auto sprite : this->sprites) {
        sprite.setPosition(static_cast<sf::Vector2f>(current_node->data));
        window->draw(sprite);
        current_node = current_node->next;
    }
}

bool Snake::isOkToMove(const sf::Vector2i &next_position) {
    return this->set.find(next_position) == this->set.end();
}

