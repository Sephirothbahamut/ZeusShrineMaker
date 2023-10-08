#pragma once
#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Image_manip.h"
#include "Codes.h"

uint32_t get_height(uint8_t alpha)
	{
	return (alpha - 100) / 20;
	}

void print_heightmap(sf::Image& image)
	{
	std::cout << "Heightmap\n";
	for (uint32_t y = 0; y < image.getSize().y; y++)
		{
		for (uint32_t x = 0; x < image.getSize().x; x++)
			{
			std::cout << static_cast<char>('a' + get_height(image.getPixel(x, y).a)) << " ";
			}
		std::cout << '\n';
		}
	}
void print_clearmap(sf::Image& image)
	{
	std::cout << "Clear\n";
	for (uint32_t y = 0; y < image.getSize().y; y++)
		{
		for (uint32_t x = 0; x < image.getSize().x; x++)
			{
			std::cout << (get_building_id(image.getPixel(x, y)) != Building_id::SKIP ? "-" : "X") << " ";
			}
		std::cout << '\n';
		}
	}

void print_stairs(sf::Image& image)
	{
	std::cout << "Stairs\n";
	for (uint32_t y = 0; y < image.getSize().y; y++)
		{
		for (uint32_t x = 0; x < image.getSize().x; x++)
			{
			std::cout << (get_building_id(image.getPixel(x, y)) != Building_id::STAIRS ? "-" : "X") << " ";
			}
		std::cout << '\n';
		}
	}

void print_statues(sf::Image& image)
	{
	std::cout << "Statues\n";
	for (uint32_t y = 0; y < image.getSize().y; y++)
		{
		for (uint32_t x = 0; x < image.getSize().x; x++)
			{
			switch (get_building_id(image.getPixel(x, y)))
				{
				case Building_id::STATUE_OF_ZEUSN: std::cout << "N"; break;
				case Building_id::STATUE_OF_ZEUSE: std::cout << "E"; break;
				case Building_id::STATUE_OF_ZEUSS: std::cout << "S"; break;
				case Building_id::STATUE_OF_ZEUSW: std::cout << "W"; break;
				case Building_id::SCULPTURE_ZEUS_N: std::cout << "n"; break;
				case Building_id::SCULPTURE_ZEUS_E: std::cout << "e"; break;
				case Building_id::SCULPTURE_ZEUS_S: std::cout << "s"; break;
				case Building_id::SCULPTURE_ZEUS_W: std::cout << "w"; break;
				default: std::cout << "-";
				}
			std::cout << " ";
			}
		std::cout << '\n';
		}
	}



std::string to_string(sf::Image& image, God_id god)
	{
	print_heightmap(image);
	print_stairs(image);
	print_statues(image);

	std::cout << "Checking and clearing buildings larger than 1\n";
	clear_groups(image);
	print_clearmap(image);


	std::stringstream s;

	for (uint32_t y = 0; y < image.getSize().y; y++)
		{
		for (uint32_t x = 0; x < image.getSize().x; x++)
			{
			sf::Color color = image.getPixel(x, y);

			Building_id building;
			try
				{
				building = get_building_id(color, god);
				}
			catch (std::runtime_error& e) { throw std::runtime_error{e.what() + std::string{" at position "} + to_string(sf::Vector2u{x, y})}; }

			if (building == Building_id::SKIP) { continue; }

			s << "{" << x << ", " << y << ", " << building << ", " << get_height(color.a) << ",},\n";
			}
		}
	return s.str();
	}