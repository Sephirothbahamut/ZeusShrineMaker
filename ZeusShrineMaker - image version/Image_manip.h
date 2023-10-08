#pragma once
#include <stdexcept>

#include <SFML/Graphics.hpp>

#include "Support.h"
#include "Codes.h"

sf::Vector2u get_building_size_from_color(sf::Color color)
	{
	color = noalpha(color);

	/**/ if (color == Color_id::SANCTUARY_FRONT) { return {4, 4}; }
	else if (color == Color_id::SANCTUARY_BACK)  { return {4, 4}; }
	else if (color == Color_id::ALTAR)           { return {2, 2}; }
	else if (color == Color_id::STATUE_LARGE_N)  { return {2, 2}; }
	else if (color == Color_id::STATUE_LARGE_E)  { return {2, 2}; }
	else if (color == Color_id::STATUE_LARGE_S)  { return {2, 2}; }
	else if (color == Color_id::STATUE_LARGE_W)  { return {2, 2}; }
	return {1, 1};
	}


void clear_group(sf::Image& image, sf::Color root_color, sf::Vector2u pos, sf::Vector2u size)
	{
	sf::Color root255 = noalpha(root_color);

	for (uint32_t y = pos.y; y < pos.y + size.y; y++)
		{
		for (uint32_t x = pos.x; x < pos.x + size.x; x++)
			{
			sf::Color ca255 = noalpha(image.getPixel(x, y));

			if (root255 != ca255) { throw std::runtime_error("Part of color " + to_string(root_color) + " in position " + to_string(pos) + " is expected to be of the size " + to_string(size)); }
			image.setPixel(x, y, sf::Color::Transparent);
			}
		}
	image.setPixel(pos.x, pos.y, root_color);
	}

void clear_groups(sf::Image& image)
	{
	for (uint32_t y = 0; y < image.getSize().y; y++)
		{
		for (uint32_t x = 0; x < image.getSize().x; x++)
			{
			sf::Color color = image.getPixel(x, y);

			auto size = get_building_size_from_color(color);
			if (size != sf::Vector2u{1, 1}) { clear_group(image, color, {x, y}, size); }
			}
		}
	}