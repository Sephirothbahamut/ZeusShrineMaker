#pragma once
#include <SFML/Graphics.hpp>
#include <string>

std::string to_string(sf::Color color) { return ("(r: " + std::to_string(color.r) + ", g : " + std::to_string(color.g) + ", b : " + std::to_string(color.b) + ")"); }
template <typename T>
std::string to_string(sf::Vector2<T> v) { return ("(x: " + std::to_string(v.x) + ", y : " + std::to_string(v.y) + ")"); }

sf::Color noalpha(sf::Color color) { color.a = 255; return color; }