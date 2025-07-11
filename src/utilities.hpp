//
// Created by ivan on 7/10/25.
//

#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <functional>


#include "SFML/System/Vector2.hpp"

struct Vector2iHash {
    size_t operator()(const sf::Vector2i& p) const
    {
        return std::hash<float>()(static_cast<float>((p.x + p.y) * (p.x + p.y + 1)) / 2.f + static_cast<float>(p.y));
    }
};

template <typename T, typename H>
std::unordered_set<T, H> operator-(const std::unordered_set<T, H>& lhs, const std::unordered_set<T, H>& rhs) {
    std::unordered_set<T, H> result{lhs};
    for (const auto& item : rhs) {
        result.erase(item);
    }
    return result;
}

#endif //UTILITIES_HPP
